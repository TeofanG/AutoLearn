#ifndef QUIZ_H
#define QUIZ_H

#include <QDialog>
#include <QFileInfo>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QTimer>
#include <QScopedPointerDeleter>
#include <QPainter>
#include <QTime>
#include <QLabel>
#include <QPixmap>
#include <QBitmap>


namespace Ui {
class quiz;
}

class quiz : public QDialog
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
    explicit quiz(QWidget *parent = nullptr);
    void set_question();
    void set_nota();
    QString q1,q2,q3,q4,q5,q6,q7,q8,q9,q10;
    int i=2, greseli = 0;
    ~quiz();




private slots:
    void on_next_clicked();

    void on_var_1_clicked();

    void set_var();

    void on_var_2_clicked();

    void on_var_3_clicked();

     void paintEvent(QPaintEvent *pe);


     void on_close_clicked();

private:
    Ui::quiz *ui;
    int nota=0;
    void delay();
    void reset();
};

#endif // QUIZ_H
