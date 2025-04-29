#include "schedule.h"
#include "ui_schedule.h"
extern QString loggedInUsername;
QString starttime,endtime,desc,lecday,selday3,timetableday;
QDate selectedday,today,tod;

Schedule::Schedule(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Schedule)
{
    tod=QDate::currentDate();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/sande/SQLITE/PROJECT.db");
    if (db.open()) {
        QSqlQuery qry2;
        qry2.prepare("SELECT Description  FROM schedule "
                     "WHERE usern=:loggedInUsername AND day=:tod ");
        qry2.bindValue(":loggedInUsername",loggedInUsername);
        qry2.bindValue(":tod",tod);
        if(qry2.exec())
        {
            if (qry2.next()) {

                QMessageBox::information(this,"Important","You have taskes scheduled for today");
            }
        }
    }
    ui->setupUi(this);
}

Schedule::~Schedule()
{
    delete ui;
}


void Schedule::on_dateEdit_userDateChanged(const QDate &date)
{

}



void Schedule::on_pushButton_clicked()
{   
}


void Schedule::on_timetableadd_clicked()
{
    starttime=ui->starttime->text();
    endtime=ui->endtime->text();
    desc=ui->descline->text();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/sande/SQLITE/PROJECT.db");
    timetableday = ui->datesbox->currentText();
    if(db.open())
    {

        if (timetableday=="Monday")
        {
            QSqlQuery qrytue;
            qrytue.prepare("INSERT INTO timetable(username,Start_Time,End_Time,date,Monday) "
                           "VALUES(:loggedInUsername,:starttime,:endtime,:timetableday,:desc)"
                           );
            qrytue.bindValue(":loggedInUsername",loggedInUsername);
            qrytue.bindValue(":starttime",starttime);
            qrytue.bindValue(":endtime",endtime);
            qrytue.bindValue(":timetableday",timetableday);
            qrytue.bindValue(":desc",desc);
            if(qrytue.exec())
            {QMessageBox::information(this,"Sucess","Added");}
            else
            {
                qDebug()<<qrytue.lastError().text();
            }
        }
    else if (timetableday=="Tuesday")
    {
        QSqlQuery qrytue;
        qrytue.prepare("INSERT INTO timetable(username,Start_Time,End_Time,date,Tuesday) "
                       "VALUES(:loggedInUsername,:starttime,:endtime,:timetableday,:desc)"
                       );
        qrytue.bindValue(":loggedInUsername",loggedInUsername);
        qrytue.bindValue(":starttime",starttime);
        qrytue.bindValue(":endtime",endtime);
        qrytue.bindValue(":timetableday",timetableday);
        qrytue.bindValue(":desc",desc);
        if(qrytue.exec())
        {QMessageBox::information(this,"Sucess","Added");}
        else
        {
            qDebug()<<qrytue.lastError().text();
        }
    }
    else if (timetableday=="Wednesday")
    {
        QSqlQuery qrytue;
        qrytue.prepare("INSERT INTO timetable(username,Start_Time,End_Time,date,Wednesday) "
                       "VALUES(:loggedInUsername,:starttime,:endtime,:timetableday,:desc)"
                       );
        qrytue.bindValue(":loggedInUsername",loggedInUsername);
        qrytue.bindValue(":starttime",starttime);
        qrytue.bindValue(":endtime",endtime);
        qrytue.bindValue(":timetableday",timetableday);
        qrytue.bindValue(":desc",desc);
        if(qrytue.exec())
        {QMessageBox::information(this,"Sucess","Added");}
        else
        {
            qDebug()<<qrytue.lastError().text();
        }
    }
        else if (timetableday=="Thursday")
        {
            QSqlQuery qrytue;
            qrytue.prepare("INSERT INTO timetable(username,Start_Time,End_Time,date,Thursday) "
                           "VALUES(:loggedInUsername,:starttime,:endtime,:timetableday,:desc)"
                           );
            qrytue.bindValue(":loggedInUsername",loggedInUsername);
            qrytue.bindValue(":starttime",starttime);
            qrytue.bindValue(":endtime",endtime);
            qrytue.bindValue(":timetableday",timetableday);
            qrytue.bindValue(":desc",desc);
            if(qrytue.exec())
            {QMessageBox::information(this,"Sucess","Added");}
            else
            {
                qDebug()<<qrytue.lastError().text();
            }
        }
    else if (timetableday=="Friday")
    {
        QSqlQuery qrytue;
        qrytue.prepare("INSERT INTO timetable(username,Start_Time,End_Time,date,Friday) "
                       "VALUES(:loggedInUsername,:starttime,:endtime,:timetableday,:desc)"
                       );
        qrytue.bindValue(":loggedInUsername",loggedInUsername);
        qrytue.bindValue(":starttime",starttime);
        qrytue.bindValue(":endtime",endtime);
         qrytue.bindValue(":timetableday",timetableday);
        qrytue.bindValue(":desc",desc);
        if(qrytue.exec())
        {QMessageBox::information(this,"Sucess","Added");}
        else
        {
            qDebug()<<qrytue.lastError().text();
        }
    }

    }
    else
    {
        QMessageBox::critical(this,"Error","Database Unavailable");
    }


}


