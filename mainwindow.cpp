#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "displayfacade.h"

#include <QCloseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_displayFacade = new DisplayFacade(this);
    m_displayFacade->setListWidget(ui->listWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    m_displayFacade->terminate();
    QMainWindow::closeEvent(event);
}

void MainWindow::on_buttonStart_clicked()
{
    ui->buttonStart->setEnabled(false);
    m_displayFacade->start();
}
