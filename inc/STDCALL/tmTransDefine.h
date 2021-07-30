/***************************************************************************
								tmTransDefine.h
                             -------------------
    begin                :  2005.12.21
    copyright            : (C) 2005 by aipstar
 ***************************************************************************/

/***************************************************************************
 *  ���ļ�ΪAS��Ƶ����������Ƶ�������ͻ������÷������ṹ�����ļ�		   *
 ***************************************************************************/

/*�޸���־
 *2007-12-18
 *2009-05-19 ����豸�������������������֧�����ǵ��豸������ģ��
 *2010-04-44 ����Ƶ�������ýṹ<tmPicPreviewCfg_t/tmPicModeScheduleInfo_t>����ȱ���
 *2011-11-11 ֧�ֳ�D1 960x576
*/

#ifndef __TMTRANSEDEFINE_H__
#define __TMTRANSEDEFINE_H__

/* ���º궨�岻������޸� */
#define IP_LEN					24
#define NAME_LEN 				32
#define SERIALNO_LEN 			48
#define MACADDR_LEN 			6
#define MAX_ETHERNET 			2
#define PATHNAME_LEN 			128
#define PASSWD_LEN 				32
#define MAX_CHANNUM 			64
#define MAX_ALARMOUT 			64
#define MAX_TIMESEGMENT			4
#define MAX_PRESET				256
#define MAX_DAYS 				7
#define MAX_WEEKNAME			20
#define PHONENUMBER_LEN			32
#define MAX_DISKNUM 			16
#define MAX_WINDOW 				16
#define MAX_VGA 				1
#define MAX_USERNUM 			16
#define MAX_EXCEPTIONNUM		16
#define MAX_LINK 				6
#define MAX_ALARMIN 			64
#define MAX_IRALARMIN 			8
#define MAX_VIDEOOUT 			4
#define MAX_NAMELEN				16		/*DVS���ص�½��*/
#define MAX_RIGHT				64		/*Ȩ��*/
#define CARDNUM_LEN 			20
#define DECODER_NAME_LEN		20
#define MAX_MOTIONAREANUM		5		/*�ƶ��������*/
#define MAX_SERIALTRANS_LEN		128
#define MAX_CIRCLE_NUM			32
#define MAX_NTP_SERVERS			3		/*NTP��������������*/
#define MAX_RS232NUM			6
#define CRUISE_MAX_LINE_NUMS	8
#define MAX_ALARMDEVICE			6		/*���ı����豸*/
#define MAX_CIRCLECONNECTNUM	32		/*����ѭ����*/
#define MAX_WINDOWNUM 			16		/*������ͨ����*/
#define MAX_SCHEDVIDEOINMODE	5		/*���֧������ģʽ*/
#define MAX_FRAMERATE_NUM		25		/*���֧��֡��ģʽ*/
#define COLOR_MODE_NUM			16

/* ����ӿڶ��� */
#define NET_IF_AUTO				0
#define NET_IF_10M_HALF			1		/* 10M ethernet*/
#define NET_IF_10M_FULL			2
#define NET_IF_100M_HALF		3		/* 100M ethernet */
#define NET_IF_100M_FULL		4
#define NET_IF_1000M_HALF		5		/* 1000M ethernet */
#define NET_IF_1000M_FULL		6

/*�豸�ͺ�(DVS����)*/
#define DVS								3	/*��Ƶ������*/
#define DEC								4	/*���������*/
#define HD_DEC							5	/*���������*/
#define HD_NVR							6	/*����NVR*/
#define HD_STORAGE						7	/*�洢������*/
#define HD_TURN							8	/*ת����*/
#define HD_TVWALL						9	/*����ǽ������*/
#define DVS_IPCAMERA					12	/*15/17����ģ��*/
#define HD_IPCAMERA 					13	/*1080p10(�����)*/
#define HD_IPCAMERA1 					14	/*720p(�����)*/
#define HD_IPCAMERA2 					15	/*D1(�����)*/
#define HD_IPCAMERA3 					16	/*1080p30(�����)*/
#define HD_IPCAMERA4 					17	/*����*/
#define HD_NVS							21	/*D1����ģ��(BNC����)*/
#define HD_NVS1							22	/*�������ģ��(YPbPr����)*/
#define	HD_SC110_CAM					23	/*SC110����ģ��*/

#define HD_DIGITALCAMERA_2M18			25	/*2M����һ���*/

#define ANALOG_CAM						31	/*ģ��CAM*/
#define HD_IPCAMERA_1M 					32	/*1M���������*/
#define HD_IPCAMERA_2M 					33	/*2M���������*/
#define HD_IPCAMERA_3M 					34	/*3M���������*/
#define HD_IPCAMERA_5M 					35	/*5M���������*/
#define HD_IPCAMERA_2M18				36	/*2M18������һ���*/
#define HD_IPCAMERA_2M16				37	/*2M16������һ���*/
#define HD_IPCAMERA_2M22				38	/*2M22������һ���*/
#define HD_IPCAMERA_D1					39	/*D1�����*/
#define HD_IP38x38_2M					40	/*2M38x38ģ��*/
#define HD_IP38x38_1M					41	/*1M38x38ģ��*/
#define HD_IP38x38_D1					42	/*D138x38ģ��*/
#define HD_IPCAMERA_2M1M				43	/*2M1M���������*/
#define HD_IPCAMERA_2M1M16				44	/*2M118������һ���*/
#define HD_IPCAMERA_2M1M18				45	/*2M1M16������һ���*/
#define HD_IPCAMERA_2M1M22				46	/*2M1M22������һ���*/
#define HD_IPCAMERA_SAFE				47	/*��ȫ��ʿϵͳ*/
#define HD_IPCAMERA_2MINTELLIGENT		48	/*2M����ǹ��*/
#define HD_IPCAMERA_2M20				49	/*2M20������һ���*/
#define HD_IPCAMERA_2M36				50	/*2M30������һ���*/
#define HD_IPCAMERA_1D3M18				51	/*1.3M18������һ���*/
#define HD_IPCAMERA_1D3M16				52	/*1.3M16������һ���*/
#define HD_IPCAMERA_1M18				53	/*1M18������һ���*/
#define HD_IPCAMERA_1M16				54	/*1M16������һ���*/
#define HD_IPCAMERA_1M22				55	/*1M22������һ���*/
#define HD_IPCAMERA_1D3M22				56	/*1.3M22������һ���*/
#define	HD_IPCAMERA_1M3					57	/*1M3������һ���*/
#define	HD_IPCAMERA_1D3M3				58	/*1.3M3������һ���*/
#define	HD_IPCAMERA_2M3					59	/*2M3������һ���*/
#define HD_IPCAMERA_1D3M 				60	/*1.3M���������*/
#define HD_IP38x38_1D3M					61	/*1.3M38x38ģ��*/
#define HD_IP2BALL_1M					62	/*1M��������*/
#define HD_IP2BALL_1D3M					63	/*1.3M��������*/
#define HD_IP2BALL_2M					64	/*2M��������*/
#define HD_IPCAMERA_1M30 				65	/*1Mһ���*/
#define HD_IPCAMERA_1D3M30				66	/*1.3Mһ���*/
#define HD_IPCAMERA_2M30				67	/*2Mһ���*/
#define HD_IPCAMERA_2M4CH				68	/*2M4����ǹ��*/
#define HD_IP38x38_2M4CH				69	/*2M4����M38ģ��*/
#define HD_IPCAMERA_4M 					70	/*4M���������*/
#define HD_IPCAMERA_2M60FRAME			71	/*2M60֡���������*/
#define HD_IPCAMERA_3M60FRAME 			72	/*3M60֡���������*/
#define HD_IPCAMERA_6M 					73	/*6M���������*/
#define HD_IPCAMERA_8M 					74	/*8M���������*/
#define HD_IPCAMERA_12M 				75	/*12M���������*/
#define HD_IP38x38_3M					76	/*3M˫��M38ģ��*/
#define HD_IPCAMERA_PANORAMA			77	/*ȫ�������*/
#define HD_IP38x38_4M					78	/*1M˫��M42ģ��*/

#define HD_IP38x42_1M					79	/*1M˫��M38x42ģ��*/
#define HD_IP38x42_1D3M					80	/*1.3M˫��M38x42ģ��*/
#define HD_IP38x42_2M					81	/*2M˫��M38x42ģ��*/
#define HD_IP38x42_3M					82	/*3M˫��M38x42ģ��*/
#define HD_IP38x42_4M					83	/*4M˫��M38x42ģ��*/

#define HD_IP42x42_1M					84	/*1M˫��M42ģ��*/
#define HD_IP42x42_1D3M					85	/*1.3M˫��M42ģ��*/
#define HD_IP42x42_2M					86	/*2M˫��M42ģ��*/
#define HD_IP42x42_3M					87	/*3M˫��M42ģ��*/
#define HD_IP42x42_4M					88	/*4M˫��M42ģ��*/
#define HD_IP42x42_5M					89	/*5M˫��M42ģ��*/

#define	HD_IPCAMERA_YTJ_1M				90	/*1M������һ���*/
#define	HD_IPCAMERA_YTJ_1D3M			91	/*1.3M������һ���*/
#define	HD_IPCAMERA_YTJ_2M				92	/*2M������һ���*/
#define	HD_IPCAMERA_YTJ_3M				93	/*3M������һ���*/
#define	HD_IPCAMERA_YTJ_4M				94	/*4M������һ���*/
#define	HD_IPCAMERA_YTJ_5M				95	/*5M������һ���*/

#define HD_IP2BALL_3M					100	/*3M��������*/
#define HD_IP2BALL_6M					101	/*6M��������*/
#define HD_IP2BALL_8M					102	/*8M��������*/

#define HD_IPATM_1D3M					105	/*ATM1.3M�豸*/
#define HD_IPATM_2M						106	/*ATM2M�豸*/
#define HD_IPATM_3M						107	/*ATM3M�豸*/
#define HD_IPATM_4M						108	/*ATM4M�豸*/

#define HD_IPELEVATOR_2M				108	/*�����豸*/

/* �û���Ϣ���壬�����û���Ϣ */
typedef struct tmUserInfo_t
{
	unsigned int	dwSize;						/* �ýṹ��С���������ڰ汾��ͬ���仯*/
	char			szUserName[32];				/* �û��� */
	char			szPassword[32];				/* ���� */
	char			szMotifyPassword[32];		/* ���� */
	unsigned short	wRemoteLevel;				/* ���� */
	unsigned short	wRemoteLoginNum;			/* ����ͬʱ��¼����0-Ϊ���Ƶ�¼ */
	unsigned int	dwRemoteRightHi;			/* Ȩ�� */
	unsigned int	dwRemoteRightLo;			/* Ȩ�� */									
	unsigned int	dwUserIP;					/* ������ʵ�Զ��IP��ַ(Ϊ0ʱ��ʾ�����κε�ַ) */
	unsigned char	byMACAddr[6];				/* ������ʵ�Զ�������ַ(Ϊ0ʱ��ʾ�����κε�ַ)*/
}tmUserInfo_t;

/* �û��б��о��û�ʱʹ�� */
typedef struct tmUser_t
{
	unsigned int	dwSize;						/*�ýṹ��С*/
	int				iUserCount;					/*�����û�����������С��MAX_USERNUM*/
	tmUserInfo_t	struUserInfo[16];			/*�û���Ϣ����*/
}tmUser_t;

/* �û���������TMCC_MINOR_CMD_GETENCRYPTDATA */
typedef struct tmUserEncryptMD5Cfg_t
{
	unsigned int	dwSize;
	unsigned char	byUserData[128];			/*��Ҫ���ܵ�Դ����*/
	unsigned int	dwUserDataLen;				/*��Ҫ���ܵ����ݳ���*/
	unsigned char	byMD5Data[16];				/*���ܺ������16���ֽ�*/
}tmUserEncryptMD5Cfg_t;

/*DVS�豸����*/
typedef struct tmDeviceCfg_t
{
	unsigned int	dwSize;
	char			sDVSName[32];				/*DVS����*/
	unsigned int	dwDVSID;					/*DVS ID,����ң����*/
	unsigned int	dwRecycleRecord;			/*�Ƿ�ѭ��¼��,0:����; 1:��*/
	unsigned int	dwVideoStandard;			/*��Ƶ��ʽ0:PAL 1:NTSC*/
	unsigned int	dwMicrophone;				/*�Ƿ����������Խ�, 0������,��������*/

/*���²��ܸ���*/
	char			szSerialNumber[48];			/*���к�*/
	unsigned int	dwSoftwareVersion;			/*����汾��,��16λ�����汾,��16λ�Ǵΰ汾*/
	unsigned int	dwSoftwareBuildDate;		/*�����������,0xYYYYMMDD*/
	unsigned int	dwDSPSoftwareVersion;		/*DSP����汾,��16λ�����汾,��16λ�Ǵΰ汾*/
	unsigned int	dwDSPSoftwareBuildDate;		/*DSP�����������,0xYYYYMMDD*/
	unsigned int	dwPanelVersion;				/*ǰ���汾,��16λ�����汾,��16λ�Ǵΰ汾*/
	unsigned int	dwHardwareVersion;			/*Ӳ���汾,��16λ�����汾,��16λ�Ǵΰ汾*/
	unsigned char	byAlarmInPortNum;			/*DVS�����������, MAX_ALARMIN-byAlarmInPortNumΪ���籨������*/
	unsigned char	byAlarmOutPortNum;			/*DVS�����������*/
	unsigned char	byRS232Num;					/*DVS 232���ڸ���*/
	unsigned char	byRS485Num;					/*DVS 485���ڸ���*/
	unsigned char	byNetworkPortNum;			/*����ڸ���*/
	unsigned char	byDiskCtrlNum;				/*DVS Ӳ�̿���������*/
	unsigned char	byDiskNum;					/*DVS Ӳ�̸���*/
	unsigned char	byDVSType;					/*DVS����, */
	unsigned char	byChanNum;					/*DVS ͨ������*/
	unsigned char	byStartChan;				/*��ʼͨ����,����DVS-1,DVS - 1*/
	unsigned char	byDecordChans;				/*DVS ����·��*/
	unsigned char	byVGANum;					/*VGA�ڵĸ���*/
	unsigned char	byUSBNum;					/*USB�ڵĸ���*/
	unsigned char	byFactory;					/*���̴��룬��Ƶ�������ĳ���ID,AIP��˾����*/
	unsigned short  wDeviceExternType;			/*�豸��չ���ͣ���һλ��ʾ�Ƿ�֧�ֺ��⣬�ڶ�λ��ʾ�Ƿ�֧��˫·��������(0x0001 -- ֧�ֺ���; 0x0002 -- ֧��˫·����)*/
	char			sDVSType[16];				/*�豸��������*/
	unsigned int	dwModeType;					/*�豸����,����A5DDR2 A5DDR3 S2 ��,�μ�MODAL_ONLY_FLAG_A5*/
}tmDeviceCfg_t;

/*DVS�豸��չ����*/
typedef struct tmDeviceExCfg_t
{
	unsigned int	dwSize;						/*���ṹ��С*/
	unsigned char	byAlarmOutTurnIn;			/*��������޸ĳɱ�������(M38ģ��֧�ִ˹���)*/
	unsigned char	byTransProtocol;			/*ѡ�õ�Э��0-Ĭ������Э��,1-ONVIFЭ��,2-����Э��,3-���Ż�ͨЭ��*/
	unsigned char	byTemp[2];	
}tmDeviceExCfg_t;

/* ����ӿڲ��� */
typedef struct tmEthernet_t
{
	unsigned int	dwSize;
	char			sDVSIP[25];					/*������IP��ַ*/
	char			sDVSIPMask[25];				/*������IP��ַ����*/
	unsigned short	wDHCP;						/*1���ö�̬IP��ȡ,0ָ��IP*/
	unsigned int	dwNetInterface;				/*����ӿ� 1-10MBase-T 2-10MBase-Tȫ˫�� 3-100MBase-TX 4-100Mȫ˫�� 5-10M/100M����Ӧ*/
	unsigned short	wDVSPort;					/*�˿ں�*/
	unsigned short	wHttpPort;					/*Http�������˿ں�*/
	unsigned char	byMACAddr[6];				/*�������������ַ*/
	unsigned char	byInitNetInterface;			/*��ǰ��������*/
	unsigned char	byClientConnectType;		/*Ҫ��ͻ��˵�����ģʽ*/
}tmEthernet_t;

/* DDNS��������Ϣ���� */
typedef struct tmDDNS_t
{
	unsigned int		dwSize;
	char				sDDNSServerName[32];	/*DDNS����������*/
	char				sDDNSServerName2[32];	/*����DDNS����������*/
	char				sDDNSName[32];			/*DDNS����*/
	char				sDDNSUser[32];			/*DDNS�û���*/
	char				sDDNSPassword[32];		/*DDNS����*/
}tmDDNS_t;

/* �������ýṹ */
typedef struct tmNetCfg_t
{
	unsigned int		dwSize;
	tmEthernet_t		struEtherNet[2];				/* ��̫���� */
	char				sManageHostIP[26];				/*Զ�̹���������ַ*/
	unsigned short		wManageHostPort;				/*Զ�̹��������˿ں�*/
	unsigned int		dwManageHost;					/*Զ�̹�����0-������,1-����*/
	unsigned int		dwSyncTimeFromManageHost;		/*�ӹ�������ͬ��ʱ��*/

	char				sDNSIP[25];						/*DNS��������ַ  */
	char				sDNSIP2[25];					/*����DNS��������ַ  */

	char				sMultiCastIP[18];				/*�ಥ���ַ*/
	unsigned int		dwMultiCastPort;				/*�ಥ��˿ڣ���2����+1,��3����+2,��4����+3*/
	unsigned char		byMultiCastIPMode;				/*�ಥ��ַ���ģʽ:0-ʹ�����õĵ�ַ, 1-��ַxxx.aaa.aaa.aaa(����aaa�뱾����ַһ��,xxxʹ���趨��)*/
	unsigned char		byMultiCastPortMode;			/*�ಥ�˿����ģʽ:0-�������˿���ͬ,1-�������˿ڵ��������ͨ��Ҳ����ͨ��������*/
	unsigned char		byMultiCastTemp;				/**/

	char				sGatewayIP[25];       			/*���ص�ַ */

	char				sNFSIP[25];						/*NAS����IP��ַ	*/
	char				sNFSDirectory[130];				/*NASĿ¼*/
	unsigned char		byEnableNFS;					/*�Ƿ�����NFS�����ú����������ָ��Ŀ¼д�ļ�*/

	unsigned int		dwPPPOE;						/*0-������,1-����*/
	char				sPPPoEUser[32];					/*PPPoE�û���*/
	char				sPPPoEPassword[32];				/*PPPoE����*/
	char				sPPPoEIP[16];					/*PPPoE IP��ַ(ֻ��)*/

	unsigned char		byTemp[12];						/*����*/

	unsigned int		dwDDNS;							/*0-������,1-���ã�����Ǿ�������¼����¼DDNS�ĵ�ַΪ���ص�ַ*/
	tmDDNS_t			struDDNS;						/*DDNS*/

	char				sManaeHostUser[32];				/*��½���������û���*/
	char				sManaeHostPassword[32];			/*��½������������*/
	
	/*RTP�Ƿ�����0-�����ã�1-����*/
	unsigned int		dwEnableRtsp;
	/*RTP/RTSP�����˿�*/
	unsigned short		wRtspPort;
	/*RTP/RTSP����ģʽ0-VLC����ģʽ,1-QT����ģʽ*/
	unsigned short		wRtspMode;
	/*RTSP�������ķ��ʱ�ʶ��Ĭ��Ϊbs0*/
	char				sMajorStream[32];
	/*RTSP�������ķ��ʱ�ʶ��Ĭ��Ϊbs1*/
	char				sMinorStream[32];
	/*RTSP�������ķ��ʱ�ʶ��Ĭ��Ϊbs2*/
	char				sThirdStream[32];
	/*RTSP�������ķ��ʱ�ʶ��Ĭ��Ϊbs3*/
	char				sFourthStream[32];
}tmNetCfg_t;

typedef struct tmRtspMutiCastStreamCfg_t
{
	unsigned int		dwSize;
	unsigned char		byEnableVideo;						/*ʹ����Ƶ�鲥����*/
	unsigned char		byEnableAudio;						/*ʹ����Ƶ�鲥����*/
	unsigned char		byReserve[2];
	char				sMultiCastIpVideo[20];				/*��Ƶ�ಥ���ַ*/
	char				sMultiCastIpAduio[20];				/*��Ƶ�ಥ���ַ*/
	unsigned short		wMultiCastPortVideo;				/*��Ƶ�鲥�˿�*/
	unsigned short		wMultiCastPortAudio;				/*��Ƶ�鲥�˿�*/
	unsigned char		byReserve2[8];
}tmRtspMutiCastStreamCfg_t;

/*RTSP�鲥�������ò���*/
typedef struct tmRtspMutiCastCfg_t					/*TMCC_MINOR_CMD_RTSPMUTICASTCFG*/
{
	unsigned int					dwSize;

	unsigned char					byCurStreamNum;
	unsigned char					byReserve[3];
	
	tmRtspMutiCastStreamCfg_t		tRtspMuticast[8];
}tmRtspMutiCastCfg_t;

/* �����������ýṹ */
typedef struct tmWifiCfg_t
{
	unsigned int		dwSize;						/*���ṹ��С*/	
	unsigned char		byEnable;					/*�����Ƿ�����	*/
	unsigned char		byDhcp;						/*���ߵ�ַ��ʽ,1���ö�̬IP��ȡ,0ָ��IP*/
	
	char				sIpAddr[16];				/*Wifi��ַ  */
	char				sIpMaskAddr[16];			/*Wifi��ַ����  */
	char				sGatewayIP[16];       		/*Wifi���ص�ַ */
	char				sDNSIP1[16];				/*WifiDNS1��ַ*/
	char				sDNSIP2[16];				/*WifiDNS2��ַ*/
	
	char				sSsid[48];					/*��������SSID����32*/
	char				sKey[48];					/*��Կ����32*/
	unsigned char		byKeyMgmt;					/*���������֤0-����,1-����,2-WPA,3-WPA-PSK,4-WPA2,5-WPA2-PSK*/
	unsigned char		byKeyType;					/*���ݼ���0-���ã�1-WEP��2-TKIP,3-AES*/
	unsigned char		byKeyIndex;					/*��������*/
	unsigned char		byScanSsid;					/*��ʹû�й㲥Ҳ����*/
	unsigned int		dwWpaPtkRekey;				/*������Կʱ��*/

	BYTE				byMACAddr[6];				/*WifiMac��ַ*/

	unsigned char		byKeyFormat;				/*�����ʽ0-�ַ���,1-16��*/
	unsigned char		byTemp[3];
}tmWifiCfg_t;

/*2010-09-39 add by stone*/
typedef struct tmDDNSCfg_t
{
	unsigned int		dwSize;
	unsigned char		byDDNSEnable;
	unsigned char		byTemp[3];
	char				sDDNSServerName[32];		/*DDNS����������*/
	char				sDDNSServerName2[32];		/*����DDNS����������*/
	char				sDDNSName[32];				/*DDNS����*/
	char				sDDNSUser[32];				/*DDNS�û���*/
	char				sDDNSPassword[32];			/*DDNS����*/
}tmDDNSCfg_t;

/*2007/11/29 frankxia add for Simpe Network Time Protocol Server*/
typedef struct tmNTPCfg_t
{
	unsigned int	dwSize;
	/*ʵ�ʵ�NTP���������� 1<=dwCount<= NTPSERVER_MAX*/
	unsigned int	dwCount;
	/*����ʹ�õķ���������,0<=dwIdx<MAX_NTP_SERVERS*/
	unsigned int	dwIdx;		
	/*��������NTP�������ĸ���*/
	char			strNTPServer[MAX_NTP_SERVERS][PATHNAME_LEN];	
}tmNTPCfg_t;

typedef struct tmNTPCfgEx_t
{
	unsigned int	dwSize;
	/*�Ƿ�����*/
	unsigned int	dwEnableNtp;
	/*ͬ��ʱ����(��λ:����)*/
	unsigned int	dwNtpTime;		
	/*��������NTP�������ĸ���*/
	char			strNTPServer[128];	
}tmNTPCfgEx_t;

/*2007/12/26 frankxia add for ftp file recorder*/
/*FTP���������ã�������*/
typedef struct tmFTPCfg_t
{
	/*���ṹ��С*/
	unsigned int	dwSize;	

	/*�Ƿ�����FTP������*/
	unsigned char	byUseFTP;

	/*�������128�ֽ�*/
	char			strFTPServerIpAddr[128];

	/*FTP¼������ID��*/
	unsigned char	byRecordStreamId;

	/*¼���ʽ����ʱδ��*/
	unsigned char	byRecordFormat;

	/*�Ƿ�����ָ��Ŀ¼���*/
	unsigned char	byEnableDirectory;

	/*�������Ķ˿ڣ�ftpĬ��21*/
	unsigned int	dwServerPort;

	/*FTP�������û���*/
	char			strFTPCliUserName[16];

	/*FTP�������û�����*/
	char			strFTPCliUserPass[16];

	/*��¼�ļ���ʱ��*/
	unsigned int	dwFTPRecordFileSize;

	/*ָ���Ĵ��Ŀ¼*/
	char			strDirectoryName[128];
}tmFTPCfg_t;


/*2007/12/26 frankxia add for sendmail*/
typedef struct tmSMTPCfg_t
{
	unsigned int	dwSize;	
	/*�Ƿ������ʼ�������*/
	unsigned char	byUseSMTP;
	/*�ʼ���������ַ*/
	char			strSMTPServerIpAddr[128];/*�������128�ֽ�*/
	/*�ֽڶ��䱣��*/
	unsigned char	byReserves[3];
	/*�ʼ��������û���*/
	char			strSMTPCliUserName[16];
	/*�ʼ��������û�����*/
	char			strSMTPCliUserPass[16];
}tmSMTPCfg_t;

/*�豸�������ö���*/
typedef struct tmLiveHeartCfg_t
{
	unsigned int		dwSize;							/*�ýṹ�Ĵ�С��������д*/
	unsigned char		byEnableLiveHeart;				/*�Ƿ���������*/
	unsigned char		byLiveHeartMode;				/*����������ģʽ0-UDP,1-TCP/IP*/
	unsigned short		wLiveTime;						/*�����������ʱ��(��λ:��)*/
	char				sServerAddress[32];				/*Զ�̹���������ַ*/
	unsigned int		dwServerPort;					/*Զ�̹��������˿ں�*/
	unsigned char		byEnableRecord;					/*�Ƿ����ö����Զ�¼��*/
	unsigned char		byTem[3];
}tmLiveHeartCfg_t;

/*�豸�����������ϴ���������Ϣ*/
typedef struct tmStreamUpToServerCfg_t
{
	unsigned short		dwSize;							/*�ýṹ�Ĵ�С��������д*/
	unsigned char		byEnable;						/*�Ƿ������Զ��ϴ�*/
	unsigned char		byTemp;							/*����*/
	char				sServerAddress[64];				/*Զ�̹���������ַ*/
	unsigned short		wControlPort;					/*Զ�̹��������˿ں�*/
	unsigned short		wStreamPort;					/*Զ�̹��������˿ں�*/
	unsigned short		wTalkPort;						/*Զ�̹��������˿ں�*/
	unsigned short		wTemp;							/*����*/
	char				sDeviceNumber[32];				/*�豸���к�*/
}tmStreamUpToServerCfg_t;

/* ʱ�����ã����ӷ��еõ�ʱ�䣬����ʱ��ϵͳʱ�� */
typedef struct tmTimeCfg_t
{
	unsigned int	dwSize;
	unsigned short	wYear;			/*��*/
	unsigned short	wMonth;			/*��*/
	unsigned short	wDay;			/*��*/
	unsigned short	wDayOfWeek;		/*��*/
	unsigned short	wHour;			/*ʱ*/
	unsigned short	wMinute;		/*��*/
	unsigned short	wSecond;		/*��*/
	short			wTimeZone;		/*ʱ��*/	
	int				iDayLightTime;	/*����ʱʱ��ƫ���	*/
	unsigned short	wZoneIndex;		/*ʱ����������,����wTimeZoneȷ��ʱ��������wZoneIndexȷ�����ĸ������������ͬʱ����ͬ����������*/
	unsigned char	byTemp[2];
}tmTimeCfg_t;

/*ʱ�䶨��*/
typedef struct tmTimeInfo_t
{
	unsigned short	wYear;			/*��*/
	unsigned char	byMonth;		/*��*/
	unsigned char	byDay;			/*��*/
	unsigned char	byHour;			/*ʱ*/
	unsigned char	byMinute;		/*��*/
	unsigned char	bySecond;		/*��*/
	unsigned char	byTemp;			/*����*/
	unsigned int	dwMicroSecond;	/*����*/
}tmTimeInfo_t;

/* ʱ�䷶Χ */
typedef struct tmSchedTime_t
{
	unsigned int	dwSize;
	/*��ʼʱ��*/
    unsigned char	byStartHour;
	unsigned char	byStartMin;
	/*����ʱ��*/
	unsigned char	byStopHour;
	unsigned char	byStopMin;
}tmSchedTime_t;

