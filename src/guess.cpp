#include "guess.h"
#include "ui_guess.h"

int id_1, id_2, id_3, id_4, id_5, id_6, id_7, id_8, id_9, id_10;
int id_curent, contor, contor_max, nota, greseli=0;
QString idToString, correct_var;

void guess::paintEvent(QPaintEvent *pe)
{
    QPixmap pixmap("../assets/design/learn_bg.png");
    QPainter paint(this);
    int widWidth = this->width();
    int widHeight = this->height();
    pixmap = pixmap.scaled(widWidth, widHeight, Qt::KeepAspectRatioByExpanding);
    paint.drawPixmap(0, 0, pixmap);
    QWidget::paintEvent(pe);
}

guess::guess(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::guess)
{
    setWindowFlags(Qt::Window);
    ui->setupUi(this);
    connOpen();
    count_rows();
    init();
}

void guess::count_rows() {
    QSqlQuery* qry = new QSqlQuery;
    qry->prepare("SELECT COUNT(*) FROM guess_tab");
    qry->exec();
    qry->first();
    contor_max = qry->value(0).toInt();
}

void guess::init() {
    select();
    contor = 1;
    select_id_curent();
    set_var_img(idToString);
}

void guess::select() {                  // selectarea si memorarea id-urilor intrebarilor
     QSqlQuery* qry = new QSqlQuery;
     qry->prepare("SELECT id from guess_tab order by random() limit 10");
     qry->exec();
     qry->first();
     id_1 = qry->value(0).toInt();
     qry->next();
     id_2 = qry->value(0).toInt();
     qry->next();
     id_3 = qry->value(0).toInt();
     qry->next();
     id_4 = qry->value(0).toInt();
     qry->next();
     id_5 = qry->value(0).toInt();
     qry->next();
     id_6 = qry->value(0).toInt();
     qry->next();
     id_7 = qry->value(0).toInt();
     qry->next();
     id_8 = qry->value(0).toInt();
     qry->next();
     id_9 = qry->value(0).toInt();
     qry->next();
     id_10 = qry->value(0).toInt();
}

void guess::select_id_curent() {
    switch (contor) {
        case 1:
            id_curent = id_1;
            idToString = QString::number(id_1);
            break;
        case 2:
            id_curent = id_2;
            idToString = QString::number(id_2);
            break;
        case 3:
            id_curent = id_3;
            idToString = QString::number(id_3);
            break;
        case 4:
            id_curent = id_4;
            idToString = QString::number(id_4);
            break;
        case 5:
            id_curent = id_5;
            idToString = QString::number(id_5);
            break;
        case 6:
            id_curent = id_6;
            idToString = QString::number(id_6);
            break;
        case 7:
            id_curent = id_7;
            idToString = QString::number(id_7);
            break;
        case 8:
            id_curent = id_8;
            idToString = QString::number(id_8);
            break;
        case 9:
            id_curent = id_9;
            idToString = QString::number(id_9);
            break;
        case 10:
            id_curent = id_10;
            idToString = QString::number(id_10);
            break;
    }
}

void guess::set_var_img(QString id) {
    // selectare imagine
    ui->img->setPixmap("../assets/pictures/img_"+id+".png");

    // selectare varianta 1
    QSqlQuery* qry1 = new QSqlQuery;
    qry1->prepare("SELECT var1 from guess_tab where id='"+id+"'");
    qry1->exec();
    qry1->first();
    ui->v1->setText(qry1->value(0).toString());

    //selectare varianta 2
    QSqlQuery* qry2 = new QSqlQuery;
    qry2->prepare("SELECT var2 from guess_tab where id='"+id+"'");
    qry2->exec();
    qry2->first();
    ui->v2->setText(qry2->value(0).toString());

    //selectare varianta 3
    QSqlQuery* qry3 = new QSqlQuery;
    qry3->prepare("SELECT var3 from guess_tab where id='"+id+"'");
    qry3->exec();
    qry3->first();
    ui->v3->setText(qry3->value(0).toString());

    //selectare varianta 4
    QSqlQuery* qry4 = new QSqlQuery;
    qry4->prepare("SELECT var4 from guess_tab where id='"+id+"'");
    qry4->exec();
    qry4->first();
    ui->v4->setText(qry4->value(0).toString());
}

