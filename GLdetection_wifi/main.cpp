#include "GLdetection_wifi.h"
#include <QtWidgets/QApplication>
#include <QDebug>
#include "Log_output.h"
#include "Wifi_control.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	//初始化 日志
	Log_output::InitLog();
// 	qDebug() << "hello";
// 	qDebug() << "log";

	Wifi_control wifiCtl;
	QStringList list;
	//wifiCtl.Scan_retSSID(list);



	GLdetection_wifi w;
	w.show();
	return a.exec();
}