/* ��������ʽ*/
#define NOACTION			0x00				/*����Ӧ*/
#define WARNONMONITOR		0x01				/*�������Ͼ���*/
#define WARNONAUDIOOUT		0x02				/*��������*/
#define UPTOCENTER			0x04				/*�ϴ�����*/
#define TRIGGERALARMOUT		0x08				/*�����������*/
#define UPTOCTRLCLIENT		0x10				/*�ϴ����ƿͻ���*/
#define UPTOAVCLIENT		0x20				/*�ϴ�����Ƶ�ͻ���*/
typedef struct tmHandleException_t
{
	unsigned char		byRelAlarmOutEnable[4];	/* �������������ЧbyRelAlarmOutEnable[0]Ϊ12�򱨾����0-3 */
	unsigned int		dwHandleType;			/*����ʽ,����ʽ��"��"���*/
	unsigned char		byRelAlarmOut[4];		/*�������������ͨ��,�������������,Ϊ1��ʾ���������*/
}tmHandleException_t;


/* ���������� */
typedef struct tmTransFer_t
{
	/*ȡ���ṹ��С����*/
	unsigned char	byTransFerType;			/* ������������12ΪtmTransFer_tΪͨ������0-16, 13Ϊͨ����byChannel����*/
	unsigned char	byChannel;				/* ͨ����0-MAX_CHANNUM */
	unsigned char	byTemp[2];				/* ���� */
	unsigned char	byEnableRelRecordChan;	/* ����������¼��ͨ��,Ϊ1��ʾ������ͨ�� */
	unsigned char	byEnablePreset;			/* �Ƿ����Ԥ�õ� */
	unsigned char	byPresetNo;				/* ���õ���̨Ԥ�õ����,һ������������Ե��ö��ͨ������̨Ԥ�õ�*/
	unsigned char	byEnableCruise;			/* �Ƿ����Ѳ�� */
	unsigned char	byCruiseNo;				/* Ѳ�� */
	unsigned char	byEnablePtzTrack;		/* �Ƿ���ù켣 */
	unsigned char	byPTZTrack;				/* ���õ���̨�Ĺ켣��� */
	unsigned char	byEnableCaptureChan;	/* ����������ץͼͨ����Ϊ1��ʾ������ͨ�� */
}tmTransFer_t;

/* ͨ��ͼ��ṹ, �����壬������704*576 */
typedef struct tmAreaScope_t
{
	unsigned short	wAreaTopLeftX;		/* �����x���� */
	unsigned short	wAreaTopLeftY;		/* �����y���� */
	unsigned short	wAreaWidth;			/* ����Ŀ� */
	unsigned short	wAreaHeight;		/* ����ĸ� */
}tmAreaScope_t;
/* �ƶ���� */
typedef struct tmMotion_t
{
	unsigned int			dwSize;	
	unsigned char			byMotionScopeNum;							/*����������������С�ڻ����5*/
	tmAreaScope_t			struMotionScope[5];							/*�������704*576*/
	unsigned char			byMotionSensitive;							/*�ƶ����������, 0 - 5,Խ��Խ����*/
	unsigned char			byMotionThreshold;							/*�ƶ���ֵⷧ��Ϊ�����ƶ�����ĺ�������ٷֱȣ�0-100����Ϊ0ʱֻҪ��һ������ƶ������ƶ�*/
																		/*��ԽСԽ����*/
	unsigned char			byEnableHandleMotion;						/*�Ƿ����ƶ����*/ 
	tmHandleException_t		strMotionHandleType;						/*����ʽ*/
	tmSchedTime_t			struAlarmTime[7][4];						/*����ʱ��*/
	tmTransFer_t			struAlarmTransFer[16];						/*����ͨ��*/
}tmMotion_t;

/* �ƶ���� */
typedef struct tmVideoMotionCfg_t
{
	unsigned int			dwSize;	
	tmAreaScope_t			struMotionScope[5];							/*�������704*576*/
	unsigned char			byMotionScopeNum;							/*����������������С�ڻ����5*/	
	unsigned char			byMotionSensitive;							/*�ƶ����������, 0 - 5,Խ��Խ����*/
	unsigned char			byMotionThreshold;							/*�ƶ���ֵⷧ��Ϊ�����ƶ�����ĺ�������ٷֱȣ�0-100����Ϊ0ʱֻҪ��һ������ƶ������ƶ�*/																		/*��ԽСԽ����*/
	unsigned char			byEnableHandleMotion;						/*�Ƿ����ƶ����*/ 
	tmHandleException_t		strMotionHandleType;						/*����ʽ*/
	tmSchedTime_t			struAlarmTime[7][4];						/*����ʱ��*/
	tmTransFer_t			struAlarmTransFer[16];						/*����ͨ��*/
	unsigned int			dwHandleMinTime;							/*����������Сʱ�䣬��λ����(�ڴ�ʱ�����жԴ˱���ֻ����һ��)*/
}tmVideoMotionCfg_t;

/* �ڵ���������Ϊ704*576 */
typedef struct tmHideAlarm_t
{
	unsigned int			dwSize;
	unsigned char			byHideSensitive;			/* �ڵ������� ,0 - 5,Խ��Խ���� */
	tmAreaScope_t			struHideAlarmArea;			/* �ڵ����� */
	unsigned char			byEnableHandleHideAlarm;	/* �Ƿ����źŶ�ʧ���� */ 
	tmHandleException_t		strHideAlarmHandleType;		/* ����ʽ */	
	tmSchedTime_t			struAlarmTime[7][4];		/* ����ʱ�� */	
}tmHideAlarm_t;
/* �ڵ�����������չΪ704*576 */
typedef struct tmVideoHideCfg_t
{
	unsigned int			dwSize;
	tmAreaScope_t			struHideAlarmArea;			/* �ڵ����� */
	unsigned char			byHideSensitive;			/* �ڵ������� ,0 - 5,Խ��Խ���� */
	unsigned char			byEnableHandleHideAlarm;	/* �Ƿ����źŶ�ʧ���� */ 
	unsigned char			byHideScopeNum;				/*�ڵ��������������С�ڻ����5*/
	unsigned char			byTemp[1];
	tmHandleException_t		strHideAlarmHandleType;		/* ����ʽ */	
	tmSchedTime_t			struAlarmTime[7][4];		/* ����ʱ�� */
	unsigned int			dwHandleMinTime;			/* ����������Сʱ�䣬��λ����(�ڴ�ʱ�����жԴ˱���ֻ����һ��) */
	tmAreaScope_t			struHideAlarmAreaEx[4];		/* ����������չ��Ϊ�˳������ֻ��������4�������,�ܹ�5��*/
}tmVideoHideCfg_t;

/* �źŶ�ʧ���� */
typedef struct tmViLost_t
{
	unsigned int			dwSize;
	unsigned char			byEnableHandleVILost;		/* �Ƿ����źŶ�ʧ���� */ 
	tmHandleException_t		strVILostHandleType;		/* ����ʽ */	
	tmSchedTime_t			struAlarmTime[7][4];		/* ����ʱ�� */
}tmViLost_t;

/* �źŶ�ʧ������չ */
typedef struct tmVideoLostCfg_t
{
	unsigned int			dwSize;
	unsigned char			byEnableHandle;				/* �Ƿ����źŶ�ʧ���� */ 
	unsigned char			byTemp[3];
	tmHandleException_t		strHandleType;				/* ����ʽ */	
	tmSchedTime_t			struAlarmTime[7][4];		/* ����ʱ�� */
}tmVideoLostCfg_t;

/* ��Ƶ�ڵ����� */
typedef struct tmVideoMaskCfg_t
{
	unsigned int			dwSize;
	unsigned char			byEnableMask;				/* �Ƿ������ڵ� ,0-��,1-�� ����Ϊ704*576*/
	unsigned char			byTemp[3];
	tmAreaScope_t			struHideArea[4];			/*�ڵ�����*/
}tmVideoMaskCfg_t;

/* ����������� */
typedef struct tmFaceDetectCfg_t
{
	unsigned int			dwSize;
	unsigned char			byEnable;				/* �Ƿ������ڵ� ,0-��,1-��*/
	unsigned char			byTemp[3];
}tmFaceDetectCfg_t;

/* ���ܸ��٣���Ҫһ�����о����Ч */
typedef struct tmAptitudeScoutCfg_t
{
	unsigned int			dwSize;	
	unsigned char			byEnable;					/*�Ƿ�����*/	
	unsigned char			byTimeOut;					/*���ٳ�ʱʱ�� 60s-200s*/
	unsigned char			byTemp[2];					/*����*/
}tmAptitudeScoutCfg_t;

/* ͼ��Ԥ������ */
typedef struct tmPicPreviewCfg_t
{
	unsigned int			dwSize;
	unsigned char			dwVideoFormat;				/*ֻ������Ƶ��ʽ 0-PAL 1-NTSC*/
	unsigned char			byTemp[1];
	unsigned char			byEnableAcutanceA;			/*�Ƿ�����0-������ʹ�ã�����byAcutance���ã�1-����ʹ��*/
	unsigned char			byAcutanceA;				/*���A,0-255*/   
	short					byBrightness;  				/*����,0-255*/
	short					byContrast;    				/*�Աȶ�,0-255*/	
	short					bySaturation;  				/*���Ͷ�,0-255 */
	short					byHue;    					/*ɫ��,0-255*/
	short					byAcutance;					/*���,0-255*/   
}tmPicPreviewCfg_t;

/* ͼ��Ԥ������ */
typedef struct tmPicPreviewInfo_t
{
	/*����,0-255*/
	unsigned char	byBrightness;
	/*�Աȶ�,0-255*/
	unsigned char	byContrast;
	/*���Ͷ�,0-255 */
	unsigned char	bySaturation;
  	/*ɫ��,0-255*/
	unsigned char	byHue;
}tmPicPreviewInfo_t;

/*ͼ��ģʽԤ��ƻ�*/
typedef struct tagPicModeScheduleInfo_t
{
	/*ʱ�����Ϣ����ʼʱ*/
	unsigned char		byStartHour;      
	unsigned char		byStartMin;
	unsigned char		byStopHour;
	unsigned char		byStopMin;
	
	/*�Ƿ����ñ�־: 0-������; 1-����*/
	unsigned char		byEnable;         
	/*��Ƶģʽ����: 0-����ģʽ; 1-ǿ��ģʽ; 2-����ģʽ; 3-ҹ��ģʽ*/
	unsigned char		byMode;  
	/*��չ�����(0-255)*/
	unsigned char		byAcutance;
	/*����*/
	unsigned char		byTemp;     
}tmPicModeScheduleInfo_t;

typedef struct tagPicModeScheduleCfg_t
{
	unsigned int					dwSize ;
	/*ͼ��ģʽ:0-����ģʽ; 1-ǿ��ģʽ; 2-����ģʽ; 3-ҹ��ģʽ*/
	tmPicPreviewInfo_t				struMode[4];                  
	/*����0��1��2.3�ֱ�����ĸ�ʱ���*/
	tmPicModeScheduleInfo_t			struModeSched[4];   
}tmPicModeScheduleCfg_t;

/*��ͼ��ɼ�ƫ��΢������ */
typedef struct tmVideoOffsetCfg_t
{
	unsigned int	dwSize;	
	short			offset_left;
	short			offset_top;
	short			offset_right;
	short			offset_bottom;
}tmVideoOffsetCfg_t;

/* ͼ��OSD�������� */
typedef struct tmVideoOsdCfg_t
{
	unsigned int			dwSize;

	char					sChanName[64];				/* ͨ���� */
	unsigned short			wShowNameTopLeftX;			/* ͨ��������ʾλ�õ�x���� */
	unsigned short			wShowNameTopLeftY;			/* ͨ��������ʾλ�õ�y���� */
	unsigned char			byShowChanName;				/* Ԥ����ͼ�����Ƿ���ʾͨ������,0-����ʾ,1-��ʾ ����Ϊ704*576 */
	unsigned char			byNameCoordinateMode;		/* ����ģʽͨ��ģʽ*/
														/* 0-������Ͻǣ�1-������Ͻǣ�2-������½ǣ�3-������½�*/

	unsigned short			wShowTimeTopLeftX;			/* OSD��x���� */
	unsigned short			wShowTimeTopLeftY;			/* OSD��y���� */
	unsigned char			byShowTime;					/* Ԥ����ͼ�����Ƿ���ʾOSD,0-����ʾ,1-��ʾ*/
	unsigned char			byTimeType;					/* OSD����(��Ҫ�������ո�ʽ) */
														/* 0: xxxx/xx/xx xx:xx:xx ��/��/�� ʱ����*/
														/* 1: xx/xx/xxxx xx:xx:xx ��/��/�� ʱ����*/
														/* 2: xx:xx:xx ʱ����*/
														/* 3: xxxx-xx-xx xx:xx:xx ��-��-�� ʱ����*/
														/* 4: xx-xx-xxxx xx:xx:xx ��-��-�� ʱ����*/
														/* 5: xx-xx-xxxx xx:xx:xx ��-��-�� ʱ���� wangjun*/
														/* 6: xx/xx/xxxx xx:xx:xx ��/��/�� ʱ���� wangjun*/
														/* 7: xxxx��xx��xx�� xxʱxx��xx�� wangjun*/
														/* 8: xxxx��xx��xx�� xx:xx:xx */
	unsigned char			byShowWeek;					/* �Ƿ���ʾ���� */	
	unsigned char			byWeekType;					/* ��������0-���ģ�1-Ӣ�� */
	unsigned char			byTimeCoordinateMode;		/* ����ģʽʱ��ģʽ*/

	unsigned char			byOsdAttrib;				/* OSD����: */
														/* 0: ��͸�� */	
														/* 1: ��͸�� */	
														/* 2: ��͸������ */	
	unsigned char			byFontMode;					/* OSD������ģʽͨ������С */	
	unsigned char			byAlignMode;				/* �ַ����������\n��������ʾ��ͷ�����뷽ʽ,0-�Ҷ��룬1-�м䣬2-����룬0xFF-�Զ�*/
	unsigned char			byFontMode1;				/* OSD������ģʽʱ�� */	
	unsigned char			byFontMode2;				/* OSD������ģʽ��չ�ַ� */	

	/*��չ��ʾ�ı���*/
	char					sShowText[256];				/* ��չ�ı��� */
	unsigned short			wShowTextTopLeftX;			/* ��չ�ı�����ʾλ�õ�x���� */
	unsigned short			wShowTextTopLeftY;			/* ��չ�ı�����ʾλ�õ�y���� */
	unsigned char			byShowText;					/* Ԥ����ͼ�����Ƿ���ʾ��չ�ı���,0-����ʾ,1-��ʾ ����Ϊ704*576 */
	unsigned char			byTextCoordinateMode;		/* ����ģʽ*/
														/* 0-������Ͻǣ�1-������Ͻǣ�2-������½ǣ�3-������½�*/
	unsigned char			byTextExpandMode;			/* �Ƿ�������չ����Ĳ˵�ģʽ*/
	unsigned char			byTextBackGroundMode;		/* ��չOSD������Сģʽ 0-�Ը�Ϊ׼��1-�Կ�Ϊ׼��2-�Զ���ͼ���������, 3-ָ����С*/

	unsigned char			byTextBackGroundColor;		/* ����͸���� */
	unsigned char			byNameColorMode;			/* ͯ����������ɫ����0~15 */
	unsigned char			byTimeColorMode;			/* ʱ��������ɫ����0~15 */
	unsigned char			byTextColorMode;			/* ��չ�ַ�������ɫ����0~15 */

	unsigned short			wTextBackGroundWidth;		/* ��չ������ȣ������704*576 */
	unsigned short			wTextBackGroundHeight;		/* ��չ�����߶ȣ������704*576 */
}tmVideoOsdCfg_t;

/*OSD��ɫ��������*/
typedef struct tmVideoOsdColorInfo_t
{
	/*����������ɫRGB*/
	unsigned char			byEnable;
	unsigned char			byFontR;
	unsigned char			byFontG;
	unsigned char			byFontB;
	/*�����Ե��ɫRGB*/
	unsigned char			byEnableEdge;
	unsigned char			byEdgeR;
	unsigned char			byEdgeG;
	unsigned char			byEdgeB;
	/*���屳����ɫRGB*/
	unsigned char			byEnableBack;
	unsigned char			byBackR;
	unsigned char			byBackG;
	unsigned char			byBackB;
	unsigned char			byBackAlpha;
	unsigned char			byTemp[3];
}tmVideoOsdColorInfo_t;
typedef struct tmVideoOsdColorCfg_t
{
	unsigned int			dwSize;
	tmVideoOsdColorInfo_t	struColorMode[COLOR_MODE_NUM];
}tmVideoOsdColorCfg_t;

typedef struct tmVideoExpandOsdInfo_t
{
	/*λ�úʹ�С��Ϣ�������704*576*/
	tmAreaScope_t			pos;
	/*�����С*/
	unsigned char			size;
	/*������ɫ*/
	unsigned char			color;
	/*ģʽ0-�����ַ�����1-����2-����ƶ�����*/
	unsigned char			mode;
	/*�Ƿ����˵�����Ϣ���������ǲ��ܸ��������������*/
	unsigned char			save;
	/*�ַ���Ϣ*/
	char					szInfo[256];
}tmVideoExpandOsdInfo_t;

typedef struct tmVideoExpandOsdCfg_t
{
	unsigned int			dwSize;
	int						iCount;
	tmVideoExpandOsdInfo_t	struOsdInfo[1];
}tmVideoExpandOsdCfg_t;

/* ͼ����� */
typedef struct tmPicCfg_t
{
	unsigned int			dwSize;
	char					sChanName[32];
	unsigned int			dwVideoFormat;				/* ֻ������Ƶ��ʽ 0-PAL 1-NTSC*/

	/*��ʾͨ����*/
	unsigned int			dwShowChanName;				/* Ԥ����ͼ�����Ƿ���ʾͨ������,0-����ʾ,1-��ʾ ����Ϊ704*576 */
	unsigned short			wShowNameTopLeftX;			/* ͨ��������ʾλ�õ�x���� */
	unsigned short			wShowNameTopLeftY;			/* ͨ��������ʾλ�õ�y���� */
	unsigned char			byShowNamAttrib;			/* ��������:͸�� */

	/*�źŶ�ʧ����*/
	tmViLost_t				struVILost;
	/*�ƶ����*/
	tmMotion_t				struMotion;	
	/*�ڵ�����*/
	tmHideAlarm_t			struHideAlarm;
	/*�ڵ�*/
	unsigned char			dwEnableHide;				/* �Ƿ������ڵ� ,0-��,1-�� ����Ϊ704*576*/
	tmAreaScope_t			struHideArea;				/*�ڵ�����*/

	unsigned int			dwShowOsd;					/* Ԥ����ͼ�����Ƿ���ʾOSD,0-����ʾ,1-��ʾ*/
	unsigned short			wOSDTopLeftX;				/* OSD��x���� */
	unsigned short			wOSDTopLeftY;				/* OSD��y���� */
	unsigned char			byOSDType;					/* OSD����(��Ҫ�������ո�ʽ) */
														/* 0: xxxx/xx/xx xx:xx:xx ������ ʱ����*/
														/* 1: xx/xx/xxxx xx:xx:xx ������ ʱ����*/
														/* 2: xx:xx:xx ʱ����*/
	unsigned char			byDispWeek;					/* �Ƿ���ʾ���� */	
	unsigned char			byOSDAttrib;				/* OSD����:͸�� */
														/* 0: ��͸�� */	
														/* 1: ��͸�� */	
	char					sWeekName[7][20];			/*�������ƣ�0Ϊ����һ��6Ϊ������*/

	unsigned char			byEnableStreamNum;			/*�Ƿ�֧��˫������0-��������1-˫�������˲������������NVSӲ������*/
}tmPicCfg_t;

/*ѹ������*/
typedef struct tmCompression_t
{
	/*�˽ṹֵ�޸�Ϊ�����ʽ��Ϊ�˱���һ�´�ֵ����Ϊ16*/
	/*unsigned int	dwSize;*/
	/*��Ƶ�����ʽ��0-BKMPEG4,1-H264,2-MJPEG,3-H265,10-YPbPr,11-cvbs,12-hdmi,13-Digital*/
	unsigned char		byCompressFormat;

	/*�ؼ�֡��� : 0x00 ��ʾʹ��Ĭ�ϣ�0xFF ��ʾȫ�ؼ�֡;����ֵ��ʾ�ؼ�֡֡���*/
	unsigned char		byKeyFrameInterval;

	/*���õ�ȫ֡ʱ��ʾ��֡��*/
	unsigned char		byDisplayFrame;
	/*�Ƿ�����ͼ����������*/
	unsigned char		byEnableQuality;

	/*��������0-��Ƶ��,1-������*/
	unsigned char		byStreamType;

	/*�ֱ���
	 0-CIF(352x288) 1-QCIF(176x144), 2-2CIF(704x288), 3-4CIF(704x576), 
	 4-QQCIF(88x72), 5-DCIF(512x384), 6-VGA(640x480), 7-QDICF(256x192), 8-QVGA(320x240),
	 9-800x600, 10-1024x768 11-1280x720, 12-D1(720x576),
	 13-1600x1200, 14-1440x1080, 15-1920x1080, 16-1280x1024, 17-1280x960
	 18-1920x1200, 19-2048x1152, 20-2048x1536, 21-2560x1440, 22-2592x1944
	 23-960x576, 24-2304x1296, 25-3072x2048, 26-3840x2160, 27-4096x2160, 28-4000x3000
	 29-1280x1280, 30-2880x720
	*/
	unsigned char		byResolution;

	/*��������0:������, 1:������, 2:������*/
	unsigned char		byBitrateType;

	/*ͼ������ 0-��� 1-�κ� 2-�Ϻ� 3-һ�� 4-�ϲ� 5-�� 6-���*/	
	unsigned char		byPicQuality;

	/*��Ƶ���� 0-���� 1-���� 2-32K 3-48k 4-64K 5-80K 6-96K 7-128K 8-160k 9-192K 10-224K 11-256K 12-320K
	  13-384K 14-448K 15-512K 16-640K 17-768K 18-896K 19-1024K 20-1280K 21-1536K 22-1792K 23-2048K
	  ���λ(32λ)�ó�1��ʾ���Զ�������, 0-31λ��ʾ����ֵ(MIN-16K MAX-8192K)��
	*/
	unsigned int		dwVideoBitrate; 

	/*֡�� 0-ȫ��; 1-1/16; 2-1/8; 3-1/4; 4-1/2; 5-1; 6-2; 7-4; 8-6; 9-8; 10-10; 11-12; 12-16; 13-20;
	  ��չ 14-1/15; 15-1/14: 16-1/13; 17-1/12; 18-1/11; 19-1/10; 20-1/9; 21-1/7; 22-1/6; 23-1/5; 24-1/3;
	  25-ʹ��byVideoFrameRate��ʵ��֡��
	*/
	unsigned char		dwVideoFrameRate;
	unsigned char		byVideoFrameRate;
	
	/*H26x���뼶��<10-Ĭ��, 10-Baseline, 11-MainProfile, 12-HighProfile*/
	unsigned char		byProfileLevel;
	unsigned char		byTemp1;
}tmCompression_t;

typedef struct tmCompressionCfg_t
{
	unsigned int			dwSize;
	/*¼����������*/
	tmCompression_t			struRecordPara;		
	/*���紫������������*/
	tmCompression_t			struNetPara;
	/*��3����������*/
	tmCompression_t			struThirdPara;
	/*��ϱ����ʽ������������µı��뷽ʽ��������Ϊ0*/
	unsigned char			byFormatId;
	/*0λ��ʾD1ʹ�õķֱ���(0-720x576,1-704x576)*/
	unsigned char			byResolutionCfg;
	/*�����������Ǽ���ģʽ0-�����ܣ�1-����*/
	unsigned char			byStreamEncryptMode;
	/*����*/
	unsigned char			byTemp;
	/*��4����������*/
	tmCompression_t			struFourthPara;
	/*��5678����������*/
	tmCompression_t			struOtherPara[4];
}tmCompressionCfg_t;

/* �����������������������Ϣ */
typedef struct tmVideoEnjoyInfo_t
{
	unsigned char			byEnable;							/*�Ƿ�����5*/	
	unsigned char			byScopeNum;							/*������*/
	unsigned char			byTemp[2];							/*����*/
	struct
	{
		tmAreaScope_t		struScope;						/*�������704*576*/
		unsigned char		byQuality;						/*���������*/
		unsigned char		byLevel;						/*����ı��뼶��*/
		unsigned char		byTemp[6];
	}scope[4];
	unsigned char			byResTemp[12];
}tmVideoEnjoyInfo_t;
/* �������������� */
typedef struct tmVideoEnjoyCfg_t
{
	unsigned int			dwSize;	
	tmVideoEnjoyInfo_t		struEnjoy[8];
}tmVideoEnjoyCfg_t;

/*������Ϣ*/
typedef struct tmStreamDescription_t
{
	unsigned char			byResolution;			/*ͼ���С��ʽ����*/
	unsigned char			byFormat;				/*�����ʽ*/
	unsigned char			byFrameRateNum;			/*֡���б���*/
	unsigned char			byType;					/*��������0-ѹ�����룬1-���ֻ�ģ�������2-ץͼ����*/
	unsigned char			byFramesRateList[MAX_FRAMERATE_NUM];	/*֡���б�*/
	unsigned char			byMaxFrameRate;			/*���֡������*/
	unsigned short			nWidth;					/*ͼ���*/
	unsigned short			nHeight;				/*ͼ���*/
	unsigned char			byTemp[2];				/*����*/
	unsigned int			dwMaxBitRate;			/*��������*/
	unsigned int			dwDisplayRatio;			/*��ʾ����ȷ����*1000*/
}tmStreamDescription_t;

/*����������ѯ*/
typedef struct tmCompressCapability_t
{
	char					sName[64];			/*�����ʽ����,��1080P(H264) + D1(H264)*/
	unsigned char			byFormatId;			/*�����ʽ*/
	unsigned char			byStreamCount;		/*������*/
	unsigned char			byTemp[2];
	tmStreamDescription_t	struStreamFormat[4];/*�����ı����ʽ*/
}tmCompressCapability_t;

typedef struct tmCompressCapabilityCfg_t
{
	unsigned int			dwSize;				/*���ṹ��С*/
	unsigned int			dwCount;			/*֧�ֵ�ѹ����ʽ��*/
	tmCompressCapability_t	struCapability[1];	/*��ϱ����б����������Զ���һ��*/
}tmCompressCapabilityCfg_t;

/*��չ����������ѯ*/
typedef struct tmCompressCapabilityEx_t
{
	char					sName[128];			/*�����ʽ����,��1080P(H264) + D1(H264)*/
	unsigned char			byFormatId;			/*�����ʽ*/
	unsigned char			byStreamCount;		/*������*/
	unsigned char			byTemp[2];
	tmStreamDescription_t	struStreamFormat[8];/*�����ı����ʽ*/
}tmCompressCapabilityEx_t;

typedef struct tmCompressCapabilityExCfg_t
{
	unsigned int				dwSize;				/*���ṹ��С*/
	unsigned int				dwCount;			/*֧�ֵ�ѹ����ʽ��*/
	tmCompressCapabilityEx_t	struCapability[1];	/*��ϱ����б����������Զ���һ��*/
}tmCompressCapabilityExCfg_t;

/*��Ƶѹ�������ýṹ�������������������ϵͳ������ͨ��*/
typedef struct tmAudioCfg_t
{
	/*���ṹ��С*/
	unsigned int		dwSize;
	/*��Ƶ�����ʽ���ο���Ƶ�����ʽ�б�*/
	unsigned char		byCompressFormat;
	/*Ҫ����Ƶ������0-��������1-��������2-������*/
	unsigned char		byChannelMode;
	/*��Ƶѹ������Ĭ��0-Ĭ��,1-16K,2-24K,3-32K,4-40K,5-48K,6-56K,7-64K,8-128K,9-256K*/
	unsigned char		byBitRate;
	/*��Ƶ������0-Ĭ��, 1-8000Hz, 2-16000Hz, 3-22050Hz, 4-44100Hz, 5-48000Hz*/
	unsigned char		bySamplesRate;
	/*��Ƶ�Ŵ���*100,��1��ʾ0.01,100��ʾ1*/
	unsigned int		dwLampFactor;
	/*����ѡ��0-ѡ����Ƶ���룬1-ѡ��MIC����*/
	unsigned char		byAudioInMode;
	/*����*/
	unsigned char		byTemp;
}tmAudioCfg_t;
/*��Ƶ�����ʽ�б�*/
#define TMCC_AUDIO_ENCTYPE_MP2		0x00
#define TMCC_AUDIO_ENCTYPE_AAC		0x01
#define TMCC_AUDIO_ENCTYPE_MULAW	0x02
#define TMCC_AUDIO_ENCTYPE_ALAW		0x03
#define TMCC_AUDIO_ENCTYPE_G721		0x04
#define TMCC_AUDIO_ENCTYPE_G722		0x05
#define TMCC_AUDIO_ENCTYPE_G723_24	0x06
#define TMCC_AUDIO_ENCTYPE_G723_40	0x07
#define TMCC_AUDIO_ENCTYPE_G726		0x08
#define TMCC_AUDIO_ENCTYPE_G729		0x09
#define TMCC_AUDIO_ENCTYPE_S16LE	0x0A


