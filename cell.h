#ifndef CELL_H
#define CELL_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QFileInfo>
#include <QDir>

class Cell : public QWidget{
    Q_OBJECT
  public:
    Cell(QString path = "", QWidget* parent = nullptr);
    virtual ~Cell() = default;
  private:
    QLabel* name;
    QString path;
    QPushButton* open_btn;
  private slots:
    void handle_open_btn();

  signals:
    void clicked_folder(QString path);
    void clicked_file(QString path);
};

#endif // CELL_H
