#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit  MainWindow(QWidget *empl= nullptr);
    ~MainWindow();

private slots:

    void on_ajouter_clicked();

    void on_supprimer_clicked();

    void on_afficher_clicked();

    void on_ajouterE_clicked();

    void on_afficherE_clicked();

    void on_supprimerE_clicked();

private:
    Ui::MainWindow *ui;
    equipement temequipement;
    fournisseur temfournisseur;
};
#endif // MAINWINDOW_H
