#include "frminput.h"
#include "ui_frminput.h"
#include "qdesktopwidget.h"
#include "adddatabase.h"
#include <QDebug>

//QString chinese = "你好。";

frmInput *frmInput::_instance = 0;
frmInput::frmInput(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frmInput)
{
    Audio = new audio(this);
    ui->setupUi(this);
    this->InitProperty();//初始化属性
    this->InitForm();//初始化窗体数据
    this->ChangeStyle();//改变样式
}

frmInput::~frmInput()
{
    delete ui;
}

//初始化面板状态,包括字体大小
void frmInput::Init(QString position, QString style, int btnFontSize, int labFontSize)
{
    this->currentPosition = position;//当前输入法面板位置类型
    this->currentStyle = style;//当前输入法面板样式
    this->btnFontSize = btnFontSize;//当前输入法面板按钮字体大小
    this->labFontSize = labFontSize;//当前输入法面板标签字体大小
    this->ChangeStyle();
    this->ChangeFont();
}

//鼠标滑动事件：
void frmInput::mouseMoveEvent(QMouseEvent *e)
{
    if (mousePressed && (e->buttons() && Qt::LeftButton)) {
        this->move(e->globalPos() - mousePoint);
        e->accept();
    }
}

void frmInput::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton) {
        mousePressed = true;//鼠标是否按下
        mousePoint = e->globalPos() - this->pos();//鼠标拖动自定义标题栏时的坐标
        e->accept();
    }
}

void frmInput::mouseReleaseEvent(QMouseEvent *)
{
    mousePressed = false;
}

//初始化窗体数据
void frmInput::InitForm()
{
    this->mousePressed = false;//鼠标是否按下:否
    this->setWindowFlags(Qt::Tool | Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);

    QDesktopWidget w;
    deskWidth = w.availableGeometry().width();//桌面宽度：电脑桌面高度
    deskHeight = w.availableGeometry().height();//桌面高度：电脑桌面高度
    frmWidth = this->width();//窗体宽度：ui宽度
    frmHeight = this->height();//窗体高度：ui高度

    //连接数据库
    QSqlDatabase DbConn;
    DbConn = QSqlDatabase::addDatabase("QSQLITE", "py");//addDatabase("驱动"，"数据库名")
    DbConn.setDatabaseName(qApp->applicationDirPath() + "/py.db");
    DbConn.open();

    isFirst = true;//是否首次加载：是
    isPress = false;//是否长按退格键：否
    timerPress = new QTimer(this);//退格键定时器： 初始化一个
    connect(timerPress, SIGNAL(timeout()), this, SLOT(reClicked()));//????

    currentWidget = 0;//当前的焦点对象
    currentLineEdit = 0;//当前焦点的单行文本框
    currentTextEdit = 0;//当前焦点的多行文本框
    currentPlain = 0;//当前焦点的富文本框
    currentBrowser = 0;//当前焦点的文本浏览框
    currentEditType = "";//当前焦点控件的类型


    //如果需要更改输入法面板的显示位置,改变currentPosition这个变量即可
    //control--显示在对应输入框的正下方 bottom--填充显示在底部  center--窗体居中显示
    currentPosition = "";//当前输入法面板位置类型


    //如果需要更改输入法面板的样式,改变currentStyle这个变量即可
    //blue--淡蓝色  dev--dev风格  black--黑色  brown--灰黑色  lightgray--浅灰色  darkgray--深灰色  gray--灰色  silvery--银色
    currentStyle = "";

    //输入法面板字体大小,如果需要更改面板字体大小,该这里即可
    btnFontSize = 10;
    labFontSize = 10;

    //如果需要更改输入法初始模式,改变currentType这个变量即可
    //min--小写模式  max--大写模式  chinese--中文模式
    currentType = "chinese";//QString默认中文模式
    changeType(currentType);//当前输入法类型

    QList<QPushButton *> btn = this->findChildren<QPushButton *>();
    foreach (QPushButton * b, btn) {
        //每个btn,点击都执行btn_click()事件
        connect(b, SIGNAL(clicked()), this, SLOT(btn_clicked()));
    }

    //绑定全局改变焦点信号槽
    connect(qApp, SIGNAL(focusChanged(QWidget *, QWidget *)),
            this, SLOT(focusChanged(QWidget *, QWidget *)));
    //绑定按键事件过滤器
    qApp->installEventFilter(this);
}

