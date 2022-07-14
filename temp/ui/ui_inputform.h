/********************************************************************************
** Form generated from reading UI file 'inputform.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUTFORM_H
#define UI_INPUTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_inputForm
{
public:
    QFrame *frame;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;

    void setupUi(QWidget *inputForm)
    {
        if (inputForm->objectName().isEmpty())
            inputForm->setObjectName(QStringLiteral("inputForm"));
        inputForm->resize(487, 548);
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/csu.png"), QSize(), QIcon::Normal, QIcon::Off);
        inputForm->setWindowIcon(icon);
        inputForm->setStyleSheet(QLatin1String("QWidget{\n"
"	border-radius:10px;\n"
"}"));
        frame = new QFrame(inputForm);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(-10, -10, 501, 721));
        frame->setStyleSheet(QLatin1String("#frame{\n"
"	background-image: url(:/image/login.png);\n"
"}\n"
"#frame *{\n"
"	background-image: url();\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        textEdit = new QTextEdit(frame);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(110, 100, 351, 51));
        textEdit_2 = new QTextEdit(frame);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(110, 190, 351, 51));
        QFont font;
        font.setPointSize(9);
        textEdit_2->setFont(font);

        retranslateUi(inputForm);

        QMetaObject::connectSlotsByName(inputForm);
    } // setupUi

    void retranslateUi(QWidget *inputForm)
    {
        inputForm->setWindowTitle(QApplication::translate("inputForm", "\344\270\255\345\215\227\345\244\247\345\255\246\344\277\241\346\201\257\351\227\250\346\210\267", Q_NULLPTR));
        textEdit->setHtml(QApplication::translate("inputForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
        textEdit_2->setHtml(QApplication::translate("inputForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class inputForm: public Ui_inputForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUTFORM_H
