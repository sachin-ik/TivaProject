#ifndef BSP_H
#define BSP_H

#include<stdint.h>

/* system clock tick [Hz] */
#define HW_TICKS_PER_SEC 100U

void HwInit(void);

void HwDelay(uint32_t delay);

void HwBlueLedOn(void);
void HwBlueLedOff(void);

void HwGreenLedOn(void);
void HwGreenLedOff(void);

void HwRedLedOn(void);
void HwRedLedOff(void);

#endif