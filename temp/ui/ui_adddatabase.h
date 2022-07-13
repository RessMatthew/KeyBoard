/********************************************************************************
** Form generated from reading UI file 'adddatabase.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDDATABASE_H
#define UI_ADDDATABASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addDataBase
{
public:
    QPushButton *pushButton;
    QTextEdit *textPinyin;
    QTextEdit *textWord;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *addDataBase)
    {
        if (addDataBase->objectName().isEmpty())
            addDataBase->setObjectName(QStringLiteral("addDataBase"));
        addDataBase->resize(567, 86);
        pushButton = new QPushButton(addDataBase);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(350, 40, 61, 28));
        textPinyin = new QTextEdit(addDataBase);
        textPinyin->setObjectName(QStringLiteral("textPinyin"));
        textPinyin->setGeometry(QRect(70, 40, 111, 31));
        textWord = new QTextEdit(addDataBase);
        textWord->setObjectName(QStringLiteral("textWord"));
        textWord->setGeometry(QRect(230, 40, 111, 31));
        label = new QLabel(addDataBase);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 50, 51, 16));
        label_2 = new QLabel(addDataBase);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(190, 50, 31, 16));
        pushButton_2 = new QPushButton(addDataBase);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(420, 40, 61, 28));
        pushButton_3 = new QPushButton(addDataBase);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(490, 40, 61, 28));

        retranslateUi(addDataBase);

        QMetaObject::connectSlotsByName(addDataBase);
    } // setupUi

    void retranslateUi(QWidget *addDataBase)
    {
        addDataBase->setWindowTitle(QApplication::translate("addDataBase", "Form", Q_NULLPTR));
        pushButton->setText(QApplication::translate("addDataBase", "Add", Q_NULLPTR));
        label->setText(QApplication::translate("addDataBase", "pinyin", Q_NULLPTR));
        label_2->setText(QApplication::translate("addDataBase", "word", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("addDataBase", "Del", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("addDataBase", "Quit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class addDataBase: public Ui_addDataBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDDATABASE_H
