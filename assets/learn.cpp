#include "learn.h"
#include "ui_learn.h"

learn::learn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::learn)
{
    setWindowFlags(Qt::Window);
    ui->setupUi(this);

    QFile file("/home/teofan/Desktopp/anastasia");

    QString line;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&file);
        while (!stream.atEnd()){

            line.append(stream.readLine()+"\n");
        }
        ui->label_2->setText(line);
    }
    file.close();

     ui->label->setText("<img src=/home/teofan/Desktop/bmw.png align=middle> ");
}

learn::~learn()
{
    delete ui;
}
