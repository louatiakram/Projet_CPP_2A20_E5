#ifndef VISITEURS_H
#define VISITEURS_H
#include <QString>
#include<QSqlQuery>
#include<QSqlQueryModel>


class visiteurs
{
private:
    int numero_visiteur;
    QString nom;
    QString prenom;
    int age;
    int num_tel;
    QString adresse_mail;
public:
    visiteurs();
    visiteurs(int,QString,QString,int,int,QString);
    int getnum();
    QString getnom();
    QString getprenom();
    int getage();
    int getnum_tel();
    QString getadresse();
    void setnum(int);
    void setnom(QString);
    void setprenom(QString);
    void setage(int);
    void setnum_tel(int);
    void setadresse(QString);
    bool ajouter();
    bool supprimer(int);
    QSqlQueryModel* afficher();
    bool modifier();
    QSqlQueryModel *tri_num();
    QSqlQueryModel *tri_prenom();
    QSqlQueryModel *tri_nom();
    QSqlQueryModel *rechercher(QString);
    void notification(QString);
};

#endif // VISITEURS_H
