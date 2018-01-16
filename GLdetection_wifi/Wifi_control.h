#pragma once

#include <qt_windows.h>
#include <wlanapi.h>
#include <QStringList>

#pragma comment(lib,"wlanapi.lib")

//wifi���� ����
typedef struct  
{
	QString m_strSSID; //����ID
	int m_iType; //���ܷ�ʽ none 0 \ wep 1 \ wap(wap2) 2
	QString m_strPwd; //����
}WifiCnt_config;

//���� SSID ��״̬
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

	//wifi ɨ�� ������SSID
	void Scan_retSSID(QList<Wireless_info> &list);

	//����ָ����wifi 
	BOOL Connect_wifi(WifiCnt_config const& cnf);
private:
	HANDLE m_clientHandle = 0; //�ͻ��˾��

};

