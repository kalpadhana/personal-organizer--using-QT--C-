#ifndef AFTERLOG_H
#define AFTERLOG_H

#include <QDialog>

namespace Ui {
class AfterLog;
}

class AfterLog : public QDialog
{
    Q_OBJECT

public:
    explicit AfterLog(QWidget *parent = nullptr);
    ~AfterLog();

private:
    Ui::AfterLog *ui;
};

#endif // AFTERLOG_H
