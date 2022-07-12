#include "adddatabase.h"
#include "ui_adddatabase.h"

addDataBase::addDataBase(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addDataBase)
{
    ui->setupUi(this);
}

addDataBase::~addDataBase()
{
    delete ui;
}

void addDataBase::on_pushButton_clicked()
{
    //连接数据库
    QSqlDatabase DbConn;
    DbConn = QSqlDatabase::addDatabase("QSQLITE", "py");//addDatabase("驱动"，"数据库名")
    DbConn.setDatabaseName(qApp->applicationDirPath() + "/py.db");
    DbConn.open();
    QSqlQuery query(QSqlDatabase::database("py"));


    QString Pinyin = ui->textPinyin->toPlainText();
    QString Word = ui->textWord->toPlainText();
//    query.exec(QString(R"(INSERT INTO my_table(name,age) VALUES('%1',%2);)").arg(name).arg(age));

//    QString sql = QString("select word from pinyin where pinyin='%1'").arg(currentPY);
    query.exec(QString(R"(INSERT INTO pinyin(pinyin,word) VALUES('%1','%2');)").arg(Pinyin).arg(Word));
//    query.exec(sql);

    this->close();
}
