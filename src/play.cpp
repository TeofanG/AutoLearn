#include "play.h"
#include "ui_play.h"

play::play(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::play)
{
    setWindowFlags(Qt::Window);
    ui->setupUi(this);
}

void play::paintEvent(QPaintEvent *pe)
{
    QPixmap pixmap("../assets/design/learn_bg.png");
    QPainter paint(this);
    int widWidth = this->width();
    int widHeight = this->height();
    pixmap = pixmap.scaled(widWidth, widHeight, Qt::KeepAspectRatioByExpanding);
    paint.drawPixmap(0, 0, pixmap);
    QWidget::paintEvent(pe);
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


void play::on_pushButton_6_clicked()
{
    this->close();
}
