#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    p = new Partie();
    p->setscore(0);
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
        timer->stop();
        p->setEtatTime(0);
    }
    painter.drawText(50,250,QString(QString::number(nbIntTimer)));
    painter.drawText(5,20,QString(QString::number(p->getscore())));
    painter.drawText(100,20,QString(QString::number(p->getlevel())));
}


void MainWindow::update() {
    if (p->getlevel()==2)
    {
        timer->start(300);
    }
    else if (p->getlevel()==3)
    {
        timer->start(100);
    }
    else
    {
        timer->start(1000);
    }
    nbIntTimer++;
    bool res=p->Deplacement(0,15);
    if(res==true)
    {
        int ligne= p->fixerPuit();
        p->SuppLigne(ligne);
        p->SuppTetroCourant();
        p->CreerTetroCourant();
    }
    this->repaint();
}

void MainWindow::keyPressEvent ( QKeyEvent * event ) {
    if ((!p->getFin()) && (p->getEtatTime()==1) )
    {
        switch(event->key())
        {
            case Qt::Key_Left :p->Deplacement(-15,0);
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

            } break;
        }

        this->repaint();
    }
}


void MainWindow::on_BoutonDemarrer_clicked()
{
    timer->start(1000);
    p->setEtatTime(1);
    p->setlevel(1);
    //timer->stop();
}

void MainWindow::on_BoutonRestart_clicked()
{
    timer->start(1000);
    nbIntTimer=0;
    delete p;
    p = new Partie();
    p->setEtatTime(1);
    p->setlevel(1);
}


void MainWindow::on_BoutonPause_clicked()
{
    if (p->getEtatTime()==1)
    {
        timer->stop();
        p->setEtatTime(0);
    }
    else
    {
        if (p->getlevel()==2)
        {
            timer->start(500);
        }
        else if (p->getlevel()==3)
        {
            timer->start(100);
        }
        else
        {
            timer->start(1000);
        }
        p->setEtatTime(1);
    }
}

