#ifndef PLAY_H
#define PLAY_H

#include <QDialog>
#include "quiz.h"

namespace Ui {
class play;
}

class play : public QDialog
{
    Q_OBJECT

public:
    explicit play(QWidget *parent = nullptr);
    ~play();

private slots:
    void on_pushButton_5_clicked();

private:
    Ui::play *ui;
};

#endif // PLAY_H
