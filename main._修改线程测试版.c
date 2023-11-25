/*
*	Bluetooth Remote Control example file- 
*	
*	Copyright (C) 2008-2009 Sam zhen <sam_code@hotmail.com>
*	3Dijoy Inc.
*/




//==========================================
//system header file
#include <stdio.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>


/*
//==================================
//bluetooth header file
#include <bluetooth/bluetooth.h> //BTPROTO_HCI
#include <bluetooth/hci.h>          //struct hci_dev_info
#include <bluetooth/hci_lib.h>     //hci_devid()
#include <bluetooth/l2cap.h>      //l2cap
#include <bluetooth/hidp.h>       //hidp
*/
//==========================================
//BTX header file
//#include "BTX.h"



//==================================
//local header file
#include "bluetooth_remote.h"
#include "AnalysisDirection.h"




void *thread_Scan_Device(void *arg);
void *thread_Connect_Device(void *arg);
void *thread_Read_Control_Data(void *arg);


pthread_mutex_t RW_mutex =PTHREAD_MUTEX_INITIALIZER;   //read write lock


//Scan Bluetooth device. and bdaddr in this buffer
BDAddr_t bdaddr_buf[24];
int iDevice_num = 0;  //current device number
int iScan_enable = 0;
int iConnect_enable = 0;

int gExit;
int gButton_A;

#define Debounce 500000

//#define BTRemote_DEBUG_MESSAGE
#define BTR_Debug (1)

#ifdef BTRemote_DEBUG_MESSAGE 
	#define BTRemote_PRINT(f,args...)\
		do\
		{ \
			if(f & BTR_Debug)\
			{\
				printf("[%s  %6d]	",__FILE__,__LINE__);\
				printf(args);	\
			}\
		}\
		while(0); 
#else 
#define BTRemote_PRINT(f,args...)\
		do\
		{ \
			if(f & BTR_Debug)\
			{\
				printf(args);	\
			}\
		}\
		while(0); 
#endif 

