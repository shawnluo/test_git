#include "test.hpp"

#include <functional>
#include <semaphore.h>
#include <thread>
using namespace std;


/*********************************************************************************************

* File name： main.c

* Author: ZXL

* Description： 通过定时器，让LED灯每0.5秒闪烁一次,蜂鸣器每0.5秒鸣叫一次

* History: 2013.5.8

*********************************************************************************************/


#include "2440addr.h"
#include "2440lib.h"
#include "def.h"
#include "option.h"


void dely(U32 tt) {

    U32 i;

    for (; tt > 0; tt--)

        for (i = 0; i < 10000; i++)
            ;
}


void init() {

    U32 i;

    U8 key;

    U32 mpll_val = 0;

    i = 2;

    switch (i) // 设置2440的时钟频率

    {

    case 0: // 200

        key = 12;

        mpll_val = (92 << 12) | (4 << 4) | (1);

        break;

    case 1: // 300

        key = 13;

        mpll_val = (67 << 12) | (1 << 4) | (1);

        break;

    case 2: // 400

        key = 14;

        mpll_val = (92 << 12) | (1 << 4) | (1);

        break;

    case 3: // 440!!!

        key = 14;

        mpll_val = (102 << 12) | (1 << 4) | (1);

        break;

    default:

        key = 14;

        mpll_val = (92 << 12) | (1 << 4) | (1);

        break;
    }

    // MDIV=92,PDIV=1,SDIV=1 通过配置MPLLCON，MPLL确定，即FCLK=400MHZ确定

    ChangeMPllValue((mpll_val >> 12) & 0xff, (mpll_val >> 4) & 0x3f, mpll_val & 3);

    ChangeClockDivider(key, 12); // FCLK:HCLK:PCLK = 1：1/4：1/8 =400M:100M:50M


    Port_Init();


    Uart_Init(0, 115200);

    Uart_Select(0);

    Uart_Printf("n每0.5秒闪烁一次,鸣叫一次!n");
}


int main(int argc, char** argv) {

    init();

    led1_port_init();

    beep_init();

    timer0_init();

    Uart_Printf("nTimer Test beginn");

    while (1)
        ;
}


定时器程序：


/*********************************************************************************************

* File name： timer.c

* Author: ZXL

* Description： 通过定时器，让LED灯每0.5秒闪烁一次,蜂鸣器每0.5秒鸣叫一次

* History: 2013.5.8

*********************************************************************************************/


#include "def.h"

#include "option.h"

#include "2440addr.h"

#include "2440lib.h"


#define LED1_ON ~(1 << 5)

#define LED2_ON ~(1 << 6)

#define LED3_ON ~(1 << 7)

#define LED4_ON ~(1 << 8)


#define LED1_OFF (1 << 5)

#define LED2_OFF (1 << 6)

#define LED3_OFF (1 << 7)

#define LED4_OFF (1 << 8)


void led1_port_init() {

    rGPBCON &= ~(0x3 << 10); // 控制寄存器清零

    rGPBCON |= (0x1 << 10); // 控制寄存器设置为输出

    rGPBDAT |= (LED1_OFF) | (LED2_OFF) | (LED3_OFF) | (LED4_OFF); // LED灯全灭
}


void led1_run() {

    if (rGPBDAT & (1 << 5))
        rGPBDAT &= ~(1 << 5); // LED灯原来是亮 ——> 则灭

    else
        rGPBDAT |= (1 << 5); // LED灯原来是灭 ——> 则亮
}


void beep_init() {

    rGPBCON &= ~(3 << 0); // 控制寄存器清零

    rGPBCON |= (1 << 0); // 控制寄存器设置为输出
}


void beep_run() {

    if (rGPBDAT & (1 << 0))
        rGPBDAT &= ~(1 << 0); // 蜂鸣器鸣叫 ——> 则停止

    else
        rGPBDAT |= (1 << 0); // 蜂鸣器停止 ——> 则鸣叫
}


void __irq IRQ_Timer0_Handle(void) {

    if (rINTPND == BIT_TIMER0) // 如果BIT_TIMER0触发中断，则INTPEND寄存器中对应BIT_TIMER0位被置1

        ClearPending(BIT_TIMER0); // 清空BIT_TIMER0位中断

    led1_run(); // LED闪烁

    beep_run(); // 蜂鸣器鸣叫
}


void timer0_init() {

    rTCFG0 = 49; // 第一次50分频 pclk/(49+1)=50M/50=1M

    rTCFG1 = 0x03; // 第二次16分频=62500HZ=1M/16

    rTCNTB0 = 62500 / 2; // TCNTB0[15:0]=计数值

    rTCMPB0 = 0;

    rTCON |= (1 << 1); // 将计数值装入TCNTB0、TCMPB0

    rTCON = 0x09; // 启动定时器0 并自动重载


    rINTMOD = 0x0; // 设置为IRQ模式

    ClearPending(BIT_TIMER0); // 清除BIT_TIMER0中断

    pISR_TIMER0 = (U32)IRQ_Timer0_Handle; // 将定时器执行函数对应定时器中断入口地址

    EnableIrq(BIT_TIMER0); // 使能BIT_TIMER0中断

    Uart_Printf("n中断类型INTMSK=0x%xn", rINTMSK); // 显示CPU将要服务的中断的内型  1：屏蔽 0：可服务
}