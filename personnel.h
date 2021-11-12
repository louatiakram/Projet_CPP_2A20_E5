#ifndef PERSONNEL_H
#define PERSONNEL_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QDoubleValidator>

class Personnel
{
public:

    Personnel();
    Personnel(int,QString,QString,int,int,int,int);


    int getcin();
    QString getnom();
    QString getprenom();
    int getage();
    int getsalaire();
    int getnumero_tel();


    void setcin(int);
    void setnom(QString);
    void setprenom(QString);
    void setage(int);
    void setsalaire(int);
    void setnumero_tel(int);


    bool ajouter();
    bool modifierP();
    bool supprimer(int);
    QSqlQueryModel* afficher();



private:
    int CIN;
    QString NOM;
    QString PRENOM;
    int AGE;
    int SALAIRE;
    int NUM_TEL;
    int CIN_DIRIGEUR;




};

#endif // PERSONNEL_H






