#include "sys.h"
#include "led.h"
#include "usart.h"
#include "delay.h"	 	 
#include "string.h"	   
#include "stmflash.h"

int main(void)
{	 	
	delay_init();	    	 //延时函数初始化	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	//设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	uart_init(115200);	 	//串口初始化为115200
	LED_Init(); 
	while(1) 
	{		
		Flash_Write();//写入数据
		LED0=0;
		delay_ms(500);
		
		Flash_Read();//读取数据
		LED0=1;
		delay_ms(100);	
	}
}