//初始化属性
void frmInput::InitProperty()
{
    //21个特殊字符
    ui->btnOther1->setProperty("btnOther", true);
    ui->btnOther2->setProperty("btnOther", true);
    ui->btnOther3->setProperty("btnOther", true);
    ui->btnOther4->setProperty("btnOther", true);
    ui->btnOther5->setProperty("btnOther", true);
    ui->btnOther6->setProperty("btnOther", true);
    ui->btnOther7->setProperty("btnOther", true);
    ui->btnOther8->setProperty("btnOther", true);
    ui->btnOther9->setProperty("btnOther", true);
    ui->btnOther10->setProperty("btnOther", true);
    ui->btnOther11->setProperty("btnOther", true);
    ui->btnOther12->setProperty("btnOther", true);
    ui->btnOther13->setProperty("btnOther", true);
    ui->btnOther14->setProperty("btnOther", true);
    ui->btnOther15->setProperty("btnOther", true);
    ui->btnOther16->setProperty("btnOther", true);
    ui->btnOther17->setProperty("btnOther", true);
    ui->btnOther18->setProperty("btnOther", true);
    ui->btnOther19->setProperty("btnOther", true);
    ui->btnOther20->setProperty("btnOther", true);
    ui->btnOther21->setProperty("btnOther", true);

    //最下排4个特殊键
    ui->btnDot->setProperty("btnOther", true);
    ui->btnSpace->setProperty("btnOther", true);
    ui->btnEnter->setProperty("btnOther", true);
    ui->btnDelete->setProperty("btnOther", true);

    //数字
    ui->btn0->setProperty("btnNum", true);
    ui->btn1->setProperty("btnNum", true);
    ui->btn2->setProperty("btnNum", true);
    ui->btn3->setProperty("btnNum", true);
    ui->btn4->setProperty("btnNum", true);
    ui->btn5->setProperty("btnNum", true);
    ui->btn6->setProperty("btnNum", true);
    ui->btn7->setProperty("btnNum", true);
    ui->btn8->setProperty("btnNum", true);
    ui->btn9->setProperty("btnNum", true);
//    ui->btn00->setProperty("btnNum", true);

    //字母
    ui->btna->setProperty("btnLetter", true);
    ui->btnb->setProperty("btnLetter", true);
    ui->btnc->setProperty("btnLetter", true);
    ui->btnd->setProperty("btnLetter", true);
    ui->btne->setProperty("btnLetter", true);
    ui->btnf->setProperty("btnLetter", true);
    ui->btng->setProperty("btnLetter", true);
    ui->btnh->setProperty("btnLetter", true);
    ui->btni->setProperty("btnLetter", true);
    ui->btnj->setProperty("btnLetter", true);
    ui->btnk->setProperty("btnLetter", true);
    ui->btnl->setProperty("btnLetter", true);
    ui->btnm->setProperty("btnLetter", true);
    ui->btnn->setProperty("btnLetter", true);
    ui->btno->setProperty("btnLetter", true);
    ui->btnp->setProperty("btnLetter", true);
    ui->btnq->setProperty("btnLetter", true);
    ui->btnr->setProperty("btnLetter", true);
    ui->btns->setProperty("btnLetter", true);
    ui->btnt->setProperty("btnLetter", true);
    ui->btnu->setProperty("btnLetter", true);
    ui->btnv->setProperty("btnLetter", true);
    ui->btnw->setProperty("btnLetter", true);
    ui->btnx->setProperty("btnLetter", true);
    ui->btny->setProperty("btnLetter", true);
    ui->btnz->setProperty("btnLetter", true);

    //汉字标签数组QList<QLabel *>labCh汉字标签数组；
    labCh.append(ui->labCh0);
    labCh.append(ui->labCh1);
    labCh.append(ui->labCh2);
    labCh.append(ui->labCh3);
    labCh.append(ui->labCh4);
    labCh.append(ui->labCh5);
    labCh.append(ui->labCh6);
    labCh.append(ui->labCh7);
    labCh.append(ui->labCh8);
    labCh.append(ui->labCh9);
    for (int i = 0; i < 10; i++) {
        //给每个数组元素安装事件过滤器
        labCh[i]->installEventFilter(this);
    }
}

