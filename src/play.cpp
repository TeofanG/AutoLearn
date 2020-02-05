#include "play.h"
#include "ui_play.h"

play::play(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::play)
{
    setWindowFlags(Qt::Window);
    ui->setupUi(this);
}

play::~play()
{
    delete ui;
}

void play::on_pushButton_5_clicked()
{
    quiz quiz_window;
    quiz_window.setModal(true);
    quiz_window.exec();
}
