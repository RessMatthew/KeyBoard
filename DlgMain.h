#ifndef DLGMAIN_H
#define DLGMAIN_H

#include <QDialog>
#include <QMouseEvent>
#include <QRect>
#include <QTimer>
#include <QTextCursor>
#include <QDebug>
#include "hand/handsinput.h"

QT_BEGIN_NAMESPACE
namespace Ui { class DlgMain; }
QT_END_NAMESPACE

class DlgMain : public QDialog
{
    Q_OBJECT

public:
    DlgMain(QWidget *parent = nullptr);
    ~DlgMain();

    /////
    handsInput inputs;
    InPutRltS tempRlt;
    QTimer *timer;      //自动输入定时器
    bool autoinput;     //是否自动输入
    void input_word(QString new_word);  //输入文字
    ////////////
protected:
    void mouseReleaseEvent(QMouseEvent *e);
private slots:
    //按钮槽函数
    void on_Btn_delete_2_clicked();
signals://发送
    void sendData(QString);

private slots:
    void on_Btn_delete_clicked();
    void on_Btn_word1_clicked();
    void on_Btn_word2_clicked();
    void on_Btn_word3_clicked();
    void on_Btn_word4_clicked();
    void on_Btn_word5_clicked();
    void on_Btn_word6_clicked();
    void on_Btn_word7_clicked();
    void on_Btn_word8_clicked();
    void on_Btn_word9_clicked();
    //重写
    void on_Btn_clear_clicked();
    void SLOT_timeout();//自动输入槽

    void on_pushButton_clicked();



private:
    Ui::DlgMain *ui;
};
#endif // DLGMAIN_H
