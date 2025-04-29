#ifndef CATEGORYBUDGETING_H
#define CATEGORYBUDGETING_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QCoreApplication>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#include "mainwindow.h"
#include <QLocale>
#include <QDialog>
#include <Qdate>

namespace Ui {
class categorybudgeting;
}

class categorybudgeting : public QDialog
{
    Q_OBJECT

public:
    explicit categorybudgeting(QWidget *parent = nullptr);
    ~categorybudgeting();

private slots:
    void on_setlimitbtn_clicked();

    void on_pushButton_clicked();

private:
    Ui::categorybudgeting *ui;
};

#endif // CATEGORYBUDGETING_H
