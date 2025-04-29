#ifndef REGISTERPAGE_H
#define REGISTERPAGE_H

#include <QDialog>
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
class RegisterPage;
}

class RegisterPage : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterPage(QWidget *parent = nullptr);
    ~RegisterPage();

private slots:
    void on_pushButton_clicked();


    void on_pushButton_3_clicked();

private:
    Ui::RegisterPage *ui;
};

#endif // REGISTERPAGE_H
