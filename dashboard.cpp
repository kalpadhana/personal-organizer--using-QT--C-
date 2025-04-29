#include "dashboard.h"
#include "ui_dashboard.h"
#include "dialog.h"
#include "expwin.h"
#include "categorybudgeting.h"
#include "reports.h"
#include "schedule.h"

Dashboard::Dashboard(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dashboard)
{
    ui->setupUi(this);
}

Dashboard::~Dashboard()
{
    delete ui;
}

void Dashboard::on_pushButton_clicked()
{
    Dialog dialog;
    dialog.setModal(true);
    dialog.exec();
}


void Dashboard::on_pushButton_2_clicked()
{
    Expwin expwin;
    expwin.setModal(true);
    expwin.exec();
}


void Dashboard::on_pushButton_3_clicked()
{
    categorybudgeting cb;
    cb.setModal(true);
    cb.exec();

}




void Dashboard::on_reportbtn_clicked()
{
    Reports rep;
    rep.setModal(true);
    rep.exec();
}


void Dashboard::on_reportbtn_2_clicked()
{
    Schedule sch;
    sch.setModal(true);
    sch.exec();

}

