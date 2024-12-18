#include "explorer.h"

Explorer::Explorer(QWidget* parent) : QWidget(parent) {
    this->setFixedSize(1000, 600);
    init();
    setup();
    connections();
    show_dirs();
}

Explorer::~Explorer() {}


void Explorer::init() {
    label_left = new QLabel(this);
    label_top = new QLabel(this);
    label_right = new QLabel(this);
    current_path = new QLabel("Dir Path", label_top);

    scroll_content = new QWidget();
    scroll = new QScrollArea(label_left);

    prev_btn = new QPushButton(label_top);
    next_btn = new QPushButton(label_top);
    home = new QPushButton(scroll_content);
    // dir_box = new QComboBox(label_top);
}

void Explorer::setup() {
    label_left->setGeometry(0, 50, 200, 550);
    label_left->setStyleSheet("border: 1px solid white");
    label_top->setGeometry(0, 0, 1000, 50);
    label_top->setStyleSheet("border: 1px solid white");
    label_right->setGeometry(200, 50, 800, 550);
    label_right->setStyleSheet("border: 1px solid white");

    current_path->setGeometry(100, 10, 600, 30);
    current_path->setAlignment(Qt::AlignCenter);

    next_btn->setText("➤");
    next_btn->setGeometry(60, 10, 30, 30);

    prev_btn->setText("⮜");
    prev_btn->setGeometry(10, 10, 30, 30);

    scroll->setGeometry(10, 45, 180, 500);
    scroll->setBackgroundRole(QPalette::Dark);
    scroll->setWidget(scroll_content);

    scroll_content->setGeometry(5, 5, 160, 1000);

    // home->setParent(this);
    home->setGeometry(5, 5, 150, 30);
    home->setText("home/");
    home->show();



}

void Explorer::connections() {
    connect(next_btn, SIGNAL(clicked()), this, SLOT(handle_next()));
    connect(prev_btn, SIGNAL(clicked()), this, SLOT(handle_prev()));
    connect(home, &QPushButton::clicked, this, [this]() {this->open_folder(QDir::homePath());});
}

void Explorer::show_dirs() {
    QDir dir = QDir::home();
    QStringList chlp = dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
    int y = 40;
    for (const QString& item : chlp) {
        QPushButton* btn = new QPushButton(item, scroll_content);
        QString arg_path = dir.absolutePath() + "/" + item;
        connect(btn, &QPushButton::clicked, [this, arg_path]() {this->open_folder(arg_path);});
        btn->setGeometry(5, y, 150, 30);
        y += 40;
    }
}


void Explorer::open_folder(QString path) {
    qDebug() << path;
    current_path->setText(path);
}

void Explorer::handle_next()
{

}

void Explorer::handle_prev()
{

}
