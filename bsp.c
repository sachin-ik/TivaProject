#include "bsp.h"
#include "TM4C123GH6PM.h"

#define LED_RED (1U << 1) // PF1
#define LED_BLUE (1U << 2) // PF2
#define LED_GREEN (1U << 3) // PF3

static volatile uint32_t tickCounter = 0;

void HwInit()
{
    // Enable the system clock for GPIO ports
    SYSCTL->RCGCGPIO |= (1U << 5); // Port F

    //Enable AHB bus fpr GPIOF
    SYSCTL->GPIOHBCTL |= (1U << 5); // Port F

    // Set the direction of PF1 as output
    GPIOF_AHB->DIR |= (LED_RED | LED_BLUE | LED_GREEN);

    // Enable digital function for PF1
    GPIOF_AHB->DEN |= (LED_RED | LED_BLUE | LED_GREEN);

    // system core clock update
    SystemCoreClockUpdate();

    // enable systick timer using systick_config
    SysTick_Config(SystemCoreClock / HW_TICKS_PER_SEC);

}

void SysTick_Handler()
{
    ++tickCounter;
}

void HwDelay(uint32_t delay)
{
    uint32_t i;
    for(i = 0; i < delay; i++)
    {
        // do nothing
    }
}

void HwBlueLedOn()
{
    GPIOF_AHB->DATA_Bits[LED_BLUE] = LED_BLUE;
}

void HwBlueLedOff()
{
    GPIOF_AHB->DATA_Bits[LED_BLUE] = 0;
}

void HwGreenLedOn()
{
    GPIOF_AHB->DATA_Bits[LED_GREEN] = LED_GREEN;
}

void HwGreenLedOff()
{
    GPIOF_AHB->DATA_Bits[LED_GREEN] = 0;
}

void HwRedLedOn()
{
    GPIOF_AHB->DATA_Bits[LED_RED] = LED_RED;
}

void HwRedLedOff()
{
    GPIOF_AHB->DATA_Bits[LED_RED] = 0;
}

