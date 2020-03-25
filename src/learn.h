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

    void on_toolButton_2_clicked();

    void on_sasiul_clicked();

    void on_motorul_clicked();

    void on_caroseria_clicked();

    void on_sas_1_clicked();

    void on_sas_2_clicked();

    void on_sas_3_clicked();

    void on_sas_4_clicked();

    void on_sas_5_clicked();

    void on_mot_1_clicked();

    void on_mot_2_clicked();

    void on_car_1_clicked();

    void on_car_2_clicked();

    void on_car_3_clicked();

    void on_car_4_clicked();

    void on_car_5_clicked();

    void on_car_6_clicked();

    void on_car_7_clicked();

    void paintEvent(QPaintEvent *pe);


    void on_toolButton_3_clicked();

private:
    Ui::learn *ui;
    int counter = 1;
    int a = 0, b=0, c=0;

};

#endif // LEARN_H
