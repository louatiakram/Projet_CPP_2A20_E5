#include "gde.h"
#include "ui_gde.h"
#include "evenements.h"

GDE::GDE(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GDE)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/ASUS/Desktop/Smart Parc/EE.jpg");
    ui->EE->setPixmap(pix.scaled(1200,700,Qt::KeepAspectRatio));

    ui->le_ref->setValidator(new QIntValidator(0, 99999999, this));
    ui->le_duree->setValidator(new QIntValidator(0, 999, this));
    ui->tab_evenements->setModel(E.afficher());
    #define NOM_RX "^([a-z]+[,.]?[ ]?|[a-z]+['-]?)+$"
    QRegExp rxNom(NOM_RX);
    QRegExpValidator*valiNom= new QRegExpValidator(rxNom,this);
    ui->le_nom->setValidator(valiNom);
    ui->le_sujet->setValidator(valiNom);
    ui->le_emplacement->setValidator(valiNom);
    ui->le_date->setDateTime(QDateTime::currentDateTime());
    ui->le_date_modif->setDateTime(QDateTime::currentDateTime());
}

GDE::~GDE()
{
    delete ui;
}
void GDE::on_pb_ajouter_clicked()
{
    int reference=ui->le_ref->text().toInt();
   QString nom=ui->le_nom->text();
   QString sujet=ui->le_sujet->text();
   QDate date_e=ui->le_date->date();
   QString emplacement=ui->le_emplacement->text();
   int duree=ui->le_duree->text().toInt();
   evenements E(reference,nom,sujet,date_e,emplacement,duree);
   bool test=E.ajouter();
   QMessageBox msgbox;
   if(test)
 {msgbox.setText("Ajout avec succes.");
           ui->tab_evenements->setModel(E.afficher());
           ui->le_ref->setText("");
           ui->le_nom->setText("");
           ui->le_sujet->setText("");
           ui->le_date->setDate(date_e);
           ui->le_emplacement->setText("");
           ui->le_duree->setText("");
       }
   else
            msgbox.setText("Echec d'ajout");
        msgbox.exec();
}

void GDE::on_pb_supprimer_clicked()
{
                evenements E1;
                E1.setRef(ui->le_ref_supprimer->text().toInt());
                QSqlQuery query ;
                query.prepare("Select * from evenements WHERE reference=:reference ");
                query.bindValue(":reference",E1.getRef()) ;
                query.exec();
                bool alreadyExist = false;
                    alreadyExist = query.next();
                    if(alreadyExist)
                    {
                bool test=E1.supprimer(E1.getRef());
                QMessageBox msgbox;
                if(test)
                    {msgbox.setText("Suppression avec succes.");
                        ui->tab_evenements->setModel(E.afficher());
                        ui->le_ref_supprimer->setText("");
                    }
                    else
                        msgbox.setText("Echec de suppression");
                    msgbox.exec();
                    }
                  else
                                 {
                                     QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                                     QObject::tr("ID INTROUVABLE .\n" "Click Cancel to exit."), QMessageBox::Cancel);
                                 }
}

       void GDE::on_pb_modifier_clicked()
{
            int reference=ui->le_ref_modif->text().toInt();
            QString nom=ui->le_nom_modif->text();
            QString sujet=ui->le_sujet_modif->text();
            QDate date_e=ui->le_date_modif->date();
            QString date=date_e.toString("yyyy,dd,MM");
            QString emplacement=ui->le_emplacement_modif->text();
            int duree=ui->le_duree_modif->text().toInt();
            evenements E(reference,nom,sujet,date_e,emplacement,duree);
            QSqlQuery query ;
                    query.prepare("SELECT * from evenements WHERE reference=:reference ");
                    query.bindValue(":reference",reference) ;
                    query.exec();
                    bool alreadyExist = false;
                        alreadyExist = query.next();
                        if(alreadyExist)
                        {
                    bool test=E.modifier(reference);
                    QMessageBox msgbox;
                    if(test)
                        {
                        msgbox.setText("Modification avec succes.");

                        }
                        else
                            msgbox.setText("Echec de modification");
                        msgbox.exec();
                        }
                      else
                                     {
                                         QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                                         QObject::tr("ID INTROUVABLE .\n" "Click Cancel to exit."), QMessageBox::Cancel);

                                     }
                        ui->tab_evenements->setModel(E.afficher());
}
void GDE::on_pb_verifier_clicked()
{
    QSqlQuery query ;
            QString reference=ui->le_ref_modif->text() ;
            query.prepare("Select * from EVENEMENTS WHERE reference=:reference");
            query.bindValue(":reference",reference) ;
            query.exec() ;
            query.next() ;
            ui->le_nom_modif->setText(query.value(1).toString());
            ui->le_sujet_modif->setText(query.value(2).toString());
            ui->le_date_modif->setDate(query.value(3).toDate());
            ui->le_emplacement_modif->setText(query.value(4).toString());
            ui->le_duree_modif->setText(query.value(5).toString());
}

