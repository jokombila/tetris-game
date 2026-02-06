#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QPainterPath>
#include "partie.h"
#include <QKeyEvent>
#include <QTimer>
#include <iostream>
#include "dialogregles.h"
#include "dialogcommandes.h"
#include "dialogniveaux.h"
#include "dialogthemes.h"
using namespace std;

namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Partie *p;
    void drawGlowRect(QPainter* painter, QRectF rect, QColor fillColor, QColor glowColor);
    void paintEvent(QPaintEvent* e);
    void keyPressEvent ( QKeyEvent * event );
    QTimer *timer;
    int nbIntTimer;
    DialogRegles *fenetreRegles;
    DialogCommandes *fenetreCommandes;
    DialogNiveaux *fenetreNiveaux;
    DialogThemes *fenetreThemes;


private slots:
    void update();
    void on_BoutonDemarrer_clicked();
    void on_BoutonRestart_clicked();
    void on_BoutonPause_clicked();
    void on_Regles_Triggered();
    void on_Commandes_Triggered();
    void on_ongletNiveaux_triggered();
    void on_ongletThemes_triggered();
};
#endif // MAINWINDOW_H