//显示输入法面板
void frmInput::ShowPanel()
{
    this->setVisible(true);
    int width = ui->btn0->width();
    width = width > 60 ? width : 60;
    ui->btnPre->setMinimumWidth(width);
    ui->btnPre->setMaximumWidth(width);
    ui->btnNext->setMinimumWidth(width);
    ui->btnNext->setMaximumWidth(width);
    ui->btnClose->setMinimumWidth(width);
    ui->btnClose->setMaximumWidth(width);
}

//事件过滤器,用于识别鼠标单击汉字标签处获取对应汉字
bool frmInput::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
        if (mouseEvent->button() == Qt::LeftButton) {
            if (obj == ui->labCh0) {
                setChinese(0);
            } else if (obj == ui->labCh1) {
                setChinese(1);
            } else if (obj == ui->labCh2) {
                setChinese(2);
            } else if (obj == ui->labCh3) {
                setChinese(3);
            } else if (obj == ui->labCh4) {
                setChinese(4);
            } else if (obj == ui->labCh5) {
                setChinese(5);
            } else if (obj == ui->labCh6) {
                setChinese(6);
            } else if (obj == ui->labCh7) {
                setChinese(7);
            } else if (obj == ui->labCh8) {
                setChinese(8);
            } else if (obj == ui->labCh9) {
                setChinese(9);
            } else if (currentEditType != "" && obj != ui->btnClose) {
                QString objName = obj->objectName();
                if (!obj->property("noinput").toBool() && objName != "frmMainWindow"
                        && objName != "frmInputWindow" && objName != "qt_edit_menu") {
                    ShowPanel();
                }
            }

            btnPress = (QPushButton *)obj;
            if (checkPress()) {
                isPress = true;
                timerPress->start(500);
            }
            return false;
        }
    } else if (event->type() == QEvent::MouseButtonRelease) {
        btnPress = (QPushButton *)obj;
        if (checkPress()) {
            isPress = false;
            timerPress->stop();
        }
        return false;
    } else if (event->type() == QEvent::KeyPress) {
        //如果输入法窗体不可见,则不需要处理
        if (!isVisible()) {
            return QWidget::eventFilter(obj, event);
        }

        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        //Shift切换输入法模式,esc键关闭输入法面板,空格取第一个汉字,退格键删除
        //中文模式下回车键取拼音,中文模式下当没有拼音时可以输入空格
        if (keyEvent->key() == Qt::Key_Space) {
            if (ui->labPY->text() != "") {
                setChinese(0);
                return true;
            } else {
                return false;
            }
        } else if (keyEvent->key() == Qt::Key_Return || keyEvent->key() == Qt::Key_Enter) {
            insertValue(ui->labPY->text());
            ui->labPY->setText("");
            selectChinese();
            return true;
        } else if (keyEvent->key() == Qt::Key_Shift) {
            ui->btnType->click();
            return true;
        } else if (keyEvent->key() == Qt::Key_Escape) {
            ui->btnClose->click();
            return true;
        } else if (keyEvent->key() == Qt::Key_Backspace) {
            ui->btnDelete->click();
            return true;
        } else if (keyEvent->text() == "+" || keyEvent->text() == "=") {
            if (ui->labPY->text() != "") {
                ui->btnNext->click();
                return true;
            } else {
                return false;
            }
        } else if (keyEvent->text() == "-" || keyEvent->text() == "_") {
            if (ui->labPY->text() != "") {
                ui->btnPre->click();
                return true;
            } else {
                return false;
            }
        } else if (keyEvent->key() == Qt::Key_CapsLock) {
            if (currentType != "max") {
                currentType = "max";
            } else {
                currentType = "min";
            }
            changeType(currentType);
            return true;
        } else {
            if (currentEditType == "QWidget") {
                return false;
            }
            QString key;
            if (currentType == "chinese") {
                key = keyEvent->text();
            } else if (currentType == "min") {
                key = keyEvent->text().toLower();
            } else if (currentType == "max") {
                key = keyEvent->text().toUpper();
            }
            QList<QPushButton *> btn = this->findChildren<QPushButton *>();
            foreach (QPushButton * b, btn) {
                if (b->text() == key) {
                    b->click();
                    return true;
                }
            }
        }
        return false;
    }
    return QWidget::eventFilter(obj, event);
}

