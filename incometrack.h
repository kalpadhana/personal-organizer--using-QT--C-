#ifndef INCOMETRACK_H
#define INCOMETRACK_H

#include <QMainWindow>
#include "registerpage.h"
#include "mainwindow2.h"
#include <QtSql>
#include <QSqlDatabase>
#include <QCoreApplication>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QString>

namespace Ui {
class Incometrack;
}

class Incometrack : public QMainWindow
{
    Q_OBJECT

public:
    explicit Incometrack(QWidget *parent = nullptr);
    ~Incometrack();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Incometrack *ui;
    Incometrack *inctrack;
};

#endif // INCOMETRACK_H
