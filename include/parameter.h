/***************************************************************************/
// 程序：清洗设备控制器
// 模块：参数头文件
// 文件：parameter.h
// 作者：卜晓旸
// 版本：V0.02
// 日期：2013年11月8日
// 功能：参数头文件
// 芯片：STC12C5A60S2
// 编译：Keil uVision3 V3.90
/***************************************************************************/

#ifndef __PARAMETER_H__
#define __PARAMETER_H__

#include <reg52.h>

/***************************************************************************/
// 引脚定义
/***************************************************************************/
//输入
sbit EncoderCounting		= P3^2;  	// 编码器计数（绿色）
sbit EncoderDirection		= P2^0;  	// 编码器方向（白色）
sbit HydClamInductorTop		= P0^0;  	// 液压剪刀上方感应器(系统在工作之前，根据液压剪刀是否在上的位置（常亮）
										// 来判定是否可以正常工作)
sbit HydClamInductorBottom	= P0^1;  	// 液压剪刀下方感应器
sbit KeyStart				= P0^2;  	// 启动按钮
sbit KeyStop				= P0^4;  	// 停止按钮
sbit KeyHydClam				= P0^5;  	// 液压剪刀按钮，液压剪刀关闭自动模式后需要此按钮启动剪刀


//输出
sbit MotorForwardFast  		= P1^6;  //	电机前进快速
sbit MotorForwardSlow  		= P1^5;  //	电机前进慢速
sbit MotorBackFast  		= P1^4;  // 电机后退快速
sbit MotorBackSlow  		= P1^7;  //	电机后退慢速

sbit HydClamDown  			= P1^0;  //	液压剪刀输出(向下)
sbit HydClamUp  			= P1^1;  //	液压剪刀关闭（向上）
sbit HydMonitorOut  		= P2^4;  //	液压电机输出
sbit SystemAlarm	  		= P2^5;  //	系统报警指示灯


sbit TestOut		  		= P2^7;  //	测试输出


/***************************************************************************/
// 参数定义
/***************************************************************************/
struct Board  //板材结构体
{
	unsigned int boardLength;   //板材长度
	unsigned int boardDecLength;   //板材递减长度
	unsigned int boardNumber;	//板材数量
};


/***************************************************************************/
// 参数声明
/***************************************************************************/
void parameter_init();
unsigned char parameter_save();

extern unsigned int powerMode; //运行状态 0关闭 1启动 2报警 
extern unsigned int HydClamStatus; //液压剪刀状态 0：关闭  1：打开
extern unsigned int HydMonitorStatus; //液压电机状态 0：关闭  1：打开
extern struct Board parameterBoard[4];	//板材参数

extern unsigned int sysParm1_SignalNumPerMeter; //系统参数一：一米距离编码器的信号数
extern unsigned int sysParm2_ErrorCorrectionValue; //系统参数二：误差修正值，信号数
extern unsigned int sysParm3; //系统参数三
extern unsigned int sysParm4; //系统参数四
extern unsigned int sysParm5; //系统参数五

extern unsigned int settingBoardLength; //设定长度
extern unsigned int settingBoardNumber; //设定块数

extern unsigned int currentlyBoardLength; //已做长度
extern unsigned int currentlyBoardNumber; //已做块数

extern unsigned int errorCorrectionBoardLength; //修正的板子误差长度

extern unsigned long currentlySignalNum; //当前编码器信号数
extern unsigned long maxSignalNum;	  //最大编码器信号数

#endif
