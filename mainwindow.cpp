#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <sstream>

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
  const char *name, *value;
  
  for (int i = 0; i < count; i++) {
    gp_list_get_name(list, i, &name);
    gp_list_get_value(list, i, &value);

    std::stringstream a;
    a << name << ": " << value;
    
    ui->listWidget->addItem(a.str().c_str());
  }
    
  
  std::cout << "Number of Cameras Detected: " << count << std::endl;
}
