#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "camera_container.h"

#include <iostream>
#include <sstream>

#include <QStringListModel>

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
  
  CameraContainer cameras;
  size_t count = cameras.DetectAttachedCameras();
  for (CameraContainer::port_iterator it = cameras.begin();
       it != cameras.end();
       it++   
  ) {
    std::stringstream a;
    a << it->name << ": " << it->port;
    ui->listWidget->addItem(a.str().c_str());
  }

  std::cout << "Number of Cameras Detected from class: " << count << std::endl;
}
