#include "gestiondesproduits.h"
#include "ui_gestiondesproduits.h"

GestionDesProduits::GestionDesProduits(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GestionDesProduits)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/ASUS/Desktop/2021-2022/Projects/C++Qt/Projects/Gestion Des Produits/F.jpg");
    ui->IMG->setPixmap(pix.scaled(1200,700,Qt::KeepAspectRatio));
    ui->dateEdit->setDateTime(QDateTime::currentDateTime());
    ui->dateEdit_3->setDateTime(QDateTime::currentDateTime());

    ui->dateEdit_2->setTime(QTime::currentTime());
    ui->dateEdit_4->setTime(QTime::currentTime());


#define NOM_RX "^([A-z]+[,.]?[ ]?|[A-z]+['-]?)+$"
    QRegExp rxNom(NOM_RX);
    QRegExpValidator*valiNom= new QRegExpValidator(rxNom,this);

#define PRIX_RX "^([0-9]+[,.]?[ ]?|[0-9]+['-]?)+$"
    QRegExp rxPrix(PRIX_RX);
    QRegExpValidator*valiPrix= new QRegExpValidator(rxPrix,this);

    ui->lineEdit_01->setValidator(new QIntValidator(0,999999,this));
    ui->lineEdit_02->setValidator(valiNom);
    ui->lineEdit_03->setValidator(valiPrix);
    ui->lineEdit_04->setValidator(new QIntValidator(0,999999,this));
    ui->lineEdit_05->setValidator(valiNom);
    ui->lineEdit_06->setValidator(valiPrix);
    ui->lineEdit_07->setValidator(new QIntValidator(0,999999,this));

    ui->tableView->setModel(G.afficher());
    ui->comboBox_01->setModel(G.afficher());
    ui->comboBox_02->setModel(G.afficher());

    GDP G;
}
GestionDesProduits::~GestionDesProduits()
{
    delete ui;
}

void GestionDesProduits::on_Quitter_clicked()
{
    close();
}

void GestionDesProduits::on_Ajouter_clicked()
{
        int ID_PRODUIT=ui->lineEdit_01->text().toInt();
        QString NOM_PRODUIT=ui->lineEdit_02->text();
        QDate DATE_PRODUCTION=ui->dateEdit->date();
        QDate DATE_EXPIRATION=ui->dateEdit_2->date();
        qreal PRIX=ui->lineEdit_03->text().toDouble();
        int QUANTITE=ui->lineEdit_04->text().toInt();

        GDP G(ID_PRODUIT,NOM_PRODUIT,DATE_PRODUCTION,DATE_EXPIRATION,PRIX,QUANTITE);


        if(ui->lineEdit_01->text().isEmpty()||ui->lineEdit_02->text().isEmpty()||ui->dateEdit->date().isNull()||ui->dateEdit_2->date().isNull()||ui->lineEdit_03->text().isEmpty()||ui->lineEdit_04->text().isEmpty())
        {
            QMessageBox::information(nullptr, QObject::tr("ERROR"),
            QObject::tr("Please Fill All Data"), QMessageBox::Ok);
        }
        else
        {
         bool test=G.ajouter();
         if(test)
         {
             QMessageBox::information(nullptr, QObject::tr("DONE"),
             QObject::tr("Added Successfully !"), QMessageBox::Ok);
         }
         else
         {
             QMessageBox::critical(nullptr, QObject::tr("ERROR"),
             QObject::tr("Add Failed !"), QMessageBox::Ok);
         }
        }
        ui->tableView->setModel(G.afficher());
        ui->comboBox_01->setModel(G.afficher());
        ui->comboBox_02->setModel(G.afficher());
}

void GestionDesProduits::on_Modifier_clicked()
{
    int ID_PRODUIT=ui->comboBox_01->currentText().toInt();
    QString NOM_PRODUIT=ui->lineEdit_05->text();
    QDate DATE_PRODUCTION=ui->dateEdit_3->date();
    QDate DATE_EXPIRATION=ui->dateEdit_4->date();
    qreal PRIX=ui->lineEdit_06->text().toDouble();
    int QUANTITE=ui->lineEdit_07->text().toInt();

    GDP G(ID_PRODUIT,NOM_PRODUIT,DATE_PRODUCTION,DATE_EXPIRATION,PRIX,QUANTITE);

    if(ui->comboBox_01->currentText().isEmpty()||ui->lineEdit_05->text().isEmpty()||ui->dateEdit_3->text().isEmpty()||ui->dateEdit_4->text().isEmpty()||ui->lineEdit_06->text().isEmpty()||ui->lineEdit_07->text().isEmpty())
    {
        QMessageBox::information(nullptr, QObject::tr("ERROR"),
        QObject::tr("Please Fill All Data"), QMessageBox::Ok);
    }
    else
    {
     bool test=G.modifier(ID_PRODUIT);
     if(test)
     {
         QMessageBox::information(nullptr, QObject::tr("DONE"),
         QObject::tr("Modified Successfully !"), QMessageBox::Ok);
     }
     else
     {
         QMessageBox::critical(nullptr, QObject::tr("ERROR"),
         QObject::tr("Modification Failed !"), QMessageBox::Ok);
     }
    }
    ui->tableView->setModel(G.afficher());
    ui->comboBox_01->setModel(G.afficher());
    ui->comboBox_02->setModel(G.afficher());
}

