#include "Wifi_control.h"
#include <QDebug>
#if _MSC_VER >= 1600  
#pragma execution_character_set("utf-8")  
#endif  

Wifi_control::Wifi_control()
{
	m_clientHandle = nullptr;
	Init_handle();
}


Wifi_control::~Wifi_control()
{
	if (m_clientHandle != nullptr)
	{
		WlanCloseHandle(m_clientHandle,nullptr);
	}

}
void Wifi_control::Init_handle()
{
	int vsn = -1; //WlanOpenHandle ��һ������ ��ʾ �ͻ��� ϵͳ����
	DWORD apiVersion = 0; //wirless api �汾��Ϣ
	HANDLE clientHandle = 0; //�ͻ��˾��
	PWLAN_INTERFACE_INFO_LIST pIfList = nullptr; //������Ϣ �б�
	WLAN_INTERFACE_INFO * pIfInfo = nullptr; //����������Ϣ
	QSysInfo::WinVersion winVersion = QSysInfo::windowsVersion();
	if (winVersion >= QSysInfo::WV_VISTA) //ϵͳΪvista  �����
	{
		vsn = 2;
	}
	if (winVersion == QSysInfo::WV_XP) //xp ϵͳ
	{
		vsn = 1;
	}
	if (vsn > -1) //֧�� ��ϵͳ
	{
		DWORD ret = WlanOpenHandle(vsn, NULL, &apiVersion, &clientHandle);

		if (ret != ERROR_SUCCESS)
		{
			qDebug() << QString("WlanOpenHandle failed with error: %u").arg(ret);
		}
		else
			m_clientHandle = clientHandle;
		return;
	}
	qDebug() << QString("��֧��ϵͳ!_%1").arg(winVersion);
}
//wifi ɨ�� ������SSID
void Wifi_control::Scan_retSSID(QList<Wireless_info> & list)
{
	int vsn = -1; //WlanOpenHandle ��һ������ ��ʾ �ͻ��� ϵͳ����
	DWORD apiVersion = 0; //wirless api �汾��Ϣ
	HANDLE clientHandle = 0; //�ͻ��˾��
	PWLAN_INTERFACE_INFO_LIST pIfList = nullptr; //������Ϣ �б�
	WLAN_INTERFACE_INFO * pIfInfo = nullptr; //����������Ϣ
	QSysInfo::WinVersion winVersion = QSysInfo::windowsVersion();
	if (winVersion >= QSysInfo::WV_VISTA) //ϵͳΪvista  �����
	{
		vsn = 2;
	}
	if (winVersion == QSysInfo::WV_XP) //xp ϵͳ
	{
		vsn = 1;
	}
	if (vsn > -1) //֧�� ��ϵͳ
	{
		DWORD ret = WlanOpenHandle(vsn, NULL, &apiVersion, &clientHandle);

		if (ret != ERROR_SUCCESS)
		{
			qDebug() << QString("WlanOpenHandle failed with error: %u").arg(ret);
		}
			//��ȡ ����GUID
		ret = WlanEnumInterfaces(clientHandle, nullptr, &pIfList);
		if (ret != ERROR_SUCCESS)
		{
			qDebug() << QString("WlanEnumInterfaces failed with error: %u").arg(ret);
		}
		WCHAR GuidString[40] = { 0 };
		for (int i = 0; i < (int)pIfList->dwNumberOfItems; i++) {
			pIfInfo = (WLAN_INTERFACE_INFO *)&pIfList->InterfaceInfo[i];
			
			ret = StringFromGUID2(pIfInfo->InterfaceGuid, (LPOLESTR)&GuidString, 39);
			// For c rather than C++ source code, the above line needs to be
			// iRet = StringFromGUID2(&pIfInfo->InterfaceGuid, (LPOLESTR) &GuidString, 39); 
			if (ret == 0)
				qDebug() << QString("StringFromGUID2 failed");
			else {
				qDebug() << QString("  InterfaceGUID[%1]: %2").arg(i)
					.arg(QString::fromStdWString(GuidString));
			}
			qDebug() << QString("  Interface Description[%1]: %2").arg( i).arg(
				QString::fromWCharArray(pIfInfo->strInterfaceDescription));
		
			switch (pIfInfo->isState) {
			case wlan_interface_state_not_ready:
				qDebug() << QString("Not ready");
				break;
			case wlan_interface_state_connected:
				qDebug() << QString("Connected");
				break;
			case wlan_interface_state_ad_hoc_network_formed:
				qDebug() << QString("First node in a ad hoc network");
				break;
			case wlan_interface_state_disconnecting:
				qDebug() << QString("Disconnecting");
				break;
			case wlan_interface_state_disconnected:
				qDebug() << QString("Not connected");
				break;
			case wlan_interface_state_associating:
				qDebug() << QString("Attempting to associate with a network");
				break;
			case wlan_interface_state_discovering:
				qDebug() << QString("Auto configuration is discovering settings for the network");
				break;
			case wlan_interface_state_authenticating:
				qDebug() << QString("In process of authenticating");
				break;
			default:
				qDebug() << QString("Unknown state %1").arg(pIfInfo->isState);
				break;
			}
		
		}
	}
	
}

//����ָ����wifi 
BOOL Wifi_control::Connect_wifi(WifiCnt_config const& cnf)
{
	return TRUE;
}