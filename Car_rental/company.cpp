#include "company.h"

Company::Company()
{
	this->flag = true;
}
Company::Company(QString name, QString email, QString phone) :Client(email, phone) {
	this->name = name;
    this->flag = false;

}
Company::Company(QString name, QString email, QString phone, QString nip, QString street, QString locNum, QString post_code, QString city) : Client(email, phone, street, post_code, city)
{
	this->name = name;
	this->nip = nip;
	this->locNum = locNum;
	this->flag = false;

}


QString Company::getName()
{
	return name;
}
QString Company::getNip()
{
	return nip;
}
QString Company::getLocNum() {
	return locNum;
}
QString Company::getEmail()
{
	return email;
}

QString Company::getPhone()
{
	return phone;
}

QString Company::getStreet() {
	return street;
}
QString Company::getPostCode() {
	return postCode;
}
QString Company::getCity() {
	return city;
}
QString Company::toString() {
	return this->name + ";" + this->email + ";" + this->phone + ";" + this->nip + ";" + this->street + ";" + this->locNum + ";" + this->postCode + ";" + this->city + ";";
}
bool Company::getFlag() {
	return flag;
}

Company::~Company() {}
