#include "staf.h"
Staf Staf::currentStaf=Staf();
Staf::Staf()
{

}
Staf::Staf(QString name, QString password) {
	this->name = name;
	this->password = password;
    this->start = QDateTime::currentDateTime();
}
QString Staf::getName() {
	return name;
}
QString Staf::getPassword() {
	return password;
}
QDateTime Staf::getStart(){
    return start;
}

QString Staf::toString(){
    //zwracanie aktualnego czasu
    QDateTime now=QDateTime::currentDateTime();
    return " "+ this-> name+" dnia "+ now.toString("dddd, d MMMM yy hh:mm:ss") +"\n";
}

Staf::~Staf() {

}
