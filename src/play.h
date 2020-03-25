#ifndef PLAY_H
#define PLAY_H

#include <QDialog>
#include <QPainter>
#include <QWidget>
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
    void paintEvent(QPaintEvent *pe);

    void on_pushButton_6_clicked();

private:
    Ui::play *ui;
};

#endif // PLAY_H
