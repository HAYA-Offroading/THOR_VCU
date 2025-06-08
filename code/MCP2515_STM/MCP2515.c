/*
 * MCP2515.c
 *
 *  Created on: May 16, 2025
 *      Author: neil
 */
#include "MCP2515.h"

void delay_sw(int n){
  for(int i = 0; i<n; i++){__asm__("nop");}
}


void MCP2515_ModifyRegister(uint8_t Register, uint8_t Mask, uint8_t Data){
  uint8_t buffer[4] = {0x05,Register,Mask,Data};
  Start_SPI();
  SPI_Send_Buffer(buffer,4);
  Stop_SPI();
}

void MCP2515_Reset(){
  Start_SPI();
  SPI_Send(0xC0);
  Stop_SPI();
}

void MCP2515_SetRegister(uint8_t Register, uint8_t value){
  uint8_t buffer[3] = {0x02,Register,value};
  Start_SPI();
  SPI_Send_Buffer(buffer,3);
  Stop_SPI();
}

void MCP2515_ReadRegister(uint8_t Register){
  uint8_t buffer[2] = {0x03,Register};
  int data;
  Start_SPI();
  SPI_Send_Buffer(buffer,2);
  data = SPI_Receive();
  Stop_SPI();
}

void MCP2515_getStatus(void){
  Start_SPI();
  SPI_Send(INSTRUCTION_RX_STATUS);
  SPI_Receive();
  Stop_SPI();
}

void MCP2515_SetMode(uint8_t CANMODE){
  MCP2515_ModifyRegister(MCP_CANCTRL,CANCTRL_REQOP,CANMODE);
  delay_sw(10);
  MCP2515_ReadRegister(MCP_CANSTAT);
}

void MCP2515_SetBitrate(){
  //MCP2515_SetMode(CANCTRL_REQOP_CONFIG);
  MCP2515_SetRegister(MCP_CNF1,0x00);
  MCP2515_SetRegister(MCP_CNF2,0xB1);
  MCP2515_SetRegister(MCP_CNF3,0x85);
}

void MCP2515_WriteByteSequence(uint8_t startAddr, uint8_t endAddr, uint8_t *data){
	Start_SPI();
	SPI_Send(0x02);
	SPI_Send(startAddr);
	SPI_Send_Buffer(data, (endAddr-startAddr +1));
	Stop_SPI();
}

void MCP2515_Initialize(){
	  RXF0 RXF0reg;
	  RXF1 RXF1reg;
	  RXF2 RXF2reg;
	  RXF3 RXF3reg;
	  RXF4 RXF4reg;
	  RXF5 RXF5reg;
	  RXM0 RXM0reg;
	  RXM1 RXM1reg;

	  /* Intialize Rx Mask values */
	  RXM0reg.RXM0SIDH = 0x00;
	  RXM0reg.RXM0SIDL = 0x00;
	  RXM0reg.RXM0EID8 = 0x00;
	  RXM0reg.RXM0EID0 = 0x00;

	  RXM1reg.RXM1SIDH = 0x00;
	  RXM1reg.RXM1SIDL = 0x00;
	  RXM1reg.RXM1EID8 = 0x00;
	  RXM1reg.RXM1EID0 = 0x00;

	  /* Intialize Rx Filter values */
	  RXF0reg.RXF0SIDH = 0x00;
	  RXF0reg.RXF0SIDL = 0x00;      //Starndard Filter
	  RXF0reg.RXF0EID8 = 0x00;
	  RXF0reg.RXF0EID0 = 0x00;

	  RXF1reg.RXF1SIDH = 0x00;
	  RXF1reg.RXF1SIDL = 0x08;      //Exntended Filter
	  RXF1reg.RXF1EID8 = 0x00;
	  RXF1reg.RXF1EID0 = 0x00;

	  RXF2reg.RXF2SIDH = 0x00;
	  RXF2reg.RXF2SIDL = 0x00;
	  RXF2reg.RXF2EID8 = 0x00;
	  RXF2reg.RXF2EID0 = 0x00;

	  RXF3reg.RXF3SIDH = 0x00;
	  RXF3reg.RXF3SIDL = 0x00;
	  RXF3reg.RXF3EID8 = 0x00;
	  RXF3reg.RXF3EID0 = 0x00;

	  RXF4reg.RXF4SIDH = 0x00;
	  RXF4reg.RXF4SIDL = 0x00;
	  RXF4reg.RXF4EID8 = 0x00;
	  RXF4reg.RXF4EID0 = 0x00;

	  RXF5reg.RXF5SIDH = 0x00;
	  RXF5reg.RXF5SIDL = 0x08;
	  RXF5reg.RXF5EID8 = 0x00;
	  RXF5reg.RXF5EID0 = 0x00;

	  MCP2515_SetMode(CANCTRL_REQOP_CONFIG);

	  MCP2515_WriteByteSequence(MCP2515_RXM0SIDH, MCP2515_RXM0EID0, &(RXM0reg.RXM0SIDH));
	  MCP2515_WriteByteSequence(MCP2515_RXM1SIDH, MCP2515_RXM1EID0, &(RXM1reg.RXM1SIDH));

	  MCP2515_WriteByteSequence(MCP2515_RXF0SIDH, MCP2515_RXF0EID0, &(RXF0reg.RXF0SIDH));
	  MCP2515_WriteByteSequence(MCP2515_RXF1SIDH, MCP2515_RXF1EID0, &(RXF1reg.RXF1SIDH));

	  MCP2515_WriteByteSequence(MCP2515_RXF2SIDH, MCP2515_RXF2EID0, &(RXF2reg.RXF2SIDH));
	  MCP2515_WriteByteSequence(MCP2515_RXF3SIDH, MCP2515_RXF3EID0, &(RXF3reg.RXF3SIDH));

	  MCP2515_WriteByteSequence(MCP2515_RXF4SIDH, MCP2515_RXF4EID0, &(RXF4reg.RXF4SIDH));
	  MCP2515_WriteByteSequence(MCP2515_RXF5SIDH, MCP2515_RXF5EID0, &(RXF5reg.RXF5SIDH));

	  MCP2515_SetRegister(MCP2515_RXB0CTRL,0x04);
	  MCP2515_SetRegister(MCP2515_RXB1CTRL,0x01);

	  MCP2515_SetRegister(MCP_CNF1, 0x00);
	  MCP2515_SetRegister(MCP_CNF2, 0x00);
	  MCP2515_SetRegister(MCP_CNF3, 0x00);

	  MCP2515_SetBitrate();

	  MCP2515_SetMode(CANCTRL_REQOP_NORMAL);
}

