#ifndef CHARTS_H
#define CHARTS_H

#include <QDialog>
#include <QtCharts>

namespace Ui {
class Charts;
}

class Charts : public QDialog
{
    Q_OBJECT

public:
    explicit Charts(QWidget *parent = nullptr);
    ~Charts();

    void updateChart(); // Function to update the chart

private slots:
//void on_pushButton_clicked();

    void on_pushButton_clicked();

    void on_dateEdit_userDateChanged(const QDate &date);

private:
    Ui::Charts *ui;
    void createChart(const QMap<QString, double>& expensesMap, const QMap<QString, double>& budgetMap);

    // Make chartView a member variable to avoid recreating it every time
    QChartView *chartView;
};

#endif // CHARTS_H
