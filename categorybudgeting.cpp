#include "categorybudgeting.h"
#include "ui_categorybudgeting.h"
#include "mainwindow.h"
#include <QDebug>
extern QString loggedInUsername;

categorybudgeting::categorybudgeting(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::categorybudgeting)
{
    ui->setupUi(this);
}

categorybudgeting::~categorybudgeting()
{
    delete ui;
}


void categorybudgeting::on_setlimitbtn_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/sande/SQLITE/PROJECT.db");

    if (db.open())
    {
        QString limitcombobox = ui->categorycomboBox->currentText();
        QString catamt = ui->lineEdit->text();

        if (limitcombobox.isEmpty() || catamt.isEmpty())
        {
            QMessageBox::critical(this, "Warning", "Please select category and enter your amount limit");
        }
        else
        {

            QSqlQuery qry6;
            qry6.prepare("INSERT INTO budget (username,category,amount) VALUES(:loggedInUsername,:limitcombobox,:catamt)");
            qry6.bindValue(":loggedInUsername",loggedInUsername);
            qry6.bindValue(":limitcombobox",limitcombobox);
            qry6.bindValue(":catamt",catamt);
            if(qry6.exec())
            { QMessageBox::information(this,"Sucess","Added");}
            else
            {

        QSqlQuery qry5;
        qry5.prepare("UPDATE  budget SET amount = :catamt  WHERE category=:limitcombobox AND username=:loggedInUsername");
        qry5.bindValue(":loggedInUsername",loggedInUsername);
        qry5.bindValue(":limitcombobox",limitcombobox);
        qry5.bindValue(":catamt",catamt);


        if (qry5.exec())
        {
            QMessageBox::information(this,"Sucess","Added");
        }
        else
        {

        }
            }
        }

    }
else
    {
        QMessageBox::critical(this, "Error", "Database Unavailable");
    }

    //show table

    if (db.open())
    {
        QSqlQueryModel *modal = new QSqlQueryModel();

        QSqlQuery qry3;
        qDebug()<<loggedInUsername;
        qry3.prepare("SELECT category,amount  FROM budget WHERE username=:loggedInUsername");
        qry3.bindValue(":loggedInUsername", loggedInUsername);
        qry3.exec();
        modal->setQuery(qry3);
        ui->tableView->setModel(modal);
    }
    else
    {
        QMessageBox::critical(this,"Error","Database Unavailable");
    }
}




void categorybudgeting::on_pushButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/sande/SQLITE/PROJECT.db");

    if (db.open())
    {
    QSqlQueryModel *modal = new QSqlQueryModel();

    QSqlQuery qry3;
    qDebug()<<loggedInUsername;
    qry3.prepare("SELECT category,amount  FROM budget WHERE username=:loggedInUsername");
    qry3.bindValue(":loggedInUsername", loggedInUsername);
    qry3.exec();
    modal->setQuery(qry3);
    ui->tableView->setModel(modal);
    }
    else
    {
        QMessageBox::critical(this,"Error","Database Unavailable");
    }
}



