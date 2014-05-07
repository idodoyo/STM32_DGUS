#ifndef __network_handle__h
#define __network_handle__h
#include "stdint.h"

//#define FH        0
//#define TID       1
//#define BRWN      2
//#define BNO       3
//#define DevArea   4
//#define DevAreaNo 5
//#define DealBalance 6
//#define MealID    7
//#define MealNO    8
//#define MealName  9
//#define MealPrice 10
//#define PayType   11
//#define PayBack   12
//#define LeftMeal  13
//#define MAC       14
//#define CardInfo  15
//#define FL        16
//#define SendFlag  17

extern   unsigned char   F_RX1_Right ;
extern   uint16_t		  rx1BufIndex ;
extern   uint8_t		  F_RX1_VAILD ;
extern   long  		    CrcValue ;
extern   uint8_t		  F_RX1_SYNC ;

extern unsigned char  TID[7];
extern unsigned char  BRWN[7+3];
extern unsigned char  BNO[6];
extern unsigned char  DeviceArea[3+3];
extern unsigned char  DeviceAreaNO[4+3];
extern unsigned char  DeviceStatus[2+3];
extern unsigned char  DealData[7];
extern unsigned char  DealTime[6];
extern unsigned char  MAC[8+3];
extern unsigned char  DealBalance[6+3];
extern unsigned char  MealID[4+3];
extern unsigned char  MealNO[1+3];
extern unsigned char  MealName[20+3];
extern unsigned char  MealPrice[6+3];
extern unsigned char  PayType[1+3];
extern unsigned char  Change[6+3];
extern unsigned char  RemainMealNum[2+3];
extern unsigned char  MName[20+3];
extern unsigned char  APPVersion[8+3];
extern unsigned char  ParaFileVersion[8+3];
extern unsigned char  BDataFileVersion[8+3];
extern unsigned char  ChechStatus[2+3];
extern unsigned char  MID[3+3];
extern unsigned char  TTCount[3+2];
extern unsigned char  TNCT[6+3];
extern unsigned char  TNtype[3+2];
extern unsigned char  TotalChange[3+6];

extern unsigned char  UpdataFlag[4];
extern unsigned char  WordKeyCipher[11];

/*******************************************
这个结构体是定义9种餐品的定义
设置餐品的时候定义的一个结构体 与服务器对比

********************************/
typedef struct
{

	unsigned char MealID[4];
	unsigned char MaelName[20];
	unsigned char MealNum[2];
	unsigned char MealPreace[4];
	unsigned char MealType[4];

}Meal_struction;
extern	Meal_struction  	Meal[4];


/*******************************************
这个结构体是用户选择取餐的时候需要定义的
********************************/
typedef struct
{
 unsigned char 	 MealID[4] ;        /*餐品的ID*/
 unsigned char   MealNo ;           /*餐品的数量*/
 unsigned char   DealBalance[6];	/*支付金额*/
 unsigned char   PayType;	        /*支付方式*/
 unsigned char   MealPrice[6];       /*餐品的价格*/
 unsigned char   Change[6] ;        /*应该找回多少钱*/
 unsigned char   RemainMealNum[2] ; /*剩余餐品数*/
 unsigned char   MealName;

}CustomerSel__struction ;
extern CustomerSel__struction CustomerSel;

extern char ReadSdBuff[256];
extern char SendHostBuff[128];
extern char ReadBuf[20];

extern unsigned char  F_RX1_Right;
extern unsigned char  rx1Buf[512];	  //发送数据给服务器，服务器返回数据存在这个buffer
extern char mealvariety;

uint16_t mem_copy01(unsigned char *dest, const unsigned char *source, const long s_len);
uint16_t mem_copy00(unsigned char *dest, const unsigned char *source, const long s_len);
unsigned char TakeMealsFun1(unsigned char *SendBuffer);
void memcpy_02(char *dest,char *source,char type);
unsigned char SignInFun(void);
uint32_t  MealDataCompareFun(void);/*餐品数据对比*/
unsigned char SignOutFun(void);/*退签*/
unsigned char StatusUploadingFun(void);/*状态上送*/
unsigned char EchoFun(void);/*回响测试*/
unsigned char TakeMealsFun(unsigned char *SendBuffer);/*取餐设置*/
unsigned char MealUploadingFun(void);/*上送餐品数据*/
unsigned char ClearingFun(void);/*结算命令*/
//void  EchoFuntion(void (*fptr)(void)) ;
unsigned char 	Resend(unsigned char *p,long lenght);
void WriteToSD_data(void);
void DataUpload(void);
void StateSend(void);
//void SignInFunction(void);
void GetBRWN(void);

unsigned int GetCrc16(unsigned char *bufData,unsigned int sizeData);
void HL_IntToBuffer(const uint16_t int_v, unsigned char *ret_buf);
bool StringToHexGroup1(unsigned char *OutHexBuffer, char *InStrBuffer, unsigned int strLength);

bool EchoFuntion(void (*fptr)(void));
bool SignInFunction(void);
#endif

