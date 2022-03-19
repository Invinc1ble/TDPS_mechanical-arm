/****************************************************************************
	*	@笔者	：	W
	*	@日期	：	2019年12月03日
	*	@所属	：	杭州众灵科技
	*	@论坛	：	www.ZL-robot.com
	*	@功能	：	存放永久循环执行的函数
	*	@函数列表:
	*	1.	void loop_key(void) -- 循环检测按键状态
	*	2.	void loop_servo(void) -- 循环处理舵机的指令
 ****************************************************************************/
 
#include "z_loop.h"

/***********************************************
	函数名称：	loop_key2() 
	功能介绍：	用于放球
	函数参数：	无
	返回值：		无
 ***********************************************/
void loop_key(void) {
	static u32 systick_ms_bak = 0;
	int i=0;

/*****************按键1按下检测*****************/
	if(KEY1==0){
		delay_ms(50);
		if(KEY1==0){
/*****************按键1长按检测*****************/
			systick_ms_bak = millis();
//			while(KEY1==0){
//				if(millis() - systick_ms_bak >= 500) {
///*****************按键1长按执行*****************/
//					if((millis() - systick_ms_bak) % 500 == 0)
//						servo_run(5,servo_data[5].aim+=10,0);
//					
///***********************************************/
//				}
//			}
///*****************按键1松开执行*****************/
//			servo_run(5,servo_data[5].cur,0);
/***********************************************/
/*****************按键1单次检测*****************/
			if(millis() - systick_ms_bak < 500) {
/*****************按键1单次执行*****************/
        for (i=0; i<2;i++){
				 switch (i){
					 case 0: servo_run(5,1000,0); break;
					 case 1: servo_run(4,1050,0); break;
				}
			}
/***********************************************/
			}
		}
	}

/*****************按键2按下检测*****************/
	if(KEY2==0){
		delay_ms(50);
		if(KEY2==0){
/*****************按键2长按检测*****************/
			systick_ms_bak = millis();
//			while(KEY2==0){
//				if(millis() - systick_ms_bak >= 500) {
///*****************按键2长按执行*****************/
//					if((millis() - systick_ms_bak) % 500 == 0)
//						servo_run(5,servo_data[5].aim-=10,0);
///***********************************************/
//				}
//			}
///*****************按键2松开执行*****************/
//			servo_run(5,servo_data[5].cur,0);
/***********************************************/
/*****************按键2单次检测*****************/
			if(millis() - systick_ms_bak < 500) {
/*****************按键2单次执行*****************/
//				for (i=0; i<2;i++){
//				 switch (i){
//					 case 0: servo_run(5,2497,0); break;
//					 case 1: servo_run(4,1400,19999); break;
//				}
				servo_run(5,2497,0);
				servo_run(4,1400,19999);
			}
		}
	}
}


/***********************************************
	函数名称：	loop_key1() 
	功能介绍：	用于模拟自动控制
	函数参数：	无
	返回值：		无
 ***********************************************/
// void loop_key1(void){
//	 static u32 systick_ms_bak = 0;
//	  if(KEY1==0){
//		delay_ms(50);
//		systick_ms_bak = millis();
//		if(millis() - systick_ms_bak < 500) {
//        delay_ms (50);
//        servo_run(4,servo_data[4].aim+1497,1497);
//        servo_run(4,servo_data[4].cur,0);
//        delay_ms(2000);
//        servo_run(5,servo_data[5].aim+1497,1497);
//        servo_run(5,servo_data[5].cur,0);
//        delay_ms(2000);
//        servo_run(4,servo_data[4].aim-1497,1497);
//        servo_run(4,servo_data[4].cur,0);
//        servo_run(5,servo_data[5].aim-1497,1497);
//        servo_run(5,servo_data[5].cur,0);  
//    } 
//  }
//}
/***********************************************
	函数名称：	loop_servo() 
	功能介绍：	循环处理舵机的指令
	函数参数：	无
	返回值：		无
 ***********************************************/

void loop_servo(void) {
	if(servo_data[servo_index].inc != 0) {
		if(servo_data[servo_index].aim>2497)	servo_data[servo_index].aim=2497;
		if(servo_data[servo_index].aim<500)		servo_data[servo_index].aim=500;
		if(servo_abs(servo_data[servo_index].aim - servo_data[servo_index].cur) <= servo_abs(servo_data[servo_index].inc + servo_data[servo_index].inc)) {
			servo_data[servo_index].cur = servo_data[servo_index].aim;
			servo_data[servo_index].inc = 0;
		} else {
			servo_data[servo_index].cur += servo_data[servo_index].inc;
		}
	}
}
