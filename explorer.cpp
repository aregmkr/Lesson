#include "explorer.h"

Explorer::Explorer(QWidget* parent) : QWidget(parent) {
    this->setFixedSize(1000, 600);
    init();
    setup();
    connections();
    show_dirs();

    // Cell* cell_1 = new Cell("path", label_right);
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

    dir_box = new QComboBox(label_top);


    cells_layout = new QGridLayout();
    label_right->setLayout(cells_layout);

    for_layout = new QScrollArea(this);
    for_layout->setWidget(label_right);

}

void Explorer::setup() {
    label_left->setGeometry(0, 50, 200, 550);
    label_left->setStyleSheet("border: 1px solid white");
    label_top->setGeometry(0, 0, 1000, 50);
    label_top->setStyleSheet("border: 1px solid white");
    // label_right->setGeometry(200, 50, 800, 550);
    label_right->setStyleSheet("border: 1px solid white");

    dir_box->setGeometry(725, 10, 250, 30);
    current_path->setGeometry(100, 10, 600, 30);
    current_path->setAlignment(Qt::AlignCenter);

    next_btn->setText("▶");
    next_btn->setGeometry(60, 10, 30, 30);

    prev_btn->setText("◀");
    prev_btn->setGeometry(10, 10, 30, 30);

    scroll->setGeometry(10, 45, 180, 500);
    scroll->setBackgroundRole(QPalette::Dark);
    scroll->setWidget(scroll_content);

    scroll_content->setGeometry(5, 5, 160, 1000);

    // home->setParent(this);
    home->setGeometry(5, 5, 150, 30);
    home->setText("home/");
    home->show();

    for_layout->setGeometry(200, 50, 800, 550);


}

void Explorer::connections() {
    // connect(next_btn, SIGNAL(clicked()), this, SLOT(handle_next()));
    // connect(prev_btn, SIGNAL(clicked()), this, SLOT(handle_prev()));
    connect(dir_box, &QComboBox::currentIndexChanged, this, &Explorer::handle_box);
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
    // if (dir_box->find(path)) {}
    qDebug() << path;
    history_dir_names.append(path);
    dir_box->addItem(QFileInfo(path).fileName());
    current_path->setText(path);
    cell_manager(path);
}

void Explorer::handle_box(int index) {
    if (dir_box->count() - 1 != index) {
        QString path = history_dir_names.at(index);
        history_dir_names.remove(index);
        dir_box->removeItem(index);
        open_folder(path);
    }
}

void Explorer::cell_manager(QString path) {
    for (auto item : cells_array)  {
        delete item;
    }
    cells_array.clear();
    QStringList inside_of_path = QDir(path).entryList();
    for (auto item : inside_of_path) {
        Cell* new_cell = new Cell(path + "/" + item);
        connect(new_cell, &Cell::clicked_file, this, &Explorer::open_file);
        connect(new_cell, &Cell::clicked_folder, this, &Explorer::open_folder);
        cells_array.append(new_cell);
        qDebug() << item;
    }

    for (int i = 0; i < cells_array.size(); ++i) {
        int x = i / 7;
        int y = i % 7;
        cells_layout->addWidget(cells_array[i], x, y, Qt::AlignLeft | Qt::AlignTop);
        cells_array[i]->show();
    }
    // cells_layout->setSpacing(0);
    cells_layout->setColumnStretch(6, 10);
    int h = (cells_array.size() / 7 + 1) * 2 * cells_array[0]->width();
    label_right->resize(795, (h < 547) ? 547 : h);
}

void Explorer::open_file(QString path) {
    qDebug() << path;
}

void Explorer::handle_next()
{

}

void Explorer::handle_prev()
{

}
