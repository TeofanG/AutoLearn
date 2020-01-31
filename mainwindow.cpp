#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    this->close();
    learn learn_window;
    learn_window.setModal(true);
    learn_window.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    this->close();
    play play_window;
    play_window.setModal(true);
    play_window.exec();
}