void GestionDesProduits::on_Supprimer_clicked()
{
    GDP G;
       G.setid(ui->comboBox_02->currentText().toInt());

       if(ui->comboBox_02->currentText().isEmpty())
       {
           QMessageBox::information(nullptr, QObject::tr("ERROR"),
           QObject::tr("No 'ID' Selected"), QMessageBox::Ok);
       }
       else
       {
       bool test=G.supprimer(G.getid());
       if(test)
       {
          QMessageBox::information(nullptr, QObject::tr("DONE"),
          QObject::tr("Deleted Successfully !"), QMessageBox::Ok);
       }
       else
       {
           QMessageBox::critical(nullptr, QObject::tr("ERROR"),
           QObject::tr("Delete Failed !"), QMessageBox::Ok);
       }
       }
       ui->tableView->setModel(G.afficher());
       ui->comboBox_01->setModel(G.afficher());
       ui->comboBox_02->setModel(G.afficher());
}

void GestionDesProduits::on_TRIN_clicked()
{
    ui->tableView->setModel(G.trie_produitN());
}
void GestionDesProduits::on_TRIQ_clicked()
{
    ui->tableView->setModel(G.trie_produitQ());
}
void GestionDesProduits::on_TRIP_clicked()
{
    ui->tableView->setModel(G.trie_produitP());
}
void GestionDesProduits::on_Chercher_clicked()
{
    if (ui->checkBoxN->isChecked())
    {
        QString nom=ui->lineEdit_08->text();
        QSqlQueryModel *verif=G.chercherN(nom);
        if (verif!=nullptr)
        {
            ui->tableView->setModel(verif);
        }
     }
     if (ui->checkBoxP->isChecked())
     {
        qreal prix=ui->lineEdit_10->text().toDouble();
        QSqlQueryModel *verif=G.chercherP(prix);
        if (verif!=nullptr)
        {
            ui->tableView->setModel(verif);
        }
     }

     if (ui->checkBoxQ->isChecked())
     {
        int quantite=ui->lineEdit_09->text().toInt();
        QSqlQueryModel *verif=G.chercherQ(quantite);
        if (verif!=nullptr)
        {
            ui->tableView->setModel(verif);
        }
     }

     if ((ui->checkBoxQ->isChecked())&&(ui->checkBoxN->isChecked()))
     {
        int quantite=ui->lineEdit_09->text().toInt();
        QString nom=ui->lineEdit_08->text();

                    QSqlQueryModel *verif=G.chercherNQ(nom,quantite);
                    if (verif!=nullptr)
                    {
                        ui->tableView->setModel(verif);
                    }

      }
      if ((ui->checkBoxQ->isChecked())&&(ui->checkBoxP->isChecked()))
      {
        qreal prix=ui->lineEdit_10->text().toDouble();
       int quantite=ui->lineEdit_09->text().toInt();


                    QSqlQueryModel *verif=G.chercherQP(quantite,prix);
                    if (verif!=nullptr)
                    {
                        ui->tableView->setModel(verif);
                    }

       }
       if ((ui->checkBoxN->isChecked())&&(ui->checkBoxP->isChecked()))
       {
       QString nom=ui->lineEdit_08->text();
       qreal prix=ui->lineEdit_10->text().toDouble();


                    QSqlQueryModel *verif=G.chercherNP(nom,prix);
                    if (verif!=nullptr)
                    {
                        ui->tableView->setModel(verif);
                    }

       if ((ui->checkBoxN->isChecked())&&(ui->checkBoxP->isChecked())&&(ui->checkBoxQ->isChecked()))
       {
           QString nom=ui->lineEdit_08->text();
           qreal prix=ui->lineEdit_10->text().toDouble();
           int quantite=ui->lineEdit_09->text().toInt();

                 QSqlQueryModel *verif=G.chercherT(nom,prix,quantite);
                 if (verif!=nullptr)
                 {
                     ui->tableView->setModel(verif);
                 }
        }
 }
}

void GestionDesProduits::on_Reafficher_clicked()
{
    ui->lineEdit_08->setText("");
    ui->lineEdit_09->setText("");
    ui->lineEdit_10->setText("");

    ui->tableView->setModel(G.afficher());
}