UINT8	adpcm_data[] = 
{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
39,121,250,136,10,49,69,144,74,152,55,127,213,138,5,26,
193,156,39,11,230,44,193,89,200,19,42,192,64,186,50,187,
67,172,20,10,160,24,138,32,16,155,4,60,136,25,33,47,
49,248,135,165,25,190,160,100,12,3,185,249,17,8,115,190,
38,158,17,153,72,185,81,185,66,188,34,153,2,137,128,106,
152,40,153,160,85,154,9,16,140,4,29,18,47,131,28,145,
43,162,56,165,27,161,169,68,156,49,188,52,187,5,26,153,
33,184,23,137,130,27,226,91,162,73,248,56,148,27,226,72,
202,52,157,149,56,233,67,158,132,27,161,72,160,8,2,89,
217,18,11,179,80,153,34,155,144,16,185,153,6,19,153,72,
154,131,190,168,64,34,139,244,28,149,62,177,58,97,201,65,
234,98,219,83,202,35,170,18,139,1,152,0,41,147,64,240,
40,216,1,41,146,44,164,28,165,12,68,220,53,189,38,188,
35,171,35,186,50,168,128,8,129,43,199,11,146,43,149,43,
178,107,165,9,161,136,65,240,32,155,72,144,41,225,57,177,
48,160,144,64,251,81,169,18,153,33,201,52,171,134,155,132,
59,210,73,184,65,186,49,217,49,176,48,160,32,128,217,216,
33,48,19,159,144,26,50,233,50,173,4,24,169,0,31,194,
97,201,66,203,51,171,51,217,17,144,41,179,28,180,88,200,
49,171,33,153,67,218,36,170,2,155,132,9,129,152,85,9,
186,128,154,71,155,37,155,148,25,178,90,208,64,176,73,176,
88,200,64,155,18,8,9,147,44,193,72,176,41,161,68,200,
58,200,67,174,128,0,81,216,17,169,80,187,66,170,34,154,
20,141,1,129,41,240,57,176,88,184,88,153,128,32,153,39,
11,130,142,129,40,136,18,159,3,11,179,88,176,58,201,82,
170,35,204,67,234,34,137,49,232,65,217,34,186,34,154,20,
138,130,10,129,155,4,9,130,44,129,32,217,33,25,185,93,
4,13,135,12,147,44,163,58,177,88,184,65,200,32,137,186,
67,142,19,170,67,171,145,58,185,57,212,80,200,8,160,48,
168,82,48,221,129,49,206,4,27,179,57,194,80,187,18,153,
160,57,55,13,132,10,177,57,162,16,184,17,75,163,10,202,
18,249,112,9,0,169,96,189,35,11,0,9,177,56,128,114,
188,20,190,21,155,20,137,136,136,140,21,9,50,189,17,155,
19,160,136,161,59,167,88,160,12,129,152,81,169,50,157,145,
146,128,128,156,132,113,193,42,225,58,176,57,1,0,128,138,
137,148,189,7,9,131,57,249,56,129,141,17,158,3,10,39,
140,2,154,2,155,53,170,51,218,65,154,25,193,82,186,49,
138,136,154,26,135,152,66,152,136,201,33,158,3,58,225,80,
185,51,189,130,24,217,36,12,131,73,201,49,217,18,138,18,
0,44,248,56,162,64,200,25,160,104,162,89,176,60,162,40,
129,155,23,13,130,28,129,129,34,234,36,138,8,129,26,182,
44,177,64,170,36,13,180,73,232,48,152,2,155,20,153,146,
9,136,3,96,187,42,181,59,224,49,171,50,11,193,48,35,
15,136,137,16,130,121,249,49,155,49,144,80,170,40,131,221,
4,8,130,11,168,33,63,161,33,172,50,154,1,15,7,137,
129,9,128,25,10,3,74,233,34,194,141,33,154,23,10,130,
139,2,27,225,40,208,20,45,129,26,160,48,202,65,139,23,
26,144,153,25,146,58,171,115,138,176,104,154,37,142,131,27,
162,75,194,89,162,42,144,10,136,35,49,217,144,3,191,7,
154,129,16,128,138,88,154,96,184,67,172,0,8,201,2,190,
39,26,129,43,208,17,128,138,152,50,82,171,128,202,1,43,
101,170,34,169,9,192,81,219,50,137,18,153,51,143,18,144,
200,34,204,19,157,2,41,208,35,138,1,123,144,64,186,152,
132,152,50,137,83,191,164,9,184,64,128,2,32,31,178,172,
18,131,56,208,66,249,65,170,2,154,2,208,67,188,0,136,
0,40,41,148,26,1,158,168,146,120,132,77,161,41,185,50,
138,178,59,248,113,152,1,176,144,9,36,33,218,152,162,67,
154,13,188,66,38,44,176,25,25,8,198,28,17,25,145,91,
185,67,139,192,25,1,8,132,96,27,218,148,26,37,138,129,
13,130,57,202,48,129,1,12,24,27,136,88,14,133,154,20,
42,184,147,156,48,26,142,7,73,210,29,145,16,144,146,18,
192,57,184,64,173,152,5,160,52,141,132,11,160,30,18,41,
128,41,171,49,154,26,154,23,121,170,133,161,24,177,28,49,
19,155,71,141,137,0,0,8,153,3,23,60,179,25,234,2,
128,32,1,148,44,217,132,25,153,20,136,1,175,17,138,131,
89,153,140,151,9,168,50,146,9,178,7,153,146,11,184,135,
136,146,169,96,136,146,180,170,162,24,17,0,183,75,160,152,
49,172,93,8,40,17,56,164,143,178,18,240,16,8,8,178,
24,241,32,161,27,1,70,201,8,161,24,33,161,128,131,137,
201,154,150,1,138,67,194,139,0,216,34,138,107,58,9,209,
74,57,130,10,159,128,2,1,157,32,24,145,17,137,124,41,
129,192,17,9,155,57,165,9,40,129,137,90,17,202,90,196,
73,193,152,17,177,33,1,153,145,128,138,187,41,2,148,40,
176,90,58,166,168,131,155,122,25,145,24,1,169,214,152,8,
146,27,132,9,17,185,25,41,185,33,130,58,26,25,43,26,
193,112,178,12,17,129,186,123,57,42,179,32,169,32,130,140,
156,97,144,147,160,10,44,29,0,19,26,74,145,10,56,145,
144,1,160,146,181,160,129,12,90,9,32,12,74,136,56,138,
0,0,0,0};