void Schedule::on_viewbyday_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/sande/SQLITE/PROJECT.db");

    if (db.open()) {

       QString viewday = ui->viewdaybox->currentText();
        if(viewday=="Monday")
       {
           QSqlQuery qryviewtt;
           qryviewtt.prepare("SELECT Start_time, End_time,Monday  FROM timetable "
                             "WHERE username=:loggedInUsername AND date=:viewday");
           qryviewtt.bindValue(":loggedInUsername",loggedInUsername);
           qryviewtt.bindValue(":viewday",viewday);

           if(qryviewtt.exec())
           {
               QSqlQueryModel *modal = new QSqlQueryModel();
               modal->setQuery(qryviewtt);
               ui->ttview->setModel(modal);
           }
           else
           {
               qDebug()<<qryviewtt.lastError().text();
           }
       }
        else if(viewday=="Tuesday")
        {
            QSqlQuery qryviewtt;
            qryviewtt.prepare("SELECT Start_time, End_time,Tuesday  FROM timetable "
                              "WHERE username=:loggedInUsername AND date=:viewday");
            qryviewtt.bindValue(":loggedInUsername",loggedInUsername);
            qryviewtt.bindValue(":viewday",viewday);

            if(qryviewtt.exec())
            {
                QSqlQueryModel *modal = new QSqlQueryModel();
                modal->setQuery(qryviewtt);
                ui->ttview->setModel(modal);
            }
            else
            {
                qDebug()<<qryviewtt.lastError().text();
            }
        }
        else if(viewday=="Wednesday")
        {
            QSqlQuery qryviewtt;
            qryviewtt.prepare("SELECT Start_time, End_time,Wednesday  FROM timetable "
                              "WHERE username=:loggedInUsername AND date=:viewday");
            qryviewtt.bindValue(":loggedInUsername",loggedInUsername);
            qryviewtt.bindValue(":viewday",viewday);

            if(qryviewtt.exec())
            {
                QSqlQueryModel *modal = new QSqlQueryModel();
                modal->setQuery(qryviewtt);
                ui->ttview->setModel(modal);
            }
            else
            {
                qDebug()<<qryviewtt.lastError().text();
            }
        }
        else if(viewday=="Thursday")
        {
            QSqlQuery qryviewtt;
            qryviewtt.prepare("SELECT Start_time, End_time,Thursday  FROM timetable "
                              "WHERE username=:loggedInUsername AND date=:viewday");
            qryviewtt.bindValue(":loggedInUsername",loggedInUsername);
            qryviewtt.bindValue(":viewday",viewday);

            if(qryviewtt.exec())
            {
                QSqlQueryModel *modal = new QSqlQueryModel();
                modal->setQuery(qryviewtt);
                ui->ttview->setModel(modal);
            }
            else
            {
                qDebug()<<qryviewtt.lastError().text();
            }
        }
        else if(viewday=="Friday")
        {
            QSqlQuery qryviewtt;
            qryviewtt.prepare("SELECT Start_time, End_time,Friday  FROM timetable "
                              "WHERE username=:loggedInUsername AND date=:viewday");
            qryviewtt.bindValue(":loggedInUsername",loggedInUsername);
            qryviewtt.bindValue(":viewday",viewday);

            if(qryviewtt.exec())
            {
                QSqlQueryModel *modal = new QSqlQueryModel();
                modal->setQuery(qryviewtt);
                ui->ttview->setModel(modal);
            }
            else
            {
                qDebug()<<qryviewtt.lastError().text();
            }
        }
        else if(viewday=="week")
        {
            QSqlQuery qryviewtt;
            qryviewtt.prepare("SELECT Start_time, End_time,Monday,Tuesday,Wednesday,Thursday,Friday  FROM timetable "
                              "WHERE username=:loggedInUsername ");
            qryviewtt.bindValue(":loggedInUsername",loggedInUsername);

            if(qryviewtt.exec())
            {
                QSqlQueryModel *modal = new QSqlQueryModel();
                modal->setQuery(qryviewtt);
                ui->ttview->setModel(modal);
            }
            else
            {
                qDebug()<<qryviewtt.lastError().text();
            }
        }

    }
    else
    {
        QMessageBox::critical(this,"Error","Database Unavailable");
    }
}


