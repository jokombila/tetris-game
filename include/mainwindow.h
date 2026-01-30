#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "partie.h"
#include <QKeyEvent>

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
    void on_bStart_clicked();
    void on_bStop_clicked();
    void update();
};
#endif // MAINWINDOW_H
