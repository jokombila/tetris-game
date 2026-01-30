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
#include <QTimer>
#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    p = new Partie();

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    nbIntTimer = 0;
}
MainWindow::~MainWindow() {
    delete ui;
    delete p;
    delete timer;
}

void MainWindow::paintEvent(QPaintEvent* e) {
    QWidget::paintEvent(e);
    QPainter painter(this);
    p->dessiner(&painter);
    if (p->getFin())
    {
        painter.setPen( QPen(Qt::red, 1) );
        painter.setFont(QFont("Arial",50));
        painter.drawText(50,250,QString("Game Over !"));
    }
    painter.drawText(50,250,QString(QString::number(nbIntTimer)));
}

void MainWindow::on_bStart_clicked() {
    timer->start(1000);
}
void MainWindow::on_bStop_clicked() {
    timer->stop();
}

void MainWindow::update() {
    nbIntTimer++;
    this->repaint();
}

void MainWindow::keyPressEvent ( QKeyEvent * event ) {
    if (!p->getFin())
    {
        switch(event->key())
        {
            case Qt::Key_Left : p->Deplacement(-15,0);
                                // appeler deplacer de partie et dans cette fonction il faudra
                                // tester si collision
                                // si collision alos redeplacer le tetromino dans l'autre sens et pas de repaint
                break;
            case Qt::Key_Right : p->Deplacement(15,0);
                break;
            case Qt::Key_Up : p->Rotation();
                break;
            case Qt::Key_Down :
                {
                    p->Deplacement(0,15);
                }
                break;
            case Qt::Key_Space :
            {

                bool res=p->Deplacement(0,15);
                if(res==true)
                {
                    cout << "ici";

                    int ligne= p->fixerPuit();
                    p->SuppLigne(ligne);
                    p->SuppTetroCourant();
                    p->CreerTetroCourant();
                }
            } break;
        }

        this->repaint();
    }
}