/*�����ץ�Ķ���*/
typedef struct tmCaptureImageCfg_t
{
	/*���ṹ��С*/
	unsigned int		dwSize;
	/*ͼ���ʽ��0-BMP, 1-JPEG, 2-H264, 3-YUV, 4-H265Ŀǰ����ֻ����1*/
	unsigned char		byFormat;
	/*ץͼ���λ��0-���浽����Ӳ�̣�1-�ϴ���FTP������,2-ͨ������ͨ���ϴ�*/
	/*3-���ر���ͬʱ�ϴ�FTP,4-���ر���ͬʱ�ϴ�����ͨ��*/
	unsigned char		bySaveMode;
	/*ÿ�α���ץͼ��Ŀ1~5*/
	unsigned char		byCaptureNum;
	/*�Ƿ�����ָ��Ŀ¼���*/
	unsigned char		byEnableDirectory;
	/*ץͼ�ļ��ʱ�����*/
	unsigned int		dwCaptureInterval;

	/*ץͼFTP����������*/
	/*�������128�ֽ�*/
	char				sFTPServerIpAddr[128];

	/*�������Ķ˿ڣ�ftpĬ��21*/
	unsigned int		dwFTPServerPort;

	/*FTP�������û���*/
	char				sFTPCliUserName[16];

	/*FTP�������û�����*/
	char				sFTPCliUserPass[16];
	
	/*ץͼ�Ĵ��Ŀ¼*/
	char				sDirectoryName[128];

	/*ץͼ����Ϊ������0-��������1-��������2-��3������3-��4������0xFFʹ��Ĭ����������Ĭ������ѡ���*/
	unsigned char		byCaptureStream;
	
	/*ץͼͨ���Ƿ���Ӻ�������һ����OSD��Ϣ������ֻ����е�����ץͼͨ����������������������ô���*/
	unsigned char		byRenderOsdInfo;

	/*����ץͼʱ�����һֱ�б�������ôÿ�ο�ʼץͼ��ʱ��������λ�룬Ĭ��1��,0Ϊ��ʼ������ץͼ*/
	/*ע�⵱����ͣ�������10����ٱ���Ϊ����һ�α�����������ǰһ�α���*/
	unsigned char		byAlarmIntervalCapture;
	/*Ĭ��ץͼ����0-�Զ�ѡ�����ץͼ(����ѡ������MJPEG����ѡ��������)��1-������ץͼ��2-2����ץͼ��3-3����ץͼ��4-4����ץͼ*/
	unsigned char		byDefaultCaptureMode;
	/*ͼ������ 0-��� 1-�κ� 2-�Ϻ� 3-һ�� 4-�ϲ� 5-�� 6-���*/	
	unsigned char		byPicQuality;
	/*ץͼץ�������(���vin�����������)*/
	unsigned char		byMaxVinImage;
	/*����*/
	unsigned char		byTemp[2];
}tmCaptureImageCfg_t;
#define CAPTUREIMAGE_MODE_SAVE			0x00
#define CAPTUREIMAGE_MODE_FTP			0x01
#define CAPTUREIMAGE_MODE_SERVER		0x02
#define CAPTUREIMAGE_MODE_SAVEANDFTP	0x03
#define CAPTUREIMAGE_MODE_SAVEANDSERVER	0x04

/*�Զ�ץͼ�Ĳ���ʱ��*/
typedef struct tmCaptureSchedCfg_t
{
	/*���ṹ��С*/
	unsigned int				dwSize;
	/*ץͼʱ���*/
	tmSchedTime_t				struCaptureSched[MAX_DAYS][MAX_TIMESEGMENT];
	/*ÿ��ץͼ�������ʱ�䣬��λ��*/
	unsigned int				dwCaptureTime;					
	/*����*/
	unsigned char				byReserves;
	/*�Ƿ����ò���ץͼ*/
	unsigned char				byEnableCapture;	
	/*����*/
	unsigned char				byTemp[2];
}tmCaptureSchedCfg_t;

/*----------------------------------------------------------------------*/

#define PTZ_REALTRANS			0	/* ͸����̨���ݴ��� */
#define PTZ_LIGHT_PWRON			2	/* ��ͨ�ƹ��Դ 1*/
#define PTZ_WIPER_PWRON			3	/* ��ͨ��ˢ���� 2*/
#define PTZ_FAN_PWRON			4	/* ��ͨ���ȿ��� 3*/
#define PTZ_HEATER_PWRON		5	/* ��ͨ���������� 4*/
#define PTZ_AUX_PWRON			6	/* ��ͨ�����豸���� 5 5*/

#define PTZ_FOCUS_AUTO			7	/* �Զ��۽� */

#define PTZ_ZOOM_IN				11	/* �������ٶ�SS���(���ʱ��) */
#define PTZ_ZOOM_OUT			12	/* �������ٶ�SS��С(���ʱ�С) */
#define PTZ_FOCUS_NEAR			13	/* �������ٶ�SSǰ�� */
#define PTZ_FOCUS_FAR			14	/* �������ٶ�SS��� */
#define PTZ_IRIS_ENLARGE		15	/* ��Ȧ���ٶ�SS���� */
#define PTZ_IRIS_SHRINK			16	/* ��Ȧ���ٶ�SS��С */
#define PTZ_ZOOM_STEPIN			17	/* �������ٶ�SS�������(���ʱ��) */
#define PTZ_ZOOM_STEPOUT		18	/* �������ٶ�SS������С(���ʱ�С) */
#define PTZ_UP					21	/* ��̨��SS���ٶ����� */
#define PTZ_DOWN				22	/* ��̨��SS���ٶ��¸� */
#define PTZ_LEFT				23	/* ��̨��SS���ٶ���ת */
#define PTZ_RIGHT				24	/* ��̨��SS���ٶ���ת */
#define PTZ_RIGHTUP				25	/* ��̨��SS���ٶ������� */
#define PTZ_RIGHTDOWN			26	/* ��̨��SS���ٶ������� */
#define PTZ_LEFTUP				27	/* ��̨��SS���ٶ������� */
#define PTZ_LEFTDOWN			28	/* ��̨��SS���ٶ������� */
#define PTZ_AUTO				29	/* ��̨��SS���ٶ������Զ�ɨ�� */

#define PTZ_485INPUT			31	/* 485������������ */
#define PTZ_485OUTPUT			32	/* 485����������� */
#define PTZ_SET_KEEPWATCH		33	/*����������*/
#define PTZ_GOTO_KEEPWATCH		34	/*����������*/
#define PTZ_LOCK_KEEPWATCH		35	/*�رտ�����*/
#define PTZ_CLOSE_KEEPWATCH		35	/*�رտ�����*/
#define PTZ_UNLOCK_KEEPWATCH	36	/*�򿪿�����*/
#define PTZ_OPEN_KEEPWATCH		36	/*�򿪿�����*/

#define PTZ_GOTO_ZOOMBS			37	/* ת��ָ������*/

#define PTZ_SET_PRESET			100	/* ����Ԥ�õ� */
#define PTZ_CLE_PRESET			101	/* ���Ԥ�õ� */
#define PTZ_GOTO_PRESET			102	/* ת��Ԥ�õ�*/

#define PTZ_STARTREC_TRACK		110	/* ��ʼ¼�ƹ켣 */
#define PTZ_STOPREC_TRACK		111	/* ֹͣ¼�ƹ켣 */
#define PTZ_STARTRUN_TRACK		112	/* ���й켣*/
#define PTZ_STOPRUN_TRACK		113	/* ֹͣ�켣*/

#define PTZ_STARTREC_CRUISE		120	/* ��ʼ¼��Ѳ�� */
#define PTZ_STOPREC_CRUISE		121	/* ֹͣ¼��Ѳ�� */
#define PTZ_STARTRUN_CRUISE		122	/* ����Ѳ��*/
#define PTZ_STOPRUN_CRUISE		123	/* ֹͣѲ��*/

#define PTZ_INTEGRATE_CONTROL	124	/* ��̨�ۺϿ��ƣ�ͬʱ������ת�ͱ䱶��*/
#define PTZ_SET_ORIGINALITYPT	125	/* ���õ�ǰλ��Ϊ����ԭʼ��*/

#define PTZ_STARTREC_LINE		130	/* ��ʼ¼����ɨ */
#define PTZ_STOPREC_LINE		131	/* ֹͣ¼����ɨ */
#define PTZ_SETLINE_POINT		132	/* ������ɨ��*/
#define PTZ_STARTRUN_LINE		133	/* ����Ѳ��*/
#define PTZ_STOPRUN_LINE		134	/* ֹͣѲ��*/

#define PTZ_SELFCHECK			255	/*��̨�Լ�*/

/*������*/
typedef struct tmDecoderCfg_t
{
	unsigned int			dwSize;
	unsigned int			dwBaudRate;				/*������(bps)ֱ�ӱ�ʾ*/
	unsigned char			byDataBit;				/* �����м�λ 0��5λ��1��6λ��2��7λ��3��8λ;*/
	unsigned char			byStopBit;				/* ֹͣλ 0��1λ��1��1.5λ��2-2;*/
	unsigned char			byParity;				/* У�� 0����У�飬1����У�飬2��żУ��;*/
	unsigned char			byFlowcontrol;			/* 0���ޣ�1��������,2-Ӳ����	*/
	unsigned char			byTransBaudRate;		/* ͸������ĵ�����������0��50��1��75��2��110��3��150��4��300��5��600��6��1200��7��2400��8��4800��9��9600��10��19200�� 11��38400��12��57600��13��76800��14��115.2k;	*/
	unsigned char			byTemp;					/*����*/
	unsigned short			wDecoderAddress;		/*��������ַ:0 - 255*/
	char					szDecoderName[20];		/*����������	*/
	unsigned short			wTrackStopTime;			/*�켣���к���ʱʱ�䣬��λΪ��*/
	unsigned char			bySetCruise[16];		/* Ѳ���Ƿ�����: 0-û������,����ֵΪԤ�õ�� */
	unsigned char			bySetPreset[16];		/* Ԥ�õ��Ƿ�����0-û������,����ֵΪԤ�õ�� */
	unsigned char			bySetTrack[16];			/* �켣�Ƿ�����,0-û������,����ֵΪԤ�õ��*/
}tmDecoderCfg_t;

typedef struct tmDecoderInfo_t
{
	unsigned int			dwSize;
	char					szDecoderName[20];				/*����������*/
}tmDecoderInfo_t;

/*
 *Ԥ�õ��½ṹ����
 */
typedef struct tmPresetInfo_t
{
	char			szPresetName[32];		/* Ԥ�õ����� */
	unsigned char	byEnable;				/* Ԥ�õ��Ƿ����� */
	unsigned char	byTemp[3];				/* ���� */
}tmPresetInfo_t;

typedef struct tmPresetCfg_t
{
	unsigned int	dwSize;					/*���ṹ��С*/
	tmPresetInfo_t	pPresetList[128];		/*Ԥ�õ��б�*/
}tmPresetCfg_t;

/*
 Ѳ���ĵ���Ϣ
 */
typedef struct tmCruisePoint_t
{
	unsigned char	byEnable;				/*�Ƿ�����0,1*/
	unsigned char	byPresetNo;				/*Ԥ�õ��0-127*/
	unsigned char	byCruiseSpeed;			/*Ѳ���ٶ�*/
	unsigned char	byTemp;					/*����*/
	unsigned int	dwStopTime;				/*ͣ��ʱ�䣬��λ��*/
}tmCruisePoint_t;

typedef struct tmCruiseInfo_t
{
	unsigned char	byEnableThisCruise;		/*�Ƿ����ñ�Ѳ���켣*/
	unsigned char	byCruiseLineMerge;		/*N���ߺϲ�Ϊһ����*/
	unsigned char	byTemp[2];
	tmCruisePoint_t	struCruise[16];			/*Ԥ�õ���Ϣ*/
}tmCruiseInfo_t;

/*Ѳ������*/
typedef struct tmCruiseCfg_t
{
	unsigned int	dwSize;					/*���ṹ��С*/
	tmCruiseInfo_t	struCruiseLine[CRUISE_MAX_LINE_NUMS];
}tmCruiseCfg_t;

typedef struct tmPtzSchedTime_t
{
	tmSchedTime_t	struSchedTime;
	unsigned char	byRunType;				/*��������0-Ѳ��,1-�켣,2-��ɨ*/
	unsigned char	byRunLine;				/*���е���,0xFFΪ������	*/
	unsigned char	byTemp[2];
}tmPtzSchedTime_t;
/*��̨������Ϣ*/
typedef struct tmPtzSchedCfg_t
{
	unsigned int		dwSize;										/*���ṹ��С*/
	unsigned char		byEnableKeepWatch;							/*�Ƿ����ÿ���λ0,1*/
	unsigned char		byEnableSchedTime;							/*�Ƿ�����ʱ�䲼��*/
	unsigned short		dwKeepWatchCheckTime;						/*(��)ֹͣ��̨����һ��ʱ���ʼ���õ��ÿ���λ������ϵͳ��������ÿ���λ*/
	tmPtzSchedTime_t	struSchedTime[MAX_DAYS][MAX_TIMESEGMENT];	/*������ʱ��*/
	unsigned char		byLimitMinSpeed;							/*Zoom����С����*/
	unsigned char		byLimitMaxSpeed;							/*Zoom���������*/
	unsigned char		byManualControlPtzTime;						/*�ֶ�����PTZ��������Զ�PTZ������Ч��Ĭ��30��*/
	unsigned char		byPtzZoomMode;								/*��̨�����ͻ�о�����Ⱥ�ģʽ��0-ͬʱ������1-����̨���о��2-�Ȼ�о����̨*/
	unsigned char		byPresetCruiseTime;							/*Ԥ�õ�ͣ��ʱ��Ĭ��ֵ(Ĭ��Ϊ10��)��������5~100��*/
	unsigned char		byPtzTransPresetMin;						/*�����Ҫ������Ԥ�õ㿪ʼ��(����)��1��ʾ��һ��,0��ʾ������*/
	unsigned char		byPtzTransPresetMax;						/*�����Ҫ������Ԥ�õ������(����)��1��ʾ��һ��,0��ʾ������*/
	unsigned char		byPtzLimitPresetMin;						/*����ʹ�õ�Ԥ�õ㿪ʼ��(����)��1��ʾ��һ��,0��ʾ������*/
	unsigned char		byPtzLimitPresetMax;						/*����ʹ�õ�Ԥ�õ������(����)��1��ʾ��һ��,0��ʾ������*/
	unsigned char		byPtzUsePresetMin;							/*�����Ԥ�õ�ſ���ʹ�ÿ�ʼ�ţ�����Ҫ9��,0��ʾ������*/
	unsigned char		bySendZoomBsMode;							/*���ͱ䱶�����������ģʽ0-�����ͣ�1-�������б�����2-��������������3-�䱶�������ͱ���*/
	unsigned char		bySendSpecialtiesZoomBs;					/*�����ر���0-�����ͣ�����Ϊ�ض�������Ĭ��3*/
	unsigned char		byViewZoomBsMode;							/*��ʾ����ģʽ0-����ѧ������ʾ��1-�����Ա�����ʾ*/
    unsigned char		byAuxLinkAlarmOut;						/*zzt add  �������������������*/							/*��ʾ����ģʽ0-����ѧ������ʾ��1-�����Ա�����ʾ*/
	unsigned char		byLimitTemp[50];							/*����*/
	unsigned char		byDisplayPtzInfo;							/*��������̨���Ƿ���ʾ��Ϣ(zoom�������Ƕ�)*/
	unsigned char		byDisplayX;									/*��Ϣ��ʾX����*/
	unsigned char		byDisplayY;									/*��Ϣ��ʾY����*/
	unsigned char		byDisplayMode;								/*��Ϣ��ʾ�ο�λ�ã��ο�OSD����*/
	unsigned char		byCruiseCaptureImage;						/*Ԥ�õ�Ѳ���Ƿ�ץͼ������ץͼ��Ϣ����tmCaptureImageCfg_t��������Ϣ*/
	unsigned char		by3DProtocal;								/*��̨3DЭ�飬0-������,1-hb1,2-hb2,3-sx*/
	unsigned short		byVerticallyMaxAngle;						/*��̨��ֱ������ƶ�*10*/
	unsigned char		byFocusTrace;								/*����Ԥ�õ��Ƿ����*/
	unsigned char		by3DZoomMaxBS;								/*ÿ�ε���3DZoom�������*/
	unsigned char		byAlarmOutByAux;							/*�������ͨ�����������������*/
	unsigned char		byPtzSpeedCtl;								/*wangjun add ����䱶���ٶȿ��Ʋ�������Ϊ������ٶȲ������еģ���������ֻ��һ�����ֵ*/
}tmPtzSchedCfg_t;

/*��̨�������ز������ã�����ͨ�������ö�ʱ�򿪸�������*/
/*�ӵ͵��ߵ�1��ʾPTZ_LIGHT_PWRON*/
/*�ӵ͵��ߵ�2��ʾPTZ_WIPER_PWRON*/
/*�ӵ͵��ߵ�3��ʾPTZ_FAN_PWRON*/
/*�ӵ͵��ߵ�4��ʾPTZ_HEATER_PWRON*/
/*�ӵ͵��ߵ�5��ʾPTZ_AUX_PWRON*/
typedef struct tmPtzAuxTime_t
{
	tmSchedTime_t	struSchedTime;			/*����ʱ��*/
	unsigned char	byAuxEnable;			/*��������ʹ��*/
	unsigned char	byAuxState;				/*��������״̬*/
	unsigned char	byTemp[2];
}tmPtzAuxTime_t;

typedef struct tmPtzAuxCfg_t
{
	unsigned int	dwSize;
	unsigned char	byEnable;				/*�������ز����Ƿ���Ч*/
	unsigned char	byTemp[3];
	tmPtzAuxTime_t	struSchedTime[MAX_DAYS][MAX_TIMESEGMENT];	/*������ʱ��*/
}tmPtzAuxCfg_t;

/*----------------------------------------------------------------------*/
/*RS232����*/
typedef struct tmPPPCfg_t
{
	unsigned int	dwSize;
	char			sRemoteIP[24];						/*Զ��IP��ַ*/
	unsigned char	byTemp1;
	char			sLocalIP[24];						/*����IP��ַ*/
	unsigned char	byTemp2;
	char			sLocalIPMask[24];					/*����IP��ַ����*/
	unsigned char	byTemp3;
	char			szUserName[32];						/* �û��� */
	char			szPassword[32];						/* ���� */
	unsigned char	byPPPMode;							/*PPPģʽ, 0��������1������	*/
	unsigned char	byRedial;							/*�Ƿ�ز�:0-��,1-��*/
	unsigned char	byRedialMode;						/*�ز�ģʽ,0-�ɲ�����ָ��,1-Ԥ�ûز�����*/
	unsigned char	byDataEncrypt;						/*���ݼ���,0-��,1-��*/
	unsigned char	byTemp4;							
	unsigned int	dwMTU;								/*MTU*/
	char			sTelephoneNumber[32];				/*�绰����*/
}tmPPPCfg_t;

typedef struct tmRS2322Cfg_t
{
	unsigned int		dwSize;
	unsigned int		dwBaudRate;			/* ������(bps)��0��50��1��75��2��110��3��150��4��300��5��600��6��1200��7��2400��8��4800��9��9600��10��19200�� 11��38400��12��57600��13��76800��14��115.2k; */
	unsigned char		byDataBit;				/* �����м�λ 0��5λ��1��6λ��2��7λ��3��8λ;*/
	unsigned char		byStopBit;				/* ֹͣλ 0��1λ,1��2λ;*/
	unsigned char		byParity;				/* У�� 0����У��,1����У�飬2��żУ��;*/
	unsigned char		byFlowcontrol;			/* 0����,1��������,2-Ӳ����*/
	unsigned int		dwWorkMode;			/* ����ģʽ��0��խ������(232��������PPP����)��1������̨(232�������ڲ�������)��2��͸��ͨ��*/
	tmPPPCfg_t			struPPPConfig;
}tmRS2322Cfg_t;
/*----------------------------------------------------------------------*/

/*IR��������*/
typedef struct tmIRAlarmInCfg_t
{
	unsigned int			dwSize;
	unsigned char			byAlarmType;								/*����������,0������,1������*/
	unsigned char			byTemp;
	unsigned short			wAdcHigh;									/*��ȡ������Ч�ĸ�ֵ(0~1000)*/
	unsigned short			wAdcLow;									/*��ȡ������Ч�ĵ�ֵ(0~1000)*/
	unsigned short			wAdcCurrent;								/*��ȡ������Ч�ĵ�ǰֵ(0~1000)��ֻ��*/
}tmIRAlarmInCfg_t;


/*��������*/
typedef struct tmAlarmInCfg_t
{
	unsigned int			dwSize;
	char					sAlarmInName[32];							/* ���� */
	unsigned char			byAlarmType;								/*����������,0������,1������*/
	unsigned char			byAlarmInHandle;							/* �Ƿ��� */
	tmHandleException_t		struAlarmHandleType;						/* ����ʽ */
	tmSchedTime_t			struAlarmTime[7][4];						/*����ʱ��*/
	tmTransFer_t			struAlarmTransFer[16];						/*������16��ͨ������tmTransFer_t�ж���ͨ����*/
	unsigned int			dwHandleMinTime;							/* ����������Сʱ�䣬��λ����(�ڴ�ʱ�����жԴ˱���ֻ����һ��)*/
	unsigned short			wAdcHigh;									/*��ȡ������Ч�ĸ�ֵ(0~1000)*/
	unsigned short			wAdcLow;									/*��ȡ������Ч�ĵ�ֵ(0~1000)*/
	unsigned short			wAdcCurrent;								/*��ȡ������Ч�ĵ�ǰֵ(0~1000)��ֻ��*/
	unsigned short			wTemp;
}tmAlarmInCfg_t;

/*DVR�������320*/
typedef struct tmAlarmOutCfg_t
{
	unsigned int			dwSize;
	unsigned char			sAlarmOutName[32];							/* ���� */
	unsigned int			dwAlarmOutDelay;							/* �������ʱ��(-1Ϊ���ޣ��ֶ��ر�), ���� */
	tmSchedTime_t			struAlarmTime[7][4];						/* �����������ʱ��� */
	unsigned char			byAlarmType;								/* ����������,0������,1������ */
	unsigned char			byManualAlarmOutModle;						/* 0:��dwAlarmOutDelay�����ر�; 1:�����ֶ��ر�*/
	unsigned char			byTemp[1];									/* ���� */
	unsigned char			dwSchedTimType;								/* �����������,0-��ʱ�䲼����1-Ĭ�Ͽ�ʼ���в�����2-���� */
}tmAlarmOutCfg_t;

/*DVR��������*/
typedef struct tmAlarmCfg_t
{
	/*���ṹ��С*/
	unsigned int	dwSize;			
				
	/*�����ϴ�ʱ����(��λ��), Ϊ0��ʾֻҪ���������������������*/
	/*���Ա����ϴ���Ч*/
	unsigned int	dwUpToTime;						

	/*����������ʱʱ��	*/									
	unsigned int	dwAlarmAudioTimeout;			
	/*��̨���Ƴ�ʱ���������5��*/
	unsigned int	dwPtzControlTimeout;			
	/*�������ӳ�ʱ���������5��*/
	unsigned int	dwConfigTimeout;				
	/*����̨�������ӳ�ʱ���������5��*/
	unsigned int	dwSerialTimeout;				

	/*����ϵͳ��λ,ĿǰӲ����֧��*/
	unsigned char	byAllowSoftReset;				
	/*�����������ӳ�ʱ���*/
	unsigned char	byAllowConfigTinmeout;			
	/*�Ƿ�����������Զ���ʱ��λ����*/
	unsigned char	byAllowAutoReset;				
	/*�������ò���ʱ���������ָʾ����*/
	unsigned char	byAllowConfigBeep;				

	/*ѭ����ʽ��0Ϊ��ָ��ʱ��ѭ������ģʽΪϵͳ������ʼ��ʱ�ο�ʱ�䣻*/
	/*����Ϊָ�������е�ָ��ʱ�临λ(1-31)*/
	unsigned char	byAutoResetMode;				
	/*�����ϴ��������ͣ�0�ͻ�����Ҫ��¼��1�ͻ��˲���Ҫ��¼*/
	unsigned char	byAlarmToManagerType;			
	/*¼���ļ���С���Է��Ӽ���0��ʾ��¼��*/
	unsigned char	byRecoderFileSize;				
	/*�Ƿ������Զ�¼��Ϊ0�ر�(��������¼��)��Ϊ1һ��¼�������ʱ����������¼������������¼��*/
	unsigned char	byNormalRecoder;				
	
	/*��DDNS������ע���ʱ��������λ�룬�������60��*/
	unsigned int	dwDDNSLoginTimeOut;				
	
	/*byAutoResetMode==0ʱΪѭ��ʱ�䣬����Ϊ��λ��������ڵ���60����ϵͳ������ʼ����*/
	/*byAutoResetMode!=0Ϊָ��ʱ���Զ���λ������ʼ�ο�ʱ�䣬����Ϊ��λ����һ���е�����(0-86400)*/
	unsigned int	dwAutoResetCircleTime;			
	/*�Զ���λ��־���ӵ�λ��ʼ��һλ����һ������*/
	/*0λΪ1��ʾ�������縴λ*/
	/*1λΪ1��ʾ������Ƶ�ɼ���λ*/
	/*31λΪ1��ʾ����ϵͳ��λ*/
	unsigned int	dwAutoResetFlags;			
	/*���紫��ǿ������ʽ,0Ϊ�ͻ����ƶ���>0Ϊָ����С���䣬256-8192*/
	unsigned short	wTranstStreamSize;
	/*�Ƿ�����д�ļ�״̬����ʾ*/
	unsigned char	byEnableWriteFileState;	
	/*�Ƿ��ϴ��ļ�����״̬������������������Ҫ����UDP�˿�*/
	unsigned char	byUpFileStateToManager;
	/*��־��������1-255,�����豸����*/
	unsigned char	byLogRemainDays;
	/*�Ƿ�����SD��¼��*/
	unsigned char	byEnableSDCardRecord;
	/*RTSP���紫���С,0ΪĬ��*/
	unsigned short	wRtpPacketSize;	

}tmAlarmCfg_t;

/*----------------------------------------------------------------------*/

#define ALARMTYPE_ALARMIN				0x00
#define ALARMTYPE_DISKFULL				0x01
#define ALARMTYPE_VIDEOLOST				0x02
#define ALARMTYPE_MOTION				0x03
#define ALARMTYPE_DISKNOTFORMAT			0x04
#define ALARMTYPE_DISKACCESS			0x05
#define ALARMTYPE_CAMREAHIDE			0x06
#define ALARMTYPE_VIDEOSTANDARD			0x07
#define ALARMTYPE_UNLAWFULACCESS		0x08

#define ALARMTYPE_WuCunChuJiHua			9	//�޴洢�ƻ�����	
#define ALARMTYPE_DISKWARRING			10	//�����쳣(������)
#define ALARMTYPE_TongDaoWeiLuXiang		11	//ͨ��δ¼��
#define ALARMTYPE_QianDuanXinHaoBaoJin	12	//ǰ���ź�������
#define ALARMTYPE_ACROSS_LINE			13	//���߱���
#define ALARMTYPE_INTO					14	//�����뱨��
#define ALARMTYPE_ABANDON				15	//�������屨��

/*�ϴ�������Ϣ156*/
typedef struct tmAlaramInfo_t
{
	unsigned int	dwSize;
	unsigned short  wAlarmType;					/*	0-�ź�������,	1-Ӳ����,	2-�źŶ�ʧ��3���ƶ���⣬
													4��Ӳ��δ��ʽ��,5-��дӲ�̳���,6-�ڵ�����,7-��ʽ��ƥ��,
													8-�Ƿ����� 9-�޴洢�ƻ� 10-�����쳣 11-ͨ��δ¼��
													12-ǰ���ź������� 13-���߱��� 14-�Ƿ����� 15-��Ʒ����/��ʧ*/

	unsigned short  wAlarmState;				/*����״̬0-����������1-��ʼ����*/
	unsigned int	dwAlarmChannel;				/*��������˿�*/
	unsigned int	dwAlarmOutputNumber[4];		/*��������˿ڶ�Ӧ������˿ڣ���һλ��Ϊ-1��ʾ��Ӧ��һ�����*/
	unsigned int	dwAlarmRelateChannel[16];	/*��������˿ڶ�Ӧ��¼��ͨ������һλ��Ϊ-1��ʾ��Ӧ��һ·¼��*/
	unsigned int	dwDiskNumber[16];			/*dwAlarmTypeΪ4ʱ,��һλ��Ϊ-1��ʾ�ĸ�Ӳ��*/
}tmAlaramInfo_t;

