#ifndef COMPANY_H
#define COMPANY_H

#include "client.h"

class Company : public Client
{
public:
	Company();
	Company(QString, QString, QString);
	Company(QString, QString, QString, QString, QString, QString, QString, QString);
	~Company();
	QString getName();
	QString getNip();
	QString getLocNum();
	QString getEmail();
	QString getPhone();
	QString getStreet();
	QString getPostCode();
	QString getCity();
	QString toString();
	bool getFlag();

private:
	QString name;
	QString nip;
	QString locNum;
	bool flag;
};

#endif // COMPANY_H
