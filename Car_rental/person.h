#ifndef PERSON_H
#define PERSON_H

#include "client.h"

class Person : public Client
{
public:
	Person();
	Person(QString, QString, QString, QString);
	Person(QString, QString, QString, QString, QString, QString, QString, QString, QString, QString);
	~Person();
	QString getName();
	QString getSumrname();
	QString getIdNumber();
	QString getPesel();
	QString getHomeNumber();
	QString getLocNumber();
	QString getEmail();
	QString getPhone();
	QString getStreet();
	QString getPostCode();
	QString getCity();
	QString toString();
	bool getFlag();
private:
	QString firstName;
	QString surname;
	QString idNumber;
	QString pesel;
	QString homeNumber;
	QString locNumber;
	bool flag;
};

#endif // PERSON_H
