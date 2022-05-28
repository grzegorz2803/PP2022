#include "worker.h"
#include "ui_worker.h"
using namespace std;

QFile file("..\\baza\\vehicles.csv");
QFile fileRent("..\\baza\\rentVehicles.csv");
QFile bookFileW("..\\baza\\bookvehicle.csv");
QList<Car> cars;
QList<Motorcycle> motors;
QList<Person> persons;
QList<Company> companies;
Car removeCar;
Motorcycle removeMotor;

Worker::Worker(QWidget* parent) :
	QDialog(parent),
	ui(new Ui::Worker)
{
	ui->setupUi(this);
	ui->add_box->setVisible(false);
	ui->remove_box->setVisible(false);
	ui->booking_box->setVisible(false);

	ui->lent_box->setVisible(false);
	ui->all_box->setVisible(false);
	ui->booking_company_box->setVisible(false);
	ui->booking_person_box->setVisible(false);
	ui->all_company_box->setVisible(false);
	ui->all_person_box->setVisible(false);

	ui->add_brand->setPlaceholderText("Marka");
	ui->add_model->setPlaceholderText("Model");
	ui->add_price->setPlaceholderText("Cena");
	ui->add_reg_num->setPlaceholderText("KR9CU78");
	ui->add_sites->setPlaceholderText("Liczba miejsc");
	ui->add_year->setPlaceholderText("2020");
	ui->add_vin->setPlaceholderText("VIN");

	ui->reg_num_remove->setPlaceholderText("KR9CU78");

	ui->reg_num_lent->setPlaceholderText("KR9CU78");

	ui->allVehicle->setColumnCount(11);
	QStringList titles;
	titles << "Rodzaj pojazdu" << "Marka" << "Model" << "Rodzaj paliwa" << " VIN" << " Nr rejestracyjny " << "Liczba miejsc" << "Rok produkcji" << "Liczba drzwi" << "Cena " << "Status";
	ui->allVehicle->setHorizontalHeaderLabels(titles);



}
//funkcja czytająca z pliku vehicle.csv
bool Worker::readFile() {
	cars.clear();
	motors.clear();
	if (file.exists()) {
		if (file.open(QIODevice::ReadWrite | QIODevice::Text)) {
			QTextStream in(&file);

			while (!in.atEnd()) {
				QString string = in.readLine();
				QStringList list = string.split(';', QString::SkipEmptyParts);
				if (list.length() == 11) {
					Car car = Car(list.at(0), list.at(1), list.at(2), list.at(3), list.at(4), list.at(5), list.at(6), list.at(7), list.at(8), list.at(9), list.at(10));
					cars.append(car);
				}
				else if (list.length() == 10) {
					Motorcycle motor = Motorcycle(list.at(0), list.at(1), list.at(2), list.at(3), list.at(4), list.at(5), list.at(6), list.at(7), list.at(8), list.at(9));
					motors.append(motor);
				}
			}
			file.close();
			return true;
		}
		else {
			return false;
		}
	}
	else
	{
		return false;
	}
}
//funkcja czytająca z pliku bookvehicle.csv
bool Worker::readFileBooking() {
	cars.clear();
	motors.clear();
    if (bookFileW.exists()) {
        if (bookFileW.open(QIODevice::ReadWrite | QIODevice::Text)) {
            QTextStream in(&bookFileW);

			while (!in.atEnd()) {
				QString string = in.readLine();
				QStringList list = string.split(';', QString::SkipEmptyParts);

                if (list.length() == 15) {
                    Car car = Car(list.at(0), list.at(1), list.at(2), list.at(3), list.at(4), list.at(5), list.at(6), list.at(7), list.at(8), list.at(9), list.at(10), list.at(11), list.at(12), list.at(13),list.at(14));
                    cars.append(car);
                }
                else if (list.length() == 14 && !(list.at(0).compare("Motocykl"))) {
                    Motorcycle motor = Motorcycle(list.at(0), list.at(1), list.at(2), list.at(3), list.at(4), list.at(5), list.at(6), list.at(7), list.at(8), list.at(9), list.at(10), list.at(11), list.at(12), list.at(13));
                    motors.append(motor);

                }
                else if (list.length() == 14) {
                    Car car = Car(list.at(0), list.at(1), list.at(2), list.at(3), list.at(4), list.at(5), list.at(6), list.at(7), list.at(8), list.at(9), list.at(10), list.at(11), list.at(12), list.at(13));
                    cars.append(car);
                }
                else if (list.length() == 13) {
                    Motorcycle motor = Motorcycle(list.at(0), list.at(1), list.at(2), list.at(3), list.at(4), list.at(5), list.at(6), list.at(7), list.at(8), list.at(9), list.at(10), list.at(11), list.at(12));
                    motors.append(motor);
                }
			}
            bookFileW.close();
			return true;
		}
		else {
			return false;
		}
	}
	else
	{
		return false;
	}
}
//funkcja czytająca z pliku rentvehicle.csv
bool Worker::readFileRent() {
    cars.clear();
    motors.clear();
    if (fileRent.exists()) {
        if (fileRent.open(QIODevice::ReadWrite | QIODevice::Text)) {
            QTextStream in(&fileRent);

            while (!in.atEnd()) {
                QString string = in.readLine();
                QStringList list = string.split(';', QString::SkipEmptyParts);

                if (list.length() == 21) {
                    Car car = Car(list.at(0), list.at(1), list.at(2), list.at(3), list.at(4), list.at(5), list.at(6), list.at(7), list.at(8), list.at(9), list.at(10), list.at(11), list.at(12), list.at(13), list.at(14), list.at(15), list.at(16), list.at(17), list.at(18), list.at(19), list.at(20));
                    cars.append(car);
                }
                else if (list.length() == 20) {
                    Motorcycle motor = Motorcycle(list.at(0), list.at(1), list.at(2), list.at(3), list.at(4), list.at(5), list.at(6), list.at(7), list.at(8), list.at(9), list.at(10), list.at(11), list.at(12), list.at(13), list.at(14), list.at(15), list.at(16), list.at(17), list.at(18), list.at(19));
                    motors.append(motor);

                }
                else if (list.length() == 19) {
                    Car car = Car(list.at(0), list.at(1), list.at(2), list.at(3), list.at(4), list.at(5), list.at(6), list.at(7), list.at(8), list.at(9), list.at(10), list.at(11), list.at(12), list.at(13), list.at(14), list.at(15), list.at(16), list.at(17), list.at(18));
                    cars.append(car);
                }
                else if (list.length() == 18) {
                    Motorcycle motor = Motorcycle(list.at(0), list.at(1), list.at(2), list.at(3), list.at(4), list.at(5), list.at(6), list.at(7), list.at(8), list.at(9), list.at(10), list.at(11), list.at(12), list.at(13), list.at(14), list.at(15), list.at(16), list.at(17));
                    motors.append(motor);
                }
            }
            fileRent.close();
            return true;
        }
        else {
            return false;
        }
    }
    else
    {
        return false;
    }
}
//funkcja usuwająca pojazd
bool Worker::removeVehicle(QString regNum) {
	removeCar = Car();
	removeMotor = Motorcycle();
	int index = 0;
	bool flag = false;
	for (auto element : cars) {

		if (!element.getRegNum().compare(regNum)) {
			flag = true;
			break;
		}
		else {
			index++;
		}
	}
	if (flag) {
		removeCar = cars.at(index);
		cars.removeAt(index);
	}

	else {
		index = 0;
		for (auto element : motors) {

			if (!element.getRegNum().compare(regNum)) {
				flag = true;
				break;
			}
			else {
				index++;
			}
		}

		if (flag) {
			removeMotor = motors.at(index);
			motors.removeAt(index);
		}
	}
	return flag;
}
//funkcja wpisująca dane do pliku
void Worker::writeToFile() {
	if (file.open(QIODevice::WriteOnly)) {
		QTextStream stream(&file);
		for (auto element : cars) {
			stream << element.toString() + "\n";
		}
		for (auto element : motors) {
			stream << element.toString() + "\n";
		}
		file.close();

	}

}
//funkcja wyswietlająca wszyskie pojazdy
void Worker::displayVehicles() {
	int rows = cars.length() + motors.length();
	ui->allVehicle->setRowCount(rows);
	int index = 0;
	for (auto element : cars) {
		QTableWidgetItem* item;
		for (int j = 0; j < ui->allVehicle->columnCount(); j++) {
			item = new QTableWidgetItem;
			switch (j) {
			case 0:
				item->setText(element.getBodyType());
				break;
			case 1:
				item->setText(element.getBrand());
				break;
			case 2:
				item->setText(element.getModel());
				break;
			case 3:
				item->setText(element.getFuel());
				break;
			case 4:
				item->setText(element.getVin());
				break;
			case 5:
				item->setText(element.getRegNum());
				break;
			case 6:
				item->setText(element.getSites());
				break;
			case 7:
				item->setText(element.getYear());
				break;
			case 8:
				item->setText(element.getDoors());
				break;
			case 9:
				item->setText(element.getPrice());
				break;
			case 10:
                item->setText("Dostępny");
				break;
			default:
				break;

			}

			ui->allVehicle->setItem(index, j, item);

		}
		index++;
	}
	// ----------------------------------------------------------------------------------
	for (auto element : motors) {
		QTableWidgetItem* item;
		for (int j = 0; j < ui->allVehicle->columnCount(); j++) {
			item = new QTableWidgetItem;
			switch (j) {
			case 0:
				item->setText(element.getBodyType());
				break;
			case 1:
				item->setText(element.getBrand());
				break;
			case 2:
				item->setText(element.getModel());
				break;
			case 3:
				item->setText(element.getFuel());
				break;
			case 4:
				item->setText(element.getVin());
				break;
			case 5:
				item->setText(element.getRegNum());
				break;
			case 6:
				item->setText(element.getSites());
				break;
			case 7:
				item->setText(element.getYear());
				break;
			case 8:
				item->setText("");
				break;
			case 9:
				item->setText(element.getPrice());
				break;
			case 10:
                item->setText("Dostępny");
				break;
			default:
				break;

			}

			ui->allVehicle->setItem(index, j, item);

		}
		index++;
	}
	// cars.clear();
	// motors.clear();
}
//funkcja wyswietlająca zarezerwowanie pojazdy
void Worker::displayBookVehicles() {
    int rows = cars.length() + motors.length();
    ui->bookVehicleTable->setRowCount(rows);
    int index = 0;
    for (auto element : cars) {
        QTableWidgetItem* item;
        for (int j = 0; j < ui->bookVehicleTable->columnCount(); j++) {
            item = new QTableWidgetItem;
            switch (j) {
            case 0:
                item->setText(element.getBodyType());
                break;
            case 1:
                item->setText(element.getBrand());
                break;
            case 2:
                item->setText(element.getModel());
                break;
            case 3:
                item->setText(element.getFuel());
                break;
            case 4:
                item->setText(element.getVin());
                break;
            case 5:
                item->setText(element.getRegNum());
                break;
            case 6:
                item->setText(element.getSites());
                break;
            case 7:
                item->setText(element.getYear());
                break;
            case 8:
                item->setText(element.getDoors());
                break;
            case 9:
                item->setText(element.getPrice());
                break;
            case 10:
                item->setText("Zarezerwowany");
                break;
            case 11:
                item->setText(element.getFirstName());
                break;
            case 12:
                item->setText(element.getLastName());
                break;
            case 13:
                item->setText(element.getName());
                break;
            case 14:
                item->setText(element.getEmail());
                break;
            case 15:
                item->setText(element.getPhone());
                break;
            default:
                break;

            }

            ui->bookVehicleTable->setItem(index, j, item);

        }
        index++;
    }
    // ----------------------------------------------------------------------------------
    for (auto element : motors) {
        QTableWidgetItem* item;
        for (int j = 0; j < ui->bookVehicleTable->columnCount(); j++) {
            item = new QTableWidgetItem;
            switch (j) {
            case 0:
                item->setText(element.getBodyType());
                break;
            case 1:
                item->setText(element.getBrand());
                break;
            case 2:
                item->setText(element.getModel());
                break;
            case 3:
                item->setText(element.getFuel());
                break;
            case 4:
                item->setText(element.getVin());
                break;
            case 5:
                item->setText(element.getRegNum());
                break;
            case 6:
                item->setText(element.getSites());
                break;
            case 7:
                item->setText(element.getYear());
                break;
            case 8:
                item->setText("");
                break;
            case 9:
                item->setText(element.getPrice());
                break;
            case 10:
                item->setText("Zarezerwowany");
                break;
            case 11:
                item->setText(element.getFirstName());
                break;
            case 12:
                item->setText(element.getLastName());
                break;
            case 13:
                item->setText(element.getName());
                break;
            case 14:
                item->setText(element.getEmail());
                break;
            case 15:
                item->setText(element.getPhone());
                break;
            default:
                break;

            }

            ui->bookVehicleTable->setItem(index, j, item);

        }
        index++;
    }
    // cars.clear();
    // motors.clear();
}
//funkcja wyswietlająca wypożyczone pojazdy
void Worker::displayVehiclesRent() {
	int rows = cars.length() + motors.length();
	ui->lentVehiclesPerson->setRowCount(rows);
	int index = 0;
	for (auto element : cars) {
		QTableWidgetItem* item;
		for (int j = 0; j < 24; j++) {
			item = new QTableWidgetItem;
			switch (j) {
			case 0:
				item->setText(element.getBodyType());
				break;
			case 1:
				item->setText(element.getBrand());
				break;
			case 2:
				item->setText(element.getModel());
				break;
			case 3:
				item->setText(element.getFuel());
				break;
			case 4:
				item->setText(element.getVin());
				break;
			case 5:
				item->setText(element.getRegNum());
				break;
			case 6:
				item->setText(element.getSites());
				break;
			case 7:
				item->setText(element.getYear());
				break;
			case 8:
				item->setText(element.getDoors());
				break;
			case 9:
				item->setText(element.getPrice());
				break;
			case 10:
                item->setText("Wypożyczony");
				break;
			case 11:
				item->setText(element.getFirstName() == "" ? " " : element.getFirstName());
				break;
			case 12:
				item->setText(element.getLastName() == "" ? " " : element.getLastName());
				break;
			case 13:
				item->setText(element.getName() == "" ? " " : element.getName());
				break;
			case 14:
				item->setText(element.getEmail());
				break;
			case 15:
				item->setText(element.getPhone());
				break;
			case 16:
				item->setText(element.getPesel() == "" ? " " : element.getPesel());
				break;
			case 17:
				item->setText(element.getIDnumber() == "" ? " " : element.getIDnumber());
				break;
			case 18:
				item->setText(element.getNIP() == "" ? " " : element.getNIP());
				break;
			case 19:
				item->setText(element.getStreet());
				break;
			case 20:
				item->setText(element.getHomeNumber() == "" ? " " : element.getHomeNumber());
				break;
			case 21:
				item->setText(element.getLocalNumber() == "" ? " " : element.getLocalNumber());
				break;
			case 22:
				item->setText(element.getPostCode());
				break;
			case 23:
				item->setText(element.getCity());
				break;


			default:
				break;

			}

			ui->lentVehiclesPerson->setItem(index, j, item);

		}
		index++;
	}
	// ----------------------------------------------------------------------------------
	for (auto element : motors) {
		QTableWidgetItem* item;
		for (int j = 0; j < 24; j++) {
			item = new QTableWidgetItem;
			switch (j) {
			case 0:
				item->setText(element.getBodyType());
				break;
			case 1:
				item->setText(element.getBrand());
				break;
			case 2:
				item->setText(element.getModel());
				break;
			case 3:
				item->setText(element.getFuel());
				break;
			case 4:
				item->setText(element.getVin());
				break;
			case 5:
				item->setText(element.getRegNum());
				break;
			case 6:
				item->setText(element.getSites());
				break;
			case 7:
				item->setText(element.getYear());
				break;
			case 8:
				item->setText("");
				break;
			case 9:
				item->setText(element.getPrice());
				break;
			case 10:
                item->setText("Wypożyczony");
				break;
			case 11:
				item->setText(element.getFirstName());
				break;
			case 12:
				item->setText(element.getLastName());
				break;
			case 13:
				item->setText(element.getName());
			case 14:
				item->setText(element.getEmail());
				break;
			case 15:
				item->setText(element.getPhone());
				break;
			case 16:
				item->setText(element.getPesel());
				break;
			case 17:
				item->setText(element.getIDnumber());
				break;
			case 18:
				item->setText(element.getNIP());
				break;
			case 19:
				item->setText(element.getHomeNumber());
				break;
			case 20:
				item->setText(element.getLocalNumber());
				break;
			case 21:
				item->setText(element.getPostCode());
				break;
			case 22:
				item->setText(element.getCity());
				break;

			default:
				break;

			}

			ui->lentVehiclesPerson->setItem(index, j, item);

		}
		index++;
	}
	// cars.clear();
	// motors.clear();
}

