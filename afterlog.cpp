#include "afterlog.h"
#include "ui_afterlog.h"

AfterLog::AfterLog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AfterLog)
{
    ui->setupUi(this);
}

AfterLog::~AfterLog()
{
    delete ui;
}