/*ͼ������ص�*/
typedef struct tmCaptureImageInfo_t
{
	/*���ṹ��С������дΪsizeof(struct tmCaptureImageInfo_t)*/
	unsigned int	dwSize;
	
	/*ץͼ���û�ID,ֻ���ֶ�������*/
	unsigned int	nUserID;

	/*ͨ����0��ʾ��һͨ��*/
	unsigned char	byChannelId;

	/*ץͼ����0-�Զ�ץ�ģ�1-����ץ�ģ�2-�ֶ�ץ��*/
	unsigned char	byCaptureFunc;

	/*����ͨ��*/
	unsigned char	byAlarmChannel;
	
	/*����ָ��*/
	unsigned char*	pBuffer;
	/*�����С*/
	int				iBufferSize;
	/*����ָ��*/
	unsigned char*	pBuffer2;
	/*�����С*/
	int				iBuffer2Size;
	 
	/*�ܹ�ץ����*/
	int				iTotalCaptureNum;
	/*��ǰ�����*/
	int				iCurrentIndex;

	/*ͼƬ��С��*/
	short			nWidth;
	/*ͼƬ��С��*/
	short			nHeight;

	/*ͼ���ʽ��0-BMP, 1-JPEG, 2-H264, 3-YUV, 4-H265Ŀǰ����ֻ����1*/
	unsigned char	byImageFormat;
	
	/*ʱ���*/
	tmTimeInfo_t	struTimeStamp;
}tmCaptureImageInfo_t;

/*�ϴ��������ı�����Ϣ*/
typedef struct tmToManagerAlarmInfo_t
{
	unsigned int		dwSize;
	tmAlaramInfo_t		struAlarmInfo;
	char				szDVSName[32];					/*DVS����*/
	unsigned char		szSerialNumber[48];				/*���������к�*/
	unsigned char		szServerGUID[16];				/*������ΨһGUID*/
	unsigned char		byMACAddr[6];					/*Զ�������ַ*/
	char				szServerIP[16];					/*��������ַ*/
	char				szServerMask[24];				/*��������ַ*/
	unsigned char		byTemp[4];
}tmToManagerAlarmInfo_t;
/*�ϴ��������ĵ�ͼƬ��Ϣ����*/
typedef struct tmToManagerImageInfo_t
{
	unsigned int		dwSize;							/*���ṹ��С*/
	struct
	{
		short			nWidth;							/*ͼƬ��С��*/
		short			nHeight;						/*ͼƬ��С��*/
		unsigned char	byBitCount;						/*ͼ��λ��*/
		unsigned char	byRevolving;					/*ͼ���Ƿ���ת*/
		short			nPitch;							/*ͼƬpitch*/
	}image;
	BYTE				byTemp1[8];
	unsigned char		byMACAddr[6];					/*Զ�������ַ*/
	unsigned char		byTemp2[2];						/*����*/
	char				szServerIP[16];					/*��������ַ*/
	unsigned char		byImageFmt;						/*ͼƬ��ʽ,0-JPEG,1-BMP,2-RGB555,3-RGB565,4-RGB24,*/
														/*5-RGB32,6-YUV444,7-YUV422,8-YUV420,9-BKMPEG4,10-H264,11-H265*/
	unsigned char		byCount;						/*����ץͼ��Ҫץȡ����*/
	unsigned char		byIndex;						/*��ǰͼƬ�����*/
	unsigned char		byImageMode;					/*ץͼ��ģʽ0-��������ץͼ, 1-�ƶ�����ץͼ, 2-�ֶ�ץͼ, 3-ˢ��ץͼ, 4-Ԥ�õ�Ѳ��,0FF-�Զ�ץͼ*/
	unsigned char		byAlarmId;						/*����ͨ��*/
	unsigned char		byChannelId;					/*�����ͨ��*/
	unsigned char		byOtherInfo[2];					/*����������Ǳ�������ô0��1��ʾ����������״̬*/
	struct
	{
		short			nYear;
		unsigned char	nMonth;
		unsigned char	nDay;
		unsigned char	nDayOfWeek;
		unsigned char	nHour;
		unsigned char	nMinute;
		unsigned char	nSecond;
	}time;
	unsigned int		dwImageSize;					/*ͼ���С��Ҳ���Ǳ��ṹ�������ݴ�С*/
}tmToManagerImageInfo_t;
/*�ϴ����ĵ�������*/
/*�豸����������*/
typedef struct tmToManagerLiveHeartInfo_t
{
	/*���ṹ����*/
	unsigned int		dwSize;							
	/*�豸����*/
	unsigned short		nDeviceType;					
	/*�豸�ĳ���ID*/
	unsigned short		nFactoryId;						
	/*�豸�˿�*/
	unsigned short		nDevicePort;					
	/*�豸��ַ*/
	unsigned int		nDeviceAddress;					
	/*������ΨһGUID*/
	unsigned char		nDeviceGUID[16];				
	/*�豸��ͨ����*/
	unsigned char		nChannelCount;		
	/*����������*/
	unsigned char		nAlarmInCount;
	/*�����������*/
	unsigned char		nAlarmOutCount;
	/*Ӳ����(������)*/
	unsigned char		nDiskCount;
	/*�豸����������(D1,HDCMA)*/
	unsigned char		nDeviceSubType;
	/*�豸������MARK��ַ����һ��������*/
	unsigned char		nMarkAddress[6];	
	/*�豸����*/
	char				nDeviceName[32];
}tmToManagerLiveHeartInfo_t;

/*��ȫ��ʿ�豸������Ϣ����*/
typedef struct tmToManagerSafeGuardInfo_t
{
	/*���ṹ����*/
	unsigned int		dwSize;				
	/*�豸��ַ*/
	unsigned int		nDeviceAddress;	
	/*�豸�˿�*/
	unsigned short		nDevicePort;					
	/*�豸������MARK��ַ����һ��������*/
	unsigned char		nMarkAddress[6];	
	
	/*�豸��ͨ�е�״̬0-��ֹ��1-ͨ��*/
	unsigned char		byLightState;
	/*�豸�ĶԽ���ť����1-�Խ�*/
	unsigned char		byTalkState;
	/*�豸�Ĳ�����ť����0-û�а��£�1-����*/
	unsigned char		byBuFangState;
	/*�豸�ĳ�����״̬0-û�а��£�1-����*/
	unsigned char		byCheFangState;
	/*�豸�ı�����ť����0-û�а��£�1-����*/
	unsigned char		byAlarmState;	
	/*�豸�ĺ���״̬0-û�д򿪣�1-��*/
	unsigned char		byInfraredState;
	/*�豸����ˢ��*/
	unsigned char		byCardEnable;
	/*����*/
	unsigned int		dwCardNo;
}tmToManagerSafeGuardInfo_t;

/*�豸������̨��Ϣ����TMCC_MAJOR_CMD_SERVERMESSAGE/TMCC_MINOR_CMD_SERVERCALLPTZ*/
typedef struct tmToManagerPtzInfo_t
{
	/*���ṹ����*/
	unsigned int		dwSize;				
	/*�豸��ַ*/
	unsigned int		nDeviceAddress;	
	/*�豸�˿�*/
	unsigned short		nDevicePort;					
	/*�豸������MARK��ַ����һ��������*/
	unsigned char		nMarkAddress[6];	
	
	/*�豸������̨������0-����Ԥ�õ�*/
	unsigned char		byCallType;
	/*Ԥ�õ��*/
	unsigned char		byCallData;
	/**/
	unsigned char		byTemp[2];
	/*����*/
	char				szCallName[32];
}tmToManagerPtzInfo_t;

/* �������豸��Ϣ 256*/
typedef struct tmServerInfo_t
{
	unsigned int		dwSize;							/*�ýṹ�Ĵ�С��������д*/
	unsigned char		bServerConnect;					/*���������ӻ��ǶϿ�����*/
	char				szDVSName[32];					/*DVS����*/
	unsigned char		szSerialNumber[48];				/*���������к�*/
	unsigned char		szServerGUID[16];				/*������ΨһGUID*/	
	unsigned char		byMACAddr[6];					/*Զ�������ַ*/
	char				szServerIP[25];					/*��������ַ*/
	char				szServerMask[25];				/*��������ַ*/
	char				szCenterManagerIP[25];			/*�������ĵ�ַ*/
	unsigned char		byCenterManager;				/*�Ƿ�������������*/

	unsigned char		byAlarmInNum;					/*���������뱨������*/
	unsigned char		byAlarmOutNum;					/*�����������������*/
	unsigned short		wChannelNum;					/*������ͨ����*/

	unsigned int		dwServerType;					/*����������*/
	unsigned short		wDVSPort;						/*�˿ں�*/
	unsigned short		wHttpPort;						/*HTTP������*/
	unsigned int		dwGroupID;						/*��������Ŷ˿ں�*/
	unsigned int		dwSoftwareVersion;				/*����汾��,��16λ�����汾,��16λ�Ǵΰ汾*/
	unsigned int		dwPanelVersion;					/*ǰ���汾,��16λ�����汾,��16λ�Ǵΰ汾*/
	unsigned int		dwHardwareVersion;				/*Ӳ���汾,��16λ�����汾,��16λ�Ǵΰ汾*/
	unsigned int		dwFactoryNo;					/*�������鳧�̱��*/
}tmServerInfo_t;

typedef struct tmServerInfoEx_t
{
	unsigned int		dwSize;							/*�ýṹ�Ĵ�С��������д*/
	unsigned char		bServerConnect;					/*���������ӻ��ǶϿ�����*/
	char				szDVSName[32];					/*DVS����*/
	unsigned char		szSerialNumber[48];				/*���������к�*/
	unsigned char		szServerGUID[16];				/*������ΨһGUID*/	
	unsigned char		byMACAddr[6];					/*Զ�������ַ*/
	char				szServerIP[25];					/*��������ַ*/
	char				szServerMask[25];				/*��������ַ*/
	char				szCenterManagerIP[25];			/*�������ĵ�ַ*/
	unsigned char		byCenterManager;				/*�Ƿ�������������*/

	unsigned char		byAlarmInNum;					/*���������뱨������*/
	unsigned char		byAlarmOutNum;					/*�����������������*/
	unsigned short		wChannelNum;					/*������ͨ����*/

	unsigned int		dwServerType;					/*����������*/
	unsigned short		wDVSPort;						/*�˿ں�*/
	unsigned short		wHttpPort;						/*HTTP������*/
	unsigned int		dwGroupID;						/*��������Ŷ˿ں�*/
	unsigned int		dwSoftwareVersion;				/*����汾��,��16λ�����汾,��16λ�Ǵΰ汾*/
	unsigned int		dwPanelVersion;					/*ǰ���汾,��16λ�����汾,��16λ�Ǵΰ汾*/
	unsigned int		dwHardwareVersion;				/*Ӳ���汾,��16λ�����汾,��16λ�Ǵΰ汾*/
	unsigned int		dwFactoryNo;					/*�������鳧�̱��*/
	unsigned int		dwRunTime;						/*������������ʱ��*/

	unsigned short		wCurrentDVSPort;				/*��ǰ�����˿ں�*/
	unsigned short		wCurrentHttpPort;				/*��ǰ����HTTP������*/
	unsigned int		dwCurrentServerIP;				/*��ǰ����IP*/
	unsigned int		dwCurrentServerMask;			/*��ǰ����IP����*/

	/*�����¼�20090306*/
	unsigned int		dwServerGateWay;				/*����������*/
	unsigned char		byEnableDhcp;					/*DHCP����*/
	unsigned char		byEtherNet;						/*����ID0-��һ�����磬1-�ڶ�������*/
	unsigned char		byWifi;							/*�Ƿ���WIFI��ַ1ΪWIFI��ַ*/
	unsigned char		byTemp;							/*����*/
	unsigned int		dwLastUpgradeTime;				/*�豸���һ������ʱ��*/
}tmServerInfoEx_t;

/*���÷�������ַ�ṹ����*/
typedef struct tmServerCfg_t
{
	unsigned int		dwSize;							/*�ýṹ�Ĵ�С��������д*/
	tmServerInfo_t		pInfo[1];						/*��������Ϣ*/
	unsigned int		dwMajorCommand;					/*��������������*/
	unsigned int		dwMinorCommand;					/*��������������*/
	char				szUserName[32];					/*�����û���*/
	char				szPassword[32];					/*���õĿ���*/
	int					iConfigMode;					/*���ú�����0��ʾ�޶�����1��ʾ��������*/
	unsigned int		dwResverse;						/*����*/
	unsigned int		dwResverse1;					/*����*/
}tmServerCfg_t;

/*���÷�������ַ�ṹ����*/
typedef struct tmServerExCfg_t
{
	unsigned int		dwSize;							/*�ýṹ�Ĵ�С��������д*/
	tmServerInfo_t		pInfo[1];						/*��������Ϣ*/
	unsigned int		dwMajorCommand;					/*��������������*/
	unsigned int		dwMinorCommand;					/*��������������*/
	char				szUserName[32];					/*�����û���*/
	char				szPassword[32];					/*���õĿ���*/
	unsigned char		iConfigMode;					/*���ú�����0��ʾ�޶�����1��ʾ��������*/
	unsigned char		bControlAll;					/*����ʱ�Ƿ����������豸*/
	unsigned char		bTemp[2];						/*����*/
	unsigned int		dwResverse;						/*ָʾ�Ƿ���tmServerCfg_t����չ�ṹ*/
														/*0��ʾʹ��tmServerInfo_t�������ݣ�1��ʾtmServerInfoEx_t��������*/
														/*����ֵ��ʾ�����ṹ*/
	unsigned int		dwResverse1;					/*����*/
	tmServerInfoEx_t	pInfoEx[1];						/*UPnp��������Ϣ����չ�޸�ֻ���޸�tmServerInfoEx_t�ṹ��*/
}tmServerExCfg_t;

/*�ಥ���ýṹ����*/
typedef struct tmMultiServerCfg_t
{
	unsigned int		dwSize;							/*�ýṹ�Ĵ�С��������д*/
	unsigned int		dwMajorCommand;					/*��������������*/
	unsigned int		dwMinorCommand;					/*��������������*/
	char				szUserName[32];					/*�����û���*/
	char				szPassword[32];					/*���õĿ���*/
	unsigned int		dwCompareSerialNumber;			/*�Ƿ���Ҫƥ�����кţ�0-��ƥ�䣬�������У�1-ƥ��GUID����*/
	char				szSerialNumber[48];				/*������Ψһ���к�*/
}tmMultiServerCfg_t;

/*�豸״̬*/
typedef struct tmChannelState_t
{
	unsigned int		dwSize;
	unsigned char		byRecordStatic;				/*ͨ���Ƿ���¼��,0-��¼��,1-¼��*/
	unsigned char		bySignalStatic;				/*���ӵ��ź�״̬,0-����,1-�źŶ�ʧ*/
	unsigned char		byHardwareStatic;			/*ͨ��Ӳ��״̬,0-����,1-�쳣,����DSP����*/
	unsigned char		reservedData;
	unsigned int		dwBitRate;					/*ʵ������*/
	unsigned int		dwLinkNum;					/*�ͻ������ӵĸ���*/
	unsigned int		dwClientIP[6];				/*�ͻ��˵�IP��ַ*/
}tmChannelState_t;

typedef struct tmDiskState_t
{
	unsigned int		dwSize;
	unsigned int		dwVolume;							/*Ӳ�̵�����*/
	unsigned int		dwFreeSpace;						/*Ӳ�̵�ʣ��ռ�*/
	unsigned int		dwHardDiskStatic;					/*Ӳ�̵�״̬,����,�,��������*/
}tmDiskState_t;

typedef struct tmUserState_t
{
	unsigned int		dwSize;
	char				szUserName[32];				/*��¼�û���*/
	unsigned int		dwLoginNum;					/*��¼��, ���Ϊ0��ʾ���û���¼*/
	unsigned int		dwLoginAddress[16];			/*��¼��ַ*/
}tmUserState_t;

typedef struct tmWorkState_t
{
	unsigned int		dwSize;
	unsigned int		dwDeviceRunTime;				/*�豸���ϴ�����������ʱ�䣬��λ��*/
	unsigned int		dwDeviceStatic; 				/*�豸��״̬,0-����,1-CPUռ����̫��,����85%,2-Ӳ������,���紮������*/
	tmDiskState_t		struHardDiskStatic[16];			/*Ӳ�̵�ǰ״̬ */
	tmChannelState_t	struChanStatic[16];				/*ͨ����״̬*/
	tmUserState_t		struUserStatic[16];				/*��¼�û���״̬*/
	unsigned char		byAlarmInStatic[16];			/*�����˿ڵ�״̬,0-û�б���,1-�б���*/
	unsigned char		byAlarmOutStatic[4];			/*��������˿ڵ�״̬,0-û�����,1-�б������*/

	/*add by stone 20090508*/
	unsigned int		dwCpuClockFrequency;			/*CPU��Ƶ��*/
	unsigned int		dwTotalMemorySize;				/*�ܹ��ڴ��С*/
	unsigned int		dwFreeMemorySize;				/*ʣ���ڴ��С*/
}tmWorkState_t;

/*��̨���Ʋ�������ƶ೤ʱ�䣬��ת�Ƕȵ�,��С����С��128�ֽ�*/
/*��byControlMode==1ʱʹ��8192�����Ҷ������λ�ã���byControlModeΪ����ֵʱʹ�ü��������ģʽ*/
typedef struct tmPtzParameter_t
{	
	unsigned int		dwAutoStopTime;					/*�Զ��Ͽ�ʱ�䣬���Ȧ����*/
	int					dwZoomValue;					/*�䱶*/
	int					dwVerticallyAngle;				/*��ֱ*/
	int					dwHorizontallyAngle;			/*ˮƽ*/
	unsigned char		byZoomMode;						/*0-����,1-��Զ,2-����*/
	unsigned char		byVerticallyMode;				/*0-��ֱ����,1-��ֱ����,2-����*/
	unsigned char		byHorizontallyMode;				/*0-ˮƽ����(������λ������),1-ˮƽ����,2-����*/
	unsigned char		byControlMode;					/*����ģʽ: 0-ʹ�ýǶ�*1000,1-ʹ��������㷽��*8192,3-ʹ�ò���,4-ʹ������ģʽ(�Ƕȣ�����x1000)*no*/
	unsigned char		byHorSpeed;						/*����ˮƽ�ٶ�1~128*/
	unsigned char		byVerSpeed;						/*���ƴ�ֱ�ٶ�1~128*/
	unsigned char		byGoPathMode;					/*����ˮƽ�����ߵ�·��0-���·���ߣ�1-ˮƽ����2-ˮƽ���ң�3-ֱ�ӵ���λ��(����)*/
	unsigned char		byRectRatio;					/*Ϊ���ñ䱶��׼ȷ���㷨:A=(���/ͼ���*100)��B=(���/ͼ���*100)��byRectRatio=(A>B)?A:(B|0x80)*/
	unsigned char		byTemp;
}tmPtzParameter_t;

/*
������㷽����
1����ͼ������Ϊ�ο�ԭ�㣬��ͼ�񻮷ֳ��ĸ����֣�����ڲο�ԭ�㣬�ֱ�Ϊ���ϡ����ϡ����¡����£������ҡ���Ϊ��������Ϊ����
2���õ���ǰ���������ԭ���ֵ���ٳ��Ե�λ���ȣ��õ���Եı���ֵ���˱���ֵ�Ѿ������ķֱ����޹�
3����Ϊ�õ�����Ա���ֵһ��С�ڵ���1��Ϊ�˱���ΪС����ͳһ���õ��ı���ֵ����8192,���˻����ֵȡ������Ϊ�������뵽Э���Ӧ�ֽڡ�
�������£�
��ǰ�ֱ���Ϊ1024��768����ͼ�����ĵ�����Ϊ(512,384)�����Ŀ��λ������Ϊ(768,576),���֪Ŀ��λ�ô������ϣ������ֵΪ��
ˮƽ��
��768-512��/512 = 0.5���ٳ���8192����Ϊ4096����Ϊ���ұߣ�����Ϊ4096�������Ӧ�ֽڼ��ɡ�
��ֱ��
��576-384��/384 = 0.5���ٳ���8192����Ϊ4096����Ϊ���ϱߣ�����Ϊ-4096,�����Ӧ�ֽڼ��ɡ�
*/

/*��̨���ƽṹ160�ֽ�*/
typedef struct tmPtzCommandCfg_t
{
	unsigned int			dwSize;						/*�ýṹ��С���˽ṹʵ�ʴ�С���ܸ���*/
	unsigned int			dwPTZCommand;				/*��̨��������*/
	unsigned int			dwPTZControl;				/*���Ʋ����������Ԥ�õ����ΪԤ�õ��*/
	unsigned int			dwAddress;
	unsigned int			dwSpeed;
	int						iPTZCodeLen;				/*PTZ�����볤��*/
	union
	{
		unsigned char		pPTZCodeBuf[256];			/*����������ֵ������ֵ����1ʱ���ӵ�2����ֵ��ʼ*/
														/*�Ļ���Ӧ�����˽ṹ��*/
		tmPtzParameter_t	struParameter;				/*��̨����*/
	}data;
}tmPtzCommandCfg_t;

/*��̨��ǰ��Ϣ��Ӧ����TMCC_MAJOR_CMD_PTZCONTROL/TMCC_MINOR_CMD_GETPTZINFO*/
/*�Ƕ���Ҫ*1000,���ĵ���㷽����Ҫ*8192,�Ƕȸ����豸��ͬ����ͬˮƽ360�ȣ���ֱ90��*/
typedef struct tmPtzIntegrateCfg_t
{
	unsigned int				dwSize;								/*�ýṹ��С���˽ṹʵ�ʴ�С*/
	int							dwVerticallyStation;				/*���ֱλ��*/
	int							dwHorizontallyStation;				/*���ˮƽλ��*/
	int							dwVerticallyVisualAngle;			/*��ǰ���Ӵ�ֱλ��*/
	int							dwHorizontallyVisualAngle;			/*��ǰ����ˮƽλ��*/
	int							dwZoomValue;						/*��ǰ�ı���*/
	unsigned char				byControlMode;						/*����ģʽ0-�Ƕ�(*1000)��1-����(��*8192), 4-����ģʽ(�Ƕ�)*/
	unsigned char				byCurrentPreset;					/*��ǰ�������ĸ�Ԥ�õ��ϣ�0��ʾû����Ԥ�õ���,1-��ʾ1��Ԥ�õ�*/
	unsigned char				byPtzMode;							/*��̨��Ϣ0-û����̨��Ϣ��1-һ���е�����2-���ۣ�3-ȫ����4-������̨��Ϣ*/
	unsigned char				byFixMode;							/*�������װģʽ 0-�ڹ�, 1-����, 2-����*/
	int							dwMaxZoomValue;						/*�����*/
	int							dwImageHorVisualAngle;				/*��ǰ������ͼ���ӽ�ˮƽ��С*/
	int							dwImageVerVisualAngle;				/*��ǰ������ͼ���ӽǴ�ֱ��С*/
	int							dwVerticallyMinStation;				/*��С��ֱλ��*/
	int							dwHorizontallyMinStation;			/*��Сˮƽλ��*/
}tmPtzIntegrateCfg_t;

typedef struct tmPtzIntegrateListCfg_t
{
	unsigned int				dwSize;								/*�ýṹ��С���˽ṹʵ�ʴ�С*/
	unsigned char				byCount;							/*�б���*/	
	unsigned char				byTemp[3];							/*����*/
	tmPtzIntegrateCfg_t			struList[8];						/*�б�*/
}tmPtzIntegrateListCfg_t;

/*����Ӳ����Ϣ�ṹ*/
typedef struct tmDriveInfo_t
{
	unsigned char				byInit;								/*Ӳ���Ƿ��ʼ��*/
	unsigned char				byReset;							/*�Ƿ��ٳ�ʼ��Ӳ��*/
	unsigned char				byFDisk;							/*Ӳ���Ƿ�ϵͳģʽ����*/
	unsigned char				byTemp[1];							/*����*/
	unsigned int				dwDriveType;						/*Ӳ������*/
	unsigned int				dwTotalSpace;						/*Ӳ���ܿռ�*/
	unsigned int				dwUsefullSpace;						/*���ÿռ��С*/
}tmDriveInfo_t;

/*����Ӳ�̽ṹ*/
typedef struct tmDriveCfg_t
{
	unsigned int				dwSize;								/*�ýṹ��С*/
	unsigned int				dwDriveCount;						/*Ӳ�̸���*/
	tmDriveInfo_t				struDisk[16];						/*Ӳ����Ϣ*/
}tmDriveCfg_t;
#define TMCC_DRIVE_UNKNOWN			0x00
#define TMCC_DRIVE_NO_ROOT_DIR		0x01
#define TMCC_DRIVE_REMOVABLE		0x02
#define TMCC_DRIVE_FIXED			0x03
#define TMCC_DRIVE_REMOTE			0x04
#define TMCC_DRIVE_CDROM			0x05
#define TMCC_DRIVE_RAMDISK			0x06
#define TMCC_DRIVE_SDRAM			0x07

typedef struct tmDriveAlarmCfg_t
{
	unsigned int				dwSize;								/*�ýṹ��С*/
	unsigned char				byEnableFullSpaceAlarm;				/*��������������*/
	unsigned char				byEnableExceptionAlarm;				/*���������쳣����*/
	unsigned char				byTemp[2];
}tmDriveAlarmCfg_t;

