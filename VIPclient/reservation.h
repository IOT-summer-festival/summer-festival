#ifndef RESERVATION_H
#define RESERVATION_H

#include <QDialog>

namespace Ui {
class reservation;
}

class reservation : public QDialog
{
    Q_OBJECT

public:
    explicit reservation(QWidget *parent = nullptr);
    ~reservation();

private slots:
    void on_pushButton_clicked();

    void on_guide_stateChanged(int arg1);

    void on_sleep_stateChanged(int arg1);

private:
    int guide_pressed=0;
    int sleep_pressed=0;
    Ui::reservation *ui;
};

#endif // RESERVATION_H
