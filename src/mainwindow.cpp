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
    p = new Partie();
}
MainWindow::~MainWindow() {
    delete ui;
    delete p;
}

void MainWindow::paintEvent(QPaintEvent* e) {
    QWidget::paintEvent(e);
    QPainter painter(this);
    p->dessiner(&painter);
}

void MainWindow::keyPressEvent ( QKeyEvent * event ) {
    switch(event->key())
    {
    case Qt::Key_Left : p->Deplacement(-15,0);
                        // appeler deplacer de partie et dans cette fonction il faudra
                        // tester si collision
                        // si collision alos redeplacer le tetromino dans l'autre sens et pas de repaint
        break;
    case Qt::Key_Right : p->Deplacement(15,0);
        break;
    case Qt::Key_Up : //r->Pivoter();
        break;
    case Qt::Key_Down : p->Deplacement(0,15);
        break;
    }
    this->repaint();
}
