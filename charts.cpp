#include "charts.h"
#include "ui_charts.h"
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QMap>
#include <QDate>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QChart>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QDebug>
#include <QtCharts>
#include <QChartView>

int mont1,yearr1;
extern QString loggedInUsername;

Charts::Charts(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Charts)
{
    ui->setupUi(this);
    int mont;
    int yearr;
    QDate currentDate = QDate::currentDate();
    QString currentDateString = currentDate.toString("yyyy-MM-dd");
    mont = currentDate.month();
    yearr = currentDate.year();
    QString montstr = QString::number(mont);
    QString yearrstr = QString::number(yearr);


    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/sande/SQLITE/PROJECT.db");

    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", "Unable to open database. Please check the database path.");
        return;
    }


    QSqlQuery qryExpenses;
    qryExpenses.prepare("SELECT method, SUM(amount) FROM expense WHERE username=:loggedInUsername AND monthx=:mont AND yearx=:yearr GROUP BY method");
    qryExpenses.bindValue(":loggedInUsername", loggedInUsername);

    qryExpenses.bindValue(":mont",mont);
    qryExpenses.bindValue(":yearr",yearr);

    QMap<QString, double> expensesMap;

    if (!qryExpenses.exec()) {
        QMessageBox::critical(this, "SQL Error", "Failed to execute expenses query");
        return;
    }


    while (qryExpenses.next()) {
        QString method = qryExpenses.value(0).toString();
        double spentAmount = qryExpenses.value(1).toDouble();
        expensesMap[method] = spentAmount;
    }


    QSqlQuery qryBudget;
    qryBudget.prepare("SELECT category, amount FROM budget WHERE username=:loggedInUsername");
    qryBudget.bindValue(":loggedInUsername", loggedInUsername);


    QMap<QString, double> budgetMap;

    if (!qryBudget.exec()) {
        QMessageBox::critical(this, "SQL Error", "Failed to execute budget query");
        return;
    }


    while (qryBudget.next()) {
        QString category = qryBudget.value(0).toString();
        double budgetAmount = qryBudget.value(1).toDouble();
        budgetMap[category] = budgetAmount;
    }

    QBarSeries *series = new QBarSeries();

    for (auto it = expensesMap.begin(); it != expensesMap.end(); ++it) {
        QString category = it.key();
        double spentAmount = it.value();
        double budgetAmount = budgetMap.value(category, 0.0);
        double remainingBalance = budgetAmount - spentAmount;


        qDebug() << "Category:" << category << "Spent:" << spentAmount << "Remaining:" << remainingBalance;


        QBarSet *spentSet = new QBarSet("Spent: " + category);
        QBarSet *remainingSet = new QBarSet("Remaining: " + category);


        *spentSet << spentAmount;
        *remainingSet << remainingBalance;


        series->append(spentSet);
        series->append(remainingSet);
    }


    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Expenses vs. Budget for " +yearrstr +montstr);
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append("Spends and Remains");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, *std::max_element(expensesMap.begin(), expensesMap.end()) + 10);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);


    QChartView *chartview = new QChartView(chart);
    chartview->setRenderHint(QPainter::Antialiasing);
    chartview->setVisible(true);

    ui->verticalLayout->addWidget(chartview);
}

Charts::~Charts()
{
    delete ui;
}


void Charts::on_dateEdit_userDateChanged(const QDate &date)
{
    mont1 = date.month();
    yearr1 = date.year();
}


void Charts::on_pushButton_clicked()
{

    QString mont1str = QString::number(mont1);
    QString yearr1str = QString::number(yearr1);


    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/sande/SQLITE/PROJECT.db");

    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", "Unable to open database. Please check the database path.");
        return;
    }


    QSqlQuery qryExpenses;
    qryExpenses.prepare("SELECT method, SUM(amount) FROM expense WHERE username=:loggedInUsername AND monthx=:mont1 AND yearx=:yearr1 GROUP BY method");
    qryExpenses.bindValue(":loggedInUsername", loggedInUsername);

    qryExpenses.bindValue(":mont1",mont1);
    qryExpenses.bindValue(":yearr1",yearr1);

    QMap<QString, double> expensesMap;

    if (!qryExpenses.exec()) {
        QMessageBox::critical(this, "SQL Error", "Failed to execute expenses query");
        return;
    }


    while (qryExpenses.next()) {
        QString method = qryExpenses.value(0).toString();
        double spentAmount = qryExpenses.value(1).toDouble();
        expensesMap[method] = spentAmount;
    }


    QSqlQuery qryBudget;
    qryBudget.prepare("SELECT category, amount FROM budget WHERE username=:loggedInUsername");
    qryBudget.bindValue(":loggedInUsername", loggedInUsername);


    QMap<QString, double> budgetMap;

    if (!qryBudget.exec()) {
        QMessageBox::critical(this, "SQL Error", "Failed to execute budget query");
        return;
    }


    while (qryBudget.next()) {
        QString category = qryBudget.value(0).toString();
        double budgetAmount = qryBudget.value(1).toDouble();
        budgetMap[category] = budgetAmount;
    }


    QBarSeries *series = new QBarSeries();


    for (auto it = expensesMap.begin(); it != expensesMap.end(); ++it) {
        QString category = it.key();
        double spentAmount = it.value();
        double budgetAmount = budgetMap.value(category, 0.0);
        double remainingBalance = budgetAmount - spentAmount;


        qDebug() << "Category:" << category << "Spent:" << spentAmount << "Remaining:" << remainingBalance;


        QBarSet *spentSet = new QBarSet("Spent: " + category);
        QBarSet *remainingSet = new QBarSet("Remaining: " + category);


        *spentSet << spentAmount;
        *remainingSet << remainingBalance;


        series->append(spentSet);
        series->append(remainingSet);
    }


    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Expenses vs. Budget for " +yearr1str +mont1str);
    chart->setAnimationOptions(QChart::SeriesAnimations);


    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append("Spends and Remains");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, *std::max_element(expensesMap.begin(), expensesMap.end()) + 10);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QChartView *chartview = new QChartView(chart);
    chartview->setRenderHint(QPainter::Antialiasing);
    chartview->setVisible(true);

    if(!ui->verticalLayout_2->isEmpty())
    {
        QMessageBox::information(this,"Sorry","You have to go back main window and regenerate to view new bar chart");

    }
    else
    {ui->verticalLayout_2->addWidget(chartview);}
}



