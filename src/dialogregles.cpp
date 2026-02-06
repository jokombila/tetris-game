#include "dialogregles.h"
#include "ui_dialogregles.h"

DialogRegles::DialogRegles(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogRegles)
{
    ui->setupUi(this);
}

DialogRegles::~DialogRegles()
{
    delete ui;
}

void DialogRegles::on_pushButton_clicked()
{
    this->hide();
}

