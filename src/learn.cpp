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
}

void learn::paintEvent(QPaintEvent *pe)
{
    QPixmap pixmap("../assets/pictures/learn_bg.png");
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