//校验当前长按的按钮
bool frmInput::checkPress()
{
    //只有属于输入法键盘的合法按钮才继续处理
    bool num_ok = btnPress->property("btnNum").toBool();
    bool other_ok = btnPress->property("btnOther").toBool();
    bool letter_ok = btnPress->property("btnLetter").toBool();
    if (num_ok || other_ok || letter_ok) {
        return true;
    }
    return false;
}

void frmInput::reClicked()
{
    if (isPress) {
        timerPress->setInterval(30);
        btnPress->click();
    }
}

//焦点改变事件槽函数处理
void frmInput::focusChanged(QWidget *oldWidget, QWidget *nowWidget)
{
    //qDebug() << "oldWidget:" << oldWidget << " nowWidget:" << nowWidget;
    if (nowWidget != 0 && !this->isAncestorOf(nowWidget)) {
        //在Qt5和linux系统中(嵌入式linux除外),当输入法面板关闭时,焦点会变成无,然后焦点会再次移到焦点控件处
        //这样导致输入法面板的关闭按钮不起作用,关闭后马上有控件获取焦点又显示.
        //为此,增加判断,当焦点是从有对象转为无对象再转为有对象时不要显示.
        //这里又要多一个判断,万一首个窗体的第一个焦点就是落在可输入的对象中,则要过滤掉
#ifndef __arm__
        if (oldWidget == 0x0 && !isFirst) {
            QTimer::singleShot(0, this, SLOT(hide()));
            return;
        }
#endif

        //如果对应属性noinput为真则不显示
        if (nowWidget->property("noinput").toBool()) {
            QTimer::singleShot(0, this, SLOT(hide()));
            return;
        }

        isFirst = false;
        if (nowWidget->inherits("QLineEdit")) {
            currentLineEdit = (QLineEdit *)nowWidget;
            currentEditType = "QLineEdit";
            ShowPanel();
        } else if (nowWidget->inherits("QTextEdit")) {
            currentTextEdit = (QTextEdit *)nowWidget;
            currentEditType = "QTextEdit";
            ShowPanel();
        } else if (nowWidget->inherits("QPlainTextEdit")) {
            currentPlain = (QPlainTextEdit *)nowWidget;
            currentEditType = "QPlainTextEdit";
            ShowPanel();
        } else if (nowWidget->inherits("QTextBrowser")) {
            currentBrowser = (QTextBrowser *)nowWidget;
            currentEditType = "QTextBrowser";
            ShowPanel();
        } else if (nowWidget->inherits("QComboBox")) {
            QComboBox *cbox = (QComboBox *)nowWidget;
            //只有当下拉选择框处于编辑模式才可以输入
            if (cbox->isEditable()) {
                currentLineEdit = cbox->lineEdit() ;
                currentEditType = "QLineEdit";
                ShowPanel();
            }
        } else if (nowWidget->inherits("QSpinBox") ||
                   nowWidget->inherits("QDoubleSpinBox") ||
                   nowWidget->inherits("QDateEdit") ||
                   nowWidget->inherits("QTimeEdit") ||
                   nowWidget->inherits("QDateTimeEdit")) {
            currentWidget = nowWidget;
            currentEditType = "QWidget";
            ShowPanel();
        } else {
            //需要将输入法切换到最初的原始状态--小写,同时将之前的对象指针置为零
            currentWidget = 0;
            currentLineEdit = 0;
            currentTextEdit = 0;
            currentPlain = 0;
            currentBrowser = 0;
            currentEditType = "";
            currentType = "min";
            changeType(currentType);
            this->setVisible(false);
        }

        //根据用户选择的输入法位置设置-居中显示-底部填充-显示在输入框正下方
        if (currentPosition == "center") {
            QPoint pos = QPoint(deskWidth / 2 - frmWidth / 2, deskHeight / 2 - frmHeight / 2);
            this->setGeometry(pos.x(), pos.y(), frmWidth, frmHeight);
        } else if (currentPosition == "bottom") {
            this->setGeometry(0, deskHeight - frmHeight, deskWidth, frmHeight);
        } else if (currentPosition == "control") {
            QRect rect = nowWidget->rect();
            QPoint pos = QPoint(rect.left(), rect.bottom() + 2);
            pos = nowWidget->mapToGlobal(pos);

            int x = pos.x();
            int y = pos.y();
            if (pos.x() + frmWidth > deskWidth) {
                x = deskWidth - frmWidth;
            }
            if (pos.y() + frmHeight > deskHeight) {
                y = pos.y() - frmHeight - rect.height() - 35;
            }

            this->setGeometry(x, y, frmWidth, frmHeight);
        }
    }
}

