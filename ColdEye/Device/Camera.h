#pragma once

#include "stdafx.h"
#include "netsdk.h"

#define DEFAULT_VOL           3
#define DEFAULT_AWT_START     (9*60)
#define DEFAULT_AWT_END       (22*60)

typedef enum {
	VIDEO_DIR_0 = 0,
	VIDEO_DIR_90,
	VIDEO_DIR_180,
	VIDEO_DIR_270
}VIDEO_DIRECTION;


#define LOCAL_CONFIG_MASK_ACTIVE       0x00000001
#define LOCAL_CONFIG_MASK_RECORD       0x00000002
#define LOCAL_CONFIG_MASK_AW           0x00000004
#define LOCAL_CONFIG_MASK_DIR          0x00000008
#define LOCAL_CONFIG_MASK_VOL          0x00000010
#define LOCAL_CONFIG_MASK_NAME         0x00000020
#define LOCAL_CONFIG_MASK_AWT          0x00000040

typedef struct {
	bool IsActivate;           //������Ƿ񿪻�
	bool IsVideoRecordEnabled; //��Ƶ�洢����
	bool IsAutoWatchEnabled;   //�Զ���������
	VIDEO_DIRECTION VideoDir;  //��Ƶ����
	UCHAR Volumn;              //����
	UCHAR NameIndex;           //���������������
	UINT  AutoWatchTimeStart;      //�Զ���������ʼʱ�䣨�Է���Ϊ��λ��
	UINT  AutoWatchTimeEnd;       //�Զ�������ʱ����(�Է���Ϊ��λ)
}LocalConfig;

class CCamera
{
public:
	CCamera();
	~CCamera();

	H264_DVR_CLIENTINFO m_ClientInfo;
	LocalConfig         m_LocalConfig;
	UINT                m_Id;

	void GetIp(char* pBuf);
	void GetUserName(char* pBuf);
	void GetPassword(char* pBuf);
	DWORD GetPort();
	long GetLoginId();


	void SetIp(char* szIp);
	void SetIp(SDK_CONFIG_NET_COMMON_V2* pCommonNetConfig);
	void SetUserName(char* szUserName);
	void SetPassword(char* szPwd);
	void SetPort(WORD nPort);
	void SetCommonNetConfig(SDK_CONFIG_NET_COMMON_V2* pCommonNetConfig);

	BOOL SetClientWindow(HWND hWnd);

	void OnLogin();
	BOOL Login();
	BOOL StartRealPlay();
	BOOL StartRealPlay(HWND hWnd);

	BOOL LoadLocalConfig();

	BOOL SubscribeAlarmMessage();
	BOOL UnsubscribeAlarmMessage();

protected:
	SDK_CONFIG_NET_COMMON_V2 mCommonNetConfig;

private:
	long m_LoginId;
	long m_hRealPlay;

	WORD m_nPort;
	char m_szIp[20];
	char m_szUserName[20];
	char m_szPassword[20];

	H264_DVR_DEVICEINFO m_DeviceInfo;

};