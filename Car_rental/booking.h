#ifndef BOOKING_H
#define BOOKING_H

#include <QDialog>
#include "zarezerwowany.h"
#include <QFile>
#include "car.h"
#include "motorcycle.h"
#include <QDebug>
#include <QMessageBox>
#include <QString>
#include <iostream>
#include <QList>
#include "person.h"
#include "company.h"
namespace Ui {
	class Booking;
}

class Booking : public QDialog
{
	Q_OBJECT

public:
	explicit Booking(QWidget* parent = nullptr);
	~Booking();
	void displaysVehicles();
	bool readsFile();
    bool bookVehicle(QString regNum);




private slots:
	void on_buttonBox_accepted();

	void on_person_clicked();

	void on_company_clicked();

private:
	Ui::Booking* ui;

};

#endif // BOOKING_H
