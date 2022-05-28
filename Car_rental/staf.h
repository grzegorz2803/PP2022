#ifndef STAF_H
#define STAF_H
#include <iostream>
#include <bits/stdc++.h>
#include <QString>
#include <QDateTime>
using namespace std;
class Staf
{
public:
	Staf();
	Staf(QString, QString);
	QString getName();
	QString getPassword();
    //zmienna statyczna do przechowywania zalogowanego użytkownika
    static Staf currentStaf;
    QDateTime getStart();
    QString toString();
    ~Staf();
private:
    QDateTime start;
	QString name;
	QString password;

};

#endif // STAF_H
