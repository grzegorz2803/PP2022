#include "motorcycle.h"
QList<Motorcycle> Motorcycle::addedMotors=QList<Motorcycle>();
QList<Motorcycle> Motorcycle::removedMotors=QList<Motorcycle>();
QList<Motorcycle> Motorcycle::rentedMotors=QList<Motorcycle>();
QList<Motorcycle> Motorcycle::returnedMotors=QList<Motorcycle>();
Motorcycle::Motorcycle()
{
	this->flag = true;
    this->returned= true;
}
Motorcycle::Motorcycle(QString bodyType, QString brand, QString model, QString fuel, QString vin, QString regNum, QString sites, QString year, QString price, QString status) :Vehicle(bodyType, brand, model, fuel, vin, regNum, sites, year, price, status)
{
	this->flag = false;
}
Motorcycle::Motorcycle(QString bodyType, QString brand, QString model, QString fuel, QString vin, QString regNum, QString sites, QString year, QString price, QString status, QString firstName,
    QString lastName,
    QString email,
    QString phone) : Vehicle(bodyType, brand, model, fuel, vin, regNum, sites, year, price, status, firstName,
        lastName,
        email,
        phone
    )
{
this->returned= false;
    this->flag = false;
}
Motorcycle::Motorcycle(QString bodyType, QString brand, QString model, QString fuel, QString vin, QString regNum, QString sites, QString year, QString price, QString status, QString name,
    QString email,
    QString phone) :Vehicle(bodyType, brand, model, fuel, vin, regNum, sites, year, price, status, name,
        email,
        phone
    )
{
this->returned= false;
    this->flag = false;
}
Motorcycle::Motorcycle(QString bodyType, QString brand, QString model, QString fuel, QString vin, QString regNum, QString sites, QString year, QString price, QString status, QString firstName,
	QString lastName,
	QString email,
	QString phone,
	QString pesel,
	QString IDnumber,
	QString street,
	QString homeNumber,
	QString postCode,
	QString city) : Vehicle(bodyType, brand, model, fuel, vin, regNum, sites, year, price, status, firstName,
		lastName,
		email,
		phone,
		pesel,
		IDnumber,
		street,
		homeNumber,
		postCode,
		city)
{
this->returned= false;
}
Motorcycle::Motorcycle(QString bodyType, QString brand, QString model, QString fuel, QString vin, QString regNum, QString sites, QString year, QString price, QString status, QString name,
	QString email,
	QString phone,
	QString NIP,
	QString street,
	QString localNumber,
	QString postCode,
	QString city) :Vehicle(bodyType, brand, model, fuel, vin, regNum, sites, year, price, status, name,
		email,
		phone,
		NIP,
		street,
		localNumber,
		postCode,
		city)
{
this->returned= false;
}
QString Motorcycle::getBodyType()
{
	return bodyType;
}
QString Motorcycle::getBrand()
{
	return brand;
}
QString Motorcycle::getModel()
{
	return model;
}
QString Motorcycle::getFuel()
{
	return fuel;
}
QString Motorcycle::getVin()
{
	return vin;
}
QString Motorcycle::getRegNum()
{
	return regNum;
}
QString Motorcycle::getSites()
{
	return sites;
}
QString Motorcycle::getYear()
{
	return year;
}
QString Motorcycle::getPrice()
{
	return  price;
}
QString Motorcycle::getStatus()
{
	return status;
}
bool Motorcycle::getFlag() {
	return flag;
}
QString Motorcycle::getFirstName() {
	return firstName;
}
QString Motorcycle::getLastName() {
	return lastName;
}
QString Motorcycle::getEmail() {
	return email;
}
QString Motorcycle::getPhone() {
	return phone;
}
QString Motorcycle::getPesel() {
	return pesel;
}
QString Motorcycle::getIDnumber() {
	return IDnumber;
}
QString Motorcycle::getStreet() {
	return street;
}
QString Motorcycle::getHomeNumber() {
	return homeNumber;
}
QString Motorcycle::getPostCode() {
	return postCode;
}
QString Motorcycle::getCity() {
	return city;
}
QString Motorcycle::getName() {
	return name;
}
QString Motorcycle::getNIP() {
	return NIP;
}
QString Motorcycle::getLocalNumber() {
	return localNumber;
}
bool Motorcycle::getReturned(){
    return returned;
}
QString Motorcycle::toString(bool isReturn) {
    QString info = this->bodyType + ";" + this->brand + ";" + this->model + ";" + this->fuel + ";" + this->vin + ";" +
        this->regNum + ";" + this->sites + ";" + this->year + ";" + this->price + ";" + this->status + ";"+this->firstName+";"+
    this->lastName+";"+
    this->name+";"+
    this->email+";"+
    this->phone+";"+
    this->pesel+";"+
    this->IDnumber+";"+
    this->NIP+";"+
    this->street+";"+
    this->homeNumber+";"+
    this->localNumber+";"+
    this->postCode+";"+
    this->city+";";
    return info;
}
QString Motorcycle::toString() {
	QString info = this->bodyType + ";" + this->brand + ";" + this->model + ";" + this->fuel + ";" + this->vin + ";" +
		this->regNum + ";" + this->sites + ";" + this->year + ";" + this->price + ";" + this->status + ";";
	return info;
}
Motorcycle::~Motorcycle()
{

}
