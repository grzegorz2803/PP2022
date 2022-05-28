#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include "vehicle.h"
#include <QList>
#include <QtCore/QtCore>
#include <cstdlib>
#include <iostream>
class Motorcycle : public Vehicle
{
public:
	Motorcycle();
	Motorcycle(QString, QString, QString, QString, QString, QString, QString, QString, QString, QString);
    Motorcycle(QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString);
    Motorcycle(QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString,QString);
	Motorcycle(QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString);
	Motorcycle(QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString);
	~Motorcycle();
	QString getBodyType();
	QString getBrand();
	QString getModel();
	QString getFuel();
	QString getVin();
	QString getRegNum();
	QString getSites();
	QString getYear();
	QString getPrice();
	QString getStatus();
	QString getFirstName();
	QString getLastName();
	QString getEmail();
	QString getPhone();
	QString getPesel();
	QString getIDnumber();
	QString getStreet();
	QString getHomeNumber();
	QString getPostCode();
	QString getCity();
	QString getName();
	QString getNIP();
	QString getLocalNumber();
	QString toString();
    QString toString(bool);
    // listy statyczne do generowania raportu
    static QList<Motorcycle> addedMotors;
    static QList<Motorcycle> removedMotors;
    static QList<Motorcycle> rentedMotors;
    static QList<Motorcycle> returnedMotors;
    bool getReturned();
	bool getFlag();
private:
    bool returned;
	bool flag;
};

#endif // MOTORCYCLE_H
