#include "choosestyle.h"
#include "ui_choosestyle.h"

chooseStyle::chooseStyle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chooseStyle)
{
    ui->setupUi(this);
}

chooseStyle::~chooseStyle()
{
    delete ui;
}
