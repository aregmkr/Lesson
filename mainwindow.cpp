#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    explorer(new Explorer(this))
{
    this -> setFixedSize(1000, 600);
    explorer->show();
}

MainWindow::~MainWindow() {}
