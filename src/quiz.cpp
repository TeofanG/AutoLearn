#include "quiz.h"
#include "ui_quiz.h"

quiz::quiz(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::quiz)
{
    setWindowFlags(Qt::Window);
    ui->setupUi(this);
    connOpen();
    set_question();
}

void quiz::set_question() {
     QSqlQuery* qry = new QSqlQuery;
     QString id = QString::number(counter);
     qry->prepare("SELECT Question from questions where var_1='"+id+"'");
     qry->exec();
     qry->first();
     if (qry->first())   qDebug() << "dfd";
            else qDebug() << "nooo";
     QString text = qry->value(0).toString();
     ui->question->setText(text);
}

quiz::~quiz()
{
    delete ui;
}