void GestionDesProduits::on_PDF_clicked()
{
        QSqlDatabase db;

                    QTableView tableView;
                    QSqlQueryModel * Modal=new  QSqlQueryModel();

                    QSqlQuery qry;
                     qry.prepare("SELECT* FROM GESTION_PRODUIT");
                     qry.exec();
                     Modal->setQuery(qry);
                     tableView.setModel(Modal);

                     db.close();

                     QString strStream;
                     QTextStream out(&strStream);

                     const int rowCount = tableView.model()->rowCount();
                     const int columnCount =  tableView.model()->columnCount();

                     const QString strTitle ="Document";

                     out <<  "<html>\n"
                             "<img src='C:/Users/ASUS/Desktop/2021-2022/Projects/C++Qt/Projects/Gestion Des Produits/SmartParc.png' height='155' width='140'/>"
                         "<head>\n"
                             "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                         <<  QString("<title>%1</title>\n").arg(strTitle)
                         <<  "</head>\n"
                         "<body bgcolor=#ffffff link=#5000A0>\n"
                        << QString("<h3 style=\" font-size: 50px; font-family: Arial, Helvetica, sans-serif; color: #e80e32; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("LISTE DES PRODUITS")
                        <<"<br>"

                        <<"<table border=1 cellspacing=0 cellpadding=2 width=\"100%\">\n";
                     out << "<thead><tr bgcolor=#f0f0f0>";
                     for (int column = 0; column < columnCount; column++)
                         if (!tableView.isColumnHidden(column))
                             out << QString("<th>%1</th>").arg(tableView.model()->headerData(column, Qt::Horizontal).toString());
                     out << "</tr></thead>\n";

                     for (int row = 0; row < rowCount; row++)
                     {
                         out << "<tr>";
                         for (int column = 0; column < columnCount; column++)
                         {
                             if (!tableView.isColumnHidden(column))
                             {
                                 QString data = tableView.model()->data(tableView.model()->index(row, column)).toString().simplified();
                                 out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                             }
                         }
                         out << "</tr>\n";
                     }
                     out <<  "</table>\n"
                             "<br><br>"
                             <<"<br>"
                             <<"<table border=1 cellspacing=0 cellpadding=2>\n";

                         out << "<thead><tr bgcolor=#f0f0f0>";

                             out <<  "</table>\n"

                         "</body>\n"
                         "</html>\n";

                     QTextDocument *Document = new QTextDocument();
                     Document->setHtml(strStream);

                     QPrinter printer;
                     QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                     if (dialog->exec() == QDialog::Accepted)
                     {

                         Document->print(&printer);
                     }
                     printer.setOutputFormat(QPrinter::PdfFormat);
                     printer.setPaperSize(QPrinter::A4);
                     printer.setOutputFileName("/tmp/Produit.pdf");
                     printer.setPageMargins(QMarginsF(15, 15, 15, 15));

                     delete Document;
}

void GestionDesProduits::on_Statistique_clicked()
{
    stat = new statistique(this);
    stat->show();
}

void GestionDesProduits::on_Inserer_IMG_clicked()
{
    QString filename= QFileDialog::getOpenFileName(this,tr("CHOOSE"),"",tr("Images(*.png *.jpg *.jpeg *.bmp *.gif)"));
    if(QString::compare(filename,QString())!=0)
    {
        QImage image;
        bool valid = image.load(filename);
        if(valid)
        {
            image= image.scaledToWidth(ui->IMG_Added->width(), Qt::SmoothTransformation);
            image= image.scaledToHeight(ui->IMG_Added->height(), Qt::SmoothTransformation);
            ui->IMG_Added->setPixmap(QPixmap::fromImage(image));
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("ERROR"),
            QObject::tr("Add Failed !"), QMessageBox::Ok);
        }
    }
}

void GestionDesProduits::on_comboBox_01_currentIndexChanged(int ID)
{
    QString res = QString::number(ID);
    res = ui->comboBox_01->currentText();
    QSqlQuery query;

    query.prepare("SELECT* FROM GESTION_PRODUIT WHERE ID_PRODUIT='"+res+"'");
    if(query.exec())
    {
        while(query.next())
        {
            ui->lineEdit_05->setText(query.value(1).toString());
            ui->dateEdit_3->setDate(query.value(2).toDate());
            ui->dateEdit_4->setDate(query.value(3).toDate());
            ui->lineEdit_06->setText(query.value(4).toString());
            ui->lineEdit_07->setText(query.value(5).toString());
        }
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("ERROR"),
        QObject::tr("Add Failed !"), QMessageBox::Ok);
    }
}
