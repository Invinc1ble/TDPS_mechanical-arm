/****************************************************************************
	*	@笔者	：	W
	*	@日期	：	2019年12月03日
	*	@所属	：	杭州众灵科技
	*	@论坛	：	www.ZL-robot.com
 ****************************************************************************/

#ifndef __LOOP_H__
#define __LOOP_H__

#include "z_main.h"
#include "z_delay.h"
#include "z_servo.h"

/*******主循环函数声明*******/
void loop_key(void);	//用于模拟自动控制
//void loop_key2(void); //用于放球
void loop_servo(void);//循环处理舵机的指令

#endif
