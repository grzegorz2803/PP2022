#include "login.h"
#include "ui_login.h"

using namespace std;
QList<Staf> stafs;




Login::Login(QWidget* parent) :
	QDialog(parent),
	ui(new Ui::Login)
{
	ui->setupUi(this);
	ui->login->setPlaceholderText("Login");
	ui->password->setPlaceholderText("Hasło");
	ui->password->setEchoMode(QLineEdit::Password);

	QFile file;
	file.setFileName("..\\baza\\workers.csv");
	if (file.exists()) {
		if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
			QTextStream in(&file);
			while (!in.atEnd()) {
				QString string = in.readLine();
				QStringList list = string.split(';', QString::SkipEmptyParts);
				Staf staf = Staf(list.at(0), list.at(1));
				stafs.append(staf);
			}
			file.close();
		}
	}
	else
	{
		QMessageBox::information(this, "Błąd", "Błąd");
	}
}

Login::~Login()
{
	delete ui;
}

void Login::on_buttonBox_accepted()
{
	bool flag = false;
	QString name = ui->login->text();
	QString password = ui->password->text();
	for (auto element : stafs) {

		if (!(element.getName().compare(name) && element.getPassword().compare(password))) {
            Staf::currentStaf=element;
            flag = true;
			break;
		}
		else {
			flag = false;
		}
	}

	if (flag) {
		Worker worker;
		worker.setModal(true);
		worker.exec();
	}
	else {
		QMessageBox::information(this, "Błąd", "Błędny login lub hasło");
	}
}

