#include "inputform.h"
#include "ui_inputform.h"

inputForm::inputForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::inputForm)
{
    ui->setupUi(this);
}

inputForm::~inputForm()
{
    delete ui;
}
