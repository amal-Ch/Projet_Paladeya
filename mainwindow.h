#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include"abonnement.h"
#include "exportexcelobject.h"
#include <QMessageBox>
#include <QFileDialog>
#include "municipalite.h"
#include "statistique.h"


QT_BEGIN_NAMESPACE

namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



    void show_tables();
    void update_list();


private slots:
    void on_lineEdit_4_textChanged(const QString &arg1);

    void on_comboBox_currentIndexChanged(int index);

    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_2_clicked();

    void on_tableView_2_clicked(const QModelIndex &index);

    void on_pushButton_10_clicked();

    void on_pushButton_9_clicked();

    void on_tableView_2_activated(const QModelIndex &index);

    void on_pushButton_7_clicked();

    void on_pushButton_11_clicked();

private:
    Ui::MainWindow *ui;
int selectedab=0;
    int selcomab=0;
    QSortFilterProxyModel *proxy, *proxym;
QString selectedm="sel";
    abonnement tmpab;
    municipalite tmpm;
    statistique *s;

};
#endif // MAINWINDOW_H
