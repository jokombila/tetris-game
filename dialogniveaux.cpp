#include "dialogniveaux.h"
#include "ui_dialogniveaux.h"

DialogNiveaux::DialogNiveaux(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogNiveaux)
{
    ui->setupUi(this);
}

DialogNiveaux::~DialogNiveaux()
{
    delete ui;
}

void DialogNiveaux::on_pushButton_clicked()
{
    this->hide();
}

