#include "main.h"

DGUS_Parameters dgus_parameter;
int gauge_value = 0;// test variable
int tacho_value = 0; 

void delay_sw(int n){
  for(int i =0; i<n; i++){}
}

int main(){
  Uart_Init();
  while(1){

    dgus_parameter.Uart_Speedometer = gauge_value;
    Display_Speedometer_Value(&dgus_parameter);

    dgus_parameter.Uart_Tachometer = tacho_value;
    Display_Speedometer_Value(&dgus_parameter);

    gauge_value++;
    tacho_value ++;
    if(gauge_value > 79){
      gauge_value = 0;
    }

    if(tacho_value > 14){
      tacho_value = 0;
    }

    delay_sw(10000000);

  }
}

