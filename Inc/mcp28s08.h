#pragma once

#include <stdint.h>

#define MCP_IODIR 0x00
#define MCP_GPPU 0x06
#define MCP_GPIO 0x09
#define MCP_OLAT 0x0A

#define MCP_IPOL 0x01
#define MCP_GPINTEN 0x02
#define MCP_DEFVAL 0x03
#define MCP_INTCON 0x04
#define MCP_IOCON 0x05
#define MCP_INTF 0x07
#define MCP_INTCAP 0x08

uint8_t mcp_reg_read(uint8_t reg);
void mcp_reg_write(uint8_t reg, uint8_t value);
