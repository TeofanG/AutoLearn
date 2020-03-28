#ifndef GUESS_H
#define GUESS_H

#include <QDialog>
#include <QPainter>
#include <QSql>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QDebug>
#include <QTime>
#include <QPixmap>

namespace Ui {
class guess;
}

class guess : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase mydb;
    void connClose(){
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpen() {
    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("quiz.db");

    if(!mydb.open())  {
           qDebug() << "Failed to connect";
           return false;
    }
    else  {
           qDebug() << "Connected";
           return true;
    }
   }

public:
    explicit guess(QWidget *parent = nullptr);
    ~guess();
    void count_rows();
    void select();
    void set_var_img(QString id);
    void delay();
    void reset();
    void set_nota();
    void init();
    void select_id_curent();
    void select_correct_var();

private slots:
    void paintEvent(QPaintEvent *pe);

    void on_inchide_clicked();

    void on_v1_clicked();

    void on_v2_clicked();

    void on_v3_clicked();

    void on_v4_clicked();

    void on_next_clicked();

private:
    Ui::guess *ui;
};

#endif // GUESS_H
