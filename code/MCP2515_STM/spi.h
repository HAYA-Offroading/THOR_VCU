#ifndef SPI_H
#define SPI_H

#include"main.h"

#define AFL_AF5   0x05

void SPI_Init();
void SPI_CS_High();
void SPI_CS_Low();
void Start_SPI();
void Stop_SPI();
void SPI_Send(uint8_t data);
void SPI_Send_Buffer (uint8_t *buffer, uint8_t buffer_size);
int SPI_Receive();

#endif
