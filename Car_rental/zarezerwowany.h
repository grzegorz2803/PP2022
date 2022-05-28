#ifndef ZAREZERWOWANY_H
#define ZAREZERWOWANY_H

#include <QDialog>

namespace Ui {
	class Zarezerwowany;
}

class Zarezerwowany : public QDialog
{
	Q_OBJECT

public:
	explicit Zarezerwowany(QWidget* parent = nullptr);
	~Zarezerwowany();

private slots:
	void on_pushButton_clicked();

private:
	Ui::Zarezerwowany* ui;
};

#endif // ZAREZERWOWANY_H
