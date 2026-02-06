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


void MainWindow::drawGlowRect(QPainter* painter, QRectF rect, QColor fillColor, QColor glowColor)
{
    // Glow blanc plus visible
    int widths[] = {12, 8, 3};  // Plus large
    int alphas[] = {60, 120, 255};  // Plus opaque
    for(int i = 0; i < 3; i++) {
        glowColor.setAlpha(alphas[i]);
        painter->setPen(QPen(glowColor, widths[i]));
        painter->setBrush(Qt::NoBrush);
        painter->drawRoundedRect(rect, 10, 10);
    }

    painter->setPen(Qt::NoPen);
    painter->setBrush(fillColor);
    painter->drawRoundedRect(rect, 10, 10);
}

void MainWindow::paintEvent(QPaintEvent* e) {
    QWidget::paintEvent(e);
    QPainter painter(this);
    painter.drawPixmap(0,25,700,600,QPixmap(":/images/fond_tetris.png"));

    // carre fond bleu avec neon autour
    painter.setRenderHint(QPainter::Antialiasing, true);
    QRectF rect(42, 80, 451, 460);
    int radius = 20;

    // Fond
    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor(25, 40, 55));
    painter.drawRoundedRect(rect, radius, radius);

    // Glow lumineux en 3 passes
    QColor glow(0, 200, 255);
    int widths[] = {10, 6, 2};
    int alphas[] = {40, 80, 255};
    for(int i = 0; i < 3; i++) {
        glow.setAlpha(alphas[i]);
        painter.setPen(QPen(glow, widths[i]));
        painter.setBrush(Qt::NoBrush);
        painter.drawRoundedRect(rect, radius, radius);
    }

    // Glow BLANC par-dessus le glow bleu (effet mixte)
    QColor glowBlanc(255, 255, 255);
    int widthsBlanc[] = {8, 5, 2};
    int alphasBlanc[] = {30, 60, 150};
    for(int i = 0; i < 3; i++) {
        glowBlanc.setAlpha(alphasBlanc[i]);
        painter.setPen(QPen(glowBlanc, widthsBlanc[i]));
        painter.setBrush(Qt::NoBrush);
        painter.drawRoundedRect(rect, radius, radius);
    }

    // Image TETRIS en haut du carré
    QPixmap tetrisLogo(":/images/tetris_logo.png");
    int logoWidth = rect.width();
    int logoHeight = 80;
    QPixmap scaledLogo = tetrisLogo.scaled(logoWidth, logoHeight, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    int logoX = rect.x();
    int logoY = 23;
    painter.drawPixmap(logoX, logoY, scaledLogo);

    // Rectangle NEXT avec glow blanc
    drawGlowRect(&painter, QRectF(320, 110, 100, 100), Qt::white, QColor(255, 255, 255));

    // Texte NEXT centré
    painter.setPen(QPen(Qt::red, 1));
    painter.setFont(QFont("Press Start 2P",14,QFont::Bold));
    QRectF rectNextLabel(320, 109, 100, 20);
    painter.drawText(rectNextLabel, Qt::AlignCenter, QString("NEXT"));

    // Les 3 carres avec glow
    drawGlowRect(&painter, QRectF(320, 259, 100, 50), QColor(255, 255, 255), QColor(255, 255, 255));  // Font blanc et Glow blanc
    drawGlowRect(&painter, QRectF(320, 324, 100, 50), QColor(255, 255, 255), QColor(255, 255, 255));  // Font blanc et Glow blanc
    drawGlowRect(&painter, QRectF(320, 389, 100, 50), QColor(255, 255, 255), QColor(255, 255, 255)); // Font blanc et Glow blancs

    // Labels centrés (SCORE, LEVEL, TIMER)
    painter.setPen(QPen(Qt::red, 1));
    painter.setFont(QFont("Press Start 2P",14,QFont::Bold));
    painter.drawText(QRectF(320, 259, 100, 20), Qt::AlignCenter, QString("SCORE"));
    painter.drawText(QRectF(320, 324, 100, 20), Qt::AlignCenter, QString("LEVEL"));
    painter.drawText(QRectF(320, 389, 100, 20), Qt::AlignCenter, QString("TIMER"));

    p->dessiner(&painter);

    if (p->getFin())
    {
        painter.setPen( QPen(Qt::red, 1) );
        painter.setFont(QFont("Arial",50));
        painter.drawText(50,250,QString("Game Over !"));
        timer->stop();
        p->setEtatTime(0);
    }

    // Chiffres centrés en dessous des labels
    painter.setPen(QColor(25, 40, 55));
    painter.setFont(QFont("Courier New",20,QFont::Bold));

    QRectF rectScoreValue(320, 279, 100, 30);
    painter.drawText(rectScoreValue, Qt::AlignCenter, QString::number(p->getscore()));

    QRectF rectLevelValue(320, 344, 100, 30);
    painter.drawText(rectLevelValue, Qt::AlignCenter, QString::number(p->getlevel()));

    QRectF rectTimerValue(320, 409, 100, 30);
    painter.drawText(rectTimerValue, Qt::AlignCenter, QString::number(nbIntTimer));
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

