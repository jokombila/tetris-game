#include "dialogthemes.h"
#include "ui_dialogthemes.h"

DialogThemes::DialogThemes(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogThemes)
{
    ui->setupUi(this);
}

DialogThemes::~DialogThemes()
{
    delete ui;
}

void DialogThemes::on_pushButton_clicked()
{
    this->hide();
}

