#include "dgus_tft.h"

DGUS_Parameters gauge_high,gauge_low;

void Display_Speedometer_Value(DGUS_Parameters *gauge_value){

    gauge_high.temp = gauge_value->Uart_Speedometer & 0XFF00 >> 8;
    gauge_low.temp = gauge_value->Uart_Speedometer & 0X00FF;
    Uart_SendValue(0x5a); // Header
    Uart_SendValue(0xa5); // header
    Uart_SendValue(0x05); // Number of bytes being sent
    Uart_SendValue(0x82); // Send/Set VP
    Uart_SendValue(0x10); // address
    Uart_SendValue(0x00); // address
    Uart_SendValue(0X00); 
    Uart_SendValue_Dgus(&gauge_low); // low 2 bytes value
}
