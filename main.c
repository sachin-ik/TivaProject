#include "bsp.h"

int main()
{
    HwInit();
    while(1)
    {
        HwBlueLedOn();
        HwDelay(1000000);
        HwBlueLedOff();
        HwDelay(1000000);
    }
}