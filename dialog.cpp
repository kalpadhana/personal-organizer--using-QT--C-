#include "dialog.h"
#include "ui_dialog.h"
#include "mainwindow.h"
int mont;
int year;

 QString selday;

QString loggedInUsername;
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_dateEdit_userDateChanged(const QDate &date)
{
    selday = date.toString("yyyy-MM-dd");
    mont = date.month();
    year=date.year();
}


void Dialog::on_addincome_clicked()
{

    if (selday==nullptr)
    {QMessageBox::critical(this,"Warning","Please select a date");}

    else
    {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("C:/Users/sande/SQLITE/PROJECT.db");


    if(db.open())
    {
    QString incMethod = ui->incomeline->text();
    QString incAmount = ui->amountline->text();
    QString incomecomboboxtext = ui->incomecombobox->currentText();

    QSqlQuery qry2;
    if(incMethod ==  nullptr || incAmount==nullptr)
    {QMessageBox::information(this,"Warning","Please fill all fields");}

    else
    {
    qry2.prepare("INSERT INTO income (username,date,method,description,amount,monthx,yearx) "
                 "VALUES (:loggedInUsername,:selday,:incomecomboboxtext,:incMethod,:incAmount,:mont,:year)");


    qry2.bindValue(":loggedInUsername", loggedInUsername);
    qry2.bindValue(":incMethod", incMethod);
    qry2.bindValue(":incAmount", incAmount);
    qry2.bindValue(":selday", selday);
    qry2.bindValue(":incomecomboboxtext",incomecomboboxtext);
    qry2.bindValue(":mont",mont);
    qry2.bindValue(":year",year);

    if(qry2.exec())
    {
        QMessageBox::information(this,"Success","Added Sucessfully");
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("C:/Users/sande/SQLITE/PROJECT.db");
        if(db.open())
        {

            QSqlQueryModel *modal = new QSqlQueryModel();

            QSqlQuery qry3;
            qDebug()<<loggedInUsername;
            qry3.prepare("SELECT date,method,description,amount  FROM income WHERE username=:loggedInUsername");
         qry3.bindValue(":loggedInUsername", loggedInUsername);
            qry3.exec();
            modal->setQuery(qry3);
            ui->tableView->setModel(modal);

        }

        else
        {
            QMessageBox::critical(this,"Error","Database unavailable");
        }
    }
    else
    {
         qDebug() << "Query execution error:" << qry2.lastError().text();
        QMessageBox::critical(this,"Error","Unsucessful");
    }

    }
    }
    else
    {
        QMessageBox::critical(this,"Caution","Database Unavailable");
    }

        }
}





void Dialog::on_pushButton_clicked()
{   QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/sande/SQLITE/PROJECT.db");
    if(db.open())
    {

        QSqlQueryModel *modal = new QSqlQueryModel();

        QSqlQuery qry3;
        qDebug()<<loggedInUsername;
        qry3.prepare("SELECT date,method,description,amount  FROM income WHERE username=:loggedInUsername ");
        qry3.bindValue(":loggedInUsername",loggedInUsername);
        qry3.exec();
        modal->setQuery(qry3);
        ui->tableView->setModel(modal);
    }

}













void Dialog::on_pushButton_2_clicked()
{
    QString addmethod = ui->methodline->text();
    ui->incomecombobox->addItem(addmethod);

}

