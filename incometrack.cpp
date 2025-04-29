#include "incometrack.h"
#include "ui_incometrack.h"
#include "mainwindow2.h"

Incometrack::Incometrack(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Incometrack)
{
    ui->setupUi(this);
}

Incometrack::~Incometrack()
{
    delete ui;
}

void Incometrack::on_pushButton_clicked()
{
   QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/sande/SQLITE/PROJECT.db");


    QString IncMethod = ui->incomeline->text();
    QString IncAmt = ui->incamtline->text();



}

