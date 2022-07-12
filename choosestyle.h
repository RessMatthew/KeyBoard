//#ifndef CHOOSESTYLE_H
//#define CHOOSESTYLE_H

//#include <QWidget>

//namespace Ui {
//class chooseStyle;
//}

//class chooseStyle : public QWidget
//{
//    Q_OBJECT

//public:
//    explicit chooseStyle(QWidget *parent = 0);
//    ~chooseStyle();

//private:
//    Ui::chooseStyle *ui;
//};

//#endif // CHOOSESTYLE_H

#ifndef CHOOSESTYLE_H

#define CHOOSESTYLE_H


#include <QtWidgets/QMainWindow>

#include "ui_chooseStyle.h"

#include <Qlabel>

#include <qpushbutton.h>

#include <qpixmap.h>

#include <qstring.h>

#include <qtimer.h>

class chooseStyle : public QMainWindow

{

 Q_OBJECT

public:

 chooseStyle(QWidget *parent=0);

 ~chooseStyle();

private:

 Ui::chooseStyleClass ui;

 QTimer *qTimer;

 int imgNumber;

private slots:

 //显示图片

 void showPictureSlot();

};