//funkcja wpisująca do pliku wypożyczone
void Worker::writeToFileRent(Car car, Motorcycle motor, Company company, Person person, bool carFlag, bool motorFlag, bool companyFlag, bool personFlag) {
	if (fileRent.open(QIODevice::Append)) {
		QString text = "";
		QTextStream stream(&fileRent);


		if (!carFlag)
			text += car.toString();
		if (!motorFlag)
			text += motor.toString();
		if (!companyFlag)
			text += company.toString() + "\n";
		if (!personFlag)
			text += person.toString() + "\n";

		stream << text;
		fileRent.close();

	}

}

Worker::~Worker()
{
	delete ui;
}

void Worker::on_add_clicked()
{
	ui->add_box->setVisible(true);
	ui->remove_box->setVisible(false);
	ui->booking_box->setVisible(false);
	ui->lent_box->setVisible(false);
	ui->all_box->setVisible(false);
}


void Worker::on_remove_clicked()
{
	ui->remove_box->setVisible(true);
	ui->add_box->setVisible(false);
	ui->booking_box->setVisible(false);
	ui->lent_box->setVisible(false);
	ui->all_box->setVisible(false);
}


void Worker::on_booking_clicked()
{
	ui->booking_box->setVisible(true);
	ui->add_box->setVisible(false);
	ui->remove_box->setVisible(false);
	ui->lent_box->setVisible(false);
	ui->all_box->setVisible(false);
    ui->bookVehicleTable->setColumnCount(16);
    QStringList titles;
    titles << "Rodzaj pojazdu" << "Marka" << "Model" << "Rodzaj paliwa" << " VIN" << " Nr rejestracyjny " << "Liczba miejsc" << "Rok produkcji" << "Liczba drzwi" << "Cena " << "Status" <<
        "Imię" << "Nazwisko" << "Name" << "Email" << "Telefon";
    ui->bookVehicleTable->setHorizontalHeaderLabels(titles);
    if(readFileBooking()){
        displayBookVehicles();
    }


}


