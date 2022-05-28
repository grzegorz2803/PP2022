#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "worker.h"
#include <iostream>
#include <QFile>
#include <QDebug>
#include "staf.h"
#include <QList>
#include <QMessageBox>
namespace Ui {
	class Login;
}

class Login : public QDialog
{
	Q_OBJECT

public:
	explicit Login(QWidget* parent = nullptr);
	~Login();

private slots:
	void on_buttonBox_accepted();

private:
	Ui::Login* ui;
};

#endif // LOGIN_H
