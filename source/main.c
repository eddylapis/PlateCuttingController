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

sbit MotorForward  		= P1^5;  //	电机前进
sbit MotorBack  		= P1^6;  // 电机后退
sbit EncoderCounting	= P3^2;  // 编码器计数（绿色）
sbit EncoderDirection	= P2^4;  // 编码器方向（白色）

/***************************************************************************/
// 主函数
// 参数：无
// 返回值：无	
/***************************************************************************/
void main()
{
	MotorForward = 1;
	MotorBack = 1;
	while(1)
	{
		 MotorBack = 0;
	}   
}








