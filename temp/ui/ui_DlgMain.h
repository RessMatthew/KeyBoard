/********************************************************************************
** Form generated from reading UI file 'DlgMain.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGMAIN_H
#define UI_DLGMAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DlgMain
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *Btn_clear;
    QPushButton *Btn_delete;
    QPushButton *Btn_delete_2;
    QGridLayout *gridLayout;
    QPushButton *Btn_word4;
    QPushButton *Btn_word3;
    QPushButton *Btn_word5;
    QPushButton *Btn_word6;
    QPushButton *Btn_word1;
    QPushButton *Btn_word7;
    QPushButton *Btn_word2;
    QPushButton *Btn_word9;
    QPushButton *Btn_word8;
    QLabel *label;
    QWidget *widget_title;

    void setupUi(QDialog *DlgMain)
    {
        if (DlgMain->objectName().isEmpty())
            DlgMain->setObjectName(QStringLiteral("DlgMain"));
        DlgMain->resize(816, 321);
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/handswriting.png"), QSize(), QIcon::Normal, QIcon::Off);
        DlgMain->setWindowIcon(icon);
        DlgMain->setStyleSheet(QStringLiteral(""));
        layoutWidget = new QWidget(DlgMain);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(9, 11, 304, 404));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        textEdit = new QTextEdit(layoutWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setMaximumSize(QSize(16777215, 40));
        textEdit->setSizeIncrement(QSize(0, 40));
        QFont font;
        font.setPointSize(15);
        textEdit->setFont(font);

        verticalLayout->addWidget(textEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        Btn_clear = new QPushButton(layoutWidget);
        Btn_clear->setObjectName(QStringLiteral("Btn_clear"));
        Btn_clear->setMinimumSize(QSize(0, 60));
        Btn_clear->setMaximumSize(QSize(16777215, 60));
        Btn_clear->setFont(font);

        horizontalLayout->addWidget(Btn_clear);

        Btn_delete = new QPushButton(layoutWidget);
        Btn_delete->setObjectName(QStringLiteral("Btn_delete"));
        Btn_delete->setMinimumSize(QSize(0, 60));
        Btn_delete->setMaximumSize(QSize(16777215, 60));
        Btn_delete->setFont(font);

        horizontalLayout->addWidget(Btn_delete);

        Btn_delete_2 = new QPushButton(layoutWidget);
        Btn_delete_2->setObjectName(QStringLiteral("Btn_delete_2"));
        Btn_delete_2->setMinimumSize(QSize(0, 60));
        Btn_delete_2->setMaximumSize(QSize(16777215, 60));
        Btn_delete_2->setFont(font);

        horizontalLayout->addWidget(Btn_delete_2);


        verticalLayout->addLayout(horizontalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        Btn_word4 = new QPushButton(layoutWidget);
        Btn_word4->setObjectName(QStringLiteral("Btn_word4"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Btn_word4->sizePolicy().hasHeightForWidth());
        Btn_word4->setSizePolicy(sizePolicy);
        Btn_word4->setMinimumSize(QSize(90, 90));
        Btn_word4->setMaximumSize(QSize(90, 90));
        Btn_word4->setFont(font);

        gridLayout->addWidget(Btn_word4, 0, 2, 1, 1);

        Btn_word3 = new QPushButton(layoutWidget);
        Btn_word3->setObjectName(QStringLiteral("Btn_word3"));
        sizePolicy.setHeightForWidth(Btn_word3->sizePolicy().hasHeightForWidth());
        Btn_word3->setSizePolicy(sizePolicy);
        Btn_word3->setMinimumSize(QSize(90, 90));
        Btn_word3->setMaximumSize(QSize(90, 90));
        Btn_word3->setFont(font);

        gridLayout->addWidget(Btn_word3, 1, 0, 1, 1);

        Btn_word5 = new QPushButton(layoutWidget);
        Btn_word5->setObjectName(QStringLiteral("Btn_word5"));
        sizePolicy.setHeightForWidth(Btn_word5->sizePolicy().hasHeightForWidth());
        Btn_word5->setSizePolicy(sizePolicy);
        Btn_word5->setMinimumSize(QSize(90, 90));
        Btn_word5->setMaximumSize(QSize(90, 90));
        Btn_word5->setFont(font);

        gridLayout->addWidget(Btn_word5, 1, 1, 1, 1);

        Btn_word6 = new QPushButton(layoutWidget);
        Btn_word6->setObjectName(QStringLiteral("Btn_word6"));
        sizePolicy.setHeightForWidth(Btn_word6->sizePolicy().hasHeightForWidth());
        Btn_word6->setSizePolicy(sizePolicy);
        Btn_word6->setMinimumSize(QSize(90, 90));
        Btn_word6->setMaximumSize(QSize(90, 90));
        Btn_word6->setFont(font);

        gridLayout->addWidget(Btn_word6, 1, 2, 1, 1);

        Btn_word1 = new QPushButton(layoutWidget);
        Btn_word1->setObjectName(QStringLiteral("Btn_word1"));
        sizePolicy.setHeightForWidth(Btn_word1->sizePolicy().hasHeightForWidth());
        Btn_word1->setSizePolicy(sizePolicy);
        Btn_word1->setMinimumSize(QSize(90, 90));
        Btn_word1->setMaximumSize(QSize(90, 90));
        Btn_word1->setFont(font);

        gridLayout->addWidget(Btn_word1, 0, 0, 1, 1);

        Btn_word7 = new QPushButton(layoutWidget);
        Btn_word7->setObjectName(QStringLiteral("Btn_word7"));
        sizePolicy.setHeightForWidth(Btn_word7->sizePolicy().hasHeightForWidth());
        Btn_word7->setSizePolicy(sizePolicy);
        Btn_word7->setMinimumSize(QSize(90, 90));
        Btn_word7->setMaximumSize(QSize(90, 90));
        Btn_word7->setFont(font);
        Btn_word7->setStyleSheet(QLatin1String("QPushButton:hover{\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #4D4D4D,stop:1 #292929);\n"
"}\n"
"QPushButton{color:#4D4D4D;}"));

        gridLayout->addWidget(Btn_word7, 2, 0, 1, 1);

        Btn_word2 = new QPushButton(layoutWidget);
        Btn_word2->setObjectName(QStringLiteral("Btn_word2"));
        sizePolicy.setHeightForWidth(Btn_word2->sizePolicy().hasHeightForWidth());
        Btn_word2->setSizePolicy(sizePolicy);
        Btn_word2->setMinimumSize(QSize(90, 90));
        Btn_word2->setMaximumSize(QSize(90, 90));
        Btn_word2->setFont(font);

        gridLayout->addWidget(Btn_word2, 0, 1, 1, 1);

        Btn_word9 = new QPushButton(layoutWidget);
        Btn_word9->setObjectName(QStringLiteral("Btn_word9"));
        sizePolicy.setHeightForWidth(Btn_word9->sizePolicy().hasHeightForWidth());
        Btn_word9->setSizePolicy(sizePolicy);
        Btn_word9->setMinimumSize(QSize(90, 90));
        Btn_word9->setMaximumSize(QSize(90, 90));
        Btn_word9->setFont(font);

        gridLayout->addWidget(Btn_word9, 2, 2, 1, 1);

        Btn_word8 = new QPushButton(layoutWidget);
        Btn_word8->setObjectName(QStringLiteral("Btn_word8"));
        sizePolicy.setHeightForWidth(Btn_word8->sizePolicy().hasHeightForWidth());
        Btn_word8->setSizePolicy(sizePolicy);
        Btn_word8->setMinimumSize(QSize(90, 90));
        Btn_word8->setMaximumSize(QSize(90, 90));
        Btn_word8->setFont(font);

        gridLayout->addWidget(Btn_word8, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        label = new QLabel(DlgMain);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(330, 10, 471, 301));
        label->setFrameShape(QFrame::Box);
        widget_title = new QWidget(DlgMain);
        widget_title->setObjectName(QStringLiteral("widget_title"));
        widget_title->setGeometry(QRect(0, 0, 811, 431));
        widget_title->setMaximumSize(QSize(811, 16777215));
        widget_title->setStyleSheet(QLatin1String("\n"
"background-color: rgb(47, 47, 47);"));
        widget_title->raise();
        layoutWidget->raise();
        label->raise();

        retranslateUi(DlgMain);

        QMetaObject::connectSlotsByName(DlgMain);
    } // setupUi

    void retranslateUi(QDialog *DlgMain)
    {
        DlgMain->setWindowTitle(QApplication::translate("DlgMain", "\346\211\213\345\206\231\346\235\277", Q_NULLPTR));
        Btn_clear->setText(QApplication::translate("DlgMain", "\351\207\215\345\206\231", Q_NULLPTR));
        Btn_delete->setText(QApplication::translate("DlgMain", "\345\210\240\351\231\244", Q_NULLPTR));
        Btn_delete_2->setText(QApplication::translate("DlgMain", "\347\241\256\345\256\232", Q_NULLPTR));
        Btn_word4->setText(QString());
        Btn_word3->setText(QString());
        Btn_word5->setText(QString());
        Btn_word6->setText(QString());
        Btn_word1->setText(QString());
        Btn_word7->setText(QString());
        Btn_word2->setText(QString());
        Btn_word9->setText(QString());
        Btn_word8->setText(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DlgMain: public Ui_DlgMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGMAIN_H