void Worker::on_lent_clicked()
{
	ui->lent_box->setVisible(true);
	ui->add_box->setVisible(false);
	ui->remove_box->setVisible(false);
	ui->booking_box->setVisible(false);
	ui->all_box->setVisible(false);
	ui->lentVehiclesPerson->setColumnCount(24);
	QStringList titlesPerson;
	titlesPerson << "Rodzaj pojazdu" << "Marka" << "Model" << "Rodzaj paliwa" << " VIN" << " Nr rejestracyjny " << "Liczba miejsc" << "Rok produkcji" << "Liczba drzwi" << "Cena " << "Status" <<
		"Imię" << "Nazwisko" << "Name" << "Email" << "Telefon" << "Pesel" << "Nr dow. osob." << "NIP" << "Ulica" << "Nr domu" << "Nr lokalu" << "Kod pocztowy" << "Miasto";
	ui->lentVehiclesPerson->setHorizontalHeaderLabels(titlesPerson);

	//-----------------------------

	if (readFileRent()) {
        displayVehiclesRent();
	}
	else {
        QMessageBox::information(this, "Error", "Błąd odczytu danych z pliku");
	}
}


void Worker::on_all_clicked()
{
	ui->all_box->setVisible(true);
	ui->add_box->setVisible(false);
	ui->remove_box->setVisible(false);
	ui->booking_box->setVisible(false);
	ui->lent_box->setVisible(false);

	if (readFile()) {
		displayVehicles();

	}
	else {
        QMessageBox::information(this, "Error", "Nie udało się odczytać danych z pliku");
	}
}





