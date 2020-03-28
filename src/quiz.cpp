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
    set_var();
}

void quiz::paintEvent(QPaintEvent *pe)
{
    QPixmap pixmap("../assets/design/learn_bg.png");
    QPainter paint(this);
    int widWidth = this->width();
    int widHeight = this->height();
    pixmap = pixmap.scaled(widWidth, widHeight, Qt::KeepAspectRatioByExpanding);
    paint.drawPixmap(0, 0, pixmap);
    QWidget::paintEvent(pe);
}


void quiz::set_question() {
     QSqlQuery* qry = new QSqlQuery;
     qry->prepare("SELECT Question from questions order by random() limit 10");
     qry->exec();
     qry->first();
     q1 = qry->value(0).toString();
     ui->question->setText(q1);
     qry->next();
     q2 = qry->value(0).toString();
     qry->next();
     q3 = qry->value(0).toString();
     qry->next();
     q4 = qry->value(0).toString();
     qry->next();
     q5 = qry->value(0).toString();
     qry->next();
     q6 = qry->value(0).toString();
     qry->next();
     q7 = qry->value(0).toString();
     qry->next();
     q8 = qry->value(0).toString();
     qry->next();
     q9 = qry->value(0).toString();
     qry->next();
     q10 = qry->value(0).toString();
}



void quiz::on_next_clicked()
{
    greseli = 0;
    QString iToString = QString::number(i);
    ui->nr->setText(iToString);
    switch (i) {
        case 2:
                ui->question->setText(q2);
                break;
        case 3:
                ui->question->setText(q3);
                break;
        case 4:
                ui->question->setText(q4);
                break;
        case 5:
                ui->question->setText(q5);
                break;
        case 6:
                ui->question->setText(q6);
                break;
        case 7:
                ui->question->setText(q7);
                break;
        case 8:
                ui->question->setText(q8);
                break;
        case 9:
                ui->question->setText(q9);
                break;
        case 10:
               ui->question->setText(q10);
               break;

    }
    i++;
    set_var();
    QString n = QString::number(nota);
    if(i==12) {
        set_nota();
        reset();
        ui->nr->hide();
    }
}

void quiz::set_var()
{
    QString text_question = ui->question->text();

    // select varianta 1

    QSqlQuery* qry1 = new QSqlQuery;
    qry1->prepare("SELECT var_1 from questions where Question='"+text_question+"'");
    qry1->exec();
    qry1->first();

    QString text_var1 = qry1->value(0).toString();
    ui->var_1->setText(text_var1);
    ui->var_1->setStyleSheet("background-color: #1b10dd;");

    //select varianta 2

    QSqlQuery* qry2 = new QSqlQuery;
    qry2->prepare("SELECT var_2 from questions where Question='"+text_question+"'");
    qry2->exec();
    qry2->first();

    QString text_var2 = qry2->value(0).toString();
    ui->var_2->setText(text_var2);
    ui->var_2->setStyleSheet("background-color: #1b10dd;");
    //select varianta 3

    QSqlQuery* qry3 = new QSqlQuery;
    qry3->prepare("SELECT var_3 from questions where Question='"+text_question+"'");
    qry3->exec();
    qry3->first();

    QString text_var3 = qry3->value(0).toString();
    ui->var_3->setText(text_var3);
    ui->var_3->setStyleSheet("background-color: #1b10dd;");
}

void quiz::on_var_1_clicked()
{
    QSqlQuery* qry = new QSqlQuery;
    qry->prepare("SELECT correct_answer from questions where var_1='"+ui->var_1->text()+"'");
    qry->exec();
    qry->first();
    QString correct_var = qry->value(0).toString();

    if(ui->var_1->text()==correct_var) {
        if(greseli==0) nota+=10;
            else if (greseli==1) nota+=7;
                else nota+=5;
        ui->var_1->setStyleSheet("background-color:green");
        delay();
        on_next_clicked();
    }
            else {
                  ui->var_1->setStyleSheet("background-color:red");
                  greseli++;
    }
}

void quiz::on_var_2_clicked()
{
    QSqlQuery* qry = new QSqlQuery;
    qry->prepare("SELECT correct_answer from questions where var_2='"+ui->var_2->text()+"'");
    qry->exec();
    qry->first();
    QString correct_var = qry->value(0).toString();

    if(ui->var_2->text()==correct_var) {
        if(greseli==0) nota+=10;
            else if (greseli==1) nota+=7;
                else nota+=5;
        ui->var_2->setStyleSheet("background-color:green");
        delay();
        on_next_clicked();
    }
            else {
                  ui->var_2->setStyleSheet("background-color:red");
                  greseli++;
    }
}

void quiz::on_var_3_clicked()
{
    QString value = ui->var_3->text();

    QSqlQuery* qry = new QSqlQuery;
    qry->prepare("SELECT correct_answer from questions where var_3='"+value+"'");
    qry->exec();
    qry->first();
    QString choose = qry->value(0).toString();

    if(value==choose) {
        if(greseli==0) nota+=10;
            else if (greseli==1) nota+=7;
                else nota+=5;
        ui->var_3->setStyleSheet("background-color:green");
        delay();
        on_next_clicked();
    }
            else {
                  ui->var_3->setStyleSheet("background-color:red");
                  greseli++;
    }
}

void quiz::delay()
{
    QTime dieTime= QTime::currentTime().addMSecs(200);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void quiz::set_nota() {
    ui->verticalLayout_2->deleteLater();
    ui->label->setMaximumWidth(800);
    ui->label->setMaximumHeight(500);
    ui->label->setMinimumWidth(800);
    ui->label->setMinimumHeight(500);
  //  ui->label->setMargin(80);
    ui->var_1->hide();
    ui->var_2->hide();
    ui->var_3->hide();
    ui->next->hide();
    ui->question->hide();
    ui->next->hide();
    QString nnota = QString::number(nota);
    if(nota<20) ui->pct->setText("Felicitări, ați obținut " + nnota + " puncte!");
           else ui->pct->setText("Felicitări, ați obținut " + nnota + " de puncte!");
}

void quiz::reset() {
    greseli = 0;
    i = 2;
    nota = 0;
}

void quiz::on_close_clicked()
{
    connClose();
    this->close();
}

quiz::~quiz()
{
    connClose();
    delete ui;
}