//改变输入法类型
void frmInput::changeType(QString type)
{
    if (type == "max") {
        changeLetter(true);//改变字母大小
        ui->btnType->setText("大写");
        ui->lab_Title->setText("  中文输入法--大写");
        ui->btnOther12->setText("/");
        ui->btnOther14->setText(":");
        ui->btnOther17->setText(",");
        ui->btnOther18->setText("\\");
        ui->btnOther21->setText("\"");
    } else if (type == "min") {
        changeLetter(false);
        ui->btnType->setText("小写");
        ui->lab_Title->setText("  中文输入法--小写");
        ui->btnOther12->setText("/");
        ui->btnOther14->setText(":");
        ui->btnOther17->setText(",");
        ui->btnOther18->setText("\\");
        ui->btnOther21->setText("\"");
    } else {
        changeLetter(false);
        ui->btnType->setText("中文");
        ui->lab_Title->setText("  中文输入法--中文");
        ui->btnOther12->setText("。");
        ui->btnOther14->setText("：");
        ui->btnOther17->setText("，");
        ui->btnOther18->setText("；");
        ui->btnOther21->setText("“");
    }
    //每次切换到模式,都要执行清空之前中文模式下的信息
    clearChinese();
    ui->labPY->setText("");
}

//改变字母大小写
void frmInput::changeLetter(bool isUpper)
{
    QList<QPushButton *> btn = this->findChildren<QPushButton *>();
    foreach (QPushButton * b, btn) {
        if (b->property("btnLetter").toBool()) {
            if (isUpper) {
                b->setText(b->text().toUpper());
            } else {
                b->setText(b->text().toLower());
            }
        }
    }
}

//查询汉字,数据库操作
void frmInput::selectChinese()
{
    clearChinese();
    QSqlQuery query(QSqlDatabase::database("py"));
    QString currentPY = ui->labPY->text();
    QString sql = QString("select word from pinyin where pinyin='%1'").arg(currentPY);
    query.exec(sql);
    //逐个将查询到的字词加入汉字队列
    while(query.next()) {
        QString result = query.value(0).toString();
        QStringList text = result.split(" ");
        foreach (QString txt, text) {
            if (txt.length() > 0) {
                allPY.append(txt);
                currentPY_count++;
            }
        }
    }
    showChinese();
}

