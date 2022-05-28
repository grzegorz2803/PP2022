#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
#include <QString>
using namespace std;

class Client
{
	friend class Person;
	friend class Company;
public:
	Client();
	Client(QString, QString);
	Client(QString, QString, QString, QString, QString);
	~Client();


private:
	QString email;
	QString phone;
	QString street;
	QString postCode;
	QString city;
};

#endif // CLIENT_H
