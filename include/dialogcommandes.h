#ifndef DIALOGCOMMANDES_H
#define DIALOGCOMMANDES_H

#include <QDialog>

namespace Ui {
class DialogCommandes;
}

class DialogCommandes : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCommandes(QWidget *parent = nullptr);
    ~DialogCommandes();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DialogCommandes *ui;
};

#endif // DIALOGCOMMANDES_H
