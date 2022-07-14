#ifndef HANDSINPUT_H
#define HANDSINPUT_H

#include <QWidget>

#include <msinkaut_i.c>
#include <msinkaut.h>
#include <vector>

using namespace std;

typedef struct tag_InputRlt
{
    char rlt[128];
}InputRlt;

typedef vector <InputRlt> InPutRltS;

class handsInput : public QWidget
{
    Q_OBJECT
public:
    explicit handsInput(QWidget *parent = 0);
    ~handsInput();

    IInkCollector *     g_pIInkCollector;
    IInkDisp *          g_pIInkDisp;
    IInkRecognizerContext *   g_pIInkRecoContext;
    void inputInit( HWND hwnd );
    void RegDataEx( InPutRltS & Rlts );
    void releaseUp();
    void clear();
};

#endif // HANDSINPUT_H
