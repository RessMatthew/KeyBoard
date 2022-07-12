#ifndef INPUTFORM_H
#define INPUTFORM_H

#include <QWidget>

namespace Ui {
class inputForm;
}

class inputForm : public QWidget
{
    Q_OBJECT

public:
    explicit inputForm(QWidget *parent = 0);
    ~inputForm();

private:
    Ui::inputForm *ui;
};

#endif // INPUTFORM_H
