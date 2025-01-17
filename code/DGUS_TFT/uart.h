#ifndef UART_H
#define UART_H

#include "stm32f4xx.h"


typedef struct{
    uint32_t Uart_Speedometer;
    uint32_t temp;
}DGUS_Parameters;


//---------------Function Declarations---------------
void Uart_Init();
void Uart_SendValue(uint8_t c);
// void Uart_SendValue_Dgus(DGUS_Parameters *a);

#endif