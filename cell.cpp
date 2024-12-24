#include "cell.h"

Cell::Cell(QString path, QWidget* parent) : QWidget(parent) {
    name = new QLabel(QFileInfo(path).fileName(), this);
    this->path = path;
    open_btn = new QPushButton("", this);
    this->setFixedSize(100, 140);
    open_btn->setGeometry(10, 10, 80, 80);
    name->setGeometry(10, 104, 80, 32);
    name->setAlignment(Qt::AlignCenter);

    connect(open_btn, &QPushButton::clicked, this, &Cell::handle_open_btn);
}

// void Cell::clicked_folder(QString path) {}

// void Cell::clicked_file(QString path) {}


void Cell::handle_open_btn() {
    qDebug() << "Hello path9999999999999999999999999999999999999999999999999ik";
    qDebug() << path;
    if (QFileInfo(path).isDir()) {
        emit clicked_folder(path);
    } else {
        emit clicked_file(path);
    }
}
