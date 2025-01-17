#include "uart.h"

void Uart_Init(){
    //UART 2 is being used, PA2 pin = TX, PA3 pin = RX
    //First initialize the clocks and GPIO pins  

    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;   // Enable GPIOA clock
    RCC->APB1ENR |= RCC_APB1ENR_USART2EN;  // Enable USART2 clock

    GPIOA->MODER |= GPIO_MODER_MODE2_1;    // UART2 TX
    GPIOA->MODER |= GPIO_MODER_MODE3_1;    // UART2 RX

    GPIOA->AFR[0] |= 7 << GPIO_AFRL_AFSEL2_Pos; // Setting AFRL PA2 As alternate function 7
    GPIOA->AFR[0] |= 7 << GPIO_AFRL_AFSEL3_Pos; // setting AFRL PA3 as alternate function 7
    
    GPIOA->OSPEEDR |= GPIO_OSPEEDR_OSPEED2_1;  // Setting PA2 as high speed
    GPIOA->OSPEEDR |= GPIO_OSPEEDR_OSPEED3_1;  // Setting PA3 as high speed

    //Now configure the UART settings
    //115200 Baud Rate, Only transmit for now
    USART2->CR1 = 0; //Clear USART2
    USART2->BRR = 0x08B; // Baud rate set to 115200
    USART2->CR1 |= USART_CR1_TE; //Enable Transmission
    USART2->CR1 |= USART_CR1_UE; //Enable USART

}

void Uart_SendValue(uint8_t c){
        // Wait until TXE (Transmit Data Register Empty) is set
    while (!(USART2->SR & USART_SR_TXE));
    USART2->DR = c;  // Load data into DR
    while(!(USART2->SR & USART_SR_TC)); // wait until TC bit is set (transmission complete)
}

// void Uart_SendValue_Dgus(DGUS_Parameters *a){
//     // Wait until TXE (Transmit Data Register Empty) is set
//     while (!(USART2->SR & USART_SR_TXE));
//     USART2->DR = a->temp ;  // Load data into DR
//     while(!(USART2->SR & USART_SR_TC)); // wait until TC bit is set (transmission complete)
// }