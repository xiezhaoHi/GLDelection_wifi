#pragma once

#include <QMutex>
#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <qt_windows.h>
class Log_output
{
public:

	Log_output()
	{
	}

	~Log_output()
	{
	}
	static void InitLog()
	{
		//注册MessageHandler
		qInstallMessageHandler(OutputMessage);
	}
	static void OutputMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg)
	{
		static QMutex mutex;
		mutex.lock();

		QString text;
		switch (type)
		{
		case QtDebugMsg:
			text = QString("Debug:");
			break;

		case QtWarningMsg:
			text = QString("Warning:");
			break;

		case QtCriticalMsg:
			text = QString("Critical:");
			break;

		case QtFatalMsg:
			text = QString("Fatal:");
		}

		QString context_info = QString("File:(%1) Line:(%2)").arg(QString(context.file)).arg(context.line);
		QString current_date_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd");
		QString current_date = QString("(%1)").arg(current_date_time);
		QString message = QString("%1 %2 %3 %4").arg(text).arg(context_info).arg(msg).arg(current_date);

		QString strCurPath = QDir::currentPath();
		QString strDir = QString("%1/logfile/%2").arg(strCurPath)
			.arg(QDateTime::currentDateTime().toString("yyyy-MM"));
		QDir logDir(strDir);
		if (!logDir.exists())
		{
			logDir.mkdir(strDir);//只创建一级子目录，即必须保证上级目录存在
			
		}
		
		QFile file(QString("%1/%2.txt").arg(strDir)
			.arg(QDateTime::currentDateTime().toString("yyyy-MM-dd")));
		file.open(QIODevice::WriteOnly | QIODevice::Append);
		QTextStream text_stream(&file);
		text_stream << message << "\r\n";
		file.flush();
		file.close();
		mutex.unlock();
	}
	
};