void Worker::on_booking_peron_clicked(bool checked)
{
	if (checked) {
		ui->booking_person_box->setVisible(true);
		ui->booking_company_box->setVisible(false);
	}
}


void Worker::on_booking_company_clicked(bool checked)
{
	if (checked) {
		ui->booking_company_box->setVisible(true);
		ui->booking_person_box->setVisible(false);
	}
}







void Worker::on_all_person_clicked(bool checked)
{
	if (checked) {
		ui->all_person_box->setVisible(true);
		ui->all_company_box->setVisible(false);

	}
}


void Worker::on_all_company_clicked(bool checked)
{
	if (checked) {
		ui->all_company_box->setVisible(true);
		ui->all_person_box->setVisible(false);
	}
}


void Worker::on_add_vehicle_clicked()
{
	QString bodyType = ui->add_body_type->currentText();
	QString brand = ui->add_brand->text();
	QString model = ui->add_model->text();
	QString regNum = ui->add_reg_num->text();
	QString year = ui->add_year->text();
	QString vin = ui->add_vin->text();
	QString fuel = ui->add_fuel->currentText();
	QString doors = ui->add_dors->currentText();
	QString sites = ui->add_sites->text();
	QString price = ui->add_price->text();
    if((bodyType.compare("")&&brand.compare("")&&model.compare("")&&regNum.compare("")&&year.compare("")&&vin.compare("")&&fuel.compare("")&&doors.compare("")&&sites.compare("")&&price.compare("")))
    {


	if (file.open(QIODevice::Append | QIODevice::Text)) {
		QTextStream stream(&file);
		if (!bodyType.compare("Osobowy") || !bodyType.compare("Dostawczy"))
		{

			Car car = Car(bodyType, brand, model, fuel, vin, regNum, sites, year, doors, price, "DostÄ™pny");
            Car::addedCars.append(car);
			stream << car.toString() + "\n";
		}
		else if (!bodyType.compare("Motocykl"))
		{
			Motorcycle motor = Motorcycle(bodyType, brand, model, fuel, vin, regNum, sites, year, price, "DostÄ™pny");
            Motorcycle::addedMotors.append(motor);
			stream << motor.toString() + "\n()";
		}
		else
		{
            QMessageBox::information(this, "Error", "Błędny typ pojazdu");
		}
	}
	else {
        QMessageBox::information(this, "Error", "Błąd otwarcia pliku");
	}

	file.close();
 }else
    {
        QMessageBox::information(this, "Błąd", "nie uzupełnono danych");
    }
}

