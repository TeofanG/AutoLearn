#ifndef GUESS_H
#define GUESS_H

#include <QDialog>

namespace Ui {
class guess;
}

class guess : public QDialog
{
    Q_OBJECT

public:
    explicit guess(QWidget *parent = nullptr);
    ~guess();

private:
    Ui::guess *ui;
};

#endif // GUESS_H
