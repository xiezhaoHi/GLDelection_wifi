#pragma once

#include <qt_windows.h>
#include <wlanapi.h>
#include <QStringList>

#pragma comment(lib,"wlanapi.lib")

//wifi连接 配置
typedef struct  
{
	QString m_strSSID; //连接ID
	int m_iType; //加密方式 none 0 \ wep 1 \ wap(wap2) 2
	QString m_strPwd; //密码
}WifiCnt_config;

//网卡 SSID 与状态
typedef struct  
{
	QString m_strSSID;
	QString m_strState; 
}Wireless_info;
class Wifi_control
{
public:
	Wifi_control();
	~Wifi_control();
public:
	void Init_handle();

	//wifi 扫描 并返回SSID
	void Scan_retSSID(QList<Wireless_info> &list);

	//连接指定的wifi 
	BOOL Connect_wifi(WifiCnt_config const& cnf);
private:
	HANDLE m_clientHandle = 0; //客户端句柄

};

