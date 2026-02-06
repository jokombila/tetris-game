#ifndef DIALOGREGLES_H
#define DIALOGREGLES_H

#include <QDialog>

namespace Ui {
class DialogRegles;
}

class DialogRegles : public QDialog
{
    Q_OBJECT

public:
    explicit DialogRegles(QWidget *parent = nullptr);
    ~DialogRegles();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DialogRegles *ui;
};

#endif // DIALOGREGLES_H
