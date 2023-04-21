#include "dialogui.h"
#include "ui_dialogui.h"

DialogUI::DialogUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogUI)
{
    ui->setupUi(this);

    // calls to adjust the values of spin box
    ui->value_spinBox->setMinimum(0);
    ui->value_spinBox->setMaximum(10);
    //    ui->value_spinBox->setValue(0);
}

DialogUI::~DialogUI()
{
    delete ui;
}

// get num points value from submitted spin box value
int DialogUI::get_number_points(){
    return number_points_;
}

void DialogUI::on_butt_submit_clicked()
{
    number_points_ = ui->value_spinBox->value();
}

