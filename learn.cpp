#include "learn.h"
#include "ui_learn.h"

learn::learn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::learn)
{
    setWindowFlags(Qt::Window);
    ui->setupUi(this);
}

learn::~learn()
{
    delete ui;
}
