#ifndef CAR_H
#define CAR_H

#include <QList>
#include <QtCore/QtCore>
#include <cstdlib>
#include <iostream>
#include "vehicle.h"

class Car : public Vehicle
{
public:
	Car();
	Car(QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString);
    Car(QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString);
    Car(QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString);
	Car(QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString);
	Car(QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString);
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
	QString getDoors();
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
    bool getReturned();
	bool getFlag();
    // listy statyczne do generowania raportu
    static QList<Car> addedCars;
    static QList<Car> removedCars;
    static QList<Car> rentedCars;
    static QList<Car> returnedCars;
    QString toString(bool);
	~Car();
private:
	QString doors;
    bool returned;
	bool flag;
};

#endif // CAR_H
