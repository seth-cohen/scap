#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <QStringListModel>
#include <gphoto2/gphoto2-camera.h>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::enumerateCameras() {
  ui->listWidget->addItem("This is a test");
  std::cout << "Button pressed" << std::endl;

  CameraList *list;
  GPContext *context;
  gp_list_new(&list);
  context = gp_context_new();

  int count = gp_camera_autodetect(list, context);
  std::cout << "Number of Cameras Detected: " << count << std::endl;
}
