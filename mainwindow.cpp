#include "mainwindow.h"
#include "imageview.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralWidget->layout()->addWidget(new ImageView());
}

MainWindow::~MainWindow()
{
    delete ui;
}