void Schedule::on_viewdateline_userDateChanged(const QDate &date)
{
}

void Schedule::on_tododate_userDateChanged(const QDate &date)
{
    selday3=date.toString("yyyy-MM-dd");
   //QDate selectedday = ui->tododate->date();
    selectedday=date;
     today=QDate::currentDate();
    qDebug()<<selday3;
     qDebug()<<selectedday;
      qDebug()<<today;

}


void Schedule::on_todobtn_clicked()
{
    if(selday3.isEmpty())
        QMessageBox::critical(this,"Error","Please select a date");

    else
    {

    desc= ui->todoline->text();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/sande/SQLITE/PROJECT.db");

    if(selectedday<today)
    { QMessageBox::critical(this,"Error","Sorry you can't time travel");}
    else
    {

    if (db.open()) {
        QSqlQuery qry1;
        qry1.prepare("INSERT INTO schedule (usern,Day,Description)"
                     "VALUES(:loggedInUsername,:selday3,:desc)"
                     );
        qry1.bindValue(":loggedInUsername",loggedInUsername);
        qry1.bindValue(":selday3",selday3);
        qry1.bindValue(":desc",desc);



        if(qry1.exec())

        {
            QMessageBox::information(this,"Sucess","Sucessfully Added");
        }
        else
        {
            qDebug()<<"Error"<<qry1.lastError().text();
        }
        }
    else
    {
        QMessageBox::critical(this,"Error","Database Unavailable");
    }
    }
    }





}


void Schedule::on_viewtodo_clicked()
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/sande/SQLITE/PROJECT.db");

    if (db.open()) {
        QSqlQuery qry2;
        qry2.prepare("SELECT  day,Description  FROM schedule "
                     "WHERE usern=:loggedInUsername AND day>=:tod ORDER BY day ASC");
        qry2.bindValue(":loggedInUsername",loggedInUsername);
        qry2.bindValue(":tod",tod);


        if(qry2.exec())
        {
            QSqlQueryModel *modal = new QSqlQueryModel();
            modal->setQuery(qry2);
            ui->tableView->setModel(modal);
        }
        else
        {
            qDebug()<<qry2.lastError().text();
        }

    }
    else
    {
        QMessageBox::critical(this,"Error","Database Unavailable");
    }

    if (db.open()) {
        QSqlQuery qry2;
        qry2.prepare("SELECT Description  FROM schedule "
                     "WHERE usern=:loggedInUsername AND day=:tod ");
        qry2.bindValue(":loggedInUsername",loggedInUsername);
        qry2.bindValue(":tod",tod);
        if(qry2.exec())
        {
            QSqlQueryModel *modal = new QSqlQueryModel();
            modal->setQuery(qry2);
            ui->imptable->setModel(modal);
            }
        }



    if (db.open())
    {

        QDate tomorrowDate = QDate::currentDate().addDays(1);
        qDebug()<<tomorrowDate;
        QSqlQuery qry3;
        qry3.prepare("SELECT  Description  FROM schedule "
                     "WHERE usern=:loggedInUsername AND day=:tomorrowDate ");
        qry3.bindValue(":loggedInUsername",loggedInUsername);
        qry3.bindValue(":tomorrowDate",tomorrowDate);


        if(qry3.exec())
        {
            QSqlQueryModel *modal = new QSqlQueryModel();
            modal->setQuery(qry3);
            ui->tmrtble->setModel(modal);
        }
        else
        {
            qDebug()<<qry3.lastError().text();
        }

    }
    else
    {
        QMessageBox::critical(this,"Error","Database Unavailable");
    }

}