void guess::select_correct_var() {
    QSqlQuery* qry = new QSqlQuery;
    qry->prepare("SELECT correct_var from guess_tab where id='"+idToString+"'");
    qry->exec();
    qry->first();
    correct_var = qry->value(0).toString();
}

void guess::on_v1_clicked()
{
    QSqlQuery* qry = new QSqlQuery;
    qry->prepare("SELECT correct_var from guess_tab where id='"+idToString+"'");
    qry->exec();
    qry->first();
    QString correct_var = qry->value(0).toString();

    if(ui->v1->text()==correct_var) {
        if(greseli==0) nota+=10;
            else if (greseli==1) nota+=7;
                else if (greseli==1) nota+=5;
                    else nota+=3;
        ui->v1->setStyleSheet("background-color:green");
        delay();
        on_next_clicked();
    }
            else {
                  ui->v1->setStyleSheet("background-color:red");
                  greseli++;
    }
}

void guess::on_v2_clicked()
{
    QSqlQuery* qry = new QSqlQuery;
    qry->prepare("SELECT correct_var from guess_tab where id='"+idToString+"'");
    qry->exec();
    qry->first();
    QString correct_var = qry->value(0).toString();

    if(ui->v2->text()==correct_var) {
        if(greseli==0) nota+=10;
            else if (greseli==1) nota+=7;
                else if (greseli==1) nota+=5;
                    else nota+=3;
        ui->v2->setStyleSheet("background-color:green");
        delay();
        on_next_clicked();
    }
            else {
                  ui->v2->setStyleSheet("background-color:red");
                  greseli++;
    }
}

void guess::on_v3_clicked()
{
    QSqlQuery* qry = new QSqlQuery;
    qry->prepare("SELECT correct_var from guess_tab where id='"+idToString+"'");
    qry->exec();
    qry->first();
    QString correct_var = qry->value(0).toString();

    if(ui->v3->text()==correct_var) {
        if(greseli==0) nota+=10;
            else if (greseli==1) nota+=7;
                else if (greseli==1) nota+=5;
                    else nota+=3;
        ui->v3->setStyleSheet("background-color:green");
        delay();
        on_next_clicked();
    }
            else {
                  ui->v3->setStyleSheet("background-color:red");
                  greseli++;
    }
}

void guess::on_v4_clicked()
{
    QSqlQuery* qry = new QSqlQuery;
    qry->prepare("SELECT correct_var from guess_tab where id='"+idToString+"'");
    qry->exec();
    qry->first();
    QString correct_var = qry->value(0).toString();

    if(ui->v4->text()==correct_var) {
        if(greseli==0) nota+=10;
            else if (greseli==1) nota+=7;
                else if (greseli==1) nota+=5;
                    else nota+=3;
        ui->v4->setStyleSheet("background-color:green");
        delay();
        on_next_clicked();
    }
            else {
                  ui->v4->setStyleSheet("background-color:red");
                  greseli++;
    }
}

void guess::delay()
{
    QTime dieTime= QTime::currentTime().addMSecs(200);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void guess::on_next_clicked()
{
    contor++;
    if(contor > contor_max) set_nota();
            else {
                reset();
                select_id_curent();
                set_var_img(idToString);
                select_correct_var();
        }
}

void guess::reset() {
    ui->v1->setStyleSheet("background-color:#1b10dd;");
    ui->v2->setStyleSheet("background-color:#1b10dd;");
    ui->v3->setStyleSheet("background-color:#1b10dd;");
    ui->v4->setStyleSheet("background-color:#1b10dd;");
    greseli = 0;
}

void guess::set_nota() {
    ui->next->deleteLater();
    ui->v1->deleteLater();
    ui->v2->deleteLater();
    ui->v3->deleteLater();
    ui->v4->deleteLater();
    ui->horizontalLayout->deleteLater();
    QPixmap pixmap("../assets/design/mcqueen.png");
    ui->img->setPixmap(pixmap);
    this->setMaximumHeight(500);
    ui->label_3->setStyleSheet("font-size: 28pt;");
    QString nnota = QString::number(nota);
    if(nota<20) ui->label_3->setText("Felicitări, ați obținut " + nnota + " puncte!");
           else ui->label_3->setText("Felicitări, ați obținut " + nnota + " de puncte!");
}


void guess::on_inchide_clicked()
{
    connClose();
    this->close();
}

guess::~guess()
{
    connClose();
    delete ui;
}
