#ifndef LEARN_H
#define LEARN_H

#include <QDialog>

namespace Ui {
class learn;
}

class learn : public QDialog
{
    Q_OBJECT

public:
    explicit learn(QWidget *parent = nullptr);
    ~learn();

private:
    Ui::learn *ui;
};

#endif // LEARN_H