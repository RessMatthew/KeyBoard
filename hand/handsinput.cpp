#include "handsinput.h"
#include <QAxObject>
#include <QDebug>

handsInput::handsInput(QWidget *parent) : QWidget(parent)
{

}

handsInput::~handsInput()
{
    releaseUp();
}

void handsInput::inputInit(HWND hwnd)
{
    if(NULL == hwnd)
        return;
    g_pIInkCollector = NULL;
    g_pIInkDisp = NULL;
    g_pIInkRecoContext = NULL;
    // 初始化 COM 接口
    CoInitialize(NULL);
    HRESULT hr;

    // 使用默认的识别器创建一个识别上下文
    // 这个上下文会被所有的识别对象使用
    hr = CoCreateInstance(CLSID_InkRecognizerContext,NULL, CLSCTX_INPROC_SERVER,IID_IInkRecognizerContext,(void **) &g_pIInkRecoContext);
    if (FAILED(hr)) {
        qDebug() << "没有安装手写识别软件=";
        return ;
    }
    // 创建一个墨迹收集对象
    hr = CoCreateInstance(CLSID_InkCollector,NULL, CLSCTX_INPROC_SERVER,IID_IInkCollector,(void **) &g_pIInkCollector);
    if (FAILED(hr))
        return ;

    // 获取墨迹对象的指针
    hr = g_pIInkCollector->get_Ink(&g_pIInkDisp);
    if (FAILED(hr))
        return ;

    // 将墨迹对象关联一个 hWnd 的窗口
    hr = g_pIInkCollector->put_hWnd((long)hwnd);
    if (FAILED(hr))
        return ;

    // 设置颜色
    IInkDrawingAttributes* p;
    if (SUCCEEDED(g_pIInkCollector->get_DefaultDrawingAttributes(&p)))
    {
        p->put_Color(RGB(0,0,255));
    }

    // 打开墨迹输入的开关
    hr = g_pIInkCollector->put_Enabled(VARIANT_TRUE);
    if (FAILED(hr))
        return ;

#if 1
    //设置手写只识别为一个字
    IInkRecognizerGuide *RecognizerGuide;
    hr = CoCreateInstance(CLSID_InkRecognizerGuide,NULL, CLSCTX_INPROC_SERVER,IID_IInkRecognizerGuide,(void **) &RecognizerGuide);
    if (FAILED(hr))
        return;
    InkRecoGuide recoguide;
    RECT rect;
    rect.bottom = 2;//不能为1
    rect.left = 0;
    rect.right = 2;//不能为1
    rect.top = 0;

    recoguide.rectWritingBox = rect;
    recoguide.rectDrawnBox = rect;
    recoguide.cRows = 1;//不要过大
    recoguide.cColumns = 1;
    recoguide.midline = -1;
    RecognizerGuide->put_GuideData(recoguide);
    g_pIInkRecoContext->putref_Guide(RecognizerGuide);
#endif
}

void handsInput::RegDataEx(InPutRltS &Rlts)
{
    // 将鼠标变为沙漏
    //	HCURSOR hCursor = ::SetCursor(::LoadCursor(NULL, IDC_WAIT));
    // 获取指向墨迹收集器的指针
    // 这个收集器是整个墨迹的快照
    if (!Rlts.empty())
    {
        Rlts.clear();
    }
    IInkStrokes* pIInkStrokes = NULL;
    HRESULT hr = g_pIInkDisp->get_Strokes(&pIInkStrokes);
    if (SUCCEEDED(hr))
    {
        // 将笔触收集器传递给识别器
        hr = g_pIInkRecoContext->putref_Strokes(pIInkStrokes);
        if (SUCCEEDED(hr))
        {
            // 识别
            IInkRecognitionResult* pIInkRecoResult = NULL;
            InkRecognitionStatus RecognitionStatus = IRS_NoError;

            hr = g_pIInkRecoContext->Recognize(&RecognitionStatus, &pIInkRecoResult);
            if (SUCCEEDED(hr) && (pIInkRecoResult!= NULL))
            {
                // 枚举可能的所有结果
                //                CComPtr<IInkRecognitionAlternates> spIInkRecoAlternates;
                IInkRecognitionAlternates* spIInkRecoAlternates;
                hr = pIInkRecoResult->AlternatesFromSelection(
                            0,                              // in: selection start
                            -1,                             // in: selection length; -1 means "up to the last one"
                            10,								// in: the number of alternates we're interested in
                            &spIInkRecoAlternates           // out: the receiving pointer
                            );
                long lCount = 0;
                if (SUCCEEDED(hr) && SUCCEEDED(spIInkRecoAlternates->get_Count(&lCount)))
                {
                    // 获取所有的识别结果
                    IInkRecognitionAlternate* pIInkRecoAlternate = NULL;
                    for (LONG iItem = 0; (iItem < lCount) && (iItem < 10); iItem++)
                    {
                        // Get the alternate string if there is one
                        if (SUCCEEDED(spIInkRecoAlternates->Item(iItem, &pIInkRecoAlternate)))
                        {
                            BSTR bstr = NULL;
                            if (SUCCEEDED(pIInkRecoAlternate->get_String(&bstr)))
                            {
                                InputRlt temp = {0};
                                QString str = QString::fromWCharArray(bstr);
                                //qDebug() << "字体=" << str.toUtf8().data();
                                strcpy(temp.rlt, str.toUtf8().data());
                                Rlts.push_back(temp);
                            }
                            pIInkRecoAlternate->Release();
                        }
                    }
                    //枚举结束，显示出来
                }
            }
            // 重置识别器内容
            g_pIInkRecoContext->putref_Strokes(NULL);
        }
        pIInkStrokes->Release();
    }
    // 重置鼠标
    //	::SetCursor(hCursor);
}

void handsInput::releaseUp()
{
    if (g_pIInkRecoContext != NULL)
    {
        g_pIInkRecoContext->Release();
        g_pIInkRecoContext = NULL;
    }

    if (g_pIInkDisp != NULL)
    {
        g_pIInkDisp->Release();
        g_pIInkDisp = NULL;
    }

    if (g_pIInkCollector != NULL)
    {
        g_pIInkCollector->Release();
        g_pIInkCollector = NULL;
    }
    CoUninitialize();
}

void handsInput::clear()
{
    // 清除所有的笔触
    g_pIInkDisp->DeleteStrokes(0);
    // 清除文字
    //	m_ctrListShow.ResetContent();
    // 重绘画板
    //Invalidate();
}

