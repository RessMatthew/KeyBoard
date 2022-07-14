#include "inputform.h"
#include "ui_inputform.h"

inputForm::inputForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::inputForm)
{
    ui->setupUi(this);
    ui->textEdit->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    ui->textEdit_2->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    ui->textEdit->setFontPointSize(16);
    ui->textEdit_2->setFontPointSize(16);
    //ui->setWindowIcon(QIcon(":/image/login.png"));
}

inputForm::~inputForm()
{
    delete ui;
}
