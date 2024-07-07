#include "mcp28s08.h"
#include "spi.h"

void mcp_reg_write(uint8_t reg, uint8_t value)
{
  uint8_t tx[3] = { 0x40, reg, value };
  HAL_GPIO_WritePin(IOEXP_CS_GPIO_Port, IOEXP_CS_Pin, GPIO_PIN_RESET);
  HAL_SPI_Transmit(&hspi2, tx, 3, HAL_MAX_DELAY);
  HAL_GPIO_WritePin(IOEXP_CS_GPIO_Port, IOEXP_CS_Pin, GPIO_PIN_SET);
}
uint8_t mcp_reg_read(uint8_t reg)
{
  uint8_t txrx[3] = { 0x41, reg, 0xff};
  HAL_GPIO_WritePin(IOEXP_CS_GPIO_Port, IOEXP_CS_Pin, GPIO_PIN_RESET);
  HAL_SPI_TransmitReceive(&hspi2, txrx, txrx, 3, HAL_MAX_DELAY);
  HAL_GPIO_WritePin(IOEXP_CS_GPIO_Port, IOEXP_CS_Pin, GPIO_PIN_SET);

  return txrx[2];
}
