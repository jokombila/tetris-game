#ifndef DIALOGNIVEAUX_H
#define DIALOGNIVEAUX_H

#include <QDialog>

namespace Ui {
class DialogNiveaux;
}

class DialogNiveaux : public QDialog
{
    Q_OBJECT

public:
    explicit DialogNiveaux(QWidget *parent = nullptr);
    ~DialogNiveaux();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DialogNiveaux *ui;
};

#endif // DIALOGNIVEAUX_H
