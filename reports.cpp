#include "reports.h"
#include "ui_reports.h"
#include "charts.h"

extern QString loggedInUsername;
//extern int selmon;
QString firstday;
QString lastday;
int mon=0;
int yea;
double sumamtinc,sumamtinc1;
double sumamtexp,sumamtexp1;
double sumexp;
double suminc;
double bal;
double curmonbal;

Reports::Reports(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Reports)
{
    ui->setupUi(this);
}



Reports::~Reports()
{
    delete ui;
}


void Reports::on_start_userDateChanged(const QDate &date)
{
    // = date.toString("yyyy-MM-dd");
    mon= date.month();
    yea=date.year();

    //qDebug()<<"month"<<mon;
}




void Reports::on_pushButton_clicked()
{
    if (mon==0)
    {QMessageBox::critical(this,"Error","Please select a date");}
    else
    {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/sande/SQLITE/PROJECT.db");

    if(db.open())
    {
        QSqlQuery qryinc;
        qryinc.prepare("SELECT date, method, description, amount FROM income "
                         "WHERE username =:loggedInUsername AND monthx=:mon AND yearx=:yea ORDER BY date ASC");
        qryinc.bindValue(":loggedInUsername", loggedInUsername);
        qryinc.bindValue(":mon",mon);
        qryinc.bindValue(":yea",yea);

        if(qryinc.exec())

        {
            qDebug()<<"month"<<mon;
            QSqlQueryModel *modal = new QSqlQueryModel();
            modal->setQuery(qryinc);
            ui->tableView->setModel(modal);
        }
        else
        {
            qDebug()<<"month"<<mon;
            qDebug()<<qryinc.lastError().text();

        }
    }
    else
    {
        QMessageBox::critical(this,"Error"," Database Unavailable");

    }

    QSqlQuery incsum;
    incsum.prepare("SELECT SUM(amount) FROM income "
                     "WHERE username =:loggedInUsername AND monthx=:mon AND yearx=:yea");
    incsum.bindValue(":loggedInUsername", loggedInUsername);
    incsum.bindValue(":mon",mon);
    incsum.bindValue(":yea",yea);
    if(incsum.exec())
    {
        if (incsum.next())
        {
            QVariant result = incsum.value(0);
            if (!result.isNull())
            {
                sumamtinc = result.toDouble();
                qDebug()<<"sum"<<sumamtinc;

                ui->amtlabel->setText( QString::number(sumamtinc));
            }

        }
    }
    }
}



void Reports::on_pushButton_2_clicked()
{
    if (mon==0)
    {QMessageBox::critical(this,"Error","Please select a date");}
    else
    {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/sande/SQLITE/PROJECT.db");

    if(db.open())
    {
        QSqlQuery qryexpen;
        qryexpen.prepare("SELECT day, method, description, amount FROM expense "
                         "WHERE username =:loggedInUsername AND monthx=:mon AND yearx=:yea ORDER BY day ASC");
        qryexpen.bindValue(":loggedInUsername", loggedInUsername);
        qryexpen.bindValue(":mon",mon);
        qryexpen.bindValue(":yea",yea);
        qDebug()<<yea;

        if(qryexpen.exec())

        {
            qDebug()<<"monthex"<<mon;
            QSqlQueryModel *modal = new QSqlQueryModel();
            modal->setQuery(qryexpen);
            ui->tableView->setModel(modal);
        }
        else
        {
            qDebug()<<"month"<<mon;
            qDebug()<<qryexpen.lastError().text();

        }
    }
    else
    {
        QMessageBox::critical(this,"Error"," Database Unavailable");
    }

    QSqlQuery expensum;
    expensum.prepare("SELECT SUM(amount) FROM expense "
                     "WHERE username =:loggedInUsername AND monthx=:mon AND yearx=:yea");
    expensum.bindValue(":loggedInUsername", loggedInUsername);
   expensum.bindValue(":mon",mon);
   expensum.bindValue(":yea",yea);

    if(expensum.exec())
    {
        if (expensum.next())
        {
            QVariant result = expensum.value(0);
            if (!result.isNull())
            {
                sumamtexp = result.toDouble();
                qDebug()<<"sum"<<sumamtexp;

                ui->amtlabel->setText( QString::number(sumamtexp));
            }

    }
}
    }
}


void Reports::on_pushButton_3_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/sande/SQLITE/PROJECT.db");

    if(db.open())
    {
        QSqlQuery qryexp;
        qryexp.prepare("SELECT sum(amount) FROM expense WHERE username=:loggedInUserName");
        qryexp.bindValue(":loggedInUserName",loggedInUsername);
        if(qryexp.exec())
        {
            if (qryexp.next())
            {
                QVariant result = qryexp.value(0);
                sumexp = result.toDouble();
            }
        }
        else
        {
            qDebug()<<qryexp.lastError().text();
        }

        QSqlQuery qryinctot;
        qryinctot.prepare("SELECT sum(amount) FROM income WHERE username=:loggedInUserName");
        qryinctot.bindValue(":loggedInUserName",loggedInUsername);
        if(qryinctot.exec())
        {
            if (qryinctot.next())
            {
                QVariant result = qryinctot.value(0);
                suminc = result.toDouble();
                bal=suminc-sumexp;
                QString bala = QString :: number(bal);
                QMessageBox::information(this,"Balance","Your Balance is "+bala);
            }
        }
        else
        {
            qDebug()<<qryinctot.lastError().text();
        }
    }


}



void Reports::on_pushButton_4_clicked()
{

    Charts chart;
    chart.setModal(true);
    chart.exec();


}


void Reports::on_pushButton_5_clicked()
{
    QSqlQuery incsum;
    incsum.prepare("SELECT SUM(amount) FROM income "
                   "WHERE username =:loggedInUsername AND monthx=:mon AND yearx=:yea");
    incsum.bindValue(":loggedInUsername", loggedInUsername);
    incsum.bindValue(":mon",mon);
    incsum.bindValue(":yea",yea);
    if(incsum.exec())
    {
        if (incsum.next())
        {
            QVariant result = incsum.value(0);
            if (!result.isNull())
            {
                sumamtinc1 = result.toDouble();
            }
        }
    }

    QSqlQuery expensum;
    expensum.prepare("SELECT SUM(amount) FROM expense "
                     "WHERE username =:loggedInUsername AND monthx=:mon AND yearx=:yea");
    expensum.bindValue(":loggedInUsername", loggedInUsername);
    expensum.bindValue(":mon",mon);
    expensum.bindValue(":yea",yea);

    if(expensum.exec())
    {
        if (expensum.next())
        {
            QVariant result = expensum.value(0);
            if (!result.isNull())
            {
                sumamtexp1 = result.toDouble();
            }
        }
    }

    curmonbal=sumamtinc1-sumamtexp1;
     QString curmonbala = QString :: number(curmonbal);
    QMessageBox::information(this,"Balance","Your balance is "+curmonbala);
}