//显示查询到的汉字
void frmInput::showChinese()
{
    //每个版面最多显示10个汉字
    int count = 0;
    currentPY.clear();
    for (int i = 0; i < 10; i++) {
        labCh[i]->setText("");
    }

    for (int i = currentPY_index; i < currentPY_count; i++) {
        if (count == 10) {
            break;
        }
        QString txt = QString("%1.%2").arg(count).arg(allPY[currentPY_index]);
        currentPY.append(allPY[currentPY_index]);
        labCh[count]->setText(txt);
        count++;
        currentPY_index++;
    }
    //qDebug() << "currentPY_index:" << currentPY_index << "currentPY_count:" << currentPY_count;
}

//输入法面板按键处理
void frmInput::btn_clicked()
{
    //如果当前焦点控件类型为空,则返回不需要继续处理
    if (currentEditType == "") {
        return;
    }

    QPushButton *btn = (QPushButton *)sender();
    QString objectName = btn->objectName();
    if (objectName == "btnType") {
        if (currentType == "min") {
            currentType = "max";
        } else if (currentType == "max") {
            currentType = "chinese";
        } else if (currentType == "chinese") {
            currentType = "min";
        }
        changeType(currentType);
    } else if (objectName == "btnDelete") {
        //如果当前是中文模式,则删除对应拼音,删除完拼音之后再删除对应文本输入框的内容
        if (currentType == "chinese") {
            QString txt = ui->labPY->text();
            int len = txt.length();
            if (len > 0) {
                ui->labPY->setText(txt.left(len - 1));
                selectChinese();//查询汉字,数据库操作
            } else {
                deleteValue();
            }
        } else {
            deleteValue();
        }
    } else if (objectName == "btnPre") {
        if (currentPY_index >= 20) {
            //每次最多显示10个汉字,所以每次向前的时候索引要减20
            if (currentPY_index % 10 == 0) {
                currentPY_index -= 20;
            } else {
                currentPY_index = currentPY_count - (currentPY_count % 10) - 10;
            }
        } else {
            currentPY_index = 0;
        }
        showChinese();
    } else if (objectName == "btnNext") {
        if (currentPY_index < currentPY_count - 1) {
            showChinese();
        }
    } else if (objectName == "btnClose") {
        this->setVisible(false);
    } else if (objectName == "btnSpace") {
        if (currentType == "chinese") {
            setChinese(0);
        } else {
            insertValue(" ");
        }
    } else if (objectName == "btnEnter") {
        QWidget *widget;
        widget = 0;
        if (currentEditType == "QLineEdit") {
            widget = currentLineEdit;
        } else if (currentEditType == "QTextEdit") {
            widget = currentTextEdit;
        } else if (currentEditType == "QPlainTextEdit") {
            widget = currentPlain;
        } else if (currentEditType == "QTextBrowser") {
            widget = currentBrowser;
        } else if (currentEditType == "QWidget") {
            widget = currentWidget;
        }

        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_Enter, Qt::NoModifier);
        QApplication::sendEvent(widget, &keyPress);

        this->setVisible(false);
    } else {
        QString value = btn->text();
        //如果是&按钮，因为对应&被过滤,所以真实的text为去除前面一个&字符
        if (objectName == "btnOther7") {
            value = value.right(1);
        }
        //当前不是中文模式,则单击按钮对应text为传递参数
        if (currentType != "chinese") {
            insertValue(value);
        } else {
            //中文模式下,不允许输入特殊字符,单击对应数字按键取得当前索引的汉字
            if (btn->property("btnOther").toBool()) {
                if (ui->labPY->text().length() == 0) {
                    insertValue(value);
                }
            } else if (btn->property("btnNum").toBool()) {
                if (ui->labPY->text().length() == 0) {
                    insertValue(value);
                } else if (objectName == "btn0") {
                    setChinese(0);
                } else if (objectName == "btn1") {
                    setChinese(1);
                } else if (objectName == "btn2") {
                    setChinese(2);
                } else if (objectName == "btn3") {
                    setChinese(3);
                } else if (objectName == "btn4") {
                    setChinese(4);
                } else if (objectName == "btn5") {
                    setChinese(5);
                } else if (objectName == "btn6") {
                    setChinese(6);
                } else if (objectName == "btn7") {
                    setChinese(7);
                } else if (objectName == "btn8") {
                    setChinese(8);
                } else if (objectName == "btn9") {
                    setChinese(9);
                }
            } else if (btn->property("btnLetter").toBool()) {
                ui->labPY->setText(ui->labPY->text() + value);
                selectChinese();
            }
        }
    }
}

