#include "booking.h"
#include "ui_booking.h"
#include <QMessageBox>
// definicja plików bazy danych
QFile vehiclesFile("..\\baza\\vehicles.csv");
QFile bookFile("..\\baza\\bookvehicle.csv");
//definicja list
QList<Car> clientCars;
QList<Motorcycle> clientMotors;
//definicja zniennych pomocniczych
Car bookCar;
Motorcycle bookMotor;
Person person;
Company company;
//funkcja rezerwująca pojazdy
bool Booking::bookVehicle(QString regNum) {
    bookCar = Car();
    bookMotor = Motorcycle();
    int index = 0;
    bool flag = false;
    //inkremętacja po elemętach listy
    for (auto element : clientCars) {

        if (!element.getRegNum().compare(regNum)) { //porównanie dwóch stringów
            flag = true;
            break;
        }
        else {
            index++;
        }
    }
    if (flag) { //zwracanie zarezerwowanego pojazdu i usuwanie go z listy
        bookCar = clientCars.at(index);
        clientCars.removeAt(index);
    }

    else {
        index = 0;
        for (auto element : clientMotors) { //powtażamy to co wcześniej tylko dla motorów

            if (!element.getRegNum().compare(regNum)) {
                flag = true;
                break;
            }
            else {
                index++;
            }
        }

        if (flag) {
            bookMotor = clientMotors.at(index);
            clientMotors.removeAt(index);
        }
    }
    return flag;
}
// funkcja odczytująca dane z pliku
bool Booking::readsFile() {
// czyszczenie list
    clientCars.clear();
	clientMotors.clear();
    //sprawdzanie czy plik istnieje
    if (vehiclesFile.exists())
    {
        //otwarczie pliki moetodą czytaj wpisz
		if (vehiclesFile.open(QIODevice::ReadWrite | QIODevice::Text)) {
			QTextStream in(&vehiclesFile);
           //wsprawdzam czy pilk się nie skończył
			while (!in.atEnd()) {
                QString string = in.readLine(); //odczytujemy pojedynczą linie
                QStringList list = string.split(';', QString::SkipEmptyParts); //rozdzielamy wczytaną linie po ;
				if (list.length() == 11) {
                    //tworzymy nowy samochód
					Car car = Car(list.at(0), list.at(1), list.at(2), list.at(3), list.at(4), list.at(5), list.at(6), list.at(7), list.at(8), list.at(9), list.at(10));
                    clientCars.append(car); //dodajemy do listy
				}
				else if (list.length() == 10) {
					Motorcycle motor = Motorcycle(list.at(0), list.at(1), list.at(2), list.at(3), list.at(4), list.at(5), list.at(6), list.at(7), list.at(8), list.at(9));
					clientMotors.append(motor);
				}
			}
            vehiclesFile.close(); //zamknięcie pliku
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
//wyświetlanie wszystkich pojazdów
void Booking::displaysVehicles() {
    int rows = clientCars.length() + clientMotors.length(); //zliczamy liczbe wierszy
    ui->bookVehicles->setRowCount(rows); //ustawiamy liczbe wierszy w tabeli UI
	int index = 0;
	for (auto element : clientCars) {
        QTableWidgetItem* item; //tworzymy wskaźnik na item w tabeli UI
		for (int j = 0; j < ui->bookVehicles->columnCount(); j++) {
            item = new QTableWidgetItem; //ustawiamy wskaźnik na nowy item w tabeli UI
            //wyświetlamy dane w odpowiedniej kolumnie
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

            ui->bookVehicles->setItem(index, j, item); // ustawiamy item w konkretnym miejscu tabeli UI

		}
		index++;
	}
	// ----------------------------------------------------------------------------------
	for (auto element : clientMotors) {
		QTableWidgetItem* item;
		for (int j = 0; j < ui->bookVehicles->columnCount(); j++) {
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

			ui->bookVehicles->setItem(index, j, item);

		}
		index++;
	}

}

Booking::Booking(QWidget* parent) : //deklaracja konstruktora klasy Booking
	QDialog(parent),
	ui(new Ui::Booking)
{
	ui->setupUi(this);
	ui->reg_num->setPlaceholderText("Numer rejestracyjny");
	ui->name->setPlaceholderText("Imię");
	ui->last_name->setPlaceholderText("Nazwisko");
	ui->email->setPlaceholderText("email@xyz.ai");
	ui->phone->setPlaceholderText("777222111");
	ui->company_email->setPlaceholderText("email@xyz.ai");
	ui->company_phone->setPlaceholderText("777222111");
	ui->company_name->setPlaceholderText("Nazwa firmy");
	ui->person_box->setVisible(false);
	ui->company_box->setVisible(false);
    ui->bookVehicles->setColumnCount(11); //ustawiamy ilość kolumn w tabeli UI
	QStringList titles;
	titles << "Rodzaj pojazdu" << "Marka" << "Model" << "Rodzaj paliwa" << " VIN" << " Nr rejestracyjny " << "Liczba miejsc" << "Rok produkcji" << "Liczba drzwi" << "Cena " << "Status";
    ui->bookVehicles->setHorizontalHeaderLabels(titles); // nadajemy etykiety kolumną
	if (readsFile()) {
		displaysVehicles();
	}
	else {
        QMessageBox::information(this, "Error", "Błąd odczytu danych z pliku");
	}
}
Booking::~Booking()
{
	delete ui;
}





void Booking::on_buttonBox_accepted()
{
    bool dataFlag=false;
    person=Person();
    company=Company();
    QString regNum = ui->reg_num->text();
    if(ui->person->isChecked()) // sprawdzamy czy radiobutton został ustawiony
    {
        //pobiermy dane z UI
     QString  fistName= ui->name->text();
     QString  lastName= ui->last_name->text();
     QString  email= ui->email->text();
     QString  phone= ui->phone->text();
     if((fistName.compare("")&&lastName.compare("")&&email.compare("")&&phone.compare("")))
     {
        dataFlag=true;
     person=Person(fistName,lastName,email,phone);
     }else
         QMessageBox::information(this, "Błąd", "nie uzupełnono danych");
    } else if(ui->company->isChecked())
    {
        QString  name= ui->company_name->text();
        QString  email= ui->company_email->text();
        QString  phone= ui->company_phone->text();
        if((name.compare("")&&email.compare("")&&phone.compare("")))
     {
            dataFlag=true;
            company=Company(name,email,phone);
    }else
        QMessageBox::information(this, "Błąd", "nie uzupełnono danych");
    } else
    {
        QMessageBox::information(this, "Błąd", "Nie zaznaczono wyboru klienta");
    }
    if (dataFlag){
    if (bookVehicle(regNum))
    {
        if (bookFile.open(QIODevice::Append)) { // otwarcie pliku metodą dopisz na końcu
            QTextStream stream(&bookFile);
           QString text ="";
           if(!bookCar.getFlag())
               text+=bookCar.toString();
           if(!bookMotor.getFlag())
               text+=bookMotor.toString();
           if (!person.getFlag())
               text+=person.toString()+"\n";
           if (!company.getFlag())
               text+=company.toString()+"\n";
           stream<< text; // dopisanie danych do pliku
            bookFile.close();

        }
        if (vehiclesFile.open(QIODevice::WriteOnly)) { // otwarczie pliki metodą nadpisz
            QTextStream stream(&vehiclesFile);
            for (auto element : clientCars) {
                stream << element.toString() + "\n";
            }
            for (auto element : clientMotors) {
                stream << element.toString() + "\n";
            }

            vehiclesFile.close();

        }
        if (readsFile()) {
            displaysVehicles();
            //stwożenie nowego okna i jegoi wywołanie
            Zarezerwowany book;
            book.setModal(true);
            book.exec();
        }
        else {
            QMessageBox::information(this, "Error", "Błąd odczytu danych z pliku");
        }
    } else {
        QMessageBox::information(this, "Błąd", "Nie udało zarezerwować pojazdu");
    }
}
    }


void Booking::on_person_clicked()
{
	ui->person_box->setVisible(true);
	ui->company_box->setVisible(false);
}


void Booking::on_company_clicked()
{
	ui->company_box->setVisible(true);
	ui->person_box->setVisible(false);
}