/*��Ƶ��������ʹ������TMCC_MAJOR_CMD_VIDEOINCFG/TMCC_MINOR_CMD_VIDEOIN*/
typedef struct tmVideoInCfg_t
{
	/*�ýṹ��С*/
	unsigned int				dwSize;
	
	/*50/60Hz,0-auto, 1:50Hz,2-60Hz*/
	unsigned char				byAntiFlickerMode;
	/*0:VIDEO_COLOR_STYLE_FOR_PC 1:VIDEO_COLOR_STYLE_FOR_TV;*/
	unsigned char				byVideoColorStyle;	
	/*��Ƶ������ת0-normal,1-180,2-90,3-270,4-vflip,5-hflip*/
	unsigned char				byRotaeAngle180;
	/*��ת��ģʽ0-�Զ���1-��ɫ��2-�ڰ�*/
	unsigned char				byColorTransMode;

	/*����ģʽȡֵ��Χ0=1/25,1=1/30,2=1/50,3=1/60,4=1/100,5=1/120,6=1/240,7=1/480,8=1/960,9=1/1024*/
	/*10=�Զ�,11-1/4,12-1/8,13-1/15,14-1/180,15-1/2000,16-1/4000,17-1/10000*/
	unsigned char				byShutterSpeed;
	/*AGC����0=42dB,32=36dB,64=30dB,96=24dB,128=18dB,160=12dB,192=6dB,224-�Զ�,225-48dB,226-54dB,227-60dB*/
	unsigned char               byAgc;	
	/*�����л�ģʽ: 0��ʾ�Զ��л�ģʽ,1��ʾ��ʱ�л����л�ʱ������涨��*/
	/*2��ʾʹ�ñ��������л�,0xFFΪ�ֶ�����ģʽ*/
	unsigned char               byIRShutMode;
	/*��Ȧ�ع�0-����Ȧ;100-��С��Ȧ, 0xFF-�ֶ�;���ù�Ȧֵʱ����Ȧֵ*/
	unsigned char				byExposure;

	/*�����ʱ��͹ر�ʱ��*/
	unsigned char               byIRStartHour;
	unsigned char               byIRStartMin;
	unsigned char               byIRStopHour;
	unsigned char               byIRStopMin;

	/*0-�Զ�, 1-��������, 2-�Զ���������, 3-�Զ���Ȧ����, 4-�ֶ�ģʽ*/
	unsigned char				byModeSwitch;	
	/*��ƽ�����0-�ر�,1-�Զ�,2-�׳��,3-D4000,4-D5000,5-�չ�,6-����,7-�����,8-ӫ���,9-ӫ���H,10-ˮ��,0xFF-�ֶ�*/
	unsigned char				byWhiteBalance;
	/*��̬ģʽ0-��,1-�Զ�,2-�ڲ�ģʽ1X,3-�ڲ�ģʽ2X,4-�ڲ�ģʽ3X,5-�ڲ�ģʽ4X, 0xFF-Ĭ��*/
	unsigned char				byWdr;
	/*���ⲹ��0-�أ�1-��*/
	unsigned char				byBlc;

	/*��ƽ���ֶ�ֵ��RB(0~16383)*/
	unsigned short				nWhiteBalanceR;
	unsigned short				nWhiteBalanceB;
	/*3D����0~255*/
	unsigned char				byMctfStrength;
	/*�˹�Ƭ����0-˲������, 1-˲�䷴��, 2-��������, 3-��������*/
	unsigned char				byIRType;
	/*�л��˹�Ƭ�Ƿ���Ʊ���������ƺ����(����������Ӻ����), 0-��������1-�����������1��2-�����������2*/
	unsigned char				byIRCutTriggerAlarmOut;
	/*�˹�Ƭ�л�ʱ��Ĭ��500����,0-500, 1-100, 2-200, 3-300*/
	unsigned char				byIRCutTime;

	/*�ع�ˮƽ( 10 ~ 200 )*/
	unsigned char				byExposureLevel;
	/*�ڰ�ģʽ�Զ��л������ȷ�ֵ��ֻ�����Զ�ģʽ��Ч*/
	unsigned char				byColorTransMin;
	unsigned char				byColorTransMax;
	/*���ռ���0xFFΪ�Զ�����,0,1,2,3,4,5,6,7,8  (��������)*/
	unsigned char				byNoiseFilter;

	/*�Ƿ�ǿ�ƽ���,0/1,��Ϊ0��byNoiseFilterֻ��һ������ֵ��1-Ϊһ���̶�ֵ*/
	unsigned char				byForceNoiseFilter;
	/*�ع�ģʽ0-spot, 1-center,2-average,3-custom*/
	unsigned char				byAeMeteringMode;
	/*��̬ģʽ8bit��ÿbit��ʾһ��ģʽ, ȫΪ0��ʾһ��ģʽ, 0λ��ʾ����Ӳ����̬, 1λ��ʾ����HISOģʽ, 2λ��ʾ���õ�֡��ģʽ*/
	unsigned char				byWdrMode;
	/*����������������ı�����(����������>1ʱ��Ч)��Ĭ��0���ڲ������ı�������,1-��һ���������룬2-�ڶ�����������*/
	unsigned char               byIRShutAlarmIn;
	/*ʹ���Զ��Աȶ�, 0�رգ� 1-�Զ��� <256Ϊ����ǿ��*/
	unsigned char               byAutoContrast;
	/*ǿ�����ƹ���0-�رգ�1-6����*/
	unsigned char				byLightInhibitionEn;

	/*ǿ������֡��
	0-�Զ�, 1-1, 2-2, 3-3, 4-4, 5-5, 6-6, 7-10, 8-12, 9-13, 10-14, 11-15, 12-20, 13-24, 14-25, 15-30, 16-50, 17-60, 18-120
	19-29.75, 20-59.94, 21-23.976, 22-12.5, 23-6.25, 24-3.125, 25-7.5, 26-3.75
	*/
	unsigned char				byVinFrameRate;

	/*�ع�����Ĵ�С*/
	unsigned char				byAeMeteringRow;
	unsigned char				byAeMeteringColumn;

	/*�˹�Ƭ����0-�첨��1-����, 2-x, 3-x*/
	unsigned char				byIRFilterType;

	//YUV������ͣ�0-�ر�YUV��1-Ĭ�ϣ� 2-�������� 3-������, ��10��ʼ�ο�tmCompression_t��byResolution����-10
	unsigned char				byCaptureYuvResolution;
	//viģʽ���ں�ʨ��ʹ��0-����ģʽ��1-����ģʽ
	unsigned char				byViLineMode;
	unsigned char				byTemp[2];

	/*�ڰ�ģʽ�Զ��л������淧ֵ��ֻ�����Զ�ģʽ��Ч*/
	unsigned char				byAgcTransMin;
	unsigned char				byAgcTransMax;

	/*����ȡֵ���ֵ0-Ĭ��,������λΪ1/x*/
	unsigned short				nMaxShutterSpeed;
	/*AGC������byAgc�����ϵ��������ܵ�AGC=byAgc+nMaxAgc*/
	unsigned short              nMaxAgc;

	/*
	 * �˴��ر�ע�⣬����Щ������byAeMeteringData��96���ֽڲ�������HDR���ع������û�ã�
	 * ������ʹ������չbyAeMeteringData��496��
	 */
	/*�ع�����*/
	unsigned char				byAeMeteringData[96];
	
	/*HDR�ع�ˮƽ( 10 ~ 200 )*/
	unsigned char				byExposureLevelHdr[4];
	/*HDR���ŵ���*/
	unsigned short				nMinShutterSpeedHdr[4];
	/*HDR���Ÿ���*/
	unsigned short				nMaxShutterSpeedHdr[4];
	/*HDR�������*/
	unsigned char				byMaxAgcHdr[4];

	/*�ع�����*/
	unsigned char				byAeMeteringDataHdr[4][96];

}tmVideoInCfg_t;

#define WDR_MODE_HDR			0x01
#define WDR_MODE_HISO			0x02
#define WDR_MODE_LOWFRAMERATE	0x04

/*��Ƶ��������ʹ������TMCC_MAJOR_CMD_VIDEOINCFG/TMCC_MINOR_CMD_VIDEOINEX*/
typedef struct tmVideoInExCfg_t
{
	/*�ýṹ��С*/
	unsigned int				dwSize;
	
	/*ͼ��ģʽ0-һ��ģʽ,1-HDRӲ����̬, 2-HISOģʽ*/
	unsigned char				byImageMode;
	/*��Ƶ������ת0-normal,1-180,2-90,3-270,4-vflip,5-hflip*/
	unsigned char				byRotaeAngle180;
	/*50/60Hz,0-auto, 1:50Hz,2-60Hz*/
	unsigned char				byAntiFlickerMode;
	/*0:VIDEO_COLOR_STYLE_FOR_PC 1:VIDEO_COLOR_STYLE_FOR_TV;*/
	unsigned char				byVideoColorStyle;	

	/*��ƽ�����0-�ر�,1-�Զ�,2-�׳��,3-D4000,4-D5000,5-�չ�,6-����,7-�����,8-ӫ���,9-ӫ���H,10-ˮ��,0xFF-�ֶ�*/
	unsigned char				byWhiteBalance;
	/*��̬ģʽ0-��,1-�Զ�,2-�ڲ�ģʽ1X,3-�ڲ�ģʽ2X,4-�ڲ�ģʽ3X,5-�ڲ�ģʽ4X, 0xFF-Ĭ��*/
	unsigned char				byWdr;
	/*���ⲹ��0-�أ�1-��*/
	unsigned char				byBlc;
	/*��Ȧ�ع�0-����Ȧ;100-��С��Ȧ, 0xFF-�ֶ�;���ù�Ȧֵʱ����Ȧֵ*/
	unsigned char				byExposure;
	/*3D����0~255*/
	unsigned char				byMctfStrength;
	/*3aģʽ 0-�Զ�, 1-��������, 2-��������, 3-��Ȧ����*/
	unsigned char				by3AModeSwitch;	
	/*���ռ���0xFFΪ�Զ�����,0,1,2,3,4,5,6,7,8  (��������)*/
	unsigned char				byNoiseFilter;
	/*�Ƿ�ǿ�ƽ���,0/1,��Ϊ0��byNoiseFilterֻ��һ������ֵ��1-Ϊһ���̶�ֵ*/
	unsigned char				byForceNoiseFilter;

	/*ʹ���Զ��Աȶ�*/
	unsigned char               byAutoContrast;
	/*ǿ�����ƹ���*/
	unsigned char				byLightInhibitionEn;
	/*�ع�ģʽ0-spot, 1-center,2-average,3-custom*/
	unsigned char				byAeMeteringMode;
	/*����*/
	unsigned char				byTemp[13];

	/*һЩHDRģʽ�Ĳ�������byImageMode==0�ǣ�ֻȡ����0*/
	struct
	{
		/*�����ٶ����ֵ0-Ĭ��, ������λΪ1/x��*/
		unsigned short			nMaxShutterSpeed;
		/*����ȡֵ��Сֵ0-Ĭ��, ������λΪ1/x��*/
		unsigned short			nMinShutterSpeed;
		/*AGC����dB 0~255dB*/
		unsigned char           byMaxAgc;
		/*�ع�ˮƽ( 10 ~ 200 )*/
		unsigned char			byExposureLevel;
		unsigned char			byTemp[10];
		/*�ع�����*/
		unsigned char			byAeMeteringData[96];
	}table[4];

}tmVideoInExCfg_t;


typedef struct tmVideoAwbCfg_t
{
	/*�ýṹ��С*/
	unsigned int				dwSize;

	/*�Ƿ�����*/
	BYTE						byEnableRepairAwb;
	/*ԭʼɫ���ǲο�ɫ�»���WB����*/
	BYTE						byRefColorTemp;
	BYTE						byTemp[2];

	/*�Զ���ƽ�������ֵ����tmVideoInCfg_t��byWhiteBalance=0/1ʱ��Ч*/
	union
	{
		struct
		{
	unsigned short				wOrgLowRGainVal;		/*��ɫ��*/
	unsigned short				wOrgLowBGainVal;	
		}low;
		unsigned int			dwRefLowColorTemp;
	};
	
	union
	{
		struct
		{
	unsigned short				wOrgHighRGainVal;		/*��ɫ��*/
	unsigned short				wOrgHighBGainVal;
		}high;		
		unsigned int			dwRefHighColorTemp;
	};

	unsigned short				wTargetLowRGainVal;		/*��ɫ��*/
	unsigned short				wTargetLowBGainVal;
	unsigned short				wTargetHighRGainVal;	/*��ɫ��*/
	unsigned short				wTargetHighBGainVal;
}tmVideoAwbCfg_t;

/*��Ƶ��������ʹ������TMCC_MAJOR_CMD_VIDEOINCFG/TMCC_MINOR_CMD_IRCUTVIDEOIN*/
/*IRCUT�л���ʹ�ø�����*/
typedef struct tmIRCutVideoInCfg_t
{
	/*�ýṹ��С*/
	unsigned int				dwSize;	
	/*�Ƿ�������Ƶ����*/
	unsigned char				byEnablePicPreview;
	/*�Ƿ�����*/
	unsigned char				byEnableVideoIn;
	/*�Ƿ�����*/
	unsigned char				byEnable;
	/*Ԥ�� ���*/
	unsigned char				byPreviewMode;
	/*��Ƶ����*/
	tmPicPreviewCfg_t			struPicPreview;
	/*��Ƶ�������*/
	tmVideoInCfg_t				struVideoIn;
}tmIRCutVideoInCfg_t;

/*�����л�ʱ��*/
typedef struct tmIRCutCfg_t
{
	/*�ýṹ��С*/
	unsigned int				dwSize;

	/*�����ʱ��͹ر�ʱ��*/
	unsigned char               byIRStartHour;
	unsigned char               byIRStartMin;
	unsigned char               byIRStopHour;
	unsigned char               byIRStopMin;

	/*�����л�ģʽ: 0��ʾ�Զ��л�ģʽ,1��ʾ��ʱ�л����л�ʱ������涨��*/
	/*2��ʾʹ�ñ��������л�,0xFFΪ�ֶ�����ģʽ*/
	unsigned char               byIRShutMode;	
	/*�˹�Ƭ����0-��������1-��������2-˲������3-˲�䷴��*/
	unsigned char				byIRType;
	/*�л��˹�Ƭ�Ƿ���Ʊ���������ƺ����(����������Ӻ����)*/
	unsigned char				byIRCutTriggerAlarmOut;
	/*�˹�Ƭ�л�ʱ��Ĭ��500����,0-500, 1-100, 2-200, 3-300*/
	unsigned char				byIRCutTime;

	/*����������������ı�����(����������>1ʱ��Ч)��Ĭ��0���ڲ������ı�������,1-��һ���������룬2-�ڶ�����������*/
	unsigned char               byIRShutAlarmIn;

	/*��������0-850NM, 1-950NM*/
	unsigned char				byCurveType;

	/*��ת��ģʽ0-�Զ���1-��ɫ��2-�ڰ�*/
	unsigned char				byColorTransMode;

	/*�ڰ�ģʽ�Զ��л������ȷ�ֵ��ֻ�����Զ�ģʽ��Ч*/
	unsigned char				byColorTransMin;
	unsigned char				byColorTransMax;

	/*�ڰ�ģʽ�Զ��л������淧ֵ��ֻ�����Զ�ģʽ��Ч*/
	unsigned char				byAgcTransMin;
	unsigned char				byAgcTransMax;

}tmIRCutCfg_t;

/*��Ƶ��������ʹ������TMCC_MAJOR_CMD_VIDEOINCFG/TMCC_MINOR_CMD_SCHEDVIDEOIN*/
typedef struct tmSchedVideoInMode_t
{
	/*�ýṹ��С*/
	unsigned int				dwSize;
	/*�Ƿ�����*/
	unsigned char				byEnable;
	/*Ԥ�� ���*/
	unsigned char				byPreviewMode;	
	/*�Ƿ�������Ƶ����*/
	unsigned char				byEnablePicPreview;
	/*�Ƿ�����*/
	unsigned char				byEnableVideoIn;
	/*ģʽ������*/
	char						szModeName[32];
	/*����ʱ��*/
	tmSchedTime_t				struSchedTime;
	/*��Ƶ�������*/
	tmVideoInCfg_t				struVideoIn;
	/*��Ƶ����*/
	tmPicPreviewCfg_t			struPicPreview;
}tmSchedVideoInMode_t;

typedef struct tmSchedVideoInCfg_t
{
	/*�ýṹ��С*/
	unsigned int				dwSize;
	/*��Ƶ�������*/
	tmSchedVideoInMode_t		struVideoInMode[MAX_SCHEDVIDEOINMODE];
}tmSchedVideoInCfg_t;

/*�ع�ģʽ*/
#define EXPOSURE_MODE_AUTOR				0x00
#define EXPOSURE_MODE_AUTOREX			0x01
#define EXPOSURE_MODE_MANUALBYSHUTTER	0x07
#define EXPOSURE_MODE_MANUALBYAPERTURE	0x08
#define EXPOSURE_MODE_MANUALBYAGC		0x09
#define EXPOSURE_MODE_AUTOR1			0x10
#define EXPOSURE_MODE_AUTOR2			0x20
#define EXPOSURE_MODE_AUTOR1EX			0x11
#define EXPOSURE_MODE_AUTOR2EX			0x21
#define EXPOSURE_MODE_AUTOR3EX			0x31
/*�����л�ģʽ*/
#define IRSHUT_MODE_AUTO				0x00
#define IRSHUT_MODE_SCHEDTIME			0x01
#define IRSHUT_MODE_ALARMIN				0x02
#define IRSHUT_MODE_MANUAL				0xFF


/*��ͷ��Ȧ��������*/
typedef struct tmApertureCfg_t
{
	/*�ýṹ��С*/
	unsigned int				dwSize;

	/*��Ȧ����0-�ֶ���Ȧ, 1-�Զ���Ȧ, 2-��������Ȧ*/
	unsigned char				byApertureType;
	/*����*/
	unsigned char				byTemp[2];
	/*��Ȧ�Ŀ��÷�Χ(��ͬ��ͷ��һ����)*/
	unsigned char				byDutyDelta;
	/*��Ȧ��ƽ��ֵ(��ͬ��ͷ��һ����)*/
	unsigned int				dwDutyBalance;
}tmApertureCfg_t;

/*һ�������ģʽ����*/
typedef struct tmZoomCfg_t
{
	/*�ýṹ��С*/
	unsigned int				dwSize;

	/*��ǰ�۽�ģʽ0-auto,1-zoom then focus,2-manual*/
	unsigned char				byFocusMode;
	/*�л�IRCUT���Ƿ��Զ�ת���ֶ��۽�ģʽ*/
	unsigned char				byAutoManualFocus;
	/*�л�IRCUT���Ƿ��Զ�ת���ֶ��۽�ģʽ��ʱ�䣬��*/
	unsigned char				byAutoManualFocusTime;
	/*��������0-850NM, 1-950NM*/
	unsigned char				byCurveType;
	/*��С�۽�����: 0-Ĭ��;1-10m;2-6m;3-3m;4-2m;5-1.5m;6-1m;7-MAX*/
	unsigned char               byFocusLimt;

}tmZoomCfg_t;
/*�۽�ģʽ*/
#define ZOOM_AUTO_FOCUS			0x00
#define ZOOM_THEN_FOCUS			0x01
#define ZOOM_MANUAL_FOCUS		0x02
/*���������*/
#define ZOOM_CURVE_TYPE_NORMAL	0x00
#define ZOOM_CURVE_TYPE_850NM	0x01
#define ZOOM_CURVE_TYPE_950NM	0x02

/*��ͷ����У��*/
typedef struct tmLensDeWarpCfg_t
{
	/*�ýṹ��С*/
	unsigned int		dwSize;
	/*�Ƿ�����*/
	unsigned char		byEnable;
	/*����ѡ��ģʽ*/
	unsigned char		byLensWarpMode;
	/*��������ʾģʽ,0-ˮƽ/��ֱ�Ƕ�,1-���ĵ�����*/
	unsigned char		bySubregionMode;
	unsigned char		byTemp;
	/*�ӽǴ�С��*1000*/
	unsigned int		dwMaxFov;
	/*���۰뾶*/
	unsigned int		dwMaxRadius;
	/*���ű���*1000*/
	unsigned int		dwMaxZoom;
	
	/*����ˮƽ/��ֱ�Ƕ� x1000*/
	struct
	{
		int				pan;
		int				tilt;	
	}struPantilt;
	/*�������ĵ����� x1000*/
	struct
	{
		int				x;
		int				y;	
	}struRoi;
	/*����ѡ��*/
	struct
	{
		short			x;
		short			y;	
		short			cx;
		short			cy;
	}struNotrans;
	/*ȫ���ӽǶ���<=180, x1000 */
	unsigned int		dwHorPanorRange;
}tmLensDeWarpCfg_t;


/*��Ƶ������ýṹʹ������TMCC_MAJOR_CMD_VIDEOOUTCFG/TMCC_MINOR_CMD_VIDEOOUT*/
typedef struct tmVideoOutCfg_t
{
	/*�ýṹ��С*/
	unsigned int				dwSize;
	/*�Ƿ�������Ƶ���*/
	unsigned char				byEnableVideoOut;
	/*��Ƶ���ģʽ��֧��YPbPr,*/
	/*0xFF:Ĭ��˫��������ģ�����*/
	/*0-YPbPr(720p output,onlyģ�����,����ģ����������), */
	/*1-YPbPr(480p/576p out,������), */
	/*2-YPbPr(480i/576i out������),*/
	/*3-CVBS(480i/576i out������),��ʱ��֧��*/
	unsigned char				byVideoOutMode;
	/*���ˢ����*/
	unsigned char				byRenovator;
	/*����*/
	unsigned char				byResverse;

	/*��Ƶ����ֱ���*/
	unsigned short				wWidth;
	unsigned short				wHeight;	
	
}tmVideoOutCfg_t;

/*��Ƶ���ƫ�����ýṹʹ������TMCC_MAJOR_CMD_VIDEOOUTCFG/TMCC_MINOR_CMD_VIDEOOUTOFFSET*/
typedef struct tmVideoOutOffsetCfg_t
{
	/*�ýṹ��С*/
	unsigned int				dwSize;

	/*��Ƶ���ƫ��*/
	unsigned short				wOffsetLeft;
	unsigned short				wOffsetTop;
	unsigned short				wOffsetRight;
	unsigned short				wOffsetBottom;

	/*��Ƶ����Ƿ�ȫ����ʾ*/
	unsigned char				byFullScreen;
	/*����*/
	unsigned char				byResverse[3];
	
}tmVideoOutOffsetCfg_t;


/*��ͼ��ɼ�ƫ��΢������ */
typedef struct tmVideoEptzCfg_t
{
	unsigned int	dwSize;	

	unsigned char	byClearLeft;
	unsigned char	byClearTop;
	unsigned char	byClearRight;
	unsigned char	byClearBottom;

	short			offset_x;
	short			offset_y;
	short			offset_cx;
	short			offset_cy;
}tmVideoEptzCfg_t;

/*ȫ��¼���������(�ӽṹ)*/
typedef struct tmRecordDay_t
{
	/*�Ƿ�ȫ��¼�� 0-�� 1-��*/
	unsigned char	byAllDayRecord;	
	/*0:��ʱ¼��1:�ƶ���⣬2:����¼��3:����|������4:����&����, 5:�����, 6: ����¼��, 7:�ֶ�¼��*/
	unsigned char	byRecordType;
	/*����*/
	unsigned char	byTemp[2];
}tmRecordDay_t;

/*ʱ���¼���������(�ӽṹ)*/
typedef struct tmRecordSched_t
{
	/*¼��ʱ��*/
	tmSchedTime_t	struRecordTime;
	/*0:��ʱ¼��1:�ƶ���⣬2:����¼��3:����|������4:����&����, 5:�����, 6: ����¼��, 7:�ֶ�¼��*/
	unsigned char	byRecordType;
	/*����*/
	char			byTemp[3];
}tmRecordSched_t;

/*ͨ������¼���������*/
typedef struct tmRecordCfg_t
{
	/*���ṹ��С*/
	unsigned int				dwSize;
	/*ȫ��¼��*/
	tmRecordDay_t				struRecordAllDay[MAX_DAYS];
	/*¼��ʱ���*/
	tmRecordSched_t				struRecordSched[MAX_DAYS][MAX_TIMESEGMENT];
	/*������ʱ(��λ:�룬>=10��)��¼���ļ���С��tmAlarmCfg.byRecoderFileSize*/
	unsigned int				dwRecordTime;					
	/*Ԥ¼ʱ��(��λ:��)*/
	unsigned int				dwPreRecordTime;				
	/*¼�񱣴���ʱ��(��λ:��)*/
	unsigned int				dwRecorderDuration;				
	/*�Ƿ�����¼��,��Ҫ����˫���ݣ�0/1*/
	unsigned char				byRedundancyRec;
	/*¼��ʱ����������ʱ�Ƿ��¼��Ƶ����*/
	unsigned char				byAudioRec;
	/*¼������Ϊ������0-��������1-��������2-��3������3-��4����*/
	unsigned char				byRecordStream;
	/*�Ƿ�����¼��*/
	unsigned char				byEnableRecord;	
	/*���ö�����¼��ȫ���������Ч����1λΪ��һ������*/
	unsigned char				byMultiStreamRecord;	
	/*����*/
	unsigned char				byTemp[3];
}tmRecordCfg_t;

/*ͨ��FTP¼��������ã�FTP���òο�tmFTPCfg_t�ṹ����*/
typedef struct tmFtpRecordCfg_t
{
	/*���ṹ��С*/
	unsigned int				dwSize;
	/*ȫ��¼��*/
	tmRecordDay_t				struRecordAllDay[MAX_DAYS];
	/*¼��ʱ���*/
	tmRecordSched_t				struRecordSched[MAX_DAYS][MAX_TIMESEGMENT];
	/*������ʱ(��λ:�룬>=10��)��¼���ļ���С��tmAlarmCfg.byRecoderFileSize*/
	unsigned int				dwRecordTime;	
	/*Ԥ¼ʱ��(��λ:��)*/
	unsigned int				dwPreRecordTime;			
	/*¼��ʱ����������ʱ�Ƿ��¼��Ƶ����*/
	unsigned char				byAudioRec;
	/*¼������Ϊ������*/
	unsigned char				byRecordStream;
	/*�Ƿ�����¼��*/
	unsigned char				byEnableRecord;
	/*���ö�����¼��ȫ���������Ч����1λΪ��һ������*/
	unsigned char				byMultiStreamRecord;
}tmFtpRecordCfg_t;


/*
 *���������ýṹ����
 */
/*��������������Ϣ������ͨ����Command�и���*/
typedef struct tmConnectCfg_t
{
	unsigned int				dwSize;								/*�ýṹ��С*/
	char						sRemoteIP[24];						/*Զ��IP��ַ*/
	unsigned char				byConnectMode;						/*���ӵ�ģʽ0-Ĭ������ָ����Ϣ,1-ָ�����е�ͨ����(��Ҫ�����豸�Ƿ�֧��)*/
	char						sTurnServerIP[24];					/*ת����IP��ַ*/	
	unsigned char				byTemp2;
	char						szUserName[32];						/* �û��� */
	char						szPassword[32];						/* ���� */
	unsigned short				wConnectPort;						/* ���Ӷ˿� */
	unsigned short				wChannelID;							/* ���ӵ�ͨ���� */
	unsigned short				wStreamID;							/* ���ӵ������� */	
	unsigned short				wDelayTime;							/* ѭ��ʱ��(��)��������ڵ���10��*/
	unsigned char				byEnableTurnServer;					/* �Ƿ�����ת��������0-�رգ�1-���� */
	unsigned char				byStreamType;						/* ������������ */
	unsigned char				byTransType;						/* ���紫�䷽ʽ */
	unsigned char				byDisplay;							/* �Ƿ�������������ӣ���Ϊѭ������ʱ��Ч��������Ϊ�������� */
	unsigned char				byTemp4[2];
}tmConnectCfg_t;

/*����ͨ���б���Ϣ*/
typedef struct tmConnectListCfg_t
{
	unsigned int				dwSize;								/*�ṹ��С����Ҫ��ӳʵ�ʴ�Сsizeof(tmAlarmDeviceCfg_t)*dwCount+8*/
	unsigned int				dwCount;							/*�����豸����*/
	tmConnectCfg_t				pConnectList[1];					/*�����豸��Ϣ�б������Զ���һ������Ҫ����dwCount�ж�*/
}tmConnectListCfg_t;

/*����ͨ������*/
typedef struct tmWindowsCfg_t
{
	unsigned int				dwSize;								/* �ýṹ��С*/
	unsigned char				byImageQuant;						/* �������� */
	unsigned char				byEnableState;						/* �Ƿ���ʾ״̬ */
	unsigned char				byEnableAudio;						/* �Ƿ񲥷����� */
	unsigned char				byResverse;							/* ���� */
}tmWindowsCfg_t;
/*��ʾ��������*/
typedef struct tmDisplayCfg_t
{
	unsigned int				dwSize;								/*�ýṹ��С*/
	unsigned char				bySingleView;						/* �Ƿ񵥻�����ʾ */
	unsigned char				byWindowID;							/* ��Ҫ�Ŵ���ʾ�Ĵ��� */
	unsigned char				byResverse[2];
}tmDisplayCfg_t;
/*����������Ϣ*/
typedef struct tmLockCfg_t
{
	unsigned int				dwSize;
	unsigned char				byLocked;
	unsigned char				byResverse[3];
}tmLockCfg_t;

/*����������*/
typedef struct tmWindowCapabilityCfg_t
{
	/*���ṹ��С*/
	unsigned int				dwSize;

	/*ϵͳ֧�ִ����л���*/
	int							iSwitchWindowNum;
	/*�����б�*/
	unsigned char				bySwitchWindowList[32];

	/*ÿ����֧��Ѱ�е��������*/
	unsigned char				byCircleCount;
}tmWindowCapabilityCfg_t;

/*NVR��ͨ�����ýṹ����*/
/*add by zzt 2010-6-25*/
/*����NVR��ʹ�õ�ͨ����Ϣ*/

/*������������豸��Ϣ*/
typedef struct tmAlarmDeviceCfg_t
{
	unsigned int				dwSize;								/*�ýṹ��С*/
	unsigned int				dwFactoryId;						/*�豸��ID*/
	char						sName[32];							/*ͨ����*/
	char						sUserName[32];						/*�û���*/
	char						sPassword[32];						/*����*/
	char						sAddress[32];						/*Զ��IP��ַ����������*/
	unsigned short				wPort;								/*���Ӷ˿�*/
	unsigned short				wAlarmInBase;						/*��������ͨ����ʼͨ����*/
	unsigned short				wAlarmInNum;						/*��������ͨ����*/
	unsigned short				wAlarmOutBase;						/*�������ͨ����ʼ��*/
	unsigned short				wAlarmOutNum;						/*�������ͨ����*/
	unsigned char				byEnable;							/*�Ƿ�����*/
	unsigned char				bySourceType;						/*ֻ��,ͨ��ģʽ0-���أ�1-����*/
}tmAlarmDeviceCfg_t;

/*ͨ���б���Ϣ*/
typedef struct tmAlarmDeviceListCfg_t
{
	unsigned int				dwSize;								/*�ṹ��С����Ҫ��ӳʵ�ʴ�Сsizeof(tmAlarmDeviceCfg_t)*dwCount+8*/
	unsigned int				dwCount;							/*�����豸����*/
	tmAlarmDeviceCfg_t			pAlarmList[1];						/*�����豸��Ϣ�б������Զ���һ������Ҫ����dwCount�ж�*/
}tmAlarmDeviceListCfg_t;

/*����ͨ����Ϣ*/
typedef struct tmChannelCfg_t
{
	unsigned int				dwSize;								/*�ýṹ��С*/
	unsigned int				dwFactoryId;						/*�豸��ID*/
	char						sName[32];							/*ͨ����*/
	char						sUserName[32];						/*�û���*/
	char						sPassword[32];						/*����*/
	char						sAddress[32];						/*Զ��IP��ַ����������*/
	char						sTurnAddress[32];					/*ת������ַ*/
	unsigned short				wPort;								/*���Ӷ˿�*/
	unsigned short				wTurnPort;							/*ת�����˿�*/
	unsigned char				byChannelID;						/*���ӵ�ͨ����*/
	unsigned char				bySubStream;						/*�Ƿ��������*/
	unsigned char				byTurnServer;						/*�Ƿ�����ת��������0-�رգ�1-����*/
	unsigned char				byStreamType;						/*������������0-ֻ������Ƶ����1-��������Ƶ��*/
	unsigned char				byTransType;						/*���紫�䷽ʽ0-�ڲ�Ĭ��Э�飬1-RTSPЭ��*/
	unsigned char				byEnable;							/*��ͨ���Ƿ�����*/
	unsigned char				bySourceType;						/*ֻ��,ͨ��ģʽ0-���أ�1-����*/
	unsigned char				byTemp;								/*����*/
}tmChannelCfg_t;

