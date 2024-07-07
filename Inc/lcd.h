#pragma once
#include <stdint.h>

#define BLACK     0x0000
#define RED       0xf800
#define GREEN     0x07e0
#define BLUE      0x001f
#define YELLOW    0xffe0
#define MAGENTA   0xf81f
#define CYAN      0x07ff
#define WHITE     0xffff

void lcd_fill_box(int x, int y, int width, int height, uint16_t color);

void lcd_init(void);