UINT8 Simulate_Date_Wrong = 0;

extern int BTRC_Thread_TotalNum;
extern int gReConnect;

#define Release_CreateConnextIndex_Test

int main(int argc, char** argv)
{
	BOOL bDongle_Ready = FALSE;
	BTRC_Rel BTRC_Rel_all;
	int iRet_pthread_create = 0;
	pthread_t ntid1;
	pthread_t ntid2;
	UINT8 ID;
	UINT16 SetAudioFile_rel;
	int i = 0;
	BT_CONNECTION_STATUS status;
	DEVICE_DATA dev_data;

	int iRel_pthread_cancel = 0;
	int iRel_pthread_join = 0;
	void* value_ptr;
	int pthread_index = 0;

	BTRC_Handle *ReCon_Ret = 0;
	
	//AccAnalysisInput(0,0,0,&ID);

//	extern INT8 wii_NoPrint;
	UINT16 count = 0;
	UINT16 count2 = 0;

	UINT8 Get_Raw_Data = 0;	//0是首次进入条件判断语句
	UINT8 ReCon_Test = 0;


	static float LEFT_UP_raw;
	static float LEFT_DOWN_raw;
	static float RIGHT_UP_raw;
	static float RIGHT_DOWN_raw;

	static UINT32 LEFT_UP_ref = 17250;
	static UINT32 LEFT_DOWN_ref = 16450;
	static UINT32 RIGHT_UP_ref = 2660;
	static UINT32 RIGHT_DOWN_ref = 4482;
	
	float LEFT_UP_upset = 0.0;
	float LEFT_DOWN_upset = 0;
	float RIGHT_UP_upset = 0;
	float RIGHT_DOWN_upset = 0;

	float WEIGHT = 0;
	UINT8 tt;

	
	BTRC_Rel_all = BluetoothDongleInit();
	if(BTRC_Rel_all != BTRC_SUCCESS)
	{
		BTRemote_PRINT(1,"Bluetooth Dongle Init fail. Error Code:[%d]\n", BTRC_Rel_all);
		return -1;
	}
	else
	{
		BTRemote_PRINT(1,"Bluetooth Dongle Init Success\n");
	}
	
	bDongle_Ready = BluetoothDongleReady();
	if(bDongle_Ready != TRUE)
	{
		BTRemote_PRINT(1,"USB Bluetooth Dongle No Ready. Please check it and Run Again\n");
		return -1;
	}

	DeviceInit();

	gExit = 1;
	iScan_enable = 1;
	iConnect_enable = 1;


	//scan device
	iRet_pthread_create = pthread_create(&ntid1, NULL, thread_Scan_Device, NULL);
	if(iRet_pthread_create != 0)
	{
		BTRemote_PRINT(1,"Main Info: Create Scan_Device thread Error\n");
		return -1;
	}
//	pthread_detach(ntid);

	


	//connect thread
	iRet_pthread_create = pthread_create(&ntid2, NULL, thread_Connect_Device, NULL);
	if(iRet_pthread_create != 0)
	{
		BTRemote_PRINT(1,"Main Info: Create connect thread Error\n");
		return -1;
	}
//	pthread_detach(ntid);

	while(gExit)
	{		
		usleep(1000);
		for(i = 0; i < 4; i++)
		{
			GetConnectionStatus(i, &status);
			if(status.bIsconnected)
			{
#ifdef Release_CreateConnextIndex_Test
				sleep(5);
				if(ReleaseConnection(i) != TRUE)
				{
					BTRemote_PRINT(1,"ReleaseConnect(%d) Error.\n", i);
				}
				else 
				{
					BTRemote_PRINT(1,"ReleaseConnect(%d) Success.\n", i);
				}
				iConnect_enable = 0;
				iScan_enable = 0;
				gReConnect = 1;
				sleep(15);

				CreateConnection_Index(i, ReCon_Ret);

				SetOutputMode(i, 0x07, TRUE);
				SetLEDLevel(i, i, TRUE);

//				sleep(15);
#else
				
				if(ReadRemoteDeviceData(i, &dev_data) ==TRUE)
				{
					if(dev_data.Buttons[BUTTON_A] && i == 0)  //第一个手柄按A.则停止scan
					{
						iScan_enable = 0;
						gButton_A = 1;
						BTRemote_PRINT(1,"A\n");
					}
					else if(!dev_data.Buttons[BUTTON_A] && gButton_A == 1)
					{
						BTRemote_PRINT(1,"A\n");
						gButton_A = 2;
					}
					else if(!dev_data.Buttons[BUTTON_A] && gButton_A == 2)
					{
						BTRemote_PRINT(1,"A\n");
						gButton_A = 0;
					}
					else if(dev_data.Buttons[BUTTON_HOME] && dev_data.Buttons[BUTTON_B] )  //按下Home+B. 则About 连接
					{
						BTRemote_PRINT(1,"Home+B\n");
						if(AbortConnection(i) != TRUE)
						{
							BTRemote_PRINT(1,"AbortConnect(%d) Error.\n", i);
						}
						else
						{
							BTRemote_PRINT(1,"AbortConnect(%d) Success\n", i);
						}
					}
					else if (dev_data.Buttons[BUTTON_HOME])  //按下Home. 则Release 连接
					{
						BTRemote_PRINT(1,"Home\n");
						if(ReleaseConnection(i) != TRUE)
						{
							BTRemote_PRINT(1,"ReleaseConnect(%d) Error.\n", i);
						}
						else 
						{
							BTRemote_PRINT(1,"ReleaseConnect(%d) Success.\n", i);
						}
						ReCon_Test = 1;

						sleep(15);
					}
					else if(ReCon_Test == 1)
					{
						ReCon_Test = 0;
						printf("ReCon_Ret_in = %d\n", ReCon_Ret);
						CreateConnection_Index(i, ReCon_Ret);
						printf("ReCon_Ret_out = %d\n", ReCon_Ret);
					}
					else if(dev_data.Buttons[BUTTON_LEFT])
					{
						BTRemote_PRINT(1,"Left\n");
						SetMotorLevel(i, 1 , 1 , 20);
						usleep(Debounce);
					}
					else if(dev_data.Buttons[BUTTON_RIGHT])
					{
						BTRemote_PRINT(1,"Right\n");
						SetMotorLevel(i, 0 , 0 , 0);						
						usleep(Debounce);
					}
					else if(dev_data.Buttons[BUTTON_UP])
					{
						BTRemote_PRINT(1,"UP\n");			
//						Simulate_Date_Wrong = 1;
						SetMotorLevel(i, 2 , 3 , 20);


						usleep(Debounce);
					}
					else if(dev_data.Buttons[BUTTON_DOWN])
					{
						BTRemote_PRINT(1,"DOWN\n");
						Simulate_Date_Wrong = 0;
						gExit = 0;

						DeviceDestroy();
#if 0
//==================================================						
						iRel_pthread_cancel = pthread_cancel(ntid1);
						if(iRel_pthread_cancel != 0)
						{
							BTRemote_PRINT(1,"<ntid_Thread_ReConnect> pthread_cancel() error.\n");
							iScan_enable = 0;  // ReConnect thread exit
						}
						else
						{
//							BTRC_PRINT(0xa0,"BTRC_Thread_TotalNum = %d\n",BTRC_Thread_TotalNum);
						}
						
						iRel_pthread_join = pthread_join(ntid1, &value_ptr);
						if((iRel_pthread_join != 0) && (iRel_pthread_join != 3))
						{
							BTRemote_PRINT(1,"<ntid_Thread_ReConnect>pthread_join() error.\n");
						}
						else
						{
							BTRC_Thread_TotalNum--;
//							BTRC_PRINT(0xa0,"<pthread_join>BTRC_Thread_TotalNum = %d\n",BTRC_Thread_TotalNum);
						}
//=====================================================

						iRel_pthread_cancel = pthread_cancel(ntid2);
						if(iRel_pthread_cancel != 0)
						{
							BTRemote_PRINT(1,"<ntid_Thread_ReConnect> pthread_cancel() error.\n");
							iConnect_enable = 0;  // ReConnect thread exit
						}
						else
						{
//							BTRC_PRINT(0xa0,"BTRC_Thread_TotalNum = %d\n",BTRC_Thread_TotalNum);
						}
						
						iRel_pthread_join = pthread_join(ntid2, &value_ptr);
						if((iRel_pthread_join != 0) && (iRel_pthread_join != 3))
						{
							BTRemote_PRINT(1,"<ntid_Thread_ReConnect>pthread_join() error.\n");
						}
						else
						{
							BTRC_Thread_TotalNum--;
//							BTRC_PRINT(0xa0,"<pthread_join>BTRC_Thread_TotalNum = %d\n",BTRC_Thread_TotalNum);
						}
//=====================================================
#endif						
						usleep(Debounce);
					}
					else if(dev_data.Buttons[BUTTON_B])
					{
						BTRemote_PRINT(1,"B. [%f]\n", dev_data.Acc.Ori.Pitch);
						BTRemote_PRINT(1,"BTRC_Thread_TotalNum = %d\n",BTRC_Thread_TotalNum);
					}
					else if(dev_data.Buttons[BUTTON_ONE])
					{
						BTRemote_PRINT(1,"X\n");
					}
					else if(dev_data.Buttons[BUTTON_TWO])
					{
						BTRemote_PRINT(1,"Y\n");
					}
#if 0
					if(wii_NoPrint == 1)
					{
						if(count++ > 20)
						{
							count = 0;
							

							LEFT_UP_raw = dev_data.Press.uiPLU;
							LEFT_DOWN_raw = dev_data.Press.uiPLD;
							RIGHT_UP_raw = dev_data.Press.uiPRU;
							RIGHT_DOWN_raw = dev_data.Press.uiPRD;

							LEFT_UP_upset = LEFT_UP_raw - LEFT_UP_ref;
							LEFT_DOWN_upset = LEFT_DOWN_raw - LEFT_DOWN_ref;
							RIGHT_UP_upset = RIGHT_UP_raw - RIGHT_UP_ref;
							RIGHT_DOWN_upset = RIGHT_DOWN_raw - RIGHT_DOWN_ref;
							
							printf("LEFT_UP_raw = [%f],LEFT_DOWN_raw = [%f],RIGHT_UP_raw = [%f],RIGHT_DOWN_raw = [%f]\n",LEFT_UP_raw,LEFT_DOWN_raw,RIGHT_UP_raw,RIGHT_DOWN_raw);

							printf("LEFT_UP_upset = [%f],LEFT_DOWN_upset = [%f],RIGHT_UP_upset = [%f],RIGHT_DOWN_upset = [%f]\n",LEFT_UP_upset,LEFT_DOWN_upset,RIGHT_UP_upset,RIGHT_DOWN_upset);

							WEIGHT = (LEFT_UP_upset+LEFT_DOWN_upset+RIGHT_UP_upset+RIGHT_DOWN_upset)/100;
							printf("HAHA!   Your weight is %f\n",WEIGHT);

							if((LEFT_UP_upset >= LEFT_DOWN_upset) && (LEFT_UP_upset >= RIGHT_UP_upset) && (LEFT_UP_upset >= RIGHT_DOWN_upset) \
								&&( (LEFT_UP_upset > 0) || (LEFT_DOWN_upset > 0) || (RIGHT_UP_upset > 0) || (RIGHT_DOWN_upset > 0)) && (LEFT_UP_upset > 80))
							{
								printf("============LEFT_UP============\n");
							}

							if((LEFT_DOWN_upset >= LEFT_UP_upset) && (LEFT_DOWN_upset >= RIGHT_UP_upset) && (LEFT_DOWN_upset >= RIGHT_DOWN_upset)\
								&&( (LEFT_DOWN_upset > 0) || (LEFT_DOWN_upset > 0) || (RIGHT_UP_upset > 0) || (LEFT_DOWN_upset > 0)) && (LEFT_DOWN_upset > 80))
							{
								printf("============LEFT_DOWN============\n");
							}

							if((RIGHT_UP_upset >= LEFT_UP_upset) && (RIGHT_UP_upset >= LEFT_DOWN_upset) && (RIGHT_UP_upset >= RIGHT_DOWN_upset)\
								&&( (LEFT_UP_upset > 0) || (LEFT_DOWN_upset > 0) || (RIGHT_UP_upset > 0) || (RIGHT_DOWN_upset > 0)) && (RIGHT_UP_upset > 80))
							{
								printf("============RIGHT_UP============\n");
							}

							if((RIGHT_DOWN_upset >= LEFT_UP_upset) && (RIGHT_DOWN_upset >= LEFT_DOWN_upset) && (RIGHT_DOWN_upset >= RIGHT_UP_upset)\
								&&( (LEFT_UP_upset > 0) || (LEFT_DOWN_upset > 0) || (RIGHT_UP_upset > 0) || (RIGHT_DOWN_upset > 0)) && (RIGHT_DOWN_upset > 80))
							{
								printf("============RIGHT_DOWN============\n");
							}
						}
					}
#endif				
					//printf("\nSeq:[%d]", dev_data.seq);			
					usleep(4500);
				}
				else
				{
					usleep(4500);
				}
#endif				
			}
		}
	}
	BTRemote_PRINT(1,"##########################Exit Progrom######################\n");

	return 0;
}

