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
    Personnel(int,QString,QString,int,double);


    QString getnom();
    QString getprenom();
    int getage();
    int getcin();
    double getsalaire();


    void setnom(QString);
    void setprenom(QString);
    void setage(int);
    void setcin(int);
    void setsalaire(float);

    bool ajouter();
    bool modifier();
    bool supprimer(int);
    QSqlQueryModel* afficher();


private:
    QString nom;
    QString prenom;
    int age;
    int cin;
    double salaire;




};

#endif // PERSONNEL_H






