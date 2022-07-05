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

private:
    Ui::reservation *ui;
};

#endif // RESERVATION_H