/*ͨ���б���Ϣ*/
typedef struct tmChannelListCfg_t
{
	unsigned int				dwSize;								/*�ṹ��С����Ҫ��ӳʵ�ʴ�Сsizeof(tmChannelCfg_t)*dwCount+8*/
	unsigned int				dwCount;							/*ͨ������*/
	tmChannelCfg_t				pChannelList[1];					/*ͨ����Ϣ�б������Զ���һ������Ҫ����dwCount�ж�*/
}tmChannelListCfg_t;

/*RTSP����ͨ����Ϣ*/
typedef struct tmRtspChannelNameInfo_t
{
	BYTE						byEnable;						/*�Ƿ�����*/
	BYTE						byTemp[3];						/*����*/
	char						sName1[32];						/*��һ����������*/
	char						sName2[32];						/*�ڶ�����������*/
	char						sName3[32];						/*��������������*/
	char						sName4[32];						/*��������������*/
}tmRtspChannelNameInfo_t;
typedef struct tmRtspChannelNameCfg_t
{
	unsigned int				dwSize;							/*���ṹ��С*/
	unsigned int				dwCount;						/*ͨ����*/
	tmRtspChannelNameInfo_t		struRtspName[1];				/*RTSP�����б�*/
}tmRtspChannelNameCfg_t;


/*��־��Ϣ*/
typedef struct tmLogInfo_t
{
	unsigned int			dwSize;									/*���ṹ��С*/
	struct
	{
		unsigned short		wYear;									/*��*/
		unsigned char		byMonth;								/*��*/
		unsigned char		byDay;									/*��*/
		unsigned char		byHour;									/*ʱ*/
		unsigned char		byMinute;								/*��*/
		unsigned char		bySecond;								/*��*/
		unsigned char		byTemp;									/*����*/
	}struLogTime;													/*��־��¼ʱ��*/
	char					sUserName[32];							/*�������û���*/
	char					sAddress[16];							/*Զ��������ַ*/
	unsigned char			byUserLoginType;						/*�û���¼��ʽ0-���أ�1-����*/
	unsigned char			byMajorType;							/*������ 0-ϵͳ, 1-����; 2-�쳣; 3-����; 0xff-ȫ��*/
	unsigned char			byMinorType;							/*������ 0-ȫ��;*/
	unsigned char			byTemp;									/*����*/
    char					sInfo[4];								/*��־���ݣ������Զ���4���ֽ�*/
}tmLogInfo_t;

typedef struct tmLogInfoListCfg_t
{
	unsigned int			dwSize;									/*���ṹ��С*/
	unsigned int			dwCount;								/*��־����*/
	tmLogInfo_t				struLogInfo;							/*��־�б�ɱ��С*/
}tmLogInfoListCfg_t;

/*��־����*/
typedef struct tmLogCfg_t
{
	unsigned int			dwSize;									/*���ṹ��С*/
	tmTimeInfo_t			struStartTime;							/*��־��ʼʱ��*/
	tmTimeInfo_t			struStopTime;							/*��־����ʱ��*/
}tmLogCfg_t;

/*�������γ�����ýṹ��������TMCC_MAJOR_CMD_THEODOLITECFG*/
typedef struct tmTheodoliteCfg_t
{
	unsigned int			dwSize;									/*���ṹ��С*/
	int						dwLongitude;							/*����*10000, ��������������Ϊ����(-1800000~1800000)*/
	int						dwLatitude;								/*γ��*10000, ��γΪ��������γΪ����(-900000~900000)*/
}tmTheodoliteCfg_t;


/*��������õĵ���Ϣ*/
typedef struct tmPointInfo_t
{
	unsigned short			nxPos;									/*xˮƽ��������(PAL�ο�704*576, NTSC�ο�704*480)*/
	unsigned short			nyPos;									/*yˮƽ��������(PAL�ο�704*576, NTSC�ο�704*480)*/
}tmPointInfo_t;
/*��������߼������*/
typedef struct tmSpanAlarmCfg_t
{
	unsigned int			dwSize;									/*���ṹ��С*/
}tmSpanAlarmCfg_t;

typedef struct tmFaceDetectInfo_t
{
	unsigned int		dwSize;				/*���ṹ��С*/
	int					iImageWidth;
	int					iImageHeight;
	int					iFaceNum;
	struct
	{
		unsigned short	x;
		unsigned short	y;
		unsigned short	cx;
		unsigned short	cy;
	}list[32];
}tmFaceDetectInfo_t;

/*��������Ϣ*/
typedef struct tmRealStreamInfo_t
{
	unsigned int		dwSize;				/*���ṹ��С*/

	unsigned char		byFrameType;		/*֡����0-��Ƶ��1-��Ƶ��2-������ͷ*/
	unsigned char		byNeedReset;		/*�Ƿ���Ҫ��λ������*/
	unsigned char		byKeyFrame;			/*�Ƿ�ؼ�֡*/
	unsigned char		byStreamNo;			/*������*/

	unsigned int		dwFactoryId;		/*����ID	*/
	unsigned int		dwStreamTag;		/*������Tag*/
	unsigned int		dwStreamId;			/*��ID*/
	union
	{
		int				iWidth;				/*��Ƶ��*/
		int				iSamplesPerSec;		/*��Ƶ������*/
	};
	union
	{
		int				iHeight;			/*��Ƶ��*/
		int				iBitsPerSample;		/*��Ƶ����λ��*/
	};
	union
	{
		struct
		{
			short		iFrameRate;			/*֡��*1000�����<1000����ʵ�ʵ�֡�ʲ���*1000*/
			short		iDisplayFrameRate;	/*֡��*1000�����<1000����ʵ�ʵ�֡�ʲ���*1000*/
		}framerate;
		int				iChannels;			/*��Ƶ��������*/
	};
	
	/*add by 2009-0429*/
	union
	{
		unsigned int	nDisplayScale;	/*��ʾ����*1000*/
	};
	
	unsigned int		dwTimeStamp;	/*ʱ���(��λ����)*/
	unsigned int		dwPlayTime;		/*��֡����ʱ��(��λ����)*/
	unsigned int		dwBitRate;		/*����������������С*/	

	BYTE*				pBuffer;		/*���ݻ���*/
	int					iBufferSize;	/*���ݴ�С*/
	
	BYTE*				pBuffer2;		/*����2����*/
	int					iBuffer2Size;	/*����2��С*/

	BYTE				bInterlacer;
	BYTE				byTemp[3];

	BYTE*				pBuffer3;		/*����3����*/
	int					iBuffer3Size;	/*����3��С*/

	BYTE*				pBuffer4;		/*����4����*/
	int					iBuffer4Size;	/*����4��С*/

	tmFaceDetectInfo_t*	pFaceDetect;	/*���������*/

	BYTE*				pMotionRectList;/*�ƶ������Ϣ*/
	int					iMotionRectSize;
}tmRealStreamInfo_t;

/*������ͷ��Ϣ*/
typedef struct tmAvInfo_t
{
	/*��Ƶ*/
	unsigned char		byVideo;			/*�Ƿ����Ƶ*/
	unsigned char		byInterlacer;		/*��Ƶ��Interlacer*/
	unsigned char		byStreamId;			/*������*/
	unsigned char		byVideoIndex;		/*�������*/
	unsigned int		dwVideoTag;			/*������Tag*/
	unsigned int		dwVideoId;			/*��ID*/
	unsigned short		nWidth;				/*��Ƶ��*/
	unsigned short		nHeight;			/*��Ƶ��*/
	unsigned short		nDisplayScale;		/*��ʾ����*1000*/
	unsigned short		nTempV;				
	unsigned int		dwFrameRate;		/*֡��*1000*/
	unsigned int		dwVideoBitRate;		/*����������������С*/

	/*��Ƶ*/
	unsigned char		byAudio;			/*�Ƿ�ɼ���Ƶ	*/
	unsigned char		byBitsPerSample;	/*��Ƶ����λ��*/
	unsigned char		byChannels;			/*��Ƶ��������*/
	unsigned char		byAudioIndex;		/*�������*/
	unsigned int		dwAudioTag;			/*��Ƶ������Tag*/
	unsigned int		dwAudioId;			/*��Ƶ��ID	*/
	unsigned int		dwSamplesPerSec;	/*��Ƶ������*/
	unsigned int		dwAudioBitRate;		/*����Ƶ����������С*/
	unsigned int		dwSampleSize;		/*һ����Ƶ����������֡*/
	unsigned int		dwTempA;
}tmAvInfo_t;
typedef struct tmRealStreamHeadCfg_t
{
	unsigned int			dwSize;				/*���͹���С*/
	unsigned int			nFileTotalTime;		/*�ļ���ʱ��*/
	unsigned short			nFactoryId;			/*����ID	*/
	unsigned short			nStreamNum;			/*������	*/
	tmAvInfo_t				struStream[8];		/*����������Ƶ��Ϣ	*/	
}tmRealStreamHeadCfg_t;

/*
 *���������ݽṹ����
 */
typedef struct tmMultiStreamInfo_t
{
	unsigned int		dwSize;						/*���ṹ��С*/
	unsigned char		byEnableMultiView;			/*���ö�����ͬʱ��ʾ*/
	unsigned char		byCurrentStream;			/*������ʾ������Ĭ����0*/
	unsigned char		byStreamNum;				/*�����е�������*/
	unsigned char		byTemp;						/*����*/
	tmAvInfo_t			stream[8];					/*������Ϣ�б�*/
	struct
	{
		HWND			hWnd;						/*��ʾ���ھ��*/
		RECT			rcView;						/*��ʾ����ڴ��ڵ�λ��*/
		unsigned char	byAutoFitWindow;			/*��ʾ��ģʽ0-ʹ��rcView��ʾ��1-����������Ӧģʽ��2-2��������Ӧģʽ*/
													/*3-4��������Ӧģʽ, 4*9��������Ӧģʽ*/
		unsigned char	byWindowIndex;				/*�ര������Ӧģʽ�Ĵ���id*/
		unsigned char	byLockDisplayScale;			/*�Ƿ�������ʾ����*/
	}view[8];
}tmMultiStreamInfo_t;

/*
 *�ļ�����
 */
/*�ļ�������������*/
typedef struct tmFindConditionCfg_t
{
	unsigned int			dwSize;				/*���ṹ��С*/
	unsigned char			byChannel;			/*������ͨ��*/
	unsigned char			byFileType;			/*�������� 0xFF-ȫ����'N'-��ʱ��'M'-�ƶ���'A'-������'H'-�ֶ���'O'-����*/
	unsigned char			bySearchAllTime;	/*��������ʱ���ļ�*/
	unsigned char			bySearchImage;		/*�Ƿ�����ͼƬ*/
	tmTimeInfo_t			struStartTime;		/*�����Ŀ�ʼʱ��*/
	tmTimeInfo_t			struStopTime;		/*�����Ľ���ʱ��*/
	unsigned char			byEnableServer;		/*�Ƿ������������*/
	unsigned char			byOldServer;		/*�Ƿ������豸*/
	unsigned char			byBackupData;		/*�Ƿ����������ļ�*/
	unsigned char			byTemp;
	char					sServerAddress[32];	/*��������ַ*/
	unsigned int			dwServerPort;		/*�������˿�*/	
	char					sUserName[32];		/*�û���*/
	char					sUserPass[32];		/*�û�����*/
}tmFindConditionCfg_t;

/*��������¼���ļ���Ϣ*/
typedef struct tmFindFileCfg_t
{
	unsigned int			dwSize;	
	char					sFileName[64];		/*�ļ���*/
	unsigned char			byChannel;			/*������ͨ��*/
	union
	{
		unsigned char		byAlarmType;		/*�������� 0xFF-ȫ����'N'-��ʱ��'M'-�ƶ���'A'-������'H'-�ֶ���'O'-����*/
		unsigned char		byFileType;			/*�������� 0xFF-ȫ����'N'-��ʱ��'M'-�ƶ���'A'-������'H'-�ֶ���'C'-����(����), 'Z'-���ܣ�'B'����&����,'O'-����*/
	};
	unsigned short			wFactoryId;			/*����ID*/
	tmTimeInfo_t			struStartTime;		/*�ļ��Ŀ�ʼʱ��*/
	tmTimeInfo_t			struStopTime;		/*�ļ��Ľ���ʱ��*/
	unsigned int			dwFileTime;			/*�ļ�ʱ�䣬����*/
	unsigned int			dwFileSize;			/*�ļ��Ĵ�С(�ֽڱ�ʾ������¼���ļ�����̫��)*/
	unsigned char			byImage;			/*�ļ��Ƿ�ΪͼƬ*/
	unsigned char			byFileFormat;		/*�ļ���ʽ*/
	unsigned char			byBackupData;		/*�Ƿ��Ǳ����ļ�*/
	unsigned char			byDiskName;			/*���ڴ���*/
}tmFindFileCfg_t;

/*�ļ����Żص��ӿڶ���*/
/*�ļ����ʽӿڻص��ṹ����*/
typedef struct tmFileAccessInterface_t
{
	HANDLE			(*Open)( const char* lpFileName, const char* lpMode, void* context );
	int				(*Close)(HANDLE hFile);
	unsigned int	(*Seek)( HANDLE hFile, int offset, int origin );
	int				(*Read)( HANDLE hFile, void* lpBuffer, int nRead );
	int				(*Write)( HANDLE hFile, void* lpBuffer, int nWrite );
	unsigned int	(*Size)( HANDLE hFile );
}tmFileAccessInterface_t;

/*�ļ������ṹ����*/
typedef struct tmAvIndexEntry_t
{
    unsigned int	ckid;
    unsigned int	dwFlags;
    unsigned int	dwChunkOffset;
    unsigned int	dwChunkLength;
}tmAvIndexEntry_t;
/*������dwFlagsֵ*/
#define AVIIF_LIST							0x00000001L /* chunk is a 'LIST'*/
#define AVIIF_KEYFRAME						0x00000010L /* this frame is a key frame.*/
#define AVIIF_NOTIME						0x00000100L /* this frame doesn't take any time*/
#define AVIIF_COMPUSE						0x0FFF0000L /* these bits are for compressor use*/

/*Զ���ļ����ʽӿڻص��ṹ����*/
typedef struct tmRemoteFileInfo_t
{
	/*���ṹ��С*/
	unsigned int		dwSize;
	
	/*�򿪵��ļ�ͷ*/
	unsigned char*		pHeadBuf;
	int					iHeadSize;
	
	/*����*/
	tmAvIndexEntry_t*	pIndexBuf;
	int					iIndexCount;
	
	int					iTotalFrames;	// ��֡��
	int					iTotalTime;		// ��ʱ��
	
	/*�ص�����ָ��*/
	void*				pContext;
	/*��ȡ�ļ�֡�ص�*/
	int					(*Read)( HANDLE hObject, void* lpBuffer, int nRead, unsigned int* dwCodeTag, int* nNeedBufSize, void* context );
	/*�����ļ�λ��*/
	int					(*Seek)( HANDLE hObject, int offset, int origin, int* iPosition, unsigned int* iTimeStamp, void* context );
	
	/*���뷽ʽ*/
	unsigned char		byDecoderType;
}tmRemoteFileInfo_t;

/*�ļ�������������*/
typedef struct tmPlayConditionCfg_t
{
	unsigned int						dwSize;	
	unsigned short						wFactoryId;				/*����ID*/
	unsigned char						byChannel;				/*ͨ��	*/
	unsigned char						byPlayImage;			/*�Ƿ����ͼƬ*/
	union
	{
		/*�������ļ�ȫ���ô˽ṹ148*/
		struct
		{
			tmTimeInfo_t				struStartTime;			/*�ļ��Ŀ�ʼʱ��*/
			tmTimeInfo_t				struStopTime;			/*�ļ��Ľ���ʱ��*/
			unsigned char				byCheckStopTime;		/*�Ƿ������ʱ��*/
			unsigned char				byAlarmType;			/*��������*/
			unsigned char				byFileFormat;			/*0-JPEG,1-JPEG2000,2-RGB555,3-RGB565,4-RGB24,*/
																/*5-RGB32,6-YUV444,7-YUV422,8-YUV420,9-BKMPEG4,10-H264�ļ���ʽ20-AVI,21-MKV*/
			unsigned char				byBackupData;			/*�Ƿ��Ǳ����ļ�*/
			unsigned char				byDiskName;				/*���ڴ���*/
			unsigned char				byConvertToJpeg;		/*��JPEGǿ��ת����JPEG*/
			char						byReserves[18];
			char						sServerAddress[32];		/*��������ַ*/
			unsigned int				dwServerPort;			/*�������˿�*/	
			char						sUserName[32];			/*�û���*/
			char						sUserPass[32];			/*�û�����*/
		}time;
		/*�����ļ����ô˽ṹ148*/
		struct
		{
			unsigned char				byAutoCreateIndex;		/*�Ƿ��Զ���������*/
			unsigned char				byAutoPlay;				/*�򿪺��Ƿ��Զ�����*/
			unsigned char				byTemp[2];
			char						sFileName[128];			/*�ļ���*/
			tmFileAccessInterface_t*	pFileCallBack;			/*�ļ����ʻص�����*/
			void*						pFileContext;			/*�ļ�������ؾ��*/
			tmAvIndexEntry_t*			pAvIndex;				/*��������*/
			int							iAvIndexCount;			/*�����е�������*/
		}file;
	}info;

	unsigned char						byBufferBeforePlay;		/*��ʼ�����Ƿ���Ҫ��������*/
	unsigned char						byEnableServer;			/*�Ƿ������������*/
	unsigned char						byPlayType;				/*���ŷ�ʽ*/
	unsigned char						byDecoderType;			/*���뷽ʽ*/
	unsigned int						dwBufferSizeBeforePlay;	/*�����С*/

	/*���ݻص������ص�����*/
	int									(CALLBACK *fnStreamReadCallBack)( HANDLE hTmCC, tmRealStreamInfo_t* pStreamInfo, void* context );
	void*								fnStreamReadContext;

	/*��������ʾ�ص�*/
//	int									(CALLBACK *fnMultiStreamCallBack)( HANDLE hTmCC, tmMultiStreamInfo_t* pMultiStream, void* context );
//	void*								fnMultiStreamContext;
}tmPlayConditionCfg_t;

/*Զ���ļ����ŷ�ʽ*/
#define REMOTEPLAY_MODE_BUFFILE			0x00	/*������ʾ���ţ���Ҫ���ػ��壬�˷�ʽռ����������*/
#define REMOTEPLAY_MODE_NOBUFFILE		0x01	/*������ʾ���������ػ��壬�˷�ʽռ�����������������Сһ��*/
#define REMOTEPLAY_MODE_OLDFILE			0x02	/*�Ϸ�ʽ�����ļ�����Ҫ��a2�������*/
#define REMOTEPLAY_MODE_LOCALFILE		0x03	/*�����ļ�*/
#define REMOTEPLAY_MODE_READFILE		0x04	/*��������ʾ��ΪTMCC_ReadFile�ṩ֧��*/
#define REMOTEPLAY_MODE_CONTROLFILE		0x05	/*������������Ƶ������*/


/*�ļ�������������*/
typedef struct tmDownloadFileCfg_t
{
	unsigned int			dwSize;				/*���ṹ��С*/
	tmPlayConditionCfg_t	struCondition;		/*�ļ�����*/

	char					sFileName[128];		/*�����ļ���*/
}tmDownloadFileCfg_t;


/*Զ���ļ��򿪿��ƽṹ����*/
#define PLAY_CONTROL_PLAY				0		/*����,��iPlayData��Ϊ���Ų���(0-������ǰ����,1-�ظ�Ĭ��)*/
#define PLAY_CONTROL_STOP				1		/*ֹͣ*/
#define PLAY_CONTROL_PAUSE				2		/*��ͣ,ע��ֱֹͣ�ӵ�����عرպ�������*/
#define PLAY_CONTROL_FAST				3		/*���,��iSpeed��Ϊ�ٶ�*/
#define PLAY_CONTROL_SLOW				4		/*����,��iSpeed��Ϊ�ٶ�*/
#define PLAY_CONTROL_SEEKPOS			5		/*seek,��iCurrentPosition*/
#define PLAY_CONTROL_SEEKTIME			6		/*seek,��dwCurrentTime��Ϊʱ��*/
#define PLAY_CONTROL_STEMP				7		/*stemp,��֡����*/
#define PLAY_CONTROL_SWITCH				8		/*�л��ļ�,��szFileName��Ϊ�ļ���/��struTimeʱ��*/
#define PLAY_CONTROL_MUTE				9		/*��Ƶ����,��iEnableAudio��Ϊ����*/
#define PLAY_CONTROL_UPEND				10		/*����*/
#define PLAY_CONTROL_GETAVINDEX			11		/*�õ������ļ�������*/
#define PLAY_CONTROL_SETAVINDEX			12		/*���ò����ļ�������*/
#define PLAY_CONTROL_AUTORESETBUFTIME	13		/*�����Ƿ��Զ����ڻ���ʱ��*/
#define PLAY_CONTROL_SEEKTIME_NEW		14		/*seek,��struTime��Ϊʱ��  ����ʱ��   jukin add for gb*/
#define PLAY_CONTROL_REPAIRFILE			15		/*�޸��ļ�����*/

typedef struct tmPlayControlCfg_t
{
	unsigned int				dwSize;				/*���ṹ��С*/
	unsigned int				dwCommand;			/*��������	*/										
	union
	{
		tmTimeInfo_t			struTime;			/*�ļ��Ŀ�ʼʱ��*/
		int						iPlayData;			/*���Ų���*/
		int						iSpeed;				/*���ŵ��ٶ�*/
		int						iEnableAudio;		/*��Ƶ����*/
		int						iCurrentPosition;	/*�µĲ���λ��(֡)*/
		unsigned int			dwCurrentTime;		/*�µĲ���λ��(����)*/
		BOOL					bForward;			/*ǰ����֡*/
		BOOL					bClearDisplay;		/*�����ʾ*/
		BOOL					bAutoResetBufTime;	/*�Ƿ��Զ����ڻ���*/
		struct
		{
			unsigned char		byAutoCreateIndex;	/*�Ƿ��Զ���������*/
			unsigned char		byAutoPlay;			/*�򿪺��Ƿ��Զ�����*/
			unsigned char		byTemp[2];
			char				sFileName[128];		/*�л����ļ���*/
		}file;
		struct
		{
			tmAvIndexEntry_t*	pAvIndex;			/*��������*/
			int					iAvIndexCount;		/*�����е�������*/
			int					iAvIndexMaxCount;	/*�������������*/
		}index;
	}control;
}tmPlayControlCfg_t;

/*�����ļ��ĵ�ǰ��Ϣ*/
typedef struct tmPlayStateCfg_t
{
	unsigned int			dwSize;				/*���ṹ��С*/
	unsigned char			byCurrentState;		/*��ǰ����״̬*/
	unsigned char			byResetTime;		/*��Ҫ��λʱ���*/
	unsigned char			byResetFile;		/*��Ҫ��λʱ���*/
	unsigned char			byIndex;			/*��ǰ�ļ�������*/

	unsigned int			dwTotalFrames;		/*�ܹ�֡��*/
	unsigned int			dwCurrentFrame;		/*��ǰ֡��*/

	unsigned int			dwTotalTimes;		/*��ʱ��(����)*/
	unsigned int			dwCurrentTimes;		/*��ǰʱ��(����)*/
	
	tmTimeInfo_t			struStartTime;		/*��ǰ�����ļ��Ŀ�ʼʱ��*/

	unsigned int			dwTotalSize;		/*���ļ���С*/
	unsigned int			dwCurrentSize;		/*��ǰ�ļ���С*/
}tmPlayStateCfg_t;

/*���������Ų����ṹ����*/
/*�ļ�������������*/
typedef struct tmPlayRealStreamCfg_t
{
	unsigned int			dwSize;	
	char					szAddress[32];		/*���ӷ�������IP��ַ*/
	char					szTurnAddress[32];	/*ת������ַ*/
	int						iPort;				/*���������ӵĶ˿�*/
	char					szUser[32];			/*��¼�û���*/
	char					szPass[32];			/*��¼�û�����*/
	unsigned char			byChannel;			/*ͨ��*/
	unsigned char			byStream;			/*������*/
	unsigned char			byTranstType;		/*��������*/
	unsigned char			byReConnectNum;		/*��������	*/
	int						iTranstPackSize;	/*�������С*/
	int						iReConnectTime;		/*������ʱ����*/
	unsigned char			byTransProtocol;	/*����Э��0-�ڲ��Զ�,1-SONY,2-RTSP	*/
	unsigned char			byForceDecode;		/*����ʵ����Ϊ��ʱ�Ƿ���Ҫǿ�ƽ������*/
	unsigned char			byDecoderType;		/*���뷽ʽ*/
	unsigned char			byConnectType;		/*��������0-TcpIp,1-Udp,2-Dialing,3-TcpMulti,4-UdpMulti*/
	char					szParameter[128];	/*���Ӳ���*/
	unsigned char			byMultiStream;		/*�������б���һλ��ʾ��1�������ڶ�λ��ʾ��2����...*/
	unsigned char			byTemp[3];
}tmPlayRealStreamCfg_t;

/*����Ƶԭʼ֡��Ϣ*/
typedef struct tmAvImageInfo_t
{
	BYTE			video;				/*�Ƿ�����Ƶ*/
	BYTE			face;				/*�Ƿ������������������ôyuv[3]��tmFaceDetectInfo_tָ��*/
	BYTE			temp[2];
	union
	{
		BYTE*		yuv[4];				/* �������ʽΪYUV420ʱ��yuv[0] Y���ݣ�yuv[1] U���� yuv[2] V���ݣ���face==1ʱyuv[3]Ϊ���������ָ��*/
		BYTE*		buffer;				/*RGB��ʽʹ�����ָ�룬һ�е��ֽ�����Ӧbufsize*/
	}data;

	union
	{
		int			linesize[4];		/*�ֱ��ӦYUVһ�����ݵ��ֽ��������ܱ�ͼ���ȴ󣬱����ʽΪYUV420����ô linesize[0] Y�Ŀ�ȣ�linesize[1] U�Ŀ�� ��linesize[2] V�Ŀ��*/
		int			bufsize;			/*һ�����ݵ��ֽ����������ʽΪRGB24����ô���ֵһ��Ϊwidth����3*/
	}size;

	union
	{
		struct
		{
			short	width;
			short	height;
			int		framerate;
			BYTE	format;
			BYTE	temp[3];
		}video;
		struct
		{
			int		samplespersec;
			BYTE	channels;
			BYTE	bitspersample;
		}audio;
		BYTE		temp[16];
	}format;

	int				key_frame;	
	unsigned int	timestamp;
}tmAvImageInfo_t;


typedef enum
{
	RECORD_STATUS_STOP = 0x00,
	RECORD_STATUS_PAUSE,
	RECORD_STATUS_WORKING,
	RECORD_STATUS_ABNORMAL
}enumRecordStatus;

typedef struct tmReportRecordStatus_t		/*TMCC_MINOR_CMD_STORAGESTATUS*/
{
	unsigned int		dwSize;				/*���ṹ��С*/
	
	enumRecordStatus	enRecordStatus;		
	BYTE				byRecordType;
}tmReportRecordStatus_t;


typedef struct tmPtzSoftVersion_t		/*TMCC_MINOR_CMD_PTZ_VERSION*/
{
	unsigned int		dwSize;				/*���ṹ��С*/
	
	WORD				wptzSoftVersion;
	BYTE				byUnuse[2];
	DWORD				dwUnuse[2];
}tmPtzSoftVersion_t;

typedef struct tmPtzExtendedFunctionCfg_t				/*TMCC_MINOR_CMD_PTZ_CFG_EX*/
{
	unsigned int		dwSize;							/*���ṹ��С*/
	
	BYTE				byUartAlarmDisEn;				/*����ģʽ����ʹ��       0:�������ڱ����������  1:�ر�*/
	BYTE				byQueryAlarmDisEn;				/*ȡ������������ѯ���� 0:������ѯ 1:��������ѯ*/
	BYTE				bySendIrCutStatusDisEn;			/*IRCUT�ϱ�ʹ�� 0:�ϱ�  1:���ϱ�*/
	BYTE				byIrisCmdCtrlLaserDisEn;		/*�ر�ԭ�еĹ�Ȧ���ƹ��� 0:����IRIS���� 1:�ر��������� ������� */
		
	BYTE				byPM2_5En;						/*��3Dѡ��5ʱ��pm2.5ʹ�ܲ���Ч*/
	BYTE				byVDMProtocolEn;				/*VDMЭ��ʹ��*/
	BYTE				byUnuse[2];
	DWORD				dwUnuse[3];
}tmPtzExtendedFunctionCfg_t;


