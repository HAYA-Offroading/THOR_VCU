#include "main.h"

int main(){

  SPI_Init();
  MCP2515_Reset();
  //MCP2515_SetMode(CANCTRL_REQOP_LOOPBACK);
  MCP2515_Initialize();
  MCP2515_ReadRegister(0x2D);
  MCP2515_ReadRegister(0x1D);
  //MCP2515_getStatus();
  // SPI_Send(0x03);
  while(1){
    // MCP2515_getStatus();
  }

}
