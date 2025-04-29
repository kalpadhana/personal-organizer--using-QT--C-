#include "registerpage.h"
#include "ui_registerpage.h"
#include "mainwindow.h"
#include <QApplication>
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


RegisterPage::RegisterPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegisterPage)
{
    ui->setupUi(this);


}

RegisterPage::~RegisterPage()
{
    delete ui;
}

void RegisterPage::on_pushButton_clicked()
{

    hide();
    MainWindow *mainwin = new MainWindow;
    mainwin->show();

}


void RegisterPage::on_pushButton_3_clicked()
{


    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/sande/SQLITE/PROJECT.db");



    if (db.open()) {


        QString rusername = ui->regusername->text();
        QString rpassword = ui->regpassword->text();
        QString remail = ui->regemail->text();
        QString rphone = ui->regphone->text();

        if(rusername.isEmpty() || rpassword.isEmpty() || remail.isEmpty() || rphone.isEmpty())
        {
            QMessageBox::critical(this,"Warning","Please fill all fields ");
        }

        else
        {


        QSqlQuery qry ;

        qry.prepare("INSERT INTO regtable (regusername,regpassword,regemail,regphone)"
                     "VALUES (:rusername,:rpassword,:remail,:rphone)");

        qry.bindValue(":rusername",rusername);
        qry.bindValue(":rpassword",rpassword);
        qry.bindValue(":remail",remail);
        qry.bindValue(":rphone",rphone);

        if(qry.exec())
        {
            QMessageBox::information(this,"Success","Registered Successfully");
        }
        else

        {
            QMessageBox::critical(this,"","Username already exists,chose a different username");
           // qDebug()<<"Error"<<qry.lastError().text();
            //QMessageBox::critical(this,"Error","Database unavailable");
        }
        }
}
}




