#include "learn.h"
#include "ui_learn.h"

learn::learn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::learn)
{
    setWindowFlags(Qt::Window);
    ui->setupUi(this);

    // setare cadru initial masina + informatii

    QString counterToString = QString::number(counter);
    QFile file("../assets/text/text_"+counterToString);
         QString line;
         if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
             QTextStream stream(&file);
             while (!stream.atEnd()){
                 line.append(stream.readAll());
             }
             ui->label_2->setText(line);
         }
     file.close();

    // ui->label->setText("<img src=../assets/pictures/img_" + counterToString + ".png align=middle> ");

     this->ui->sas_1->hide();
     this->ui->sas_2->hide();
     this->ui->sas_3->hide();
     this->ui->sas_4->hide();
     this->ui->sas_5->hide();
     this->ui->mot_1->hide();
     this->ui->mot_2->hide();
     this->ui->car_1->hide();
     this->ui->car_2->hide();
     this->ui->car_3->hide();
     this->ui->car_4->hide();
     this->ui->car_5->hide();
     this->ui->car_6->hide();
     this->ui->car_7->hide();
}


void learn::paintEvent(QPaintEvent *pe)
{
    QPixmap pixmap("../assets/design/learn_bg.png");
    QPainter paint(this);
    int widWidth = this->width();
    int widHeight = this->height();
    pixmap = pixmap.scaled(widWidth, widHeight, Qt::KeepAspectRatioByExpanding);
    paint.drawPixmap(0, 0, pixmap);
    QWidget::paintEvent(pe);
}


learn::~learn()
{
    delete ui;
}

void learn::on_toolButton_clicked()
{   
    QDir dir("../assets/text");
    dir.setFilter( QDir::AllEntries | QDir::NoDotAndDotDot );
    int total_files = dir.count();

    if(counter < total_files) {
        counter++;
        QString counterToString = QString::number(counter);
        QFile file("../assets/text/text_"+counterToString);
             QString line;
             if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
                 QTextStream stream(&file);
                 while (!stream.atEnd()){
                     line.append(stream.readAll());
                 }
                 ui->label_2->setText(line);
             }
         file.close();

         ui->label->setText("<img src=../assets/pictures/img_" + counterToString + ".png align=middle> ");
    }
}

void learn::on_toolButton_2_clicked()
{
   if (counter > 1) {
        counter--;
        QString counterToString = QString::number(counter);
        QFile file("../assets/text/text_"+counterToString);
             QString line;
             if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
                 QTextStream stream(&file);
                 while (!stream.atEnd()){
                     line.append(stream.readAll());
                 }
                 ui->label_2->setText(line);
             }
         file.close();

         ui->label->setText("<img src=../assets/pictures/img_" + counterToString + ".png align=middle> ");
   }
}


void learn::on_sasiul_clicked()
{
    ui->sasiul->setMaximumHeight(40);
    a++;
        if (a%2 != 0) {
                this->ui->sas_1->show();
                this->ui->sas_2->show();
                this->ui->sas_3->show();
                this->ui->sas_4->show();
                this->ui->sas_5->show();
                this->ui->motorul->hide();
                this->ui->caroseria->hide();
        }
            else {
                this->ui->sas_1->hide();
                this->ui->sas_2->hide();
                this->ui->sas_3->hide();
                this->ui->sas_4->hide();
                this->ui->sas_5->hide();
                this->ui->motorul->show();
                this->ui->caroseria->show();
        }
      counter = 1;
      on_toolButton_clicked();
}

void learn::on_motorul_clicked()
{
    ui->motorul->setMinimumHeight(40);
    b++;
        if (b%2 != 0) {
                this->ui->mot_1->show();
                this->ui->mot_2->show();
                this->ui->sasiul->hide();
                this->ui->caroseria->hide();
        }
            else {
                this->ui->mot_1->hide();
                this->ui->mot_2->hide();
                this->ui->sasiul->show();
                this->ui->caroseria->show();
        }
    counter = 16;
    on_toolButton_clicked();
}

void learn::on_caroseria_clicked()
{
    ui->caroseria->setMinimumHeight(40);
    c++;
        if (c%2 != 0) {
                this->ui->car_1->show();
                this->ui->car_2->show();
                this->ui->car_3->show();
                this->ui->car_4->show();
                this->ui->car_5->show();
                this->ui->car_6->show();
                this->ui->car_7->show();
                this->ui->motorul->hide();
                this->ui->sasiul->hide();
        }
            else {
                this->ui->car_1->hide();
                this->ui->car_2->hide();
                this->ui->car_3->hide();
                this->ui->car_4->hide();
                this->ui->car_5->hide();
                this->ui->car_6->hide();
                this->ui->car_7->hide();
                this->ui->motorul->show();
                this->ui->sasiul->show();
        }
      counter = 19;
      on_toolButton_clicked();
}

void learn::on_sas_1_clicked()
{
     counter = 2;
     on_toolButton_clicked();
}

void learn::on_sas_2_clicked()
{
    counter = 11;
    on_toolButton_clicked();
}

void learn::on_sas_3_clicked()
{
    counter = 13;
    on_toolButton_clicked();
}

void learn::on_sas_4_clicked()
{
    counter = 14;
    on_toolButton_clicked();
}

void learn::on_sas_5_clicked()
{
    counter = 15;
    on_toolButton_clicked();
}

void learn::on_mot_1_clicked()
{
    counter = 17;
    on_toolButton_clicked();
}

void learn::on_mot_2_clicked()
{
    counter = 18;
    on_toolButton_clicked();
}

void learn::on_car_1_clicked()
{
    counter = 20;
    on_toolButton_clicked();
}

void learn::on_car_2_clicked()
{
    counter = 21;
    on_toolButton_clicked();
}

void learn::on_car_3_clicked()
{
    counter = 22;
    on_toolButton_clicked();
}

void learn::on_car_4_clicked()
{
    counter = 23;
    on_toolButton_clicked();
}

void learn::on_car_5_clicked()
{
    counter = 24;
    on_toolButton_clicked();
}

void learn::on_car_6_clicked()
{
    counter = 25;
    on_toolButton_clicked();
}

void learn::on_car_7_clicked()
{
    counter = 26;
    on_toolButton_clicked();
}


void learn::on_toolButton_3_clicked()
{
    this->close();
}
