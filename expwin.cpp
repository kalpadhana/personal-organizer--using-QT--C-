#include "expwin.h"
#include "ui_expwin.h"
#include "mainwindow.h"
extern QString loggedInUsername;
QString selday2;
double sumamount;
double limvalue = 0;
double balance;
double newbalance;
int selmon;
int selyear;

Expwin::Expwin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Expwin)
{
    ui->setupUi(this);
}

Expwin::~Expwin()
{
    delete ui;
}


void Expwin::on_dateEdit2_userDateChanged(const QDate &date)
{
    selday2 = date.toString("yyyy-MM-dd");
    selmon= date.month();
    selyear=date.year();
   qDebug()<<"selmon"<<selmon;
}

void Expwin::on_addexpense_clicked()
{
    if (selday2.isEmpty())
    {
        QMessageBox::critical(this,"Warning","Please select a date");
    }

    else
    {
        QString expMethod = ui->expensedecline->text();
        QString expAmount = ui->expenseamtline->text();
        QString expensecomboboxtext = ui->expensecombobox->currentText();

        if(expMethod.isEmpty()|| expAmount.isEmpty())
        {
            QMessageBox::information(this,"Warning","Please fill all fields");
        }

        else
        {

        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("C:/Users/sande/SQLITE/PROJECT.db");


        if(db.open())
        {
            //getting total spent amount from a selected category
            QSqlQuery qry11;
            qry11.prepare("SELECT SUM(amount) FROM expense WHERE username=:loggedInUsername AND method=:expensecomboboxtext and monthx=:selmon AND yearx=:selyear");
            qry11.bindValue(":loggedInUsername", loggedInUsername);
            qry11.bindValue(":expensecomboboxtext",expensecomboboxtext);
            qry11.bindValue(":selmon",selmon);
            qry11.bindValue(":selyear",selyear);
            if(qry11.exec())
            {
                if (qry11.next())
                {
                    QVariant result = qry11.value(0);
                    if (!result.isNull())
                    {
                        sumamount = result.toDouble();
                        qDebug()<<"sum"<<sumamount;
                    }

                }
                 else
                {
                    qDebug()<<"Error"<<qry11.lastError().text();
                }
            }

            //Getting the value of the limit in selected category

            QSqlQuery qry12;
            qry12.prepare("SELECT amount FROM budget WHERE category=:expensecomboboxtext");
            qry12.bindValue(":expensecomboboxtext",expensecomboboxtext);
            if(qry12.exec())
            {
                if(qry12.next())

                {
                QVariant limitvalue = qry12.value(0);
                limvalue=limitvalue.toDouble();
                }

            }

            if(limvalue==0)
            {
                QSqlQuery qry2;

                qry2.prepare("INSERT INTO expense (username,day,method,description,amount,monthx,yearx) "
                             "VALUES (:loggedInUsername,:selday2,:expensecomboboxtext,:expMethod,:expAmount,:selmon,:selyear)");
                qry2.bindValue(":loggedInUsername", loggedInUsername);
                qry2.bindValue(":selday2", selday2);
                qry2.bindValue(":expensecomboboxtext",expensecomboboxtext);
                qry2.bindValue(":expMethod", expMethod);
                qry2.bindValue(":expAmount", expAmount);
                qry2.bindValue(":selmon", selmon);
                qry2.bindValue(":selyear",selyear);

                if(qry2.exec())
                {   qDebug()<<"selmon"<<selmon;
                    balance=balance-(expAmount.toDouble());
                    QMessageBox::information(this, "Success",
                                             "Added Successfully \nyou haven't set budget limit for"+expensecomboboxtext);


                    QSqlQueryModel *modal = new QSqlQueryModel();

                    QSqlQuery qry3;
                    qry3.prepare("SELECT day,method,description,amount  FROM expense WHERE username=:loggedInUsername");
                    qry3.bindValue(":loggedInUsername", loggedInUsername);
                    qry3.exec();
                    modal->setQuery(qry3);
                    ui->exptableView->setModel(modal);

                }
                else
                {
                    qDebug()<<"Selyear"<<selyear;
                    qDebug()<<qry2.lastError().text();
                }
            }
            else
            {
            balance = limvalue-sumamount;

            if(balance-expAmount.toDouble()<0)
            {
                qDebug()<<"lim value"<<limvalue;
                qDebug()<<"sumamount"<<sumamount;
                QMessageBox::critical(this,"Caution","Your Budget Limit is reached for this month\nYour available balance is Rs. "+QString::number( balance) );
            }

            else
            {
                qDebug()<<"lim value"<<limvalue;
                qDebug()<<"sumamount"<<sumamount;

                //If user has enough balance add to the expense list
                QSqlQuery qry2;

                qry2.prepare("INSERT INTO expense (username,day,method,description,amount,monthx,yearx) "
                             "VALUES (:loggedInUsername,:selday2,:expensecomboboxtext,:expMethod,:expAmount,:selmon,:selyear)");
                qry2.bindValue(":loggedInUsername", loggedInUsername);
                qry2.bindValue(":selday2", selday2);
                qry2.bindValue(":expensecomboboxtext",expensecomboboxtext);
                qry2.bindValue(":expMethod", expMethod);
                qry2.bindValue(":expAmount", expAmount);
                qry2.bindValue(":selmon", selmon);
                qry2.bindValue(":selyear",selyear);

                if(qry2.exec())
                {
                    balance=balance-(expAmount.toDouble());
                    QMessageBox::information(this, "Success",
                                             "Added Successfully, \nYour remaining balance for this month " + expensecomboboxtext + " is Rs.  " + QString::number(balance));


                        QSqlQueryModel *modal = new QSqlQueryModel();

                        QSqlQuery qry3;
                        qry3.prepare("SELECT day,method,description,amount  FROM expense WHERE username=:loggedInUsername");
                        qry3.bindValue(":loggedInUsername", loggedInUsername);
                        qry3.exec();
                        modal->setQuery(qry3);
                        ui->exptableView->setModel(modal);

                }
            }

            }

        }

    }


    }


}








void Expwin::on_exploadexp_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/sande/SQLITE/PROJECT.db");
    if(db.open())
    {

        QSqlQueryModel *modal = new QSqlQueryModel();

        QSqlQuery qry3;
        qDebug()<<loggedInUsername;
        qry3.prepare("SELECT day,method,description,amount  FROM expense WHERE username=:loggedInUsername ");
        qry3.bindValue(":loggedInUsername",loggedInUsername);
        qry3.exec();
        modal->setQuery(qry3);
        ui->exptableView->setModel(modal);
    }
}



/*
void Expwin::on_expaddmethodbtn_clicked()
{
    QString addmethod = ui->expmethodline->text();
    ui->expensecombobox->addItem(addmethod);
}
*/
