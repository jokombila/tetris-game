#ifndef DIALOGTHEMES_H
#define DIALOGTHEMES_H

#include <QDialog>

namespace Ui {
class DialogThemes;
}

class DialogThemes : public QDialog
{
    Q_OBJECT

public:
    explicit DialogThemes(QWidget *parent = nullptr);
    ~DialogThemes();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DialogThemes *ui;
};

#endif // DIALOGTHEMES_H
