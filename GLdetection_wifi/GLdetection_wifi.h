#pragma once


#include <QtWidgets/QMainWindow>
#include "ui_GLdetection_wifi.h"


class GLdetection_wifi : public QMainWindow
{
	Q_OBJECT

public:
	GLdetection_wifi(QWidget *parent = Q_NULLPTR);

private:
	Ui::GLdetection_wifiClass ui;
};
