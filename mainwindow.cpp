#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainwindow2.h"
#include "dialog.h"
#include <QString>

extern  QString loggedInUsername;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->username->setPlaceholderText("  Enter your  username ");
    ui->password->setPlaceholderText("  Enter Your Password");

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_2_clicked()
{
        RegisterPage regpage;
        regpage.setModal(true);
        regpage.exec();
}

void MainWindow::on_pushButton_clicked()
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/sande/SQLITE/PROJECT.db");

    if (db.open()) {
        QString lusername = ui->username->text();
        QString lpassword = ui->password->text();


        QSqlQuery query;
        query.prepare("SELECT regpassword FROM regtable WHERE regusername = :regusername");
        query.bindValue(":regusername", lusername);

        if (lusername.isEmpty() ||lpassword.isEmpty())
        {
            QMessageBox::critical(this,"Caution","Both username and password requied");
        }
        else
        {
        if (query.exec() && query.next())
            {
            QString dbPassword = query.value(0).toString();
            if (dbPassword == lpassword)
            {
                loggedInUsername=lusername;
                QMessageBox::information(this,"Status","Login Success!\n\nWelcome  "+lusername);
                hide();


                Dashboard dashboard;
                dashboard.setModal(true);
                dashboard.exec();







            }
            else
            {
                QMessageBox::information(this,"Status","Incorrect Password");
            }
        }
        else
            {
                QMessageBox::information(this,"Status","Invalid credentials");
            }
        }
    }
}




