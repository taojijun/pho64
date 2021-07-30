#include "form___.h"
#include "ui_form___.h"

Form___::Form___(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form___)
{
    ui->setupUi(this);
}

Form___::~Form___()
{
    delete ui;
}