/*add by 2014-05-27*/
/*#define TMCC_MINOR_CMD_SCREENINFO					0x0A		��������Ļ����*/
typedef struct tmScreenInfo_t
{
	unsigned char	byScreenId;		/*��ĻID*/
	unsigned char	byScreenType;	/*0(4:3) 1(16:9)*/
	unsigned char	byChanCount;	/*ͨ����*/
	unsigned char	byStartNumber;	/*ͨ����ʼ���*/
}tmScreenInfo_t;

typedef struct tmScreenInfoCfg_t
{
	unsigned int	dwSize;			/*�ṹ��С*/
	unsigned int	dwCount;		/*��Ļ��*/
	tmScreenInfo_t	struScreen[1];
}tmScreenInfoCfg_t;

/*
* ���TMCC_MAJOR_CMD_VIDEOPARAMCFG //add by tzh
* ��TMCC_SetConfig������ʾͼ���������������ڲ�����Ƶ�ľ����������TMCC_Connect 
**/
typedef struct tagVideoParamCfg_t
{
	unsigned int		dwSize;			/* ���ṹ��С*/
	BYTE				bUsed[4];		/* bUsed[0]�������ȡ��Աȶȡ�Gama������bUsed[1]���ر��Ͷȡ�ɫ�ȵ�����bUsed[2]bUsed[3]����	*/
	int					iBrightness;	/* ����			0-255*/
	int					iContrast;		/* �Աȶ�		0-255	*/
	int					iThreshold;		/* �Աȶ���ֵ	0-255*/
	float				fGama;			/* gama����		0.1-3.0*/
	int					iSaturation;	/* ���Ͷ�		0-255*/
	int					iHue;			/* ɫ��			0-255*/
}tmVideoParamCfg_t;

#define 	MAXPOINTNUMINPOLYGON					20		/*ÿ�������������󶥵����*/
/*���߼��ķ�ʽ*/
#define  MOTIONLINE_METHOD_LEFTTORIGHT				0x01	/*��߿絽�ұ�*/
#define	 MOTION_LINE_METHOD_RIGHTTOLEFT				0x02	/*�ұ߿絽���*/
#define  MOTION_LINE_METHOD_TOPTOBOTTOM				0x04	/*�ϱ߿絽�±�*/
#define  MOTION_LINE_METHOD_BOTTOMTOTOP				0x08	/*�±߿絽�ϱ�*/

/*����������Ϣ*/
typedef	struct  tmPoint_t
{
	int		x;
	int		y;
}tmPoint_t;

/*�߻�����Ϣ*/
typedef struct tmLineInfo_t
{
	int						iMethod;				/*��ⷽ��*/
	unsigned char			byMotionSensitive;		/*���߼��������, 0 - 100,Խ��Խ���� ������Խ��ԽС���������Խ���ױ���⵽*/
	unsigned char			bytmp[3];
	tmPoint_t				pStarPostion;			/*�ߵĿ�ʼλ��*/
	tmPoint_t				pStopPostion;			/*�ߵĽ���λ��*/
}tmLineInfo_t;

/*���߼���������Ϣ*/
typedef struct  tmMotionLineCfg_t
{
	unsigned int			dwSize;
	BOOL					bEnable;									/*�Ƿ��������*/
	unsigned char			LineNum;				
	unsigned char			byTmp[3];
	tmLineInfo_t			pLineList[5];
	tmHandleException_t		strMotionHandleType;						/*����ʽ*/
	tmSchedTime_t			struAlarmTime[7][4];						/*����ʱ��*/
	tmTransFer_t			struAlarmTransFer[16];						/*����ͨ��*/
}tmMotionLineCfg_t;

/*ÿ��������Ϣ*/
typedef	struct tmPolygonScope_t
{
	int						byPointNum;				/*�õ��������*/
	unsigned char			byPolygonSensitive;						/*������������ȣ� 0-100ֵԽ��ԽС�����崳�������Խ�ܱ���⵽*/
	unsigned char			byPolygonTime;							/*ʱ����ֵ: ʱ�䷧ֵ����ʾĿ����뾯���������ͣ����ú��������,0-10s ���Ϊ0��ʾ����ͻᱨ��*/
	unsigned char			byTmp[2];
	tmPoint_t				pPointList[MAXPOINTNUMINPOLYGON];  /*����ķ�ΧΪ704*576��*/
}tmPolygonScope_t;

/*����������ò���*/
typedef struct tmPolygonCfg_t
{
	unsigned int			dwSize;
	unsigned char			byEnableAbandon;						/*�Ƿ����������*/
	unsigned char			byPolygonScopeNum;						/*������������������С�ڻ����5*/\
	unsigned char			byTmp[2];
	tmPolygonScope_t		pPolygonScope[5];
	tmHandleException_t		strMotionHandleType;					/*����ʽ*/
	tmSchedTime_t			struAlarmTime[7][4];					/*����ʱ��*/
	tmTransFer_t			struAlarmTransFer[16];					/*����ͨ��*/
}tmPolygonCfg_t;


/*****************����ͳ�Ƶķ���*************************/
#define FLOWLINE_ACTION_RIGHT						0x01		/*�ұ�Ϊ��*/
#define	FLOWLINE_ACTION_LEFT						0x02		/*���Ϊ��*/
#define FLOWLINE_ACTION_BOTTOM						0x03		/*�±�Ϊ��*/
#define FLOWLINE_ACTION_TOP							0x04		/*�ϱ�Ϊ��*/

typedef struct  tmFlowLine_t
{
	int						iMethod;				/*ͳ�Ʒ���*/
	tmPoint_t				pStarPostion;			/*�ߵĿ�ʼλ��*/
	tmPoint_t				pStopPostion;			/*�ߵĽ���λ��*/
	unsigned char			byMotionSensitive;		/*�������������, 0 - 100,Խ��Խ���� ������Խ��ԽС������Խ���ױ���⵽*/
	unsigned char			byTmp[3];
	int						iEnterCount;			/*����*/
	int						iExitCount;				/*����*/
}tmFlowLine_t;

/*����ͳ�����ò���*/
typedef struct  tmFlowCountCfg_t
{
	unsigned int			dwSize;
	unsigned char			byEnable;									/*�Ƿ�����ͳ��*/
	unsigned char			LineNum;		
	unsigned char			byTmp[2];
	tmFlowLine_t			pFlowList[5];
	tmHandleException_t		strMotionHandleType;						/*����ʽ*/
	tmSchedTime_t			struAlarmTime[7][4];						/*����ʱ��*/
	tmTransFer_t			struAlarmTransFer[16];						/*����ͨ��*/
}tmFlowCountCfg_t;


typedef	 struct tmAbandonInfo_t
{
	unsigned char			byAbandonSensitive;							/*�������������, 0 - 100,Խ��Խ���� ������Խ��ԽС������Խ���ױ���⵽*/
	unsigned char			byCheckTime;								/*�������10-120s����������������*/
	unsigned char			byTmp[2];
	tmAreaScope_t			struAbandonScope;							/*��������704*576*/
}tmAbandonInfo_t;

/*�������*/
typedef	struct tmAbandonCfg_t
{
	unsigned int			dwSize;
	unsigned char			byAbandonScopeNum;							/*�����������������С�ڻ����5*/
	unsigned char			byEnableAbandon;							/*�Ƿ����������*/
	unsigned char			byTmp[2];
	tmAbandonInfo_t			strAbandonList[5];		
	tmHandleException_t		strMotionHandleType;						/*����ʽ*/
	tmSchedTime_t			struAlarmTime[7][4];						/*����ʱ��*/
	tmTransFer_t			struAlarmTransFer[16];		
}tmAbandonCfg_t;

/*�ƶ�����������Ϣ*/
typedef struct tagtmPostionResult_t    /*�ƶ����������ʹ�С*/
{
	unsigned short		wX;
	unsigned short		wY;
	unsigned short		wWidth;
	unsigned short		wHeight;
}tmPostionResult_t;

typedef struct tagtmMotionRectList_t
{
	unsigned int		dwSize;			/*��������pPointList�ĳ��ȣ������Ժ�ü���*/
	unsigned short		wImage_width;
	unsigned short		wImage_height;
	unsigned short		wImotion_num;
	unsigned short		wTemp;
	tmPostionResult_t 	pPointList[1]; /*�м���������м������ֽṹ��,��ʱֻ����һ��������ĸ����� wImotion_num����*/
}tmMotionRectList_t;

/*͸���������  Add by TZH 2014-02-21*/
typedef struct tagDefogParams_t
{
	int			beRestoration;	 /*����Ĭ��ֵ��0-������״̬��1-�ָ�Ĭ��ֵ������Ĳ�����Ч��*/
	int			iMRadius;		 /*��Сֵ�˲��뾶*/
	int			iRadius;		 /*�˲��뾶��10-200��Ĭ��40��90��*/
	double		dEps;			 /*ͼ����������Ե����̶�0.001-1��Ĭ��0.005*/
	int			iLevel;			 /*͸����̶�1-100��Ĭ��82��90*/
	double		dThreshold;      /*��Ҫ����Զ�������������̶ȣ�ֵԽ����̶�ԽС0.1-1.0��Ĭ��0.2*/
	double		dGama;           /*���ȵ�����0.01-5.0��=1���Ȳ��䣬<1ͼ��䰵��>1ͼ�������Ĭ��ֵ1.3  */
	double		dSubSample;		 /*�²�����*/
}tmDefogParams_t;

typedef struct tagROI_t
{
	int x;                  
	int y;
	int width;
	int height;
}tmROI_t;

typedef struct tagDefogROIS_t
{
	int			iROICounts;     /*��������,0ֹͣ������,����͸��*/
	tmROI_t     stuROIS[8];     /*͸������� �ݶ�֧��8��������*/
}tmDefogROI_t;

/*����ģ�����������Ϣ*/
typedef struct tmIntelligentAlarm_t
{
	unsigned int			dwSize;
	int						iAlarmType;			/*�������� 1-���߱��� 2-�����뱨�� 3-�����ﱨ��*/
	int						iAlarmState;        /*����״̬*/
	int						iAlarmPostion;      /*����������λ�� */
}tmIntelligentAlarm_t;


/*TMCC_MINOR_CMD_STREAMSENDSTATUS*/
typedef struct tagCheckStreamSendStatusCfg_t
{
	DWORD		dwSize;
	BYTE		byEnable;					/*�Ƿ����ã�������Ƶ����ʱ�������ϱ�������������û�з�����ʱ��ÿ2���ϱ�һ��*/
	BYTE		byModuleId;					/*0:������ 1:�ڲ�RTSP 2:CGI 3:tmcc//STREAM_STAUTS_MODULE_SDK*/
	BYTE		byCheckTime;				/*��λ����СΪ5�� ���4���ӣ�Ӧ���ǹ���*/
	BYTE		byHandleWith;				/*0:������;1:����;2: �洢*/
	BYTE		byTemp[4];					/*����	*/
}tmCheckStreamSendStatusCfg_t;

/*ǹ�������������������Ϣ*/
typedef struct tmCameraItemInfo_t
{
	unsigned char		byEnable;//�Ƿ����ô������Ŀ
	unsigned char		byASsociateAlarm;//�������� 1-���߱��� 2-�����뱨�� 3-�����ﱨ��
	unsigned char		byAlarmArea;//���������ľ������� 
	unsigned char		byTmp;
	int					iHorBase; //���ˮƽλ��
	int					iVerBase;//�����ֱλ��
	int					iZoomBase;//�������
	char				szIP[32]; //���ip��ַ
	int					iPort;//�˿�
	char				szUser[32];//�û�
	char				szPass[32];//����
}CameraItemInfo_t;

/*ǹ������������Ϣ TMCC_MINOR_CMD_CAMTRACK*/
typedef struct tmCameraTrackCfg_t
{
	unsigned int		dwSize;
	int					HorViewAngle; //ˮƽ���ӽ�
	int					VerViewAngle; //��ֱ���ӽ�
	CameraItemInfo_t	pCamItemList[5]; //�����������Ϣ
	unsigned char		byTmp[4];
}CameraTrackCfg_t;

/*��ʽ3D���� TMCC_MINOR_CMD_3D_ZOOMANGLE*/
typedef struct tag3DCtrlZoomAngle_t
{
	DWORD 				dwSize;
	BYTE				byEnable;
	BYTE				byTemp[3];
	DWORD				dwZoom;			/*����*1000,��Ϊ��0ʱ,3D����ǿ���øñ���*/
	DWORD				dwHorVal;		/*��ǰ����ˮƽ����Ƶ��*1000*/
	DWORD				dwVerVal;		/*��ǰ������ֱ����Ƶ��*1000*/
}T3DCtrlZoomAngle_t;

/*3D�������� TMCC_MINOR_CMD_3D_AMENDMENT*/
typedef struct tag3DAmendment_t
{
	DWORD 				dwSize;
	BYTE				byEnable;
	BYTE				byTemp[3];
	int					iZoomOffsetX;		/*С�������������ĵ�ƫ��x,*1000��*/
	int					iZoomOffsetY;		/*С�������������ĵ�ƫ��y,*1000��*/
	int					iRotateAngle;		/*ͼ����ת�Ƕ�,1000������5.123��Ϊ5123*/
	int					iTemp;			
}T3DAmendment_t;


#define			THIRDANALYSE_BUF_SIZE     65536
//���������ܲ���
typedef struct tagThirdAnalyseCfg_t
{
	//���ṹ��С
	unsigned int			dwSize;
	unsigned char			AnalyseCfgbuf[THIRDANALYSE_BUF_SIZE];
}ThirdAnalyseCfg_t;

/*������붨��*/
/*�û�����*/
#define TMCC_MAJOR_CMD_USERCFG						0x101		/*�û��������������Ϣ*/
#define TMCC_MINOR_CMD_USER_MOTIFYDEFAULTUSER		0x00		/*�޸�ϵͳĬ���û���Ϣ*/
#define TMCC_MINOR_CMD_USER_INFO					0x01		/*�����û���Ϣ*/
#define TMCC_MINOR_CMD_USER_SINGLEINFO				0x02		/*�����û���Ϣ*/
#define TMCC_MINOR_CMD_USER_ADD						0x03		/*����û�*/
#define TMCC_MINOR_CMD_USER_DELETE					0x04		/*ɾ���û�*/
#define TMCC_MINOR_CMD_USER_MOTIFYPASSWORD			0x05		/*�޸��û�����*/
#define TMCC_MINOR_CMD_USER_MOTIFYRIGHT				0x06		/*�޸��û�Ȩ��*/
#define TMCC_MINOR_CMD_USER_VERIFY					0x07		/*��֤�û�*/
#define TMCC_MINOR_CMD_USER_DATA					0x08		/*�������չ���ݣ��������û������������ֻ��������*/
#define TMCC_MINOR_CMD_ENCRYPTKEY					0x09		/*�豸������Կ����*/
#define TMCC_MINOR_CMD_GETENCRYPTDATA				0x0A		/*�õ���������*/

/*��������������*/
#define TMCC_MAJOR_CMD_DEVICECFG					0x102		/*�豸����*/
#define TMCC_MINOR_CMD_DEVICE						0x00		/*�豸����*/
#define TMCC_MINOR_CMD_DEVICEEX						0x01		/*��չ�豸����*/

#define TMCC_MAJOR_CMD_NETCFG						0x103		/*�������*/
#define TMCC_MINOR_CMD_LANNETCFG					0x00		/*���������������*/
#define TMCC_MINOR_CMD_WIFINETCFG					0x01		/*���������������*/
#define TMCC_MINOR_CMD_RTSPMUTICASTCFG				0x02		/*RTSP�鲥�������ò���*/
#define TMCC_MINOR_CMD_P2PCFG						0x03		/*p2p����ģ��������Ϣ*/

#define TMCC_MAJOR_CMD_PICCFG						0x104		/*ȡͼ�����*/
#define TMCC_MINOR_CMD_PIC							0x00		/*ȡͼ�����(�ϳɽṹ)*/
#define TMCC_MINOR_CMD_OSD							0x01		/*ȡͼ��OSD����*/
#define TMCC_MINOR_CMD_MASK							0x02		/*ȡͼ���ڸǲ���*/
#define TMCC_MINOR_CMD_LOST							0x03		/*ȡͼ����Ƶ��ʧ����*/
#define TMCC_MINOR_CMD_MOTION						0x04		/*ȡͼ���ƶ�������*/
#define TMCC_MINOR_CMD_HIDEALARM					0x05		/*ȡͼ���ڵ���������*/
#define TMCC_MINOR_CMD_ADDEXPANDOSD					0x06		/*�������OSD*/
#define TMCC_MINOR_CMD_CLEAREXPANDOSD				0x07		/*�������OSD*/
#define TMCC_MINOR_CMD_OSDCOLOR						0x08		/*OSD��ɫ��������*/
#define TMCC_MINOR_CMD_APTITUDESCOUT				0x09		/*�������ܷ�������*/
#define TMCC_MINOR_CMD_FACEDETECT					0x0A		/*�����������*/
#define TMCC_MINOR_CMD_LINEDETECT					0x0B		/*����Խ����*/
#define TMCC_MINOR_CMD_POLYGONDETECT				0x0C		/*������������*/
#define TMCC_MINOR_CMD_FLOWDETECT					0x0D		/*���ó��������*/
#define TMCC_MINOR_CMD_ABANDONDETECT				0x0E		/*��������������*/
#define TMCC_MINOR_CMD_MOTIONRECT					0x0F	    /*��ȡ���ܷ���ģ���ƶ�����*/
#define	TMCC_MINOR_CMD_CAMTRACK						0x10		/*����ǹ��������Ϣ*/
#define TMCC_MINOR_CMD_THIRDANALYSE					0x11		/*���������ܲ���*/



#define TMCC_MAJOR_CMD_COMPRESSCFG					0x105		/*ѹ������*/
#define TMCC_MINOR_CMD_COMPRESSCFG					0x00		/*���ñ������*/
#define TMCC_MINOR_CMD_QUERYCOMPRESSCAPABILITY		0x01		/*��ѯ��������*/
#define TMCC_MINOR_CMD_QUERYCOMPRESSCAPABILITYEX	0x02		/*��չ��ѯ��������*/
#define TMCC_MINOR_CMD_QPROICFG						0x03		/*�������������������*/

#define TMCC_MAJOR_CMD_RECORDCFG					0x106		/*¼��ʱ�����*/
#define TMCC_MINOR_CMD_LOCALRECORDCFG				0x00		/*����¼������*/
#define TMCC_MINOR_CMD_FTPRECORDCFG 				0x01		/*FTP¼������*/

/*��̨����������*/
#define TMCC_MAJOR_CMD_DECODERCFG					0x107		
#define TMCC_MINOR_CMD_485CFG 						0x00		/*485��������*/
#define TMCC_MINOR_CMD_CRUISECFG 					0x01		/*Ѳ����������*/
#define TMCC_MINOR_CMD_PTZCFG						0x02		/*��̨��������*/
#define TMCC_MINOR_CMD_PRESETCFG					0x03		/*Ԥ�õ��������*/
#define TMCC_MINOR_CMD_ZOOMCFG						0x04		/*һ������ò���*/
#define TMCC_MINOR_CMD_TRACKCFG						0x05		/*�켣��������*/
#define TMCC_MINOR_CMD_LINECFG						0x06		/*��ɨ��������*/
#define TMCC_MINOR_CMD_AUXCFG						0x07		/*�������ز�������*/
#define TMCC_MINOR_CMD_APERTURECFG					0x08		/*��Ȧ��������*/
#define TMCC_MINOR_CMD_PTZ_CFG_EX					0x09		/*PTZģ����չ����ʹ������*/
#define TMCC_MINOR_CMD_3D_AMENDMENT					0x0A		/*3D��������*/
#define TMCC_MINOR_CMD_PTZ_INFO						0x0B		/*��̨�������Ϣ����*/

#define TMCC_MAJOR_CMD_RS232CFG 					0x108		/*232���ڲ���*/
#define TMCC_MAJOR_CMD_ALARMINCFG 					0x109		/*�����������*/
#define TMCC_MINOR_CMD_ALARMINCFG 					0x00		/*�����������*/
#define TMCC_MINOR_CMD_IRALARMINCFG 				0x01		/*IR�����������*/
#define TMCC_MAJOR_CMD_ALARMOUTCFG 					0x10A		/*�����������*/

#define TMCC_MAJOR_CMD_TIMECFG 						0x10B		/*DVRʱ��*/
#define TMCC_MINOR_CMD_TIMECFG 						0x00		/*ʱ������*/
#define TMCC_MINOR_CMD_ZONECFG 						0x01		/*ʱ������*/
#define TMCC_MINOR_CMD_DAYLIGHTCFG 					0x02		/*����ʱ����*/

#define TMCC_MAJOR_CMD_PREVIEWCFG 					0x10C		/*Ԥ������*/
#define TMCC_MINOR_CMD_PREVIEWCOLORCFG 				0x00		/*��ɫ����*/
#define TMCC_MINOR_CMD_COMPRESSOFFSETCFG 			0x01		/*ѹ��ƫ�Ʋ���*/
#define TMCC_MINOR_CMD_PREVIEWOFFSETCFG 			0x02		/*Ԥ��ƫ�Ʋ���*/
#define TMCC_MINOR_CMD_PICMODE						0x03        /*����ͼ��ģʽ(add by zzt 2009-09-17)*/
#define TMCC_MINOR_CMD_TEMPPREVIEWCOLORCFG 			0x04		/*��ʱԤ��ɫ�ʲ���*/

/*����������*/
#define TMCC_MAJOR_CMD_VIDEOOUTCFG 					0x10D		/*��Ƶ�������*/
#define TMCC_MINOR_CMD_VIDEOOUT						0x00		/*��Ƶ�������*/
#define TMCC_MINOR_CMD_CONNECTINFO					0x01		/*����������Ϣ*/
#define TMCC_MINOR_CMD_ENUMCONNECTINFO				0x02		/*�о�������Ϣ*/
#define TMCC_MINOR_CMD_WINDOWSINFO					0x03		/*������Ϣ*/
#define TMCC_MINOR_CMD_DISPLAYINFO					0x04		/*��������ʾ��Ϣ*/
#define TMCC_MINOR_CMD_LOCK							0x05		/*������ǰ���ӣ���ʾ��ѭ������*/
#define TMCC_MINOR_CMD_CLEAR						0x06		/*���ѭ���б�������ǰ����*/
#define TMCC_MINOR_CMD_CONNECT						0x07		/*��ʼ����*/
#define TMCC_MINOR_CMD_DISCONNECT					0x08		/*�Ͽ�����*/
#define TMCC_MINOR_CMD_WINDOWCAPABILITY				0x09		/*���봰������*/
#define TMCC_MINOR_CMD_VIDEOOUTOFFSET				0x0A		/*��Ƶ���ƫ��*/
#define TMCC_MINOR_CMD_SCREENINFO					0x0A		/*��������Ļ����*/

#define TMCC_MAJOR_CMD_EXCEPTIONCFG 				0x10E		/*�쳣����*/
/*����������Ϣ*/
#define TMCC_MAJOR_CMD_SERVERMESSAGE				0x10F		/*��������Ϣ*/
#define TMCC_MINOR_CMD_DEBUGINFO					0x01		/*������������Ϣ�����԰汾��Ч*/
#define TMCC_MINOR_CMD_SERVERSTART 					0x02		/*����������*/
#define TMCC_MINOR_CMD_SERVERSTOP 					0x03		/*�������˳�*/
#define TMCC_MINOR_CMD_SERVERALARM 					0x04		/*�����ϴ��������ľ�����Ϣ��tmToManagerAlarmInfo_t*/
#define TMCC_MINOR_CMD_SERVERWANTSYNCTIME			0x05		/*������ϣ����ͬ��ʱ��*/
#define TMCC_MINOR_CMD_SERVERIMAGE					0x06		/*����������ͼƬ�ϴ�,������Ϣ��tmToManagerImageInfo_t*/
#define TMCC_MINOR_CMD_PTZCLOSEBYOTHERUSER			0x07		/*��̨���Ʊ������û��ر�*/
#define TMCC_MINOR_CMD_PTZCLOSEBYTIMEOUT			0x08		/*��̨����ʱ�䳬ʱ�ر�*/
#define TMCC_MINOR_CMD_SERIALMESSAGE				0x09		/*���������صĴ�������*/
#define TMCC_MINOR_CMD_SERVERLIVEHEART				0x0A		/*�豸��������*/
#define TMCC_MINOR_CMD_APERTUREREPAIRCOMPLETE		0x0B		/*��ȦУ�����*/
#define TMCC_MINOR_CMD_BADPIXREPAIRCOMPLETE			0x0C		/*�����������޸����*/
#define TMCC_MINOR_CMD_SAFEGUARDINFO				0x0D		/*��ȫ��ʿ�����ϴ��������ľ�����Ϣ��tmToManagerSafeGuardInfo_t*/
#define TMCC_MINOR_CMD_ZOOMREPAIRCOMPLETE			0x0E		/*�豸����Ч�����*/
#define TMCC_MINOR_CMD_AWBREPAIRREQUEST				0x0F		/*�豸��ƽ��Ч���������*/
#define TMCC_MINOR_CMD_SERVERCALLPTZ				0x10		/*�豸������̨*/
#define TMCC_MINOR_CMD_LENSREPAIRREQUEST			0x11		/*�豸��ͷ���������������*/
#define TMCC_MINOR_CMD_ARRIVEPTZPOINT				0x12		/*��̨���õ�λ�õ�λ��*/
#define TMCC_MINOR_CMD_ARRIVEZOOMPOINT				0x13		/*��о���õ�λ�õ�λ��*/
#define TMCC_MINOR_CMD_FPNREPAIRREQUEST				0x14		/*�豸FPN�����������*/

/*��̨��������*/
#define TMCC_MAJOR_CMD_PTZCONTROL 					0x110		/*��������̨�����봮�ڿ���*/
#define TMCC_MINOR_CMD_PTZGETDECODERLIST			0x00		/*�õ���̨���ƽ�����Э��*/
#define TMCC_MINOR_CMD_PTZOPEN 						0x01		/*����̨����*/
#define TMCC_MINOR_CMD_PTZOPENANDLOCK				0x02		/*����̨���ƺ�������̨*/
#define TMCC_MINOR_CMD_PTZCLOSE 					0x03		/*�ر���̨����*/
#define TMCC_MINOR_CMD_PTZSENDCMD					0x04		/*������̨��������*/
#define TMCC_MINOR_CMD_PTZTRANS						0x05		/*����͸����������*/
#define TMCC_MINOR_CMD_SERIALOPEN					0x06		/*�򿪴���ͨ��ͨ��*/
#define TMCC_MINOR_CMD_SERIALCLOSE					0x07		/*�ر�ͨ��ͨ��*/
#define TMCC_MINOR_CMD_SERIALSEND					0x08		/*����ͨ��ͨ������*/
#define TMCC_MINOR_CMD_GETPTZINFO					0x09		/*��ȡ��ǰ��̨��Ϣ*/
#define TMCC_MINOR_CMD_SERIALRECV					0x0A		/*����ͨ��ͨ������*/
#define TMCC_MINOR_CMD_UPGRADE_PTZ					0x0B		/*�����������*/
#define TMCC_MINOR_CMD_GET_PTZVERSION				0x0C		/*��ȡ��̨�汾��Ϣ*/
#define TMCC_MINOR_CMD_GETALLPTZINFO				0x0D		/*��ȡ��ǰ������̨��Ϣ*/
#define TMCC_MINOR_CMD_GETALLVIEWSIZE				0x0E		/*��ȡzoom���п��ӽ�*/
#define TMCC_MINOR_CMD_GOTOZOOMTOP					0x0F		/*����ֱ�ӵ�����*/

