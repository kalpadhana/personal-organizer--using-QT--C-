#ifndef REPORTS_H
#define REPORTS_H


#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QCoreApplication>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QString>

//lib for bar charts
#include <QtGui>
#include <QtCore>
#include <QtWidgets>
#include <QtCharts>


namespace Ui {
class Reports;
}

class Reports : public QDialog
{
    Q_OBJECT

public:
    explicit Reports(QWidget *parent = nullptr);
    ~Reports();

private slots:
    void on_pushButton_clicked();

    void on_start_userDateChanged(const QDate &date);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();


    void on_pushButton_5_clicked();

private:
    Ui::Reports *ui;
};

#endif // REPORTS_H
