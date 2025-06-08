/*
 * MCP2515.h
 *
 *  Created on: May 16, 2025
 *      Author: neil
 */

#ifndef INC_MCP2515_H_
#define INC_MCP2515_H_

#include "main.h"

#define CANCTRL_REQOP_CONFIG 0x80
#define CANCTRL_REQOP 0xE0
#define MCP_CANCTRL  0x0F
#define MCP_CANSTAT 0x0E
#define MCP_CNF3 0x28
#define MCP_CNF2 0x29
#define MCP_CNF1 0x2A
#define MCP2515_EFLG 0x2D

#define CANCTRL_REQOP_NORMAL 0x00
#define INSTRUCTION_READ_STATUS 0xA0
#define INSTRUCTION_RX_STATUS 0xB0
#define CANCTRL_REQOP_LOOPBACK 0x40
#define CANCTRL_REQOP_CONFIG 0x80

#define MCP2515_RXM0SIDH 0x20
#define MCP2515_RXM0EID0 0x23
#define MCP2515_RXM1SIDH 0x24
#define MCP2515_RXM1EID0 0x27
#define MCP2515_RXF0SIDH 0x00
#define MCP2515_RXF0EID0 0x03
#define MCP2515_RXF1SIDH 0x04
#define MCP2515_RXF1EID0 0x07
#define MCP2515_RXF2SIDH 0x08
#define MCP2515_RXF2EID0 0x0B
#define MCP2515_RXF3SIDH 0x10
#define MCP2515_RXF3EID0 0x13
#define MCP2515_RXF4SIDH 0x14
#define MCP2515_RXF4EID0 0x17
#define MCP2515_RXF5SIDH 0x18
#define MCP2515_RXF5EID0 0x1B

#define MCP2515_RXB0CTRL 0x60
#define MCP2515_RXB1CTRL 0x70

/* MCP2515 Registers */
typedef struct{
  uint8_t RXF0SIDH;
  uint8_t RXF0SIDL;
  uint8_t RXF0EID8;
  uint8_t RXF0EID0;
}RXF0;

typedef struct{
  uint8_t RXF1SIDH;
  uint8_t RXF1SIDL;
  uint8_t RXF1EID8;
  uint8_t RXF1EID0;
}RXF1;

typedef struct{
  uint8_t RXF2SIDH;
  uint8_t RXF2SIDL;
  uint8_t RXF2EID8;
  uint8_t RXF2EID0;
}RXF2;

typedef struct{
  uint8_t RXF3SIDH;
  uint8_t RXF3SIDL;
  uint8_t RXF3EID8;
  uint8_t RXF3EID0;
}RXF3;

typedef struct{
  uint8_t RXF4SIDH;
  uint8_t RXF4SIDL;
  uint8_t RXF4EID8;
  uint8_t RXF4EID0;
}RXF4;

typedef struct{
  uint8_t RXF5SIDH;
  uint8_t RXF5SIDL;
  uint8_t RXF5EID8;
  uint8_t RXF5EID0;
}RXF5;

typedef struct{
  uint8_t RXM0SIDH;
  uint8_t RXM0SIDL;
  uint8_t RXM0EID8;
  uint8_t RXM0EID0;
}RXM0;

typedef struct{
  uint8_t RXM1SIDH;
  uint8_t RXM1SIDL;
  uint8_t RXM1EID8;
  uint8_t RXM1EID0;
}RXM1;



#endif /* INC_MCP2515_H_ */
