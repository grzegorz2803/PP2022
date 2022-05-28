#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFile>
#include <QMainWindow>
#include "login.h"
#include "booking.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget* parent = nullptr);
	~MainWindow();

private slots:
	void on_actionZamknij_triggered();

	void on_actionO_bibliotece_triggered();

	void on_actionO_programie_triggered();

	void on_login_clicked();

	void on_pushButton_clicked();

	void on_pushButton_2_clicked();

private:
	Ui::MainWindow* ui;
};
#endif // MAINWINDOW_H