void Worker::on_remove_vehicle_clicked()
{
	if (readFile()) {
		QString regNum = ui->reg_num_remove->text();
		if (removeVehicle(regNum)) {
            Car::removedCars.append(removeCar);
            Motorcycle::removedMotors.append(removeMotor);
            writeToFile();
		}
		else {
            QMessageBox::information(this, "Błąd", "Nie udało sie usunąć pojazdu");
		}
	}
	else {
        QMessageBox::information(this, "Error", "Błąd odczytu danych z pliku");
	}
}

void Worker::on_rent_vehicle_clicked()
{
    bool dataFlag= false;
	Company company = Company();
	Person person = Person();
	if (readFile()) {
		QString regNumAll = ui->reg_num_all->text();
		if (ui->all_person->isChecked() || ui->all_company->isChecked()) {


			if (ui->all_person->isChecked()) {
				QString name = ui->all_person_name->text();
				QString lastName = ui->all_person_last_name->text();
				QString email = ui->all_person_email->text();
				QString phone = ui->all_person_phone->text();
				QString street = ui->all_person_street->text();
				QString postCode = ui->all_person_post_code->text();
				QString city = ui->all_person_city->text();
				QString idNumber = ui->all_person_nr_id->text();
				QString pesel = ui->all_person_pesel->text();
				QString homeNumber = ui->all_person_nr_home->text();
                if((name.compare("")&&lastName.compare("")&&email.compare("")&&phone.compare("")&&street.compare("")&&postCode.compare("")&&city.compare("")&&idNumber.compare("")&&pesel.compare("")&&homeNumber.compare("")))
                   {
                    dataFlag= true;
                    person = Person(name, lastName, email, phone, pesel, idNumber, street, homeNumber, postCode, city);
                }else
                   QMessageBox::information(this, "Błąd", "nie uzupełnono danych");

			}
			if (ui->all_company->isChecked())
			{
				QString name = ui->all_company_name->text();
				QString email = ui->all_company_email->text();
				QString phone = ui->all_company_phone->text();
				QString nip = ui->all_company_nip->text();
				QString street = ui->all_company_street->text();
				QString nrLocal = ui->all_company_lokal->text();
				QString postCode = ui->all_company_code_post->text();
				QString city = ui->all_company_city->text();

                if((name.compare("")&&email.compare("")&&phone.compare("")&&nip.compare("")&&street.compare("")&&nrLocal.compare("")&&postCode.compare("")&&city.compare("")))
             {
                    dataFlag= true;
                    company = Company(name, email, phone, nip, street, nrLocal, postCode, city);
            }else
                    QMessageBox::information(this, "Błąd", "nie uzupełnono danych");
			}

            if(dataFlag)
            {
			if (removeVehicle(regNumAll)) {
                Car::rentedCars.append(removeCar);
                Motorcycle::rentedMotors.append(removeMotor);
                writeToFileRent(removeCar, removeMotor, company, person, removeCar.getFlag(), removeMotor.getFlag(), company.getFlag(), person.getFlag());
				writeToFile();
				displayVehicles();
			}
			else {
                QMessageBox::information(this, "Błąd", "Nie można wypożyczyć pojazdu błędne dane");
			}
            }
		}
		else {
            QMessageBox::information(this, "Błąd", "Brak danych o kliencie");
		}
	}
	else {
        QMessageBox::information(this, "Error", "Bład odczytu danych z pliku");
	}

}

