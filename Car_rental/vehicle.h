#include <iostream>
#ifndef VEHICLE_H
#define VEHICLE_H
#include <QString>
using namespace std;

class Vehicle
{
	friend class Car;
	friend class Motorcycle;
public:

	Vehicle();
	Vehicle(QString, QString, QString, QString, QString, QString, QString, QString, QString, QString);
    Vehicle(QString, QString, QString, QString, QString, QString, QString, QString, QString, QString , QString, QString, QString);
    Vehicle(QString, QString, QString, QString, QString, QString, QString, QString, QString, QString , QString, QString, QString, QString);
	Vehicle(QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString);
	Vehicle(QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString);
	~Vehicle();
private:
	QString bodyType;
	QString brand;
	QString model;
	QString fuel;
	QString vin;
	QString regNum;
	QString sites;
	QString year;
	QString price;
	QString status;
	QString firstName;
	QString lastName;
	QString email;
	QString phone;
	QString pesel;
	QString IDnumber;
	QString street;
	QString homeNumber;
	QString postCode;
	QString city;
	QString name;
	QString NIP;
	QString localNumber;

};

#endif // VEHICLE_H
