#include "dialog_v.h"
#include "ui_dialog_v.h"
#include <QMessageBox>
#include "visiteurs.h"
#include <QIntValidator>
#include <QDebug>
#include <QRegExpValidator>
#include <QDesktopServices>
#include <QUrl>
#include <QFileDialog>
#include "excel.h"

Dialog_v::Dialog_v(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_v)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/ASUS/Desktop/Smart Parc/VV.jpg");
    ui->VV->setPixmap(pix.scaled(1200,700,Qt::KeepAspectRatio));

    ui->le_numero_2->setValidator(new QIntValidator(0, 99999999, this));
        ui->le_age_2->setValidator(new QIntValidator(0, 99, this));
        ui->le_tel_2->setValidator(new QIntValidator(0, 99999999, this));
        ui->tab_visiteurs_2->setModel(V.afficher());
        #define NOM_RX "^([a-z]+[,.]?[ ]?|[a-z]+['-]?)+$"
        QRegExp rxNom(NOM_RX);
        QRegExpValidator*valiNom= new QRegExpValidator(rxNom,this);
        ui->le_nom_2->setValidator(valiNom);
        ui->le_prenom_2->setValidator(valiNom);
        ui->le_adresse_2->setValidator(valiNom);

}

Dialog_v::~Dialog_v()
{
    delete ui;
}

void Dialog_v::on_pb_ajouter_2_clicked()
{
    int numero_visiteur=ui->le_numero_2->text().toInt();
    QString nom=ui->le_nom_2->text();
    QString prenom=ui->le_prenom_2->text();
    int age=ui->le_age_2->text().toInt();
    int num_tel=ui->le_tel_2->text().toInt();
    QString adresse_mail=ui->le_adresse_2->text();
    visiteurs V(numero_visiteur,nom,prenom,age,num_tel,adresse_mail);
    bool test=V.ajouter();
    QMessageBox msgbox;
    if(test)
        {msgbox.setText("Ajout avec succes.");
            ui->tab_visiteurs_2->setModel(V.afficher());
            ui->le_numero_2->setText("");
            ui->le_nom_2->setText("");
            ui->le_prenom_2->setText("");
            ui->le_age_2->setText("");
            ui->le_tel_2->setText("");
            ui->le_adresse_2->setText("");
            V.notification("visiteur ajouté");
        }
        else
            msgbox.setText("Echec d'ajout");
        msgbox.exec();
}

void Dialog_v::on_pb_modifier_2_clicked()
{
    int numero_visiteur=ui->le_numero_modifier_2->text().toInt();
    QString nom=ui->le_nom_modifier_2->text();
    QString prenom=ui->le_prenom_modifier_2->text();
    int age=ui->le_age_modifier_2->text().toInt();
    int num_tel=ui->le_tel_modifier_2->text().toInt();
    QString adresse_mail=ui->le_adresse_modifier_2->text();
    visiteurs V(numero_visiteur,nom,prenom,age,num_tel,adresse_mail);
    bool test=V.modifier();
    QMessageBox msgbox;
    if(test)
        {msgbox.setText("Modification avec succes.");
            ui->tab_visiteurs_2->setModel(V.afficher());
            ui->le_numero_modifier_2->setText("");
            ui->le_nom_modifier_2->setText("");
            ui->le_prenom_modifier_2->setText("");
            ui->le_age_modifier_2->setText("");
            ui->le_tel_modifier_2->setText("");
            ui->le_adresse_modifier_2->setText("");
        }
        else
            msgbox.setText("Echec de modification");
        msgbox.exec();

}

void Dialog_v::on_pb_supprimer_clicked()
{
    visiteurs V1;
        V1.setnum(ui->le_numero_supprimer_2->text().toInt());
        bool test=V1.supprimer(V1.getnum());
        QMessageBox msgbox;
        if(test)
            {msgbox.setText("Suppression avec succes.");
                ui->tab_visiteurs_2->setModel(V.afficher());
                ui->le_numero_supprimer_2->setText("");
            }
            else
                msgbox.setText("Echec de suppression");
            msgbox.exec();
}

void Dialog_v::on_pb_tester_2_clicked()
{
    int numero_visiteur=ui->le_numero_modifier_2->text().toInt();
    QString nom=ui->le_nom_modifier_2->text();
    QString prenom=ui->le_prenom_modifier_2->text();
    int age=ui->le_age_modifier_2->text().toInt();
    int num_tel=ui->le_tel_modifier_2->text().toInt();
    QString adresse_mail=ui->le_adresse_modifier_2->text();
    visiteurs V(numero_visiteur,nom,prenom,age,num_tel,adresse_mail);
    QMessageBox msgbox;
    QSqlQuery query;
    bool test=V.modifier();
    if(test)
        {msgbox.setText("Modification avec succes.");
            ui->tab_visiteurs_2->setModel(V.afficher());
            ui->le_nom_modifier_2->setText("");
            ui->le_prenom_modifier_2->setText("");
            ui->le_age_modifier_2->setText("");
            ui->le_tel_modifier_2->setText("");
            ui->le_adresse_modifier_2->setText("");
        }
        else
            msgbox.setText("Echec de modification");
        msgbox.exec();
}

void Dialog_v::on_pb_tri_clicked()
{
    visiteurs V;
    QString crit=ui->comboBoxTri->currentText();
    if(crit=="numero_visiteur")
    {
        ui->tab_visiteurs_2->setModel(V.tri_num());
    }
    else if(crit=="nom")
    {
        ui->tab_visiteurs_2->setModel(V.tri_nom());
    }
    else
    {
        ui->tab_visiteurs_2->setModel(V.tri_prenom());
}
}

void Dialog_v::on_lineEdit_textChanged(const QString &arg1)
{
     ui->tab_visiteurs_2->setModel(V.rechercher(arg1));
}

void Dialog_v::on_pb_excel_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Exportation en fichier Excel"), qApp->applicationDirPath (),
                                                                tr("Fichiers d'extension Excel (*.xls)"));
                if (fileName.isEmpty())
                    return;

                EXCEL obj(fileName, "test-bd", ui->tab_visiteurs_2);

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

void Dialog_v::on_Quitter_clicked()
{
    close();
}
