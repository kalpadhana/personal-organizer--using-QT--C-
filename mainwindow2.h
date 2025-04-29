#ifndef MAINWINDOW2_H
#define MAINWINDOW2_H

#include <QMainWindow>
#include "incometrack.h"
#include "dialog.h"
#include "mainwindow2.h"
#include <QMainWindow>
#include "registerpage.h"
#include <QtSql>
#include <QSqlDatabase>
#include <QCoreApplication>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QString>

namespace Ui {
class MainWindow2;
}

class MainWindow2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow2(QWidget *parent = nullptr);
    ~MainWindow2();

private slots:
    void on_actionIncome_Tracker_triggered();

    void on_incometrack_clicked();

private:
    Ui::MainWindow2 *ui;
};

#endif // MAINWINDOW2_H
