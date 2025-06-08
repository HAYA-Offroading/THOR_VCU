#include "spi.h"

// SPI Clock = PA5
// SPI MISO = PA6
// SPI MOSI = PA7
// SPI NSS = PA4

void SPI_Init(){
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;

    GPIOA->MODER |= GPIO_MODER_MODE5_1 | GPIO_MODER_MODE6_1 | GPIO_MODER_MODE7_1 | GPIO_MODER_MODE4_0;
    GPIOA->AFR[0] |= (AFL_AF5 << 20) | (AFL_AF5 << 24) | (AFL_AF5 << 28);

    SPI1->CR1 = 0;
    SPI1->CR1 |= 4 << 3;
    SPI1->CR1 |= SPI_CR1_MSTR;
    SPI1->CR1 |= SPI_CR1_SSM | SPI_CR1_SSI; // Software NSS management
    SPI1->CR1 |= SPI_CR1_SPE;
    SPI_CS_High();
    //Currently CS PIN is LOW
  }

  void SPI_CS_High(){
    while(SPI1->SR & SPI_SR_BSY); // Wait until not busy
    GPIOA->ODR |= GPIO_ODR_OD4;
  }

  void SPI_CS_Low(){
    GPIOA->ODR &= ~(GPIO_ODR_OD4);
  }

  void Start_SPI(){
    SPI1->CR1 |= SPI_CR1_SPE;
    SPI_CS_Low();
  }

  void Stop_SPI(){
    SPI_CS_High();
    SPI1->CR1 &= ~(SPI_CR1_SPE);

  }

  void SPI_Send(uint8_t data){

    while(!(SPI1->SR & SPI_SR_TXE)){};
    SPI1->DR = data;

  }


  void SPI_Send_Buffer (uint8_t *buffer, uint8_t buffer_size){

    for(int i = 0; i < buffer_size; i++){
      while(!(SPI1->SR & SPI_SR_TXE)){};
      SPI1->DR = *(buffer+i);
    }

  }

  int SPI_Receive(){
    int data;

    SPI_Send(0x00);
    while(!(SPI1->SR & SPI_SR_RXNE)){};
    data = SPI1->DR;

    return data;
  }
