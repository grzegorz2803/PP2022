#ifndef WORKER_H
#define WORKER_H

#include <QDialog>
#include <QFile>
#include "car.h"
#include "motorcycle.h"
#include "company.h"
#include "person.h"
#include <QDebug>
#include <QMessageBox>
#include <QString>
#include <iostream>
#include <QList>

namespace Ui {
	class Worker;
}

class Worker : public QDialog
{
	Q_OBJECT

public:
	explicit Worker(QWidget* parent = nullptr);
	~Worker();
	void displayVehicles();
	bool readFile();
	bool removeVehicle(QString regNum);
	void writeToFile();
	void writeToFileRent(Car, Motorcycle, Company, Person, bool, bool, bool, bool);
	bool readFileRent();
	void displayVehiclesRent();
    void displayBookVehicles();
    bool readFileBooking();
private slots:
	void on_add_clicked();

	void on_remove_clicked();

	void on_booking_clicked();

	void on_lent_clicked();

	void on_all_clicked();

	void on_booking_peron_clicked(bool checked);

	void on_booking_company_clicked(bool checked);

	void on_all_person_clicked(bool checked);

	void on_all_company_clicked(bool checked);

	void on_add_vehicle_clicked();

	void on_remove_vehicle_clicked();


	void on_rent_vehicle_clicked();

    void on_return_vehicle_clicked();

    void on_rent_bokk_vehicle_clicked();

private:
	Ui::Worker* ui;
};

#endif // WORKER_H
