#include "dgus_tft.h"

DGUS_Parameters gauge_high,gauge_low;
uint32_t DWIN_Buffer [8] = {0x5a,0xa5,0x05,0x82,0x10,0x00,0x00,0x00};

void Display_Speedometer_Value(DGUS_Parameters *gauge_value){

    gauge_high.temp = gauge_value->Uart_Speedometer & 0XFF00 >> 8;
    gauge_low.temp = gauge_value->Uart_Speedometer & 0X00FF;
    for(int i = 0;i<8;i++){
        Uart_SendValue(DWIN_Buffer[i]);
        if(i == 7){
            DWIN_Buffer[i] = gauge_low.temp;
            Uart_SendValue(DWIN_Buffer[i]);
        }
    }
}