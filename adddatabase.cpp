#include "adddatabase.h"
#include "ui_adddatabase.h"

addDataBase::addDataBase(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addDataBase)
{
    QSqlDatabase DbConn;
    DbConn = QSqlDatabase::addDatabase("QSQLITE", "py");//addDatabase("驱动"，"数据库名")
    DbConn.setDatabaseName(qApp->applicationDirPath() + "/py.db");
    DbConn.open();
    QSqlQuery query(QSqlDatabase::database("py"));
    ui->setupUi(this);
}

addDataBase::~addDataBase()
{
    delete ui;
}

//增加关键词到数据库
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
    query.exec(QString(R"(INSERT INTO pinyin(pinyin,word) VALUES('%1','%2');)").arg(Pinyin).arg(Word));


    this->close();
}


//删除关键词从数据库
void addDataBase::on_pushButton_2_clicked()
{
    //连接数据库
    QSqlDatabase DbConn;
    DbConn = QSqlDatabase::addDatabase("QSQLITE", "py");//addDatabase("驱动"，"数据库名")
    DbConn.setDatabaseName(qApp->applicationDirPath() + "/py.db");
    DbConn.open();
    QSqlQuery query(QSqlDatabase::database("py"));


    QString Pinyin = ui->textPinyin->toPlainText();
    query.exec(QString(R"(DELETE FROM pinyin WHERE pinyin='%1';)").arg(Pinyin));
    this->close();
}

void addDataBase::on_pushButton_3_clicked()
{
    this->close();
}