void GDE::on_pb_tri_clicked()
{
                evenements E;
                QString crit=ui->comboboxtri->currentText();
                if(crit=="reference")
                {
                    ui->tab_evenements->setModel(E.tri_Ref());
                }
                else if(crit=="nom")
                {
                    ui->tab_evenements->setModel(E.tri_nom());
                }
                else
                {
                    ui->tab_evenements->setModel(E.tri_duree());
                }
}

void GDE::on_lineEdit_textChanged(const QString &arg1)
{
      ui->tab_evenements->setModel(E.rechercher(arg1));
}



void GDE::on_radioButton_clicked()
{
        QString link="https://www.google.com/maps/place/Parc+du+Belvedere/@36.8219921,10.1695377,17z/data=!3m1!4b1!4m5!3m4!1s0x12fd34819aa171bf:0x77a533be27aa925d!8m2!3d36.8219921!4d10.1717264";
        QDesktopServices::openUrl(link);
}



void GDE::on_pb_PDF_clicked()
{



            QSqlDatabase db;

                        QTableView tableView;
                        QSqlQueryModel * Modal=new  QSqlQueryModel();

                        QSqlQuery qry;
                         qry.prepare("SELECT* FROM evenements");
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
                                 "<img src='C:/Users/ASUS/Desktop/T/SmartParc.png' height='155' width='140'/>"
                             "<head>\n"
                                 "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                             <<  QString("<title>%1</title>\n").arg(strTitle)
                             <<  "</head>\n"
                             "<body bgcolor=#ffffff link=#5000A0>\n"
                            << QString("<h3 style=\" font-size: 50px; font-family: Arial, Helvetica, sans-serif; color: #e80e32; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("Liste des evenements")
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

void GDE::on_pushButton_2_clicked()
{
  //  evenements E ;
  //  E.Write_on_file() ;
    QPdfWriter pdf("C:/Users/MSI/Desktop/projetali.pdf");

            QPainter painter(&pdf);

            int i = 4000;
            painter.setPen(Qt::red);
            painter.setFont(QFont("Arial", 30));
            painter.drawText(3000,1500,"Planning");
            painter.setPen(Qt::black);
            painter.setFont(QFont("Arial", 50));
            // painter.drawText(1100,2000,afficheDC);
            painter.drawRect(2700,200,7300,2600);

            painter.drawRect(0,3000,9600,500);
            painter.setFont(QFont("Arial", 9));
            painter.drawText(300,3300,"date_e");
            painter.drawText(2300,3300,"duree");
            QSqlQuery query;
            query.prepare("select * from evenements");
            query.exec();
            while (query.next())
            {
                painter.drawText(300,i,query.value(3).toString());
                painter.drawText(2300,i,query.value(5).toString());

                i = i +500;
            }

            int reponse = QMessageBox::question(this, "AGENDA", "<Agenda modifié>...Vous Voulez Affichez Le Planning ?", QMessageBox::Yes |  QMessageBox::No);
            if (reponse == QMessageBox::Yes)
            {
                QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/MSI/Desktop/projetali.pdf"));

                painter.end();
            }
            if (reponse == QMessageBox::No)
            {
                painter.end();
            }
}

void GDE::on_Quitter_clicked()
{
    close();
}
