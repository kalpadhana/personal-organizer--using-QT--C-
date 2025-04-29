#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <QDialog>
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
class Schedule;
}

class Schedule : public QDialog
{
    Q_OBJECT

public:
    explicit Schedule(QWidget *parent = nullptr);
    ~Schedule();

private slots:
    void on_pushButton_clicked();

    void on_dateEdit_userDateChanged(const QDate &date);

    void on_viewtodo_clicked();

    void on_viewdateline_userDateChanged(const QDate &date);

    void on_timetableadd_clicked();

    void on_viewbyday_clicked();

    void on_todobtn_clicked();

    void on_tododate_userDateChanged(const QDate &date);

private:
    Ui::Schedule *ui;
};

#endif // SCHEDULE_H
