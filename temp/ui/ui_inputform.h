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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_inputForm
{
public:
    QTextEdit *textEdit_2;
    QTextEdit *textEdit_3;

    void setupUi(QWidget *inputForm)
    {
        if (inputForm->objectName().isEmpty())
            inputForm->setObjectName(QStringLiteral("inputForm"));
        inputForm->resize(703, 500);
        textEdit_2 = new QTextEdit(inputForm);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(30, 170, 151, 41));
        textEdit_3 = new QTextEdit(inputForm);
        textEdit_3->setObjectName(QStringLiteral("textEdit_3"));
        textEdit_3->setGeometry(QRect(30, 100, 151, 41));

        retranslateUi(inputForm);

        QMetaObject::connectSlotsByName(inputForm);
    } // setupUi

    void retranslateUi(QWidget *inputForm)
    {
        inputForm->setWindowTitle(QApplication::translate("inputForm", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class inputForm: public Ui_inputForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUTFORM_H
