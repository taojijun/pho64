#ifndef FORM____H
#define FORM____H

#include <QWidget>

namespace Ui {
class Form___;
}

class Form___ : public QWidget
{
    Q_OBJECT

public:
    explicit Form___(QWidget *parent = 0);
    ~Form___();

private:
    Ui::Form___ *ui;
};

#endif // FORM____H
