#include "zarezerwowany.h"
#include "ui_zarezerwowany.h"

Zarezerwowany::Zarezerwowany(QWidget* parent) :
	QDialog(parent),
	ui(new Ui::Zarezerwowany)
{
	ui->setupUi(this);
}

Zarezerwowany::~Zarezerwowany()
{
	delete ui;
}

void Zarezerwowany::on_pushButton_clicked()
{
	this->closeEvent(0);
}

