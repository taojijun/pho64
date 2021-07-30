#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setWindowTitle(tr("参数配置"));
    ui->pushButton->setStyleSheet("QPushButton{border-image:url(:/image/1010.png);border:8px;color:red;}"
                                     "QPushButton:hover{border-image:url(:/image/11.png);border:8px}"
                                     "QPushButton:pressed{border-image:url(:/image/11.png);border:8px;color:white;}");
//    QString S = ui->lineEdit->text();
//    double level = S.toDouble();
//    S = ui->lineEdit_2->text();
//    double pitch = S.toDouble();
//    S = ui->lineEdit_3->text();
//    double dis = S.toDouble();
//    S = ui->lineEdit_4->text();
//    double time = S.toDouble();
//    S = ui->lineEdit_5->text();
//    double min_spend = S.toDouble();
//    S = ui->lineEdit_6->text();
//    double max_spend = S.toDouble();
//    S = ui->lineEdit_7->text();
//    double s_min = S.toDouble();
//    S = ui->lineEdit_9->text();
//    double s_max = S.toDouble();
//    S = ui->lineEdit_11->text();
//    double h_min = S.toDouble();
//    S = ui->lineEdit_10->text();
//    double h_max = S.toDouble();
//    S = ui->lineEdit_15->text();
//    double v_min = S.toDouble();
//    S = ui->lineEdit_16->text();
//    double v_max = S.toDouble();
//    S = ui->lineEdit_12->text();
//    double speed = S.toDouble();
//    S = ui->lineEdit_13->text();
//    double jg = S.toDouble();
//    S = ui->lineEdit_14->text();
//    double height  = S.toDouble();
//    bool mr = ui->checkBox->isChecked();
//    S = ui->comboBox_3->currentText();
//    QString model = S;
//    S = ui->comboBox->currentText();
//    emit A(level,pitch,dis,time,min_spend,max_spend,s_min,s_max,h_min,h_max,S,v_min,v_max,speed,jg,height,mr,model);



}

Dialog::~Dialog()
{
    delete ui;
}



void Dialog::on_pushButton_clicked()
{
    QString S = ui->lineEdit->text();
    double level = S.toDouble();
    S = ui->lineEdit_2->text();
    double pitch = S.toDouble();
    S = ui->lineEdit_3->text();
    double dis = S.toDouble();
    S = ui->lineEdit_4->text();
    double time = S.toDouble();
    S = ui->lineEdit_5->text();
    double min_spend = S.toDouble();
    S = ui->lineEdit_6->text();
    double max_spend = S.toDouble();
    S = ui->lineEdit_7->text();
    double s_min = S.toDouble();
    S = ui->lineEdit_9->text();
    double s_max = S.toDouble();
    S = ui->lineEdit_11->text();
    double h_min = S.toDouble();
    S = ui->lineEdit_10->text();
    double h_max = S.toDouble();
    S = ui->lineEdit_15->text();
    double v_min = S.toDouble();
    S = ui->lineEdit_16->text();
    double v_max = S.toDouble();
    S = ui->lineEdit_12->text();
    double speed = S.toDouble();
    S = ui->lineEdit_13->text();
    double jg = S.toDouble();
    S = ui->lineEdit_14->text();
    double height  = S.toDouble();
    bool mr = ui->checkBox->isChecked();
    S = ui->comboBox_3->currentText();
    QString model = S;
    S = ui->comboBox->currentText();
    emit A(level,pitch,dis,time,min_spend,max_spend,s_min,s_max,h_min,h_max,S,v_min,v_max,speed,jg,height,mr,model);
    Dialog::hide();

}

void Dialog::on_pushButton_pressed()
{

}
