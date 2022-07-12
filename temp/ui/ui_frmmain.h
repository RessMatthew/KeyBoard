/********************************************************************************
** Form generated from reading UI file 'frmmain.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMMAIN_H
#define UI_FRMMAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmMain
{
public:
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QLineEdit *txt;
    QPushButton *btnDialog;
    QPushButton *btnInputDialog;
    QPushButton *btnFileDialog;
    QSpinBox *spinBox;
    QComboBox *comboBox;
    QDoubleSpinBox *doubleSpinBox;
    QComboBox *comboBox_2;
    QDateEdit *dateEdit;
    QTimeEdit *timeEdit;
    QDateTimeEdit *dateTimeEdit;
    QPlainTextEdit *plainTextEdit;
    QTextEdit *textEdit;
    QTextBrowser *textBrowser;
    QTableView *tableView;
    QTableWidget *tableWidget;

    void setupUi(QWidget *frmMain)
    {
        if (frmMain->objectName().isEmpty())
            frmMain->setObjectName(QStringLiteral("frmMain"));
        frmMain->resize(751, 543);
        frmMain->setProperty("sizeGripEnabled", QVariant(false));
        gridLayout = new QGridLayout(frmMain);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lineEdit = new QLineEdit(frmMain);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 0, 1, 1);

        txt = new QLineEdit(frmMain);
        txt->setObjectName(QStringLiteral("txt"));

        gridLayout->addWidget(txt, 0, 1, 1, 1);

        btnDialog = new QPushButton(frmMain);
        btnDialog->setObjectName(QStringLiteral("btnDialog"));

        gridLayout->addWidget(btnDialog, 1, 0, 1, 1);

        btnInputDialog = new QPushButton(frmMain);
        btnInputDialog->setObjectName(QStringLiteral("btnInputDialog"));

        gridLayout->addWidget(btnInputDialog, 1, 1, 1, 1);

        btnFileDialog = new QPushButton(frmMain);
        btnFileDialog->setObjectName(QStringLiteral("btnFileDialog"));

        gridLayout->addWidget(btnFileDialog, 2, 0, 1, 1);

        spinBox = new QSpinBox(frmMain);
        spinBox->setObjectName(QStringLiteral("spinBox"));

        gridLayout->addWidget(spinBox, 2, 1, 1, 1);

        comboBox = new QComboBox(frmMain);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setEditable(true);

        gridLayout->addWidget(comboBox, 3, 0, 1, 1);

        doubleSpinBox = new QDoubleSpinBox(frmMain);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));

        gridLayout->addWidget(doubleSpinBox, 3, 1, 1, 1);

        comboBox_2 = new QComboBox(frmMain);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        gridLayout->addWidget(comboBox_2, 4, 0, 1, 1);

        dateEdit = new QDateEdit(frmMain);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        gridLayout->addWidget(dateEdit, 4, 1, 1, 1);

        timeEdit = new QTimeEdit(frmMain);
        timeEdit->setObjectName(QStringLiteral("timeEdit"));

        gridLayout->addWidget(timeEdit, 5, 0, 1, 1);

        dateTimeEdit = new QDateTimeEdit(frmMain);
        dateTimeEdit->setObjectName(QStringLiteral("dateTimeEdit"));

        gridLayout->addWidget(dateTimeEdit, 5, 1, 1, 1);

        plainTextEdit = new QPlainTextEdit(frmMain);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        gridLayout->addWidget(plainTextEdit, 6, 0, 1, 2);

        textEdit = new QTextEdit(frmMain);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        gridLayout->addWidget(textEdit, 7, 0, 1, 1);

        textBrowser = new QTextBrowser(frmMain);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        gridLayout->addWidget(textBrowser, 7, 1, 1, 1);

        tableView = new QTableView(frmMain);
        tableView->setObjectName(QStringLiteral("tableView"));

        gridLayout->addWidget(tableView, 8, 0, 1, 1);

        tableWidget = new QTableWidget(frmMain);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (tableWidget->rowCount() < 2)
            tableWidget->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem3);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        gridLayout->addWidget(tableWidget, 8, 1, 1, 1);

        QWidget::setTabOrder(btnFileDialog, lineEdit);
        QWidget::setTabOrder(lineEdit, spinBox);
        QWidget::setTabOrder(spinBox, doubleSpinBox);
        QWidget::setTabOrder(doubleSpinBox, dateEdit);
        QWidget::setTabOrder(dateEdit, dateTimeEdit);
        QWidget::setTabOrder(dateTimeEdit, comboBox);
        QWidget::setTabOrder(comboBox, comboBox_2);
        QWidget::setTabOrder(comboBox_2, timeEdit);
        QWidget::setTabOrder(timeEdit, textEdit);

        retranslateUi(frmMain);

        QMetaObject::connectSlotsByName(frmMain);
    } // setupUi

    void retranslateUi(QWidget *frmMain)
    {
        frmMain->setWindowTitle(QApplication::translate("frmMain", "\350\276\223\345\205\245\346\263\225\346\274\224\347\244\272", Q_NULLPTR));
        txt->setText(QApplication::translate("frmMain", "\347\246\201\347\224\250\350\276\223\345\205\245\346\263\225", Q_NULLPTR));
        btnDialog->setText(QApplication::translate("frmMain", "\345\257\271\350\257\235\346\241\206\347\252\227\344\275\223", Q_NULLPTR));
        btnInputDialog->setText(QApplication::translate("frmMain", "\350\276\223\345\205\245\346\241\206", Q_NULLPTR));
        btnFileDialog->setText(QApplication::translate("frmMain", "\346\211\223\345\274\200\346\226\207\344\273\266\345\257\271\350\257\235\346\241\206", Q_NULLPTR));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("frmMain", "1", Q_NULLPTR)
         << QApplication::translate("frmMain", "2", Q_NULLPTR)
         << QApplication::translate("frmMain", "3", Q_NULLPTR)
        );
        dateEdit->setDisplayFormat(QApplication::translate("frmMain", "yyyy\345\271\264MM\346\234\210dd\346\227\245", Q_NULLPTR));
        timeEdit->setDisplayFormat(QApplication::translate("frmMain", "HH\346\227\266mm\345\210\206ss\347\247\222", Q_NULLPTR));
        dateTimeEdit->setDisplayFormat(QApplication::translate("frmMain", "yyyy\345\271\264MM\346\234\210dd\346\227\245 HH\346\227\266mm\345\210\206ss\347\247\222", Q_NULLPTR));
        plainTextEdit->setPlainText(QApplication::translate("frmMain", "    \346\233\276\347\273\217\346\234\211\346\256\265\346\227\266\351\227\264\357\274\214\346\210\221\346\234\211\344\270\200\344\270\252\345\276\210\346\211\247\347\235\200\347\232\204\346\242\246\346\203\263\357\274\214\346\210\221\350\246\201\345\257\274\346\274\224\345\207\272\344\270\200\351\203\250\347\251\272\345\211\215\347\273\235\345\220\216\347\232\204\345\217\245\345\271\225\343\200\202\344\270\215\350\277\207\347\216\260\345\256\236\346\227\240\346\203\205\345\234\260\347\242\276\347\242\216\346\210\221\347\232\204\346\242\246\346\203\263\357\274\214\344\271\237\345\220\214\346\227\266\345\260\206\346\210\221\346\216\250\350\277\233\344\272\206\344\272\272\347\224\237\347\232\204\344\275\216\350\260\267\343\200\202\n"
"    \346\210\221\345\274\200\345\247\213\346\200\235\350\200\203\357\274\214\346\200\235\346\203\263\345\276\210\345\244\232\345\276\210\345\244\232\346\210\221\344\273\245\345\211\215\346\200\273\346\230\257\345\233\236\351\201\277\347\232\204\351\227\256\351\242\230\357\274\214\345"
                        "\234\250\344\270\200\346\254\241\346\254\241\346\200\235\350\200\203\344\270\255\357\274\214\346\210\221\350\203\275\346\204\237\350\247\211\345\210\260\346\210\221\346\255\243\345\234\250\345\220\221\344\270\200\344\270\252\351\231\214\347\224\237\347\232\204\345\234\260\346\226\271\350\265\260\345\216\273\357\274\214\345\211\215\351\200\224\346\230\257\345\205\211\346\230\257\346\232\227\344\271\237\346\227\240\346\263\225\346\216\250\346\265\213\357\274\214\346\210\221\345\217\221\347\216\260\346\210\221\345\234\250\350\265\214\357\274\214\350\265\214\346\263\250\346\230\257\344\270\200\350\276\210\345\255\220\347\232\204\346\207\212\346\202\224\346\210\226\346\230\257\351\203\201\351\203\201\347\273\210\347\224\237\343\200\202\n"
"    \344\275\206\345\275\223\346\210\221\347\234\213\345\210\260\351\230\263\345\205\211\345\274\245\346\274\253\345\234\250\346\210\221\350\272\253\350\276\271\346\227\266\357\274\214\346\211\215\345\217\221\347\216\260\344\273\245\345\211\215\347\232\204\346\210\221\346\230\257"
                        "\351\202\243\344\271\210\345\271\274\347\250\232\357\274\214\346\210\221\345\247\213\347\273\210\345\234\250\346\211\276\345\200\237\345\217\243\346\210\226\344\270\215\346\230\257\345\200\237\345\217\243\347\232\204\345\200\237\345\217\243\346\216\250\345\215\270\346\216\211\344\270\216\347\224\237\344\277\261\346\235\245\347\232\204\350\264\243\344\273\273\357\274\214\345\234\250\345\205\211\346\200\252\351\231\206\347\246\273\347\232\204\347\216\260\345\256\236\344\270\255\345\215\210\346\211\276\344\270\252\345\203\273\351\235\231\347\232\204\345\234\260\346\226\271\345\270\214\346\234\233\350\277\207\344\272\221\346\267\241\351\243\216\350\275\273\347\232\204\346\227\245\345\255\220\343\200\202\346\210\221\351\224\231\344\272\206\357\274\214\346\210\221\346\213\245\346\234\211\350\266\263\345\244\237\347\232\204\350\203\275\345\212\233\345\215\264\344\270\215\346\225\242\346\201\243\346\204\217\345\246\204\344\270\272\357\274\214\346\210\221\346\213\245\346\234\211\346\203\212\344\272\272\347\232\204\345\244"
                        "\251\350\265\213\345\215\264\347\225\217\346\203\247\350\277\231\345\217\252\346\230\257\345\215\227\346\237\257\344\270\200\346\242\246\357\274\214\346\210\226\350\200\205\350\277\231\346\234\254\346\235\245\345\260\261\346\230\257\346\242\246\357\274\214\351\206\222\346\235\245\346\227\266\345\215\264\346\230\257\344\272\206\346\227\240\347\227\225\350\277\271\345\222\214\346\227\240\344\274\221\346\255\242\347\232\204\347\234\267\346\201\213\343\200\202\n"
"\344\273\216\345\211\215\346\234\211\344\270\252\345\220\214\345\255\246\351\227\256\346\210\221\346\230\257\344\270\215\346\230\257\345\271\273\346\203\263\350\277\207\344\270\200\344\272\233\347\211\271\345\210\253\347\232\204\347\273\217\345\216\206\344\274\232\351\231\215\344\270\264\345\210\260\350\207\252\345\267\261\350\272\253\344\270\212\343\200\202\n"
"    \345\275\223\346\227\266\346\210\221\345\217\252\347\254\221\344\272\206\347\254\221\357\274\214\345\215\264\344\270\215\347\237\245\351\201\223\350\257\245\346\200\216\344\271\210\345\233\236"
                        "\347\255\224\343\200\202\n"
"    \346\210\221\346\203\263\346\210\221\346\230\257\347\237\233\347\233\276\347\232\204\357\274\214\346\210\221\350\256\244\344\270\272\346\210\221\347\232\204\345\255\230\345\234\250\344\270\216\345\220\246\345\205\263\347\263\273\345\210\260\344\270\226\351\227\264\347\232\204\344\270\207\344\272\213\344\270\207\347\211\251\357\274\214\344\275\206\346\210\221\346\211\276\344\270\215\345\210\260\350\266\263\345\244\237\347\232\204\350\257\201\346\215\256\346\235\245\350\257\201\346\230\216\346\210\221\345\205\267\346\234\211\346\225\221\344\270\226\344\270\273\347\232\204\350\272\253\344\273\275\343\200\202\345\233\240\346\255\244\346\210\221\344\270\200\345\272\246\346\200\200\347\226\221\350\277\207\346\210\221\346\230\257\344\270\215\346\230\257\347\224\237\344\270\215\351\200\242\346\227\266\357\274\214\346\210\226\346\230\257\345\244\251\345\246\222\350\213\261\346\211\215\343\200\202\n"
"    \346\210\221\345\234\250\344\270\200\346\254\241\346\254\241\350\275\256\345\233\236"
                        "\344\270\255\347\255\211\345\276\205\347\235\200\344\270\200\344\270\252\346\234\272\344\274\232\357\274\214\344\271\237\350\256\270\346\230\257\344\271\261\344\270\226\357\274\214\344\271\237\350\256\270\346\230\257\345\244\252\345\271\263\357\274\214\346\210\221\346\262\241\346\234\211\346\211\200\350\260\223\347\232\204\344\270\200\346\212\200\344\271\213\351\225\277\357\274\214\345\217\252\346\234\211\351\243\236\346\211\254\350\267\213\346\211\210\347\232\204\351\252\204\345\202\262\345\222\214\346\275\256\346\264\227\346\275\256\345\215\267\347\232\204\350\203\270\346\200\200\343\200\202\345\217\252\346\234\211\344\270\200\347\254\221\347\275\256\344\271\213\347\232\204\345\255\244\345\202\262\345\222\214\347\231\275\344\272\221\350\213\215\347\213\227\347\232\204\346\226\271\345\274\217\343\200\202\n"
"    \346\210\221\346\203\263\346\210\221\344\270\215\350\257\245\345\246\204\350\207\252\350\217\262\350\226\204\357\274\214\347\224\232\350\207\263\350\277\231\346\230\257\347\220\206\346\211\200\345\275"
                        "\223\347\204\266\347\232\204\344\270\215\345\212\240\345\215\212\347\202\271\344\277\256\351\245\260\347\232\204\351\241\272\345\205\266\350\207\252\347\204\266\343\200\202\n"
"    \346\210\221\345\276\210\345\226\234\346\254\242\350\277\231\346\240\267\344\270\200\345\217\245\350\257\235\357\274\232\345\246\202\346\236\234\346\210\221\345\260\206\345\272\270\347\242\214\344\270\200\347\224\237\347\232\204\350\257\235\357\274\214\345\234\260\347\220\203\345\260\206\345\201\234\346\255\242\350\275\254\345\212\250\357\274\214\345\234\260\347\220\203\345\201\234\346\255\242\350\275\254\345\212\250\344\272\206\345\220\227\357\274\237\346\262\241\346\234\211\357\274\214\351\202\243\346\210\221\345\260\206\344\270\215\344\274\232\345\272\270\347\242\214\344\270\200\347\224\237\343\200\202\n"
"\345\234\250\347\211\271\345\256\232\347\232\204\346\227\266\351\227\264\357\274\214\347\211\271\345\256\232\347\232\204\347\216\257\345\242\203\357\274\214\347\211\271\345\256\232\347\232\204\345\234\260\347\202\271\357\274\214"
                        "\346\234\211\344\270\252\347\211\271\345\256\232\347\232\204\344\272\272\345\260\206\344\270\273\345\256\260\344\270\207\344\272\213\344\270\207\347\211\251\357\274\201\n"
"    \345\244\251\347\224\237\346\210\221\346\211\215\345\277\205\346\234\211\347\224\250\357\274\201\n"
"    \347\273\217\345\205\270\347\232\204\345\277\203\347\205\247\344\270\215\345\256\243\357\274\214\345\217\252\345\217\257\346\203\234\344\273\226\347\232\204\345\202\262\346\205\242\345\215\264\346\262\241\346\234\211\350\266\263\345\244\237\347\232\204\350\203\275\345\212\233\345\201\232\345\237\272\345\236\253\343\200\202\n"
"    \346\210\221\346\203\263\346\210\221\346\230\257\345\257\271\347\232\204\357\274\214\346\263\250\345\256\232\347\232\204\344\276\277\346\230\257\346\260\270\350\277\234\346\227\240\346\263\225\346\224\271\345\217\230\347\232\204\357\274\214\350\277\207\345\216\273\347\232\204\345\217\252\346\230\257\345\214\206\345\214\206\344\270\200\347\236\245\357\274\214\345\260\206\346\235\245\347\232\204\345\217\252\346"
                        "\230\257\347\231\275\351\251\271\350\277\207\351\232\231\357\274\214\344\270\200\346\254\241\346\254\241\347\232\204\350\275\256\345\233\236\346\215\242\346\235\245\347\232\204\346\230\257\351\272\273\346\234\250\347\232\204\345\276\252\350\247\204\350\271\210\347\237\251\357\274\214\346\211\200\344\273\245\344\270\226\347\225\214\351\234\200\350\246\201\351\202\243\344\271\210\344\270\200\344\270\252\344\272\272----\346\224\271\345\217\230\343\200\202\n"
"    \350\277\207\345\216\273\344\272\246\347\251\272\351\227\264\347\251\272\345\257\271\346\234\210\357\274\214\350\214\253\350\214\253\351\270\277\350\222\231\346\227\240\345\275\222\345\244\204\343\200\202\n"
"    \346\210\221\345\246\202\350\226\217\350\213\241\357\274\214\344\270\272\345\256\236\343\200\202\n"
"    \344\274\227\345\246\202\344\275\233\347\217\240\357\274\214\344\270\272\347\251\272\343\200\202\n"
"    \346\210\221\344\270\272\346\234\254\357\274\214\344\274\227\344\270\272\346\215\247\343\200\202\n"
"    \345\206\245\345\206\245\344\271"
                        "\213\351\227\264\344\273\245\346\227\240\350\270\252\343\200\202", Q_NULLPTR));
        textEdit->setHtml(QApplication::translate("frmMain", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\256\213\344\275\223'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("frmMain", "\346\226\260\345\273\272\345\210\227", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("frmMain", "\346\226\260\345\273\272\345\210\227", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("frmMain", "\346\226\260\345\273\272\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("frmMain", "\346\226\260\345\273\272\350\241\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class frmMain: public Ui_frmMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMMAIN_H