void *thread_Scan_Device(void *arg)
{
	BTRC_Rel Search_Rel;
	DEVICE_INFO* pDevice_Info;
	UINT32 dev_num = 0;
	int i = 0;
	char addr[24] = {0};
	UINT8 bdaddr[6] = {0};
	 
	while(iScan_enable)		//第一个连接上的手柄，按A停止scan	wallace.luo
	{
		pthread_testcancel();
		usleep(200000);
		Search_Rel = SearchDevice(&pDevice_Info, &dev_num);		/*dev_num是搜到符合条件的蓝牙设备的个数wallace.luo*/
		if(Search_Rel != BTRC_SUCCESS)
		{
			BTRemote_PRINT(1,"SearchDevice fail. Error Code:[%d]\n", Search_Rel);
		}
		else
		{
			if(dev_num > 0)
			{
				pthread_mutex_lock(&RW_mutex);
				BTRemote_PRINT(1,"################Scan [%d] 3DiJoy Game Control##################\n", dev_num);
				for(i = 0; i < dev_num; i++)
				{
					//ba2str(&((pDevice_Info+i)->DeviceAddr), addr);
					memcpy(bdaddr, &((pDevice_Info+i)->DeviceAddr), sizeof(BDAddr_t));
					BTRemote_PRINT(1,"[%x:%x:%x:%x:%x:%x]\n", bdaddr[5],bdaddr[4],bdaddr[3],bdaddr[2],bdaddr[1],bdaddr[0]);
//					BTRemote_PRINT(1,"3Dijoy bdaddr is:[%s]\n", bdaddr);
					
					iDevice_num++;
					memcpy(&(bdaddr_buf[i]), &((pDevice_Info+i)->DeviceAddr), sizeof(BDAddr_t));
					//unlock bdaddr buffer
				}
				pthread_mutex_unlock(&RW_mutex);
			}
		}
	}
	return ((void *)0);
}