void Worker::on_return_vehicle_clicked()
{
    QString regNum = ui->reg_num_lent->text();
    if (removeVehicle(regNum)) {

        Car::returnedCars.append(removeCar);
        Motorcycle::returnedMotors.append(removeMotor);
        if (file.open(QIODevice::Append)) {
            QTextStream stream(&file);
            if (!removeCar.getReturned())
                 stream << removeCar.toString()+"\n";
            if (!removeMotor.getReturned())
                stream<< removeMotor.toString()+"\n";

            file.close();

        }
    if (fileRent.open(QIODevice::WriteOnly)) {
            QTextStream stream(&fileRent);
            for (auto element : cars) {
                stream << element.toString(true) + "\n";
            }
            for (auto element : motors) {
                stream << element.toString(true) + "\n";
            }
            fileRent.close();

        }
        if (readFileRent()) {
            displayVehiclesRent();

        }
        else {
            QMessageBox::information(this, "Error", "Bład odczytu danych z pliku");
        }

    }
    else {
       QMessageBox::information(this, "Error", "Nie udało się zwrócić pojazdu");
    }

}

void Worker::on_rent_bokk_vehicle_clicked()
{
    bool dataFlag=false;
    Company company = Company();
    Person person = Person();
    if (readFileBooking()) {
        QString regNumAll = ui->reg_num_booking->text();
        if (ui->booking_peron->isChecked() || ui->booking_company->isChecked()) {


            if (ui->booking_peron->isChecked()) {
                QString name = ui->book_per_name->text();
                QString lastName = ui->book_per_last_name->text();
                QString email = ui->book_per_email->text();
                QString phone = ui->book_per_phone->text();
                QString street = ui->book_per_street->text();
                QString postCode = ui->book_per_post_code->text();
                QString city = ui->book_per_city->text();
                QString idNumber = ui->book_per_nr_id->text();
                QString pesel = ui->book_per_pesel->text();
                QString homeNumber = ui->book_per_nr_home->text();
                if((name.compare("")&&lastName.compare("")&&email.compare("")&&phone.compare("")&&street.compare("")&&postCode.compare("")&&city.compare("")&&idNumber.compare("")&&pesel.compare("")&&homeNumber.compare("")))
                {
                    dataFlag=true;
                    person = Person(name, lastName, email, phone, pesel, idNumber, street, homeNumber, postCode, city);
                }else
                   QMessageBox::information(this, "Błąd", "nie uzupełnono danych");
            }
            if (ui->booking_company->isChecked())
            {
                QString name = ui->book_com_name->text();
                QString email = ui->book_com_email->text();
                QString phone = ui->book_com_phone->text();
                QString nip = ui->book_com_nip->text();
                QString street = ui->book_com_street->text();
                QString nrLocal = ui->book_com_loc->text();
                QString postCode = ui->book_com_post_code->text();
                QString city = ui->book_com_city->text();
                if((name.compare("")&&email.compare("")&&phone.compare("")&&nip.compare("")&&street.compare("")&&nrLocal.compare("")&&postCode.compare("")&&city.compare("")))
                {
                    dataFlag= true;
                    company = Company(name, email, phone, nip, street, nrLocal, postCode, city);
                }else
                QMessageBox::information(this, "Błąd", "nie uzupełnono danych");
            }
            if(dataFlag){



            if (removeVehicle(regNumAll)) {
                Car::rentedCars.append(removeCar);
                Motorcycle::rentedMotors.append(removeMotor);
                writeToFileRent(removeCar, removeMotor, company, person, removeCar.getFlag(), removeMotor.getFlag(), company.getFlag(), person.getFlag());
                if (bookFileW.open(QIODevice::WriteOnly)) {
                    QTextStream stream(&bookFileW);
                    for (auto element : cars) {
                        stream << element.toString(true) + "\n";
                    }
                    for (auto element : motors) {
                        stream << element.toString(true) + "\n";
                    }

                    bookFileW.close();

                }
                displayBookVehicles();
            }
            else {
                QMessageBox::information(this, "Błąd", "Nie można wypożyczyć samochodu. Błędne dane");

            }
            }
        }
        else {
            QMessageBox::information(this, "Błąd", "Nie udało sie wyppożyczyć pojazdu. Brak danych o kliencie");

        }
    }
    else {
       QMessageBox::information(this, "Error", "Nie udało się odczytać danych z pliku");
    }

}

