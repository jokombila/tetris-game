#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "Tetromino.h"
#include "puits.h"
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
    Tetromino *r;
    Puits *p;
    void paintEvent(QPaintEvent* e);
    void keyPressEvent ( QKeyEvent * event );
};
#endif // MAINWINDOW_H
