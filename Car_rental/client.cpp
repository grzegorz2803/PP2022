#include "client.h"
#include <iostream>
using namespace std;
Client::Client()
{

}
Client::Client(QString email, QString phone)
{
	this->email = email;
	this->phone = phone;
}
Client::Client(QString email, QString phone, QString street, QString post_code, QString city)
{
	this->email = email;
	this->phone = phone;
	this->street = street;
	this->postCode = post_code;
	this->city = city;
}

Client::~Client() {

}
