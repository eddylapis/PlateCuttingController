/***************************************************************************/
// 程序：清洗设备控制器
// 模块：主函数	
// 文件：main.c
// 作者：卜晓旸
// 版本：V0.02
// 日期：2013年11月8日
// 功能：主函数
// 芯片：STC12C5A60S2
// 编译：Keil uVision3 V3.90
/***************************************************************************/

#include <reg52.h>
#include <basefunc.h>
#include <parameter.h>
#include <uart.h>

//External interrupt0 service routine
void exint0() interrupt 0           //(location at 0003H)
{
	if(EncoderDirection == 0)
	{
		currentlySignalNum --;
	}
	else
	{
		currentlySignalNum ++;
	}	
}

void exterInterInit()
{
	IT0 = 1;                        //set INT0 int type (1:Falling 0:Low level)
    EX0 = 1;                        //enable INT0 interrupt
    EA = 1;                         //open global interrupt switch
	
}

/***************************************************************************/
// 主函数
// 参数：无
// 返回值：无	
/***************************************************************************/
void main()
{
	exterInterInit();
	uart_init();


	currentlySignalNum = 0;	
//	MotorForward = 0;
//	MotorBack = 1;
	sysParm1_SignalNumPerMeter = 1000;
	while(1)
	{
		currentlyBoardLength = (currentlySignalNum*1000)/sysParm1_SignalNumPerMeter;	
		SendData(0x5A);
		SendData(0xA5);
		SendData(0x05);
		SendData(0x82);
		SendData(0x00);
		SendData(0x1F);
		SendData(currentlyBoardLength>>8);
		SendData(currentlyBoardLength);
	}   
}








