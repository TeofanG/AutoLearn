#ifndef QUIZ_H
#define QUIZ_H

#include <QDialog>
#include <QFileInfo>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

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
    int counter = 1;
    ~quiz();

private:
    Ui::quiz *ui;
};

#endif // QUIZ_H
