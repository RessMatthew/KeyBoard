#ifndef ADDDATABASE_H
#define ADDDATABASE_H

#include <QWidget>
#include <QtSql>

namespace Ui {
class addDataBase;
}

class addDataBase : public QWidget
{
    Q_OBJECT

public:
    explicit addDataBase(QWidget *parent = 0);
    ~addDataBase();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::addDataBase *ui;
};

#endif // ADDDATABASE_H
