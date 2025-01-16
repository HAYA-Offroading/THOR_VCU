#include "main.h"

DGUS_Parameters dgus_parameter;
int gauge_value = 0;// test variable

void delay_sw(int n){
  for(int i =0; i<n; i++){}
}

int main(){
  Uart_Init();
  while(1){
    // gauge_value++;
    // if(gauge_value > 79){
    //   gauge_value = 0;
    // }
    // gauge_value = 0;
    // dgus_parameter.Uart_Speedometer = gauge_value;
    // Display_Speedometer_Value(&dgus_parameter);
    // delay_sw(100000);

    gauge_value = 0x00;
   dgus_parameter.Uart_Speedometer = gauge_value;
    Display_Speedometer_Value(&dgus_parameter);
    delay_sw(10000000);

  }
}

