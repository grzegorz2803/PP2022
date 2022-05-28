#include "vehicle.h"

Vehicle::Vehicle()
{

}
Vehicle::Vehicle(QString bodyType, QString brand, QString model, QString fuel, QString vin, QString regNum, QString sites, QString year, QString price, QString status) {
	this->bodyType = bodyType;
	this->brand = brand;
	this->model = model;
	this->fuel = fuel;
	this->vin = vin;
	this->regNum = regNum;
	this->sites = sites;
	this->year = year;
	this->price = price;
	this->status = status;
}
Vehicle::Vehicle(QString bodyType, QString brand, QString model, QString fuel, QString vin, QString regNum, QString sites, QString year, QString price, QString status, QString firstName,
    QString lastName,
    QString email,
    QString phone)
{
    this->bodyType = bodyType;
    this->brand = brand;
    this->model = model;
    this->fuel = fuel;
    this->vin = vin;
    this->regNum = regNum;
    this->sites = sites;
    this->year = year;
    this->price = price;
    this->status = status;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->phone = phone;
}
Vehicle::Vehicle(QString bodyType, QString brand, QString model, QString fuel, QString vin, QString regNum, QString sites, QString year, QString price, QString status, QString name,
    QString email,
    QString phone
) {
    this->bodyType = bodyType;
    this->brand = brand;
    this->model = model;
    this->fuel = fuel;
    this->vin = vin;
    this->regNum = regNum;
    this->sites = sites;
    this->year = year;
    this->price = price;
    this->status = status;
    this->name = name;
    this->email = email;
    this->phone = phone;

}
Vehicle::Vehicle(QString bodyType, QString brand, QString model, QString fuel, QString vin, QString regNum, QString sites, QString year, QString price, QString status, QString firstName,
	QString lastName,
	QString email,
	QString phone,
	QString pesel,
	QString IDnumber,
	QString street,
	QString homeNumber,
	QString postCode,
	QString city)
{
	this->bodyType = bodyType;
	this->brand = brand;
	this->model = model;
	this->fuel = fuel;
	this->vin = vin;
	this->regNum = regNum;
	this->sites = sites;
	this->year = year;
	this->price = price;
	this->status = status;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->phone = phone;
	this->pesel = pesel;
	this->IDnumber = IDnumber;
	this->street = street;
	this->homeNumber = homeNumber;
	this->postCode = postCode;
	this->city = city;
}
Vehicle::Vehicle(QString bodyType, QString brand, QString model, QString fuel, QString vin, QString regNum, QString sites, QString year, QString price, QString status, QString name,
	QString email,
	QString phone,
	QString NIP,
	QString street,
	QString localNumber,
	QString postCode,
	QString city
) {
	this->bodyType = bodyType;
	this->brand = brand;
	this->model = model;
	this->fuel = fuel;
	this->vin = vin;
	this->regNum = regNum;
	this->sites = sites;
	this->year = year;
	this->price = price;
	this->status = status;
	this->name = name;
	this->email = email;
	this->phone = phone;
	this->NIP = NIP;
	this->street = street;
	this->localNumber = localNumber;
	this->postCode = postCode;
	this->city = city;

}
Vehicle::~Vehicle()
{

}
