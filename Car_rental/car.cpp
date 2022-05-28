#include "car.h"
//inicjalizowanie statycznych list
QList<Car> Car::addedCars=QList<Car>();
QList<Car> Car::removedCars=QList<Car>();
QList<Car> Car::rentedCars=QList<Car>();
QList<Car> Car::returnedCars=QList<Car>();

//przeciążanie konstruktorów
Car::Car()
{
	this->flag = true;
    this->returned= true;
}
Car::Car(QString bodyType, QString brand, QString model, QString fuel, QString vin, QString regNum, QString sites, QString year, QString doors, QString price, QString status) :Vehicle(bodyType, brand, model, fuel, vin, regNum, sites, year, price, status)
{
	this->doors = doors;
	this->flag = false;
}
Car::Car(QString bodyType, QString brand, QString model, QString fuel, QString vin, QString regNum, QString sites, QString year, QString doors, QString price, QString status, QString firstName,
    QString lastName,
    QString email,
    QString phone
) : Vehicle(bodyType, brand, model, fuel, vin, regNum, sites, year, price, status, firstName,
        lastName,
        email,
        phone)
{
    this->doors = doors;
    this->flag = false;
    this->returned= false;
}

Car::Car(QString bodyType, QString brand, QString model, QString fuel, QString vin, QString regNum, QString sites, QString year, QString doors, QString price, QString status, QString name,
    QString email,
    QString phone ) :Vehicle(bodyType, brand, model, fuel, vin, regNum, sites, year, price, status, name,
        email,
        phone
        )
{
    this->doors = doors;
    this->flag = false;
    this->returned= false;
}

Car::Car(QString bodyType, QString brand, QString model, QString fuel, QString vin, QString regNum, QString sites, QString year, QString doors, QString price, QString status, QString firstName,
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
	this->doors = doors;
    this->returned= false;
}
Car::Car(QString bodyType, QString brand, QString model, QString fuel, QString vin, QString regNum, QString sites, QString year, QString doors, QString price, QString status, QString name,
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
	this->doors = doors;
    this->returned= false;
}
QString Car::getBodyType()
{
	return bodyType;
}
QString Car::getBrand()
{
	return brand;
}
QString Car::getModel()
{
	return model;
}
QString Car::getFuel()
{
	return fuel;
}
QString Car::getVin()
{
	return vin;
}
QString Car::getRegNum()
{
	return regNum;
}
QString Car::getSites()
{
	return sites;
}
QString Car::getYear()
{
	return year;
}
QString Car::getPrice()
{
	return  price;
}
QString Car::getStatus()
{
	return status;
}
QString Car::getDoors()
{
	return doors;
}
bool Car::getFlag() {
	return flag;
}
QString Car::getFirstName() {
	return firstName;
}
QString Car::getLastName() {
	return lastName;
}
QString Car::getEmail() {
	return email;
}
QString Car::getPhone() {
	return phone;
}
QString Car::getPesel() {
	return pesel;
}
QString Car::getIDnumber() {
	return IDnumber;
}
QString Car::getStreet() {
	return street;
}
QString Car::getHomeNumber() {
	return homeNumber;
}
QString Car::getPostCode() {
	return postCode;
}
QString Car::getCity() {
	return city;
}
QString Car::getName() {
	return name;
}
QString Car::getNIP() {
	return NIP;
}
QString Car::getLocalNumber() {
	return localNumber;
}
bool Car::getReturned(){
    return returned;
}
//przeciążanie funkcji tostring
QString Car::toString(bool isReturn) {
    QString info = this->bodyType + ";" + this->brand + ";" + this->model + ";" + this->fuel + ";" + this->vin + ";" +
        this->regNum + ";" + this->sites + ";" + this->year + ";" + this->doors + ";" + this->price + ";" + this->status + ";"+this->firstName+";"+
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
QString Car::toString() {
	QString info = this->bodyType + ";" + this->brand + ";" + this->model + ";" + this->fuel + ";" + this->vin + ";" +
		this->regNum + ";" + this->sites + ";" + this->year + ";" + this->doors + ";" + this->price + ";" + this->status + ";";
	return info;
}
Car::~Car() {

}

