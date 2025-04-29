#include "mainwindow2.h"
#include "ui_mainwindow2.h"
#include "incometrack.h"

MainWindow2::MainWindow2(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow2)
{
    ui->setupUi(this);
}

MainWindow2::~MainWindow2()
{
    delete ui;
}

void MainWindow2::on_actionIncome_Tracker_triggered()
{

}


void MainWindow2::on_incometrack_clicked()
{
    Dialog dialogwin;
    dialogwin.setModal(true);
    dialogwin.exec();

}