/*�������Ļ�������*/
#define TMCC_MAJOR_CMD_SERVERCONTROL				0x111		/*Զ�̷���������*/
#define TMCC_MINOR_CMD_REMONTALARMIN				0x01		/*�����ź��ϴ�������*/
#define TMCC_MINOR_CMD_OPENLIGHT					0x02		/*������״̬�ƿ���*/
#define TMCC_MINOR_CMD_CLOSELIGHT					0x03		/*������״̬�ƹر�*/
#define TMCC_MINOR_CMD_OPENBUZZER					0x04		/*����������������*/
#define TMCC_MINOR_CMD_CLOSEBUZZER					0x05		/*�������������ر�*/
#define TMCC_MINOR_CMD_GETWORKSTATE					0x06		/*�õ�����������״̬*/
#define TMCC_MINOR_CMD_REMONTCLOSEALARMOUT			0x07		/*�ֶ��رձ������*/
#define TMCC_MINOR_CMD_REMONTOPENALARMOUT			0x08		/*�����򿪱������*/
#define TMCC_MINOR_CMD_RESET						0x09		/*ϵͳ��λ*/
#define TMCC_MINOR_CMD_REMONTVIDEOMOTION			0x0A		/*��Ƶ�ƶ������ź�*/
#define TMCC_MINOR_CMD_REMONTVIDEOLOST				0x0B		/*��Ƶ��ʧ�����ź�*/
#define TMCC_MINOR_CMD_REMONTVIDEOHIDE				0x0C		/*��Ƶ�ڵ������ź�*/
#define TMCC_MINOR_CMD_REQUESTUPGRADE				0x0D		/*Զ��������*/
#define TMCC_MINOR_CMD_OPENIRCUT					0x0E		/*���˹�Ƭ*/
#define TMCC_MINOR_CMD_CLOSEIRCUT					0x0F		/*�ر��˹�Ƭ*/
#define TMCC_MINOR_CMD_MANUALCAPTURE				0x10		/*Զ���ֶ�ץͼ��������*/
#define TMCC_MINOR_CMD_AUTOAPERTUREREPAIR			0x11		/*�Զ�����Focus��ֵ*/
#define TMCC_MINOR_CMD_UPGRADEKEEPIP				0x12		/*��������IP��ַ��Ϣ*/
#define TMCC_MINOR_CMD_SYNCNTPSERVER				0x13		/*ϵͳ����ͬ��NTP������*/
#define TMCC_MINOR_CMD_STARTMANUALRECORD			0x14		/*���ֶ�¼��*/
#define TMCC_MINOR_CMD_STOPMANUALRECORD				0x15		/*�ر��ֶ�¼��*/
#define TMCC_MINOR_CMD_HANDLE						0x16		/*����*/
#define TMCC_MINOR_CMD_SAVECONFIGINFO				0x17		/*����������Ϣ*/
#define TMCC_MINOR_CMD_CONTROLSAFEDOOR				0x18		/*���ư�ȫ��ʿ��״̬��*/
#define TMCC_MINOR_CMD_SAVEIRCUTFOCUS				0x19		/*���浱ǰzoomλ�õ�Focusֵ�Ա��л�IRCUTʹ��*/
#define TMCC_MINOR_CMD_TESTCAMEATINGLE				0x1A		/*Ч�����������*/
#define TMCC_MINOR_CMD_CLOSEOSDVIEW					0x1B		/*ǿ����ʱ�ر�OSD*/
#define TMCC_MINOR_CMD_OPENOSDVIEW					0x1C		/*ǿ����ʱ��OSD(�Ƿ���ʾ��OSD������)*/
#define TMCC_MINOR_CMD_PAUSEMANUALRECORD			0x1D		/*��ͣ�ֶ�¼��wangjun add*/
#define TMCC_MINOR_CMD_INTELLIGENT					0x1E		/*����ģ�鱨��*/

#define TMCC_MAJOR_CMD_ALARMCFG 					0x112		/*�����������*/

#define TMCC_MAJOR_CMD_DISKCONTROL					0x113		/*���̴�������*/
#define TMCC_MINOR_CMD_DRIVEINFO					0x01		/*�õ�����Ӳ����Ϣ*/
#define TMCC_MINOR_CMD_DRIVEINIT					0x02		/*��ʼ������Ӳ��*/
#define TMCC_MINOR_CMD_DRIVEALARMCFG				0x03		/*���̱�������*/
#define TMCC_MINOR_CMD_DRIVEREMOVE					0x04		/*����ж��*/
#define TMCC_MINOR_CMD_DRIVELOAD					0x05		/*���̼���*/

/*���������չ����*/
#define TMCC_MAJOR_CMD_NETCFGEX						0x114		/*net1=SNTP+..����*/
#define TMCC_MINOR_CMD_NTPCFG						0x00
#define TMCC_MINOR_CMD_FTPCFG						0x01
#define TMCC_MINOR_CMD_SMTPCFG						0x02
#define TMCC_MINOR_CMD_LIVEHEARTCFG					0x03		/*������*/
#define TMCC_MINOR_CMD_DDNSCFG						0x04		/*DDNS*/
#define TMCC_MINOR_CMD_UPCFG						0x05		/*�豸�����ϴ�����*/
#define TMCC_MINOR_CMD_STREAMSENDSTATUS				0x06		/*�����Ƶ������״̬*/

/*ѹ��������չ����*/
#define TMCC_MAJOR_CMD_COMPRESSCFGA					0x115		/*��չѹ������*/
#define TMCC_MINOR_CMD_COMPRESSCFGA					0x00		/*ͼ��ѹ������*/

#define TMCC_MAJOR_CMD_VIDEOINCFG					0x116		/*��Ƶ��������*/
#define TMCC_MINOR_CMD_VIDEOIN						0x00		/*��������*/
#define TMCC_MINOR_CMD_IRCUTVIDEOIN					0x01		/*IRCUT�л���Ӧ��������*/
#define TMCC_MINOR_CMD_SCHEDVIDEOIN					0x02		/*��ʱ�䲼������������*/
#define TMCC_MINOR_CMD_VIDEOINPREVIEW				0x03		/*��ʱԤ��VideoIn����*/
#define TMCC_MINOR_CMD_AWBCFG						0x04		/*��ƽ���������*/
#define TMCC_MINOR_CMD_LIGHTINHIBITION				0x05		/*ǿ������*/
#define TMCC_MINOR_CMD_IRCUTVIDEOINPREVIEW			0x06		/*��ʱԤ��IRCutVin����*/
#define TMCC_MINOR_CMD_SCHEDVIDEOINPREVIEW			0x07		/*��ʱԤ��SchedVideoIn����*/
#define TMCC_MINOR_CMD_LENSDEWARP					0x08		/*��ͷ����У����������*/

#define TMCC_MAJOR_CMD_SHUTTERCFG					0x117

/*ץͼ������*/
#define TMCC_MAJOR_CMD_CAPTUREIMAGECFG				0x118
#define TMCC_MINOR_CMD_CAPTUREIMAGECFG				0x00		/*ץͼ������*/
#define TMCC_MINOR_CMD_CAPTURESCHEDCFG				0x01		/*ʱ�䲼��������*/

/*��Ƶ������������*/
#define TMCC_MAJOR_CMD_AUDIOCFG                     0x119

/*NVRͨ����Ϣ��Ϣ�����������*/
#define TMCC_MAJOR_CMD_CHANNELCFG                   0x11A       /*ͨ������������*/
#define TMCC_MINOR_CMD_SINGLECHANNEL                0x00        /*���õ���ͨ����Ϣ(����/��ȡ)*/
#define TMCC_MINOR_CMD_ALLCHANNEL                   0x01        /*��������ͨ����Ϣ(����/��ȡ)*/
#define TMCC_MINOR_CMD_SINGLERTSPNAME               0x02        /*���õ���ͨ��RTSP����(����/��ȡ)*/
#define TMCC_MINOR_CMD_ALLRTSPNAME                  0x03        /*��������ͨ��RTSP����(����/��ȡ)*/

/*NVR�����ⱨ���豸*/
#define TMCC_MAJOR_CMD_ALARMDEVICECFG               0x11B       /*�����豸����������*/
#define TMCC_MINOR_CMD_SINGLEALARMDEVICE            0x00        /*���õ��������豸��Ϣ(����/��ȡ)*/
#define TMCC_MINOR_CMD_ALLALARMDEVICE               0x01        /*�������б����豸��Ϣ(����/��ȡ)*/

/*�豸��־����*/
#define TMCC_MAJOR_CMD_LOGCFG						0x11C
#define TMCC_MINOR_CMD_ENUMLOG						0x00		/*ö��������־*/
#define TMCC_MINOR_CMD_CLEARLOG						0x01		/*�����־*/

/*��������������*/
#define TMCC_MAJOR_CMD_CONNECTCFG					0x11D
#define TMCC_MINOR_CMD_CONNECTLISTCFG				0x00		/*��������*/
#define TMCC_MINOR_CMD_CLEARCONNECT					0x01		/*�����������*/

/*�������γ�����������ӦtmTheodoliteCfg_t�ṹ*/
#define TMCC_MAJOR_CMD_THEODOLITECFG				0x11E


/*IRCUT����������*/
#define TMCC_MAJOR_CMD_IRCUTCFG						0x11F
#define TMCC_MINOR_CMD_IRCUTCFG						0x00		/*����IRCUT*/

/*�����ͨ�������ϱ�״̬��Ϣ*/
#define TMCC_MAJOR_CMD_UART_REPORT					0x120
#define TMCC_MINOR_CMD_STORAGESTATUS				0x00		/*�洢״̬�ϱ�*/
#define TMCC_MINOR_CMD_FACE_CEHCK					0x01		/*��������ϱ�*/

/*CIG��Ϣ*/
#define TMCC_MAJOR_CMD_CGIMSG						0x123		/*CIG��Ϣ*/
#define TMCC_MINOR_CMD_CGIMSG						0x00	

#define TMCC_MAJOR_CMD_LOCALSPECIALCFG				0x124	/*���õ�ʽ����������*/
#define TMCC_MINOR_CMD_PTZHONGWAILIANGDU			0x00	/*���ò�ͬλ���º���Ƶ�����*/
#define TMCC_MINOR_CMD_PTZGUANGMINFAZHI				0x01	/*�������������ֵ*/
#define TMCC_MINOR_CMD_3D_ZOOMANGLE					0x02	/*3DЭ����Խ����ʽ����*/

/* ��Ƶ��ʾ�������� add by tzh*/ 
#define TMCC_MAJOR_CMD_VIDEOPARAMCFG				0x125		/*��ʾ���ȡ��Աȶȡ�٤�����Ͷȡ�ɫ�ȵ�*/
#define TMCC_MINOR_CMD_VIDEOPARAMCFG				0x00

/* �û�Ȩ�޶��� */
#define	TMCC_USERRIGHT_CONTROLPTZ					0x00000001	/*λ0: Զ�̿�����̨*/
#define	TMCC_USERRIGHT_MANUALREC					0x00000002	/*λ1: Զ���ֶ�¼��*/
#define	TMCC_USERRIGHT_PLAYBACK						0x00000004	/*λ2: Զ�̻ط�*/
#define	TMCC_USERRIGHT_SETUP						0x00000008	/*λ3: Զ�����ò�������������*/
#define	TMCC_USERRIGHT_LOOKSTAUS					0x00000010	/*λ4: Զ�̲鿴״̬����־*/
#define	TMCC_USERRIGHT_ADVANCE						0x00000020	/*λ5: Զ�̸߼�����(��������ʽ�����������ػ�)*/
#define	TMCC_USERRIGHT_TALK							0x00000040	/*λ6: Զ�̷��������Խ�*/
#define	TMCC_USERRIGHT_PREVIEW						0x00000080	/*λ7: Զ��Ԥ��*/
#define	TMCC_USERRIGHT_ALARM						0x00000100	/*λ8: Զ�����󱨾��ϴ����������*/
#define	TMCC_USERRIGHT_CONTROLLOCAL					0x00000200	/*λ9: Զ�̿��ƣ��������*/
#define	TMCC_USERRIGHT_SERIALPORT					0x00000400	/*λ10: Զ�̿��ƴ���*/
#define	TMCC_USERRIGHT_MOTIFYUSER					0x00000800	/*λ11: Զ���޸��û�*/
#define	TMCC_USERRIGHT_MOTIFYSELFPASSWORD			0x00001000	/*λ12: Զ���޸��û��Լ�������*/
#define	TMCC_USERRIGHT_RTSPCONNECT					0x00002000	/*λ13: Զ��RTSP����*/

/*�����ļ���״̬*/
#define	TMCC_PLAY_STATE_STOP						0			/*ֹͣ����*/
#define	TMCC_PLAY_STATE_PAUSE						1			/*��ͣ����*/
#define	TMCC_PLAY_STATE_PLAY						2			/*����*/
#define	TMCC_PLAY_STATE_FAST						3			/*���*/
#define	TMCC_PLAY_STATE_SLOW						4			/*����*/
#define	TMCC_PLAY_STATE_OPEN						5			/*���ļ��ɹ�*/
#define	TMCC_PLAY_STATE_SWITCH						6			/*�Ѿ��л��ļ�*/
#define	TMCC_PLAY_STATE_FILEEND						7			/*�ļ�ȫ���������*/
#define TMCC_PLAY_STATE_STREAMBUFFERRING			8			/*���ڻ�������*/
#define TMCC_PLAY_STATE_ENCFMTCHANGE				9			/*�����ʽ�ı�*/

/*������Ƶ�����ʽ*/
#define TMCC_IMAGEOUT_FMT_420P						0
#define TMCC_IMAGEOUT_FMT_RGB15						1
#define TMCC_IMAGEOUT_FMT_RGB16						2
#define TMCC_IMAGEOUT_FMT_RGB24						3
#define TMCC_IMAGEOUT_FMT_RGB32						4
#define TMCC_IMAGEOUT_FMT_YUY2						5
#define TMCC_IMAGEOUT_FMT_YVYU						6
#define TMCC_IMAGEOUT_FMT_UYVY						7
#define TMCC_IMAGEOUT_FMT_420P2						8
#define TMCC_IMAGEOUT_FMT_422P						9
#define TMCC_IMAGEOUT_FMT_422P2						10
#define TMCC_IMAGEOUT_FMT_H264						11
#define TMCC_IMAGEOUT_FMT_MJPEG						12
#define TMCC_IMAGEOUT_FMT_H265						13

#define TMCC_CAPTURE_IMAGETYPE_BMP					0x00
#define TMCC_CAPTURE_IMAGETYPE_JPEG					0x01
#define TMCC_CAPTURE_IMAGETYPE_H264					0x02
#define TMCC_CAPTURE_IMAGETYPE_YUV					0x03
#define TMCC_CAPTURE_IMAGETYPE_H265					0x04
#define TMCC_CAPTURE_IMAGETYPE_RAW					0x05
#define TMCC_CAPTURE_IMAGETYPE_DEF					0xFF

#define TMCC_CAPTURE_IMAGEFMT_JPEG					0x00
#define TMCC_CAPTURE_IMAGEFMT_BMP					0x01
#define TMCC_CAPTURE_IMAGEFMT_RGB555				0x02
#define TMCC_CAPTURE_IMAGEFMT_RGB565				0x03
#define TMCC_CAPTURE_IMAGEFMT_RGB24					0x04
#define TMCC_CAPTURE_IMAGEFMT_RGB32					0x05
#define TMCC_CAPTURE_IMAGEFMT_YUV444				0x06
#define TMCC_CAPTURE_IMAGEFMT_YUV422				0x07
#define TMCC_CAPTURE_IMAGEFMT_YUV420				0x08
#define TMCC_CAPTURE_IMAGEFMT_BKMPEG4				0x09
#define TMCC_CAPTURE_IMAGEFMT_H264					0x0A
#define TMCC_CAPTURE_IMAGEFMT_H265					0x0B
#define TMCC_CAPTURE_IMAGEFMT_Y_UV420				0x0C
#define TMCC_CAPTURE_IMAGEFMT_Y_VU420				0x0D
#define TMCC_CAPTURE_IMAGEFMT_RAW					0x0E

/*�����������*/
#define TMCC_ERR_SUCCESS						    0x00000000	/*û�д�����*/
#define TMCC_ERR_HANDLE_INVALID						0xC0000001	/*�Ƿ����*/
#define TMCC_ERR_PARAMETER_INVALID					0xC0000002	/*��������*/
#define TMCC_ERR_MEMORY_OUT							0xC0000003	/*�ڴ��������*/
#define TMCC_ERR_THREAD_CREATE						0xC0000004	/*�߳����ɴ���*/
#define TMCC_ERR_THREAD_START						0xC0000005	/*�����̴߳���*/
#define TMCC_ERR_THREAD_STOP						0xC0000006	/*ֹͣ�̴߳���*/
#define TMCC_ERR_SOCKET_CREATE						0xC0000007	/*�׽������ɴ���*/
#define TMCC_ERR_SERVERNOCONFIG 					0xC0000008  /*������û�г�ʼ�����ýӿ�*/
#define TMCC_ERR_SERVEREXCEPTION 					0xC0000009  /*�������������÷����쳣*/
#define TMCC_ERR_USERNOTLOGIN 						0xC000000A  /*���û�û�е�¼*/
#define TMCC_ERR_NOTSETUP 						    0xC000000B  /*��������*/
#define TMCC_ERR_NOTDISCONNECT					    0xC000000C  /*û�жϿ�����*/
#define TMCC_ERR_NETWORK_FAIL_CONNECT			    0xC000000D	/*���ӷ�����ʧ��*/
#define TMCC_ERR_NETWORK_SEND_ERROR				    0xC000000E	/*�����������ʧ��*/
#define TMCC_ERR_NETWORK_RECV_ERROR				    0xC000000F	/*�ӷ�������������ʧ��*/
#define TMCC_ERR_NETWORK_RECV_TIMEOUT			    0xC0000010	/*�ӷ������������ݳ�ʱ*/
#define TMCC_ERR_NETWORK_ERRORDATA				    0xC0000011	/*���͵���������*/
#define TMCC_ERR_NETWORK_SERVERNOSTART			    0xC0000012	/*������û������*/
#define	TMCC_ERR_OPERNOTFINISH					    0xC0000013  /*�ϴεĲ�����û�����*/
#define TMCC_ERR_NOENOUGH_BUF					    0xC0000014	/*������̫С*/
#define TMCC_ERR_COMMAND_INVALID				    0xC0000015	/*�Ƿ�����*/
#define TMCC_ERR_UPGRADEFILENOTOPEN				    0xC0000016	/*�����ļ����ܴ�*/
#define TMCC_ERR_UPGRADESIZELARG				    0xC0000017	/*�����ļ���С����������*/
#define TMCC_ERR_UPGRADEPARITY					    0xC0000018	/*�����ļ�Ч�����������*/
#define TMCC_ERR_UPGRADEFILENOTREAD				    0xC0000019	/*�����ļ����ܶ�ȡ*/
#define TMCC_ERR_STRUCTSIZE						    0xC000001A	/*�ṹ�еĴ�С����*/
#define TMCC_ERR_DATACRC						    0xC000001B	/*����CRCЧ�����*/
#define	TMCC_ERR_USEREXIST						    0xC000001D  /*�û��Ѿ�����*/
#define	TMCC_ERR_USERMAXNUM						    0xC000001E  /*�û��ﵽ�����*/
#define TMCC_ERR_NOINIT 						    0xC000001F /*û�г�ʼ��*/
#define TMCC_ERR_CHANNEL_ERROR 					    0xC0000020 /*ͨ���Ŵ���*/
#define TMCC_ERR_OVER_MAXLINK 					    0xC0000021 /*���ӵ�DVR�Ŀͻ��˸����������*/
#define TMCC_ERR_VERSIONNOMATCH					    0xC0000022 /*�汾��ƥ��*/
#define TMCC_ERR_ORDER_ERROR					    0xC0000023 /*���ô������*/
#define TMCC_ERR_OPERNOPERMIT					    0xC0000024 /*�޴�Ȩ��*/
#define TMCC_ERR_COMMANDTIMEOUT					    0xC0000025 /*DVR����ִ�г�ʱ*/
#define TMCC_ERR_ERRORSERIALPORT				    0xC0000026 /*���ںŴ���*/
#define TMCC_ERR_ERRORALARMPORT					    0xC0000027 /*�����˿ڴ���*/
#define TMCC_ERR_PARAMETER_ERROR 				    0xC0000028  /*��������*/
#define TMCC_ERR_CHAN_EXCEPTION					    0xC0000029	/*������ͨ�����ڴ���״̬*/
#define TMCC_ERR_NODISK							    0xC000002A	/*û��Ӳ��*/
#define TMCC_ERR_ERRORDISKNUM					    0xC000002B	/*Ӳ�̺Ŵ���*/
#define TMCC_ERR_DISK_FULL						    0xC000002C	/*������Ӳ����*/
#define TMCC_ERR_DISK_ERROR						    0xC000002D	/*������Ӳ�̳���*/
#define TMCC_ERR_NOSUPPORT						    0xC000002E	/*��������֧��*/
#define TMCC_ERR_BUSY							    0xC000002F	/*������æ*/
#define TMCC_ERR_MODIFY_FAIL					    0xC0000030	/*�������޸Ĳ��ɹ�*/
#define TMCC_ERR_PASSWORD_FORMAT_ERROR			    0xC0000031	/*���������ʽ����ȷ*/
#define TMCC_ERR_DISK_FORMATING					    0xC0000032	/*Ӳ�����ڸ�ʽ����������������*/
#define TMCC_ERR_DVRNORESOURCE					    0xC0000033	/*DVR��Դ����*/
#define	TMCC_ERR_DVROPRATEFAILED				    0xC0000034  /*DVR����ʧ��*/
#define TMCC_ERR_OPENHOSTSOUND_FAIL 			    0xC0000035  /*��PC����ʧ��*/
#define TMCC_ERR_DVRVOICEOPENED 				    0xC0000036  /*�����������Խ���ռ��*/
#define	TMCC_ERR_TIMEINPUTERROR					    0xC0000037  /*ʱ�����벻��ȷ*/
#define	TMCC_ERR_NOSPECFILE						    0xC0000038  /*�ط�ʱ������û��ָ�����ļ�*/
#define TMCC_ERR_CREATEFILE_ERROR				    0xC0000039	/*�����ļ�����*/
#define	TMCC_ERR_FILEOPENFAIL					    0xC000003A  /*���ļ�����*/
#define	TMCC_ERR_GETPLAYTIMEFAIL				    0xC000003B  /*��ȡ��ǰ���ŵ�ʱ�����*/
#define	TMCC_ERR_PLAYFAIL						    0xC000003C  /*���ų���*/
#define TMCC_ERR_FILEFORMAT_ERROR				    0xC000003D  /*�ļ���ʽ����ȷ*/
#define TMCC_ERR_DIR_ERROR						    0xC000003E	/*·������*/
#define TMCC_ERR_ALLOC_RESOUCE_ERROR			    0xC000003F  /*��Դ�������*/
#define TMCC_ERR_AUDIO_MODE_ERROR				    0xC0000040	/*����ģʽ����*/
#define TMCC_ERR_CREATESOCKET_ERROR				    0xC0000042	/*����SOCKET����*/
#define TMCC_ERR_SETSOCKET_ERROR				    0xC0000043	/*����SOCKET����*/
#define TMCC_ERR_MAX_NUM						    0xC0000044	/*�����ﵽ���*/
#define TMCC_ERR_USERNOTEXIST					    0xC0000045	/*�û�������*/
#define TMCC_ERR_WRITEFLASHERROR				    0xC0000046  /*дFLASH����*/
#define TMCC_ERR_UPGRADEFAIL					    0xC0000047  /*DVR����ʧ��*/
#define TMCC_ERR_CARDHAVEINIT					    0xC0000048  /*���뿨�Ѿ���ʼ����*/
#define TMCC_ERR_PLAYERFAILED					    0xC0000049	/*�������д���*/
#define TMCC_ERR_MAX_USERNUM					    0xC000004A  /*�û����ﵽ���*/
#define TMCC_ERR_GETLOCALIPANDMACFAIL			    0xC000004B  /*��ÿͻ��˵�IP��ַ�������ַʧ��*/
#define TMCC_ERR_NOENCODEING					    0xC000004C	/*��ͨ��û�б���*/
#define TMCC_ERR_IPMISMATCH						    0xC000004D	/*IP��ַ��ƥ��*/
#define TMCC_ERR_MACMISMATCH					    0xC000004E	/*MAC��ַ��ƥ��*/
#define TMCC_ERR_UPGRADELANGMISMATCH			    0xC000004F	/*�����ļ����Բ�ƥ��*/
#define TMCC_ERR_PASSWORDVERIFY					    0xC0000050	/*�û��������*/
#define TMCC_ERR_USERLOGIN						    0xC0000051	/*�û��Ѿ���¼*/
#define TMCC_ERR_CANNOTDELETEUSER				    0xC0000052	/*�û�����ɾ��*/
#define TMCC_ERR_MODALNOTEXIST					    0xC0000053	/*�ð汾�Ĵ�ģ�鲻����*/
#define TMCC_ERR_SERVERSTARTTING				    0xC0000054	/*����������������*/
#define TMCC_ERR_CHANNELPTZOPEN					    0xC0000055	/*�򿪿�����̨��ͨ������*/
#define TMCC_ERR_PTZCONTROLNOTOPEN				    0xC0000056	/*��̨����û�д�*/
#define TMCC_ERR_GETPTZCONTROL					    0xC0000057	/*���ܵõ���̨������Ϣ*/
#define TMCC_ERR_SERIALDATASIZE						0xC0000058	/*͸���������ݴ�С����*/
#define TMCC_ERR_PTZOPENED						    0xC0000059	/*��̨�Ѿ��������û���*/
#define TMCC_ERR_PTZLOCKED						    0xC000005A	/*��̨�Ѿ��������û�����*/
#define TMCC_ERR_NOVOICEFUNCTION				    0xC000005B	/*�������Խ�����*/
#define TMCC_ERR_VOICEHAVECONNECT				    0xC000005C	/*�����Խ��Ѿ���ռ��*/
#define TMCC_ERR_VOICENOTOPEN					    0xC000005D	/*�����Խ���ʧ��*/
#define TMCC_ERR_INUPGRADE						    0xC000005E	/*��������ģʽ���ܴ�*/
#define TMCC_ERR_ALARMINCHANNEL					    0xC000005F	/*���籨��ͨ������*/
#define TMCC_ERR_SERIALHAVEOPEN					    0xC0000060	/*ͨ��ͨ���Ѿ���*/
#define TMCC_ERR_SERIALNOTOPEN					    0xC0000061	/*ͨ��ͨ��û�д�*/
#define TMCC_ERR_NOTOPENUPGRADEMODAL				0xC0000062	/*û�д�����ģʽ*/
#define TMCC_ERR_UPGRADEMODALNOSUPPORR				0xC0000063	/*ϵͳ��֧�ֵ�����ģ��*/
#define TMCC_ERR_OPENUPGRADEMODALWRITE				0xC0000064	/*��дģ�����*/
#define TMCC_ERR_UPGRADEMODALNOTREAD				0xC0000065	/*ģ�鲻�ܶ�����*/
#define TMCC_ERR_HTTPPORTIS6000						0xC0000066	/*HTTP�����˿ڲ���Ϊ6000*/
#define TMCC_ERR_VIDEOSTANDARD						0xC0000067	/*���õ���Ƶ��ʽ��֧��*/
#define TMCC_ERR_DELETETODAYLOG						0xC0000068	/*������־����ɾ��*/
#define TMCC_ERR_NOENOUGH_DATA						0xC0000069	/*��������û��������������*/
#define TMCC_ERR_WRITEFILE							0xC000006A	/*д�ļ�����*/
#define TMCC_ERR_READFILE							0xC000006B	/*���ļ�����*/
#define TMCC_ERR_FILEEND							0xC000006C	/*���ļ����*/
#define TMCC_ERR_FILEINDEX							0xC000006D	/*���ļ���������*/
#define TMCC_ERR_CAPTUREIMAGE						0xC000006E	/*�ֶ�ץͼʧ��*/
#define TMCC_ERR_BUFFERFULL							0xC0000070	/*�ڲ������� ���ٴ�����*/

/*�������*/
#define ERROR_CODE_BEGINCONNECT						0xC0001000
#define ERROR_CODE_CONNECTSUCCESS					0xC0001001
#define ERROR_CODE_NETWORK							0xC0001002
#define ERROR_CODE_CONNECTERROR						0xC0001003
#define ERROR_CODE_CONNECTERROR_1000				0xC0001004
#define ERROR_CODE_SERVERSTOP						0xC0001005
#define ERROR_CODE_SERVERSTOP_1000					0xC0001006
#define ERROR_CODE_TIMEOUT							0xC0001007
#define ERROR_CODE_TIMEOUT_1000						0xC0001008
#define ERROR_CODE_SENDDATA							0xC0001009
#define ERROR_CODE_SENDDATA_1000					0xC000100A
#define ERROR_CODE_RECVDATA							0xC000100B
#define ERROR_CODE_RECVDATA_1000					0xC000100C

#define ERROR_CODE_CLOSECONNECT						0xC0010000
#define ERROR_CODE_SERVERNOSTART					0xC0010001
#define ERROR_CODE_SERVERERROR						0xC0010002
#define ERROR_CODE_CHANNELLIMIT 					0xC0010003
#define ERROR_CODE_SERVERLIMIT						0xC0010004
#define ERROR_CODE_SERVERREFUSE						0xC0010005
#define ERROR_CODE_IPLIMIT							0xC0010006
#define ERROR_CODE_PORTLIMIT						0xC0010007
#define ERROR_CODE_TYPEERROR						0xC0010008
#define ERROR_CODE_USERERROR						0xC0010009
#define ERROR_CODE_PASSWORDERROR					0xC001000A
#define ERROR_CODE_DONTTURN							0xC001000B
#define ERROR_CODE_VERSION							0xC0100000
#define ERROR_CODE_FACTORY							0xC0100001
#define ERROR_CODE_TRANSPACKETSIZE					0xC0100002
#define ERROR_CODE_DECODEVIDEOERROR					0xC0100003

#endif	/*__TMTRANSEDEFINE_H__*/
