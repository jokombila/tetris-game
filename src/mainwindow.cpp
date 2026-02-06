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
    connect(ui->ongletRegles, SIGNAL(triggered()),this, SLOT(on_Regles_Triggered()));
    connect(ui->ongletCommandes, SIGNAL(triggered()),this, SLOT(on_Commandes_Triggered()));
    connect(ui->ongletNiveaux, SIGNAL(triggered()),this, SLOT(on_ongletNiveaux_triggered()));
    connect(ui->ongletThemes, SIGNAL(triggered()),this, SLOT(on_ongletThemes_triggered()));
    nbIntTimer = 0;
    fenetreRegles = new DialogRegles (this);
    fenetreCommandes = new DialogCommandes(this);
    fenetreNiveaux = new DialogNiveaux(this);
    fenetreThemes = new DialogThemes(this);
}
MainWindow::~MainWindow() {
    delete ui;
    delete p;
    delete timer;
    delete fenetreRegles;
    delete fenetreCommandes;
    delete fenetreNiveaux;
    delete fenetreThemes;
}

void MainWindow::paintEvent(QPaintEvent* e) {
    QWidget::paintEvent(e);
    QPainter painter(this);
    painter.drawPixmap(0,25,700,600,QPixmap(":/images/fond_tetris.png"));
    painter.fillRect(42,80,451,460, QBrush(Qt::black));
    painter.fillRect(320,110,100,100, QBrush(Qt::white));
    painter.setPen( QPen(Qt::red, 1) );
    painter.setFont(QFont("BankGothic Lt BT",14,QFont::Bold));
    painter.drawText(345,125,QString("NEXT"));
    painter.fillRect(320,259,100,50, QBrush(Qt::white));
    painter.fillRect(320,324,100,50, QBrush(Qt::white));
    painter.fillRect(320,389,100,50, QBrush(Qt::white));
    p->dessiner(&painter);
    if (p->getFin())
    {
        painter.setPen( QPen(Qt::red, 1) );
        painter.setFont(QFont("Arial",50));
        painter.drawText(50,250,QString("Game Over !"));
        timer->stop();
        p->setEtatTime(0);
    }
    painter.drawText(360,430,QString(QString::number(nbIntTimer)));
    painter.drawText(360,300,QString(QString::number(p->getscore())));
    painter.drawText(360,365,QString(QString::number(p->getlevel())));
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


void MainWindow::on_Regles_Triggered()
{
    fenetreRegles->show();
}

void MainWindow::on_Commandes_Triggered()
{
    fenetreCommandes->show();
}

void MainWindow::on_ongletNiveaux_triggered()
{
    fenetreNiveaux->show();
}


void MainWindow::on_ongletThemes_triggered()
{
    fenetreThemes->show();
}

