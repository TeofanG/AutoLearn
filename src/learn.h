#ifndef LEARN_H
#define LEARN_H

#include <QDialog>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDir>
#include <QPainter>
#include <QWidget>

namespace Ui {
class learn;
}

class learn : public QDialog
{
    Q_OBJECT

public:
    explicit learn(QWidget *parent = nullptr);
    ~learn();

private slots:
    void on_toolButton_clicked();
    void paintEvent(QPaintEvent *pe);
    void on_toolButton_2_clicked();

private:
    Ui::learn *ui;
    int counter = 1;

};

#endif // LEARN_H
