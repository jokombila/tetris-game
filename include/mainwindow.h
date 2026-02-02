#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "partie.h"
#include <QKeyEvent>
#include <QTimer>
#include <iostream>
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
    void paintEvent(QPaintEvent* e);
    void keyPressEvent ( QKeyEvent * event );
    QTimer *timer;
    int nbIntTimer;


private slots:
    void update();
    void on_BoutonDemarrer_clicked();
    void on_BoutonRestart_clicked();
    void on_BoutonPause_clicked();
};
#endif // MAINWINDOW_H
