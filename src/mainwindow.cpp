#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Tetromino.h"
#include "I.h"
#include "J.h"
#include "L.h"
#include "O.h"
#include "S.h"
#include "T.h"
#include "Z.h"
#include "puits.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    p = new Puits();
    r = new T();
}
MainWindow::~MainWindow() {
    delete ui;
    delete r;
    delete p;
}

void MainWindow::paintEvent(QPaintEvent* e) {
    QWidget::paintEvent(e);
    QPainter painter(this);
    p->dessiner(&painter);
    r->dessiner(&painter);

}

void MainWindow::keyPressEvent ( QKeyEvent * event ) {
    switch(event->key())
    {
    case Qt::Key_Left : r->deplacerDe(-15,0);
        break;
    case Qt::Key_Right : r->deplacerDe(15,0);
        break;
    case Qt::Key_Up : r->Pivoter();
        break;
    case Qt::Key_Down : r->deplacerDe(0,15);
        break;
    }
    this->repaint();
}