void *thread_Connect_Device(void *arg)
{
	int i = 0;
	BDAddr_t current_bdaddr_buf[4];
	int current_device_num = 0;
	BTRC_Rel Connect_Rel;
	static BTRC_Handle Connect_Handle;
	char addr[24] = {0};
	int iRet_pthread_create = 0;
	pthread_t ntid;
	UINT8 lMode;

	DEVICE_INFO dev_info;

	unsigned int connect_index;
	BT_CONNECTION_STATUS connect_status;
	BOOL bGetStatus;

	

	while(iConnect_enable)
	{
		pthread_testcancel();
		usleep(1000);
		for(i = 0 ;i < 4; i++)
		{
			connect_index = i;
			// first. connect poll Game control
			
			bGetStatus = GetConnectionStatus(connect_index, &connect_status);
		}
	
		memset(current_bdaddr_buf, 0, sizeof(BDAddr_t) * 4);
		current_device_num = 0;
		
		
		pthread_mutex_lock(&RW_mutex);
		current_device_num = iDevice_num;
		if(current_device_num > 0)  //scan device
		{
			for(i =0; i < current_device_num; i++)
			{
				memcpy(current_bdaddr_buf+i, &(bdaddr_buf[i]), sizeof(BDAddr_t));
			}
		}
		iDevice_num = 0;
		pthread_mutex_unlock(&RW_mutex);


		if(current_device_num > 0)
		{
			for(i = 0; i < current_device_num; i++)
			{
				Connect_Handle = CreateConnection(current_bdaddr_buf[i], &Connect_Rel);
				
				if(Connect_Handle == -1) //create connect error
				{
					//ba2str(current_bdaddr_buf+i, addr);
					BTRemote_PRINT(1,"Can not Connect This Device. Error Code:[%d]\n", Connect_Rel);
				}
				else   //create connect success
				{
					// 0.0 get version
					ReadDeviceInfo(Connect_Handle, &dev_info);
					BTRemote_PRINT(1,"############Hardware Version:[0x%x]. Software Version:[0x%x]\n", dev_info.HardwareVer, dev_info.SoftwareVer);

					// 0. get battey
					GetConnectionStatus(Connect_Handle, &connect_status);
					BTRemote_PRINT(1,"[%d]Battery Level:[%d]\n", connect_status.bIsconnected, connect_status.BatteryLevel);

						
					
					// 1. set repotr type
					//lMode = 0x07;
					lMode = 0x07;
					SetOutputMode(Connect_Handle, lMode, TRUE);

					// 2. set LED
					SetLEDLevel(Connect_Handle, Connect_Handle, TRUE);

					// 3. set Motor
					//SetMotorLevel(Connect_Handle, 0 , 1);
//					SetMotorLevel(Connect_Handle , 0 , 1 , 0);

//					BtDevWiiFitEnable(Connect_Handle);		//这个地方有问题
#if 0					
					// 4. create read thread
					iRet_pthread_create = pthread_create(&ntid, NULL, thread_Read_Control_Data, &Connect_Handle);
					if(iRet_pthread_create != 0)
					{
						BTRemote_PRINT(1,"Main Info: Create Read Game Control data thread Error\n");
						return ((void *)-1);
					}
					pthread_detach(ntid);
#endif
					// 5. close motor
					//usleep(Debounce);
					//SetMotorLevel(Connect_Handle, 0 , 0);
				}
			}
		}
	}

	return ((void *)0);
}


void *thread_Read_Control_Data(void *arg)
{
	pthread_testcancel();
//bGetStatus = GetConnectionStatus(connect_index, &connect_status);
	return ((void *)0);
}

