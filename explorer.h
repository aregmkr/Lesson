#ifndef EXPLORER_H
#define EXPLORER_H
#include <QLabel>
#include <QWidget>
#include <QPushButton>
#include <QComboBox>
#include <QScrollArea>
#include <QDir>
#include <QStringList>
#include "cell.h"
#include <QGridLayout>

class Explorer : public QWidget
{
public:
    Explorer(QWidget* parent = nullptr);
    ~Explorer();
private:
    void init();
    void setup();
    void connections();

private:
    QLabel* label_left;
    QLabel* label_top;
    QLabel* label_right;
    QLabel* current_path;

    QPushButton* prev_btn;
    QPushButton* next_btn;
    QPushButton* home;

    QComboBox* dir_box;

    QScrollArea* scroll;

    QWidget* scroll_content;

    QStringList history_dir_names;

    QVector<Cell*> cells_array;

    QGridLayout* cells_layout;
    QScrollArea* for_layout;
private slots:
    void open_folder(QString path);
    void open_file(QString path);
    void handle_next();
    void handle_prev();
    void handle_box(int index);

private:
    void show_dirs();
    void cell_manager(QString path);
};

#endif // EXPLORER_H
