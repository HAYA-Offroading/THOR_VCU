/*
    Project is to use SPI using ZEPHYR API
    For this project, im using blackpill_f401cc from weact.
*/

#include "zephyr/kernel.h"
#include "zephyr/devicetree.h"
#include "zephyr/device.h"
#include "zephyr/drivers/spi.h"

#define SPI_DEV_NODE DT_NODELABEL(spi1) // spi1 is defined in app.overlay
static const struct device *spi_dev = DEVICE_DT_GET(SPI_DEV_NODE); //with *spi_dev, we will be using the pointer to start, send and stop SPI

static struct spi_cs_control spi_cs = {
    .gpio = GPIO_DT_SPEC_GET(SPI_DEV_NODE,cs_gpios),
    .delay = 0,
};

int main(void){



}
