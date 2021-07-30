#ifndef DIALOG_H
#define DIALOG_H
#pragma execution_character_set("utf-8")

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();



private:
    Ui::Dialog *ui;

signals:
    void A(double level,double pitch,double dis,double time,double min_spend,double max_spend,double s_min,double s_max,double h_min,double h_max,QString K,double v_min,double v_max,double speed,double jg,double height,bool mr,QString model);
private slots:
    void on_pushButton_clicked();
    void on_pushButton_pressed();
};

#endif // DIALOG_H
