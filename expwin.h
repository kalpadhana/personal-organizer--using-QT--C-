#ifndef EXPWIN_H
#define EXPWIN_H

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
#include <QVariant>
namespace Ui {
class Expwin;
}

class Expwin : public QDialog
{
    Q_OBJECT

public:
    explicit Expwin(QWidget *parent = nullptr);
    ~Expwin();

private slots:

    void on_addexpense_clicked();

    void on_exploadexp_clicked();

    //void on_expaddmethodbtn_clicked();

    void on_dateEdit2_userDateChanged(const QDate &date);

private:
    Ui::Expwin *ui;
};

#endif // EXPWIN_H
