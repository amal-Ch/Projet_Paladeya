#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connexion.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connexion c;
     c.ouvrirconnexion();
    //affichage contenu base
    show_tables();

    update_list();
}

MainWindow::~MainWindow()
{
    delete ui;
}


//affichage + metier tri
void MainWindow::show_tables(){
    //abonement
//creation model (masque du tableau) : permet recherche et tri
    proxy = new
            QSortFilterProxyModel();

 //definir la source (tableau original)
    proxy->setSourceModel(tmpab.afficher());

 //pour la recherche
    proxy->setFilterCaseSensitivity(Qt::CaseInsensitive); // S=s (pas de difference entre majuscule et minuscule)
    proxy->setFilterKeyColumn(selcomab); // chercher dans tout le tableau (-1) ou donner le numero de la colone
   //remplissage tableau avec le masque
    ui->tableView->setModel(proxy);

    //municipalite

    //creation model (masque du tableau) : permet recherche et tri
        proxym = new QSortFilterProxyModel();

     //definir la source (tableau original)
        proxym->setSourceModel(tmpm.afficher());

       //remplissage tableau avec le masque
        ui->tableView_2->setModel(proxym);

}

//recherche text changed
void MainWindow::on_lineEdit_4_textChanged(const QString &arg1)
{
    proxy->setFilterFixedString(arg1);

}

//recherche combo changed
void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    selcomab=ui->comboBox->currentIndex();
    show_tables();
}

//recuperer l'id
void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    selectedab=ui->tableView->model()->data(index).toInt();

}
void MainWindow::on_tableView_2_clicked(const QModelIndex &index)
{
    selectedm=ui->tableView_2->model()->data(index).toString();

}

//suppression
void MainWindow::on_pushButton_5_clicked()
{
    abonnement a;
  a.supprimer(selectedab);

 //refresh du tableau (affichage)
   show_tables();
}
void MainWindow::on_pushButton_10_clicked()
{
    municipalite m;
  m.supprimer(selectedm);

 //refresh du tableau (affichage)
   show_tables();
   update_list();

}
//export
void MainWindow::on_pushButton_6_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                    tr("Excel Files (*.xls)"));
    if (fileName.isEmpty())
        return;

    ExportExcelObject obj(fileName, "mydata", ui->tableView);

    //colums to export
    obj.addField(0, "id", "char(20)");
    obj.addField(1, "nom", "char(20)");
    obj.addField(2, "prenom", "char(20)");
    obj.addField(3, "debut", "char(20)");
    obj.addField(4, "fin", "char(20)");
    obj.addField(5, "municipalite", "char(20)");


    int retVal = obj.export2Excel();
    if( retVal > 0)
    {
        QMessageBox::information(this, tr("Done"),
                                 QString(tr("%1 records exported!")).arg(retVal)
                                 );
    }
}

//ajout
void MainWindow::on_pushButton_4_clicked()
{
    //recuperation des donnees

      int s1=ui->id->text().toInt();
      QString s2=ui->nom->text();
      QString s3=ui->prenom->text();
      QString s4=ui->debut->date().toString("dd.MM.yyyy");
      QString s5=ui->fin->date().toString("dd.MM.yyyy");
      QString s6=ui->mun->currentText();


      //ajout
      abonnement a(s1,s2,s3,s4,s5,s6);
      a.ajouter();

  //refresh du tableau (affichage)
   show_tables();
}
void MainWindow::on_pushButton_9_clicked()
{
    //recuperation des donnees

      QString s1=ui->nom_2->text();
      QString s2=ui->combo->currentText();
      int s3=ui->nb->value();
      QString s4=ui->prenom_2->text();
      int s5=ui->bureau->value();


      //ajout
      municipalite m(s1,s2,s3,s4,s5);
      m.ajouter();

  //refresh du tableau (affichage)
   show_tables();
   update_list();

}

//remplissage pour modification
void MainWindow::on_tableView_activated(const QModelIndex &index)
{
    int val=ui->tableView->model()->data(index).toInt();
      QSqlQuery qry;
      qry.prepare("select * from ABONNEMENT where  ID= :val");
      qry.bindValue(":val",val);
      if(qry.exec())
        {while (qry.next())
       {
              ui->id->setText(qry.value(0).toString());
         ui->nom->setText(qry.value(1).toString());
         ui->prenom->setText(qry.value(2).toString());
         ui->mun->setCurrentText(qry.value(5).toString());
         ui->debut->setDate(QDate::fromString(qry.value(3).toString(),"dd.MM.yyyy"));
         ui->fin->setDate(QDate::fromString(qry.value(4).toString(),"dd.MM.yyyy"));
          }
    }
}
void MainWindow::on_tableView_2_activated(const QModelIndex &index)
{
    QString val=ui->tableView_2->model()->data(index).toString();
      QSqlQuery qry;
      qry.prepare("select * from MUNICIPALITE where  NOM= :val");
      qry.bindValue(":val",val);
      if(qry.exec())
        {while (qry.next())
       {
         ui->nom_2->setText(qry.value(0).toString());
         ui->prenom_2->setText(qry.value(3).toString());
         ui->nb->setValue(qry.value(2).toInt());
         ui->combo->setCurrentText(qry.value(1).toString());
         ui->bureau->setValue(qry.value(4).toInt());
          }
    }
}

//modification
void MainWindow::on_pushButton_2_clicked()
{
    //recuperation des donnees

      int s1=ui->id->text().toInt();
      QString s2=ui->nom->text();
      QString s3=ui->prenom->text();
      QString s4=ui->debut->date().toString("dd.MM.yyyy");
      QString s5=ui->fin->date().toString("dd.MM.yyyy");
      QString s6=ui->mun->currentText();


      //modif
      abonnement a(s1,s2,s3,s4,s5,s6);
      a.modifier(selectedab);

  //refresh du tableau (affichage)
   show_tables();
}
void MainWindow::on_pushButton_7_clicked()
{
    //recuperation des donnees

      QString s1=ui->nom_2->text();
      QString s2=ui->combo->currentText();
      int s3=ui->nb->value();
      QString s4=ui->prenom_2->text();
      int s5=ui->bureau->value();


      //ajout
      municipalite m(s1,s2,s3,s4,s5);
      m.modifier(selectedm);

  //refresh du tableau (affichage)
   show_tables();
}

void MainWindow::on_pushButton_11_clicked()
{

    s = new statistique();

  s->setWindowTitle("statistique ComboBox");
  s->pie();
  s->show();

}

void MainWindow::update_list()
{
  QSqlQueryModel *m=new QSqlQueryModel();
  QSqlQuery *qry=new QSqlQuery();
  qry->prepare("select NOM from MUNICIPALITE");
  qry->exec();
  m->setQuery(*qry);

}
