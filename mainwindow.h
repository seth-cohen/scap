#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QStringListModel;

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT
  
 public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

  public slots:
    void enumerateCameras();
      
 private:
    QStringListModel *model;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
