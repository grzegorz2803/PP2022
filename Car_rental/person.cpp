#include "person.h"

Person::Person()
{
	this->flag = true;
}
Person::Person(QString name, QString surname, QString email, QString phone) :Client(email, phone) {

	this->firstName = name;
	this->surname = surname;
    this->flag= false;
}
Person::Person(QString name, QString lastName, QString email, QString phone, QString pesel, QString idNumber, QString street, QString homeNumber, QString postCode, QString city)
	: Client(email, phone, street, postCode, city)
{
	this->firstName = name;
	this->surname = lastName;
	this->idNumber = idNumber;
	this->pesel = pesel;
	this->homeNumber = homeNumber;
	this->flag = false;
}

QString Person::getName()
{
	return firstName;
}
QString Person::getSumrname()
{
	return surname;
}
QString Person::getIdNumber()
{
	return idNumber;
}
QString Person::getPesel()
{
	return pesel;
}
QString Person::getHomeNumber()
{
	return homeNumber;
}
QString Person::getLocNumber()
{
	return locNumber;
}

QString Person::getEmail()
{
	return email;
}

QString Person::getPhone()
{
	return phone;
}

QString Person::getStreet() {
	return street;
}
QString Person::getPostCode() {
	return postCode;
}
QString Person::getCity() {
	return city;
}
QString Person::toString() {
    return  this->firstName + ";" + this->surname + ";" + this->email + ";" + this->phone + ";" + this->pesel + ";" + this->idNumber + ";" + this->street + ";" + this->homeNumber + ";" + this->postCode + ";" + this->city + ";";
}
bool Person::getFlag() {
	return flag;
}

Person::~Person() {

}
