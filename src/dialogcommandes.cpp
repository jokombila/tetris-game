#include "dialogcommandes.h"
#include "ui_dialogcommandes.h"

DialogCommandes::DialogCommandes(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogCommandes)
{
    ui->setupUi(this);
}

DialogCommandes::~DialogCommandes()
{
    delete ui;
}

void DialogCommandes::on_pushButton_clicked()
{
    this->hide();
}

