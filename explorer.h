#ifndef EXPLORER_H
#define EXPLORER_H
#include <QLabel>
#include <QWidget>
#include <QPushButton>
#include <QComboBox>
#include <QScrollArea>
#include <QDir>
#include <QStringList>

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
private slots:
    void open_folder(QString path);
    void handle_next();
    void handle_prev();

private:
    void show_dirs();

private:
    QStringList dirs_names;
};

#endif // EXPLORER_H