//插入值到当前焦点控件
void frmInput::insertValue(QString value)
{
    if (currentEditType == "QLineEdit") {
        currentLineEdit->insert(value);
    } else if (currentEditType == "QTextEdit") {
        currentTextEdit->insertPlainText(value);
    } else if (currentEditType == "QPlainTextEdit") {
        currentPlain->insertPlainText(value);
    } else if (currentEditType == "QTextBrowser") {
        currentBrowser->insertPlainText(value);
    } else if (currentEditType == "QWidget") {
        QKeyEvent keyPress(QEvent::KeyPress, 0, Qt::NoModifier, QString(value));
        QApplication::sendEvent(currentWidget, &keyPress);
    }
}

//删除当前焦点控件的一个字符
void frmInput::deleteValue()
{
    if (currentEditType == "QLineEdit") {
        currentLineEdit->backspace();
    } else if (currentEditType == "QTextEdit") {
        //获取当前QTextEdit光标,如果光标有选中,则移除选中字符,否则删除光标前一个字符
        QTextCursor cursor = currentTextEdit->textCursor();
        if(cursor.hasSelection()) {
            cursor.removeSelectedText();
        } else {
            cursor.deletePreviousChar();
        }
    } else if (currentEditType == "QPlainTextEdit") {
        //获取当前QTextEdit光标,如果光标有选中,则移除选中字符,否则删除光标前一个字符
        QTextCursor cursor = currentPlain->textCursor();
        if(cursor.hasSelection()) {
            cursor.removeSelectedText();
        } else {
            cursor.deletePreviousChar();
        }
    } else if (currentEditType == "QTextBrowser") {
        //获取当前QTextEdit光标,如果光标有选中,则移除选中字符,否则删除光标前一个字符
        QTextCursor cursor = currentBrowser->textCursor();
        if(cursor.hasSelection()) {
            cursor.removeSelectedText();
        } else {
            cursor.deletePreviousChar();
        }
    } else if (currentEditType == "QWidget") {
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_Delete, Qt::NoModifier, QString());
        QApplication::sendEvent(currentWidget, &keyPress);
    }
}

//设置当前汉字，选着那个汉字
void frmInput::setChinese(int index)
{
    int count = currentPY.count();
    if (count > index) {
        insertValue(currentPY[index]);
        //添加完一个汉字后,清空当前汉字信息,等待重新输入
        clearChinese();
        ui->labPY->setText("");
    }
}

//清空当前汉字信息
void frmInput::clearChinese()
{
    //清空汉字,重置索引
    for (int i = 0; i < 10; i++) {
        labCh[i]->setText("");
    }
    allPY.clear();
    currentPY.clear();
    currentPY_index = 0;
    currentPY_count = 0;
}

void frmInput::on_btnStyle_clicked()
{
    if (currentStyle == "blue") {
        currentStyle="dev";

    } else if (currentStyle == "dev") {
        currentStyle="gray";

    } else if (currentStyle == "gray") {
        currentStyle="lightgray";

    } else if (currentStyle == "lightgray") {
        currentStyle="darkgray";

    } else if (currentStyle == "darkgray") {
        currentStyle="black";

    } else if (currentStyle == "black") {
        currentStyle="brown";

    } else if (currentStyle == "brown") {
        currentStyle="silvery";

    } else if (currentStyle == "silvery") {
        currentStyle="blue";
    }
    ChangeStyle();
}

