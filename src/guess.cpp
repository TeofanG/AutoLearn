#include "guess.h"
#include "ui_guess.h"

guess::guess(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::guess)
{
    setWindowFlags(Qt::Window);
    ui->setupUi(this);
}

guess::~guess()
{
    delete ui;
}
