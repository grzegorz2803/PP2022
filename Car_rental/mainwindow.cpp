#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
QFile raportFile("..\\baza\\raport.csv");
MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{


    ui->setupUi(this);
   /* ui->brand->setPlaceholderText("Marka pojazdu");
    ui->model->setPlaceholderText("Model pojazdu");
    ui->year->setPlaceholderText("Rok produkcji"); */

}

MainWindow::~MainWindow()
{
//po zamknięcu aplikacji generownie raportu
    if (raportFile.open(QIODevice::Append)) {
        QTextStream stream(&raportFile);
       QString text ="zalogowano ";
       text+= Staf::currentStaf.getName();
       text+= " dnia ";
       text+= Staf::currentStaf.getStart().toString("dddd, d MMMM yy hh:mm:ss");
       text+= "\n dodano pojazdy:\n";
       for (auto element:Car::addedCars)
       {
           if(element.getBodyType().compare(""))
           text+= element.toString()+"\n";

       }
       for (auto element:Motorcycle::addedMotors)
       {
           if(element.getBodyType().compare(""))
           text+= element.toString()+"\n";

       }
       text+="\n usunięto pojazdy \n";
       for (auto element:Car::removedCars)
       {
           if(element.getBodyType().compare(""))
           text+= element.toString()+"\n";

       }
       for (auto element:Motorcycle::removedMotors)
       {
           if(element.getBodyType().compare(""))
           text+= element.toString()+"\n";

       }
       text+="\n wypożyczono pojazdy \n";
       for (auto element:Car::rentedCars)
       {
           if(element.getBodyType().compare(""))
           text+= element.toString()+"\n";

       }
       for (auto element:Motorcycle::rentedMotors)
       {
           if(element.getBodyType().compare(""))
           text+= element.toString()+"\n";

       }
       text+="\n zwrócono pojazdy \n";
       for (auto element:Car::returnedCars)
       {
           if(element.getBodyType().compare(""))
           text+= element.toString()+"\n";

       }
       for (auto element:Motorcycle::returnedMotors)
       {
           if(element.getBodyType().compare(""))
           text+= element.toString()+"\n";

       }
       text+="\n wylogowano "+ Staf::currentStaf.toString();
       stream<< text;
        raportFile.close();

    }
	delete ui;
}


void MainWindow::on_actionZamknij_triggered()
{
	QApplication::quit();
}


void MainWindow::on_actionO_bibliotece_triggered()
{
	QApplication::aboutQt();
}


void MainWindow::on_actionO_programie_triggered()
{
    QMessageBox::information(this, "O programie", "Program do obsługi wypożyczalni pojazdów.\n"
		"Wykonany na zaliczenie przedmiotu Podstawy programowania.\n\n"
		"Autorzy:\n"
		"Michał Lis\n"
		"Grzegorz Listwan\n"
		"Krzysztof Pacura\n\n"
		"ver. 1.00\n"
		"Copyright © 2022\n");

}

void MainWindow::on_login_clicked()
{
	Login login;
	login.setModal(true);
	login.exec();
}


void MainWindow::on_pushButton_clicked()
{
    QMessageBox::information(this,"in progres","work in progres");
}
void MainWindow::on_pushButton_2_clicked()
{
	Booking booking;
	booking.setModal(true);
	booking.exec();
}

