#include "DlgMain.h"
#include "ui_DlgMain.h"

QString chinese;


DlgMain::DlgMain(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DlgMain)
{
    ui->setupUi(this);

    //
    WId hShow = ui->label->winId();
    inputs.inputInit((HWND)hShow);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(SLOT_timeout()));
    timer->setSingleShot(true);//只触发一次
    autoinput = false;

    ui->textEdit->setPlaceholderText("手写窗口传值...");
    //ui->textEdit->setPlaceholderText(chinese);
    ui->textEdit->document()->setMaximumBlockCount(1);
}

DlgMain::~DlgMain()
{
    delete ui;
}

void DlgMain::input_word(QString new_word)
{
    ui->textEdit->setFocus();//获取焦点
    if(ui->Btn_word1->text() == "")
        return;

    if(autoinput == true)//如果已经自动输入，则删掉自动输入的，然后输入点击选择的
        on_Btn_delete_clicked();

    QString str = ui->textEdit->toPlainText();

    int pos = ui->textEdit->textCursor().position();
    QString str_input = str.left(pos);
    str_input = str_input + new_word + str.right(str.length() - pos);

    ui->textEdit->clear();
    ui->textEdit->setFontUnderline(false);
    ui->textEdit->setText(str_input);

    chinese=str_input;
    qDebug()<<"chinese: "<<chinese;

    QTextCursor cur = ui->textEdit->textCursor();
    cur.setPosition(pos + 1);
    ui->textEdit->setTextCursor(cur);

    on_Btn_clear_clicked();
}

//在写字区释放鼠标后，在选字区选择文字
void DlgMain::mouseReleaseEvent(QMouseEvent *e)
{
    autoinput = false;
    timer->start(2000);
    tempRlt.clear();
    inputs.RegDataEx(tempRlt);
//    qDebug() << tempRlt.size();
    ui->Btn_word1->setText(QString::fromUtf8(QByteArray(tempRlt[0].rlt)));
    ui->Btn_word2->setText(QString::fromUtf8(QByteArray(tempRlt[1].rlt)));
    ui->Btn_word3->setText(QString::fromUtf8(QByteArray(tempRlt[2].rlt)));
    ui->Btn_word4->setText(QString::fromUtf8(QByteArray(tempRlt[3].rlt)));
    ui->Btn_word5->setText(QString::fromUtf8(QByteArray(tempRlt[4].rlt)));
    ui->Btn_word6->setText(QString::fromUtf8(QByteArray(tempRlt[5].rlt)));
    ui->Btn_word7->setText(QString::fromUtf8(QByteArray(tempRlt[6].rlt)));
    ui->Btn_word8->setText(QString::fromUtf8(QByteArray(tempRlt[7].rlt)));
    ui->Btn_word9->setText(QString::fromUtf8(QByteArray(tempRlt[8].rlt)));
}

//删除一个字
void DlgMain::on_Btn_delete_clicked()
{
    ui->textEdit->setFocus();//获取焦点
    int pos = ui->textEdit->textCursor().position();
    if(pos==0)
        return;

    QString str_old = ui->textEdit->toPlainText();
    QString str_new = "";
    if(!str_old.isEmpty())
    {
        str_new = str_old.left(pos-1) + str_old.right(str_old.length() - pos);
        ui->textEdit->setFontUnderline(false);
        ui->textEdit->setText(str_new);
        QTextCursor cur = ui->textEdit->textCursor();
        cur.setPosition(pos-1);
        ui->textEdit->setTextCursor(cur);
    }
}

//清除所写区域
void DlgMain::on_Btn_clear_clicked()
{
    ui->textEdit->setFocus();//获取焦点
    inputs.clear();// Only 删除笔触
    ui->label->clear();

    ui->Btn_word1->setText("");
    ui->Btn_word2->setText("");
    ui->Btn_word3->setText("");
    ui->Btn_word4->setText("");
    ui->Btn_word5->setText("");
    ui->Btn_word6->setText("");
    ui->Btn_word7->setText("");
    ui->Btn_word8->setText("");
    ui->Btn_word9->setText("");

    tempRlt.clear();
}

//点击取值
void DlgMain::on_Btn_word1_clicked()
{
    input_word(QString::fromUtf8(QByteArray(tempRlt[0].rlt)));
}

void DlgMain::on_Btn_word2_clicked()
{
    input_word(QString::fromUtf8(QByteArray(tempRlt[1].rlt)));
}

void DlgMain::on_Btn_word3_clicked()
{
    input_word(QString::fromUtf8(QByteArray(tempRlt[2].rlt)));
}

void DlgMain::on_Btn_word4_clicked()
{
    input_word(QString::fromUtf8(QByteArray(tempRlt[3].rlt)));
}

void DlgMain::on_Btn_word5_clicked()
{
    input_word(QString::fromUtf8(QByteArray(tempRlt[4].rlt)));
}

void DlgMain::on_Btn_word6_clicked()
{
    input_word(QString::fromUtf8(QByteArray(tempRlt[5].rlt)));
}

void DlgMain::on_Btn_word7_clicked()
{
    input_word(QString::fromUtf8(QByteArray(tempRlt[6].rlt)));
}

void DlgMain::on_Btn_word8_clicked()
{
    input_word(QString::fromUtf8(QByteArray(tempRlt[7].rlt)));
}

void DlgMain::on_Btn_word9_clicked()
{
    input_word(QString::fromUtf8(QByteArray(tempRlt[8].rlt)));
}



void DlgMain::SLOT_timeout()
{
    if(ui->Btn_word1->text() == "")
        return;
    QString str = ui->textEdit->toPlainText();
    QString str1 = QString::fromUtf8(QByteArray(tempRlt[0].rlt));

    int pos = ui->textEdit->textCursor().position();

    ui->textEdit->clear();
    ui->textEdit->setFontUnderline(false);
    ui->textEdit->setText(str.left(pos));

    ui->textEdit->moveCursor(QTextCursor::End);
    ui->textEdit->setFontUnderline(true);
    ui->textEdit->insertPlainText(str1);
    ui->textEdit->setFontUnderline(false);

    ui->textEdit->insertPlainText(str.right(str.length() - pos));

    QTextCursor cur = ui->textEdit->textCursor();
    cur.setPosition(pos + 1);
    ui->textEdit->setTextCursor(cur);

    inputs.clear();// Only 删除笔触
    ui->label->clear();

    autoinput = true;
}

//保存签名用的
#include <QScreen>
void DlgMain::on_pushButton_clicked()
{
    QPixmap pix = ui->label->grab();
    pix.save("ddd.jpg");
    QList<QScreen *> screen = QGuiApplication::screens();
    QScreen* pScr = screen.at(0);
    WId hShow = ui->label->winId();
    pScr->grabWindow(hShow).save("111.png","png");
}

void DlgMain::on_Btn_delete_2_clicked()
{
    emit sendData(chinese);
    this->close();
}
