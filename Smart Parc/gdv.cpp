#include "gdv.h"
#include "ui_gdv.h"
#include <QMessageBox>
#include "visiteurs.h"
#include <QIntValidator>
#include <QDebug>
#include <QIntValidator>
#include <QDebug>
#include <QRegExpValidator>
#include <QDesktopServices>
#include <QUrl>
#include <QFileDialog>


GDV::GDV(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GDV)
{
    ui->setupUi(this);
    ui->le_numero->setValidator(new QIntValidator(0, 99999999, this));
        ui->le_age->setValidator(new QIntValidator(0, 99, this));
        ui->le_tel->setValidator(new QIntValidator(0, 99999999, this));
        ui->tab_visiteurs->setModel(V.afficher());
        #define NOM_RX "^([a-z]+[,.]?[ ]?|[a-z]+['-]?)+$"
        QRegExp rxNom(NOM_RX);
        QRegExpValidator*valiNom= new QRegExpValidator(rxNom,this);
        ui->le_nom->setValidator(valiNom);
        ui->le_prenom->setValidator(valiNom);
        ui->le_adresse->setValidator(valiNom);
}

GDV::~GDV()
{
    delete ui;
}
void GDV::on_pb_ajouter_clicked()
{
       int numero_visiteur=ui->le_numero->text().toInt();
       QString nom=ui->le_nom->text();
       QString prenom=ui->le_prenom->text();
       int age=ui->le_age->text().toInt();
       int num_tel=ui->le_tel->text().toInt();
       QString adresse_mail=ui->le_adresse->text();
       visiteurs V(numero_visiteur,nom,prenom,age,num_tel,adresse_mail);
       bool test=V.ajouter();
       QMessageBox msgbox;
       if(test)
           {msgbox.setText("Ajout avec succes.");
               ui->tab_visiteurs->setModel(V.afficher());
               ui->le_numero->setText("");
               ui->le_nom->setText("");
               ui->le_prenom->setText("");
               ui->le_age->setText("");
               ui->le_tel->setText("");
               ui->le_adresse->setText("");
               V.notification("visiteur ajouté");
           }
           else
               msgbox.setText("Echec d'ajout");
           msgbox.exec();
}

void GDV::on_pb_modifier_clicked()
{

    int numero_visiteur=ui->le_numero_modifier->text().toInt();
    QString nom=ui->le_nom_modifier->text();
    QString prenom=ui->le_prenom_modifier->text();
    int age=ui->le_age_modifier->text().toInt();
    int num_tel=ui->le_tel_modifier->text().toInt();
    QString adresse_mail=ui->le_adresse_modifier->text();
    visiteurs V(numero_visiteur,nom,prenom,age,num_tel,adresse_mail);
    bool test=V.modifier();
    QMessageBox msgbox;
    if(test)
        {msgbox.setText("Modification avec succes.");
            ui->tab_visiteurs->setModel(V.afficher());
            ui->le_numero_modifier->setText("");
            ui->le_nom_modifier->setText("");
            ui->le_prenom_modifier->setText("");
            ui->le_age_modifier->setText("");
            ui->le_tel_modifier->setText("");
            ui->le_adresse_modifier->setText("");
        }
        else
            msgbox.setText("Echec de modification");
        msgbox.exec();

}

void GDV::on_pb_supprimer_clicked()
{
    visiteurs V1;
        V1.setnum(ui->le_numero_supprimer->text().toInt());
        bool test=V1.supprimer(V1.getnum());
        QMessageBox msgbox;
        if(test)
            {msgbox.setText("Suppression avec succes.");
                ui->tab_visiteurs->setModel(V.afficher());
                ui->le_numero_supprimer->setText("");
            }
            else
                msgbox.setText("Echec de suppression");
            msgbox.exec();
}

void GDV::on_pb_tester_clicked()
{
    int numero_visiteur=ui->le_numero_modifier->text().toInt();
    QString nom=ui->le_nom_modifier->text();
    QString prenom=ui->le_prenom_modifier->text();
    int age=ui->le_age_modifier->text().toInt();
    int num_tel=ui->le_tel_modifier->text().toInt();
    QString adresse_mail=ui->le_adresse_modifier->text();
    visiteurs V(numero_visiteur,nom,prenom,age,num_tel,adresse_mail);
    QMessageBox msgbox;
    QSqlQuery query;
    bool test=V.modifier();
    if(test)
        {msgbox.setText("Modification avec succes.");
            ui->tab_visiteurs->setModel(V.afficher());
            ui->le_nom_modifier->setText("");
            ui->le_prenom_modifier->setText("");
            ui->le_age_modifier->setText("");
            ui->le_tel_modifier->setText("");
            ui->le_adresse_modifier->setText("");
        }
        else
            msgbox.setText("Echec de modification");
        msgbox.exec();
}

void GDV::on_pb_tri_clicked()
{
                visiteurs V;
                QString crit=ui->comboBoxTri->currentText();
                if(crit=="numero_visiteur")
                {
                    ui->tab_visiteurs->setModel(V.tri_num());
                }
                else if(crit=="nom")
                {
                    ui->tab_visiteurs->setModel(V.tri_nom());
                }
                else
                {
                    ui->tab_visiteurs->setModel(V.tri_prenom());
                }
}

void GDV::on_lineEdit_textChanged(const QString &arg1)
{
    ui->tab_visiteurs->setModel(V.rechercher(arg1));
}

void GDV::on_pb_excel_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Exportation en fichier Excel"), qApp->applicationDirPath (),
                                                                tr("Fichiers d'extension Excel (*.xls)"));
                if (fileName.isEmpty())
                    return;

                EXCEL obj(fileName, "test-bd", ui->tab_visiteurs);

                // you can change the column order and
                // choose which colum to export
                obj.addField(0, "numero_visiteur", "char(20)");
                obj.addField(1, "nom", "char(20)");
                obj.addField(2, "prenom", "char(20)");
                obj.addField(3, "age", "char(20)");
                obj.addField(4, "num_tel", "char(20)");
                obj.addField(5, "adresse_mail", "char(30)");



                int retVal = obj.export2Excel();

                if( retVal > 0)
                {
                    QMessageBox::information(this, tr("FAIS!"),
                                             QString(tr("%1 enregistrements exportés!")).arg(retVal)
                                             );
                }
}

void GDV::on_Quitter_clicked()
{
    close();
}