//改变样式
void frmInput::ChangeStyle()
{
    if (currentStyle == "blue") {
        changeStyle("#DEF0FE", "#C0DEF6", "#C0DCF2", "#386487");

    } else if (currentStyle == "dev") {
        changeStyle("#C0D3EB", "#BCCFE7", "#B4C2D7", "#324C6C");

    } else if (currentStyle == "gray") {
        changeStyle("#E4E4E4", "#A2A2A2", "#A9A9A9", "#000000");

    } else if (currentStyle == "lightgray") {
        changeStyle("#EEEEEE", "#E5E5E5", "#D4D0C8", "#6F6F6F");

    } else if (currentStyle == "darkgray") {
        changeStyle("#D8D9DE", "#C8C8D0", "#A9ACB5", "#5D5C6C");

    } else if (currentStyle == "black") {
        changeStyle("#4D4D4D", "#292929", "#D9D9D9", "#CACAD0");

    } else if (currentStyle == "brown") {
        changeStyle("#667481", "#566373", "#C2CCD8", "#E7ECF0");

    } else if (currentStyle == "silvery") {
        changeStyle("#E1E4E6", "#CCD3D9", "#B2B6B9", "#000000");

    }
}


//改变样式
void frmInput::changeStyle(QString topColor, QString bottomColor, QString borderColor, QString textColor)
{
    QStringList qss;
    qss.append(QString("QWidget#widget_title{background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 %1,stop:1 %2);}")
               .arg(topColor).arg(bottomColor));
    qss.append("QPushButton{padding:5px;border-radius:3px;}");
    qss.append(QString("QPushButton:hover{background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 %1,stop:1 %2);}")
               .arg(topColor).arg(bottomColor));
    qss.append(QString("QLabel,QPushButton{color:%1;}").arg(textColor));
    qss.append(QString("QPushButton#btnPre,QPushButton#btnNext,QPushButton#btnClose{padding:5px;}"));
    qss.append(QString("QPushButton{border:1px solid %1;background:rgba(0,0,0,0);}")
               .arg(borderColor));
    qss.append(QString("QLineEdit{border:1px solid %1;border-radius:5px;padding:2px;background:none;selection-background-color:%2;selection-color:%3;}")
               .arg(borderColor).arg(bottomColor).arg(topColor));
    this->setStyleSheet(qss.join(""));
}

//改变字体大小
void frmInput::ChangeFont()
{
    QFont btnFont(this->font().family(), btnFontSize);
    QFont labFont(this->font().family(), labFontSize);

    QList<QPushButton *> btns = ui->widgetMain->findChildren<QPushButton *>();
    foreach (QPushButton * btn, btns) {
        btn->setFont(btnFont);
    }

    QList<QLabel *> labs = ui->widgetTop->findChildren<QLabel *>();
    foreach (QLabel * lab, labs) {
        lab->setFont(labFont);
    }
    ui->btnPre->setFont(labFont);
    ui->btnNext->setFont(labFont);
    ui->btnClose->setFont(labFont);
}


//弹出添加数据库对话框
void frmInput::on_btnStyle_2_clicked()
{
    view = new addDataBase(this) ;//将类指针实例化
    view->show();
}

//开始录音
void frmInput::on_SPEECHpushButton_pressed()
{
    ui->SPEECHpushButton->setText("松开识别");

    /*开始录音*/
    Audio->startAudio("audiofile");
}

//识别录音
void frmInput::on_SPEECHpushButton_released()
{
    ui->SPEECHpushButton->setText("按住说话");
    /*停止录音*/
    Audio->stopAudio();

    /*启动识别*/
    QString retStr = Audio->startSpeech();
    qDebug()<<"识别语音为 :"<<retStr;

    allPY.append(retStr);
    currentPY_count++;
    showChinese();
}

//开启手写
void frmInput::on_pushHand_clicked()
{
    dlgMain = new DlgMain(this) ;//将类指针实例化
    connect(dlgMain,SIGNAL(sendData(QString)),this,SLOT(receiveData(QString)));
    dlgMain->setModal(false);
    dlgMain->show();
}

void frmInput::receiveData(QString data){
  qDebug()<<"手写输入为 :"<<data;
  allPY.append(data);
  currentPY_count++;

  showChinese();
}


