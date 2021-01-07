#include "statistique.h"
#include "ui_statistique.h"

statistique::statistique(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistique)
{
    ui->setupUi(this);
}

statistique::~statistique()
{
    delete ui;
}

//pie chart
    void statistique::pie()
    {
    QSqlQuery q1,q2,q3,q4;
    qreal tot=0,c1=0,c2=0,c3=0;

    q1.prepare("SELECT * FROM MUNICIPALITE");
    q1.exec();

    q2.prepare("SELECT * FROM MUNICIPALITE WHERE LOCALISATION='Tunis'");
    q2.exec();

    q3.prepare("SELECT * FROM MUNICIPALITE WHERE LOCALISATION='Ariana'");
    q3.exec();

    q4.prepare("SELECT * FROM MUNICIPALITE WHERE LOCALISATION='Manouba' ");
    q4.exec();

    while (q1.next()){tot++;}
    while (q2.next()){c1++;}
    while (q3.next()){c2++;}
    while (q4.next()){c3++;}

    c1=c1/tot;
    c2=c2/tot;
    c3=c3/tot;

    // Define slices and percentage of whole they take up
    QPieSeries *series = new QPieSeries();
    series->append("Tunis",c1);
    series->append("Ariana",c2);
    series->append("Manouba",c3);




    // Create the chart widget
    QChart *chart = new QChart();

    // Add data to chart with title and show legend
    chart->addSeries(series);
    chart->legend()->show();


    // Used to display the chart
    chartView = new QChartView(chart,ui->label);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(400,400);

    chartView->show();
    }

