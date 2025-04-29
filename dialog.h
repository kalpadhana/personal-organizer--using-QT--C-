#ifndef DIALOG_H
#define DIALOG_H
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
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);

    ~Dialog();

private slots:
    void on_addincome_clicked();



    void on_pushButton_clicked();





   // void on_dateEdit_userDateChanged(const QDate &date);

    void on_dateEdit_userDateChanged(const QDate &date);

    void on_pushButton_2_clicked();

private:
    Ui::Dialog *ui;

};

#endif // DIALOG_H
