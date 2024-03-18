#ifndef __HELPERS_H__
#define __HELPERS_H__

#include "main.h"

#define BACKSPACE 127
#define MAX_LINE_LEN 80

volatile int __io_putchar(int ch);
__attribute__((weak)) int _write(int file, char *ptr, int len);

int input(char *buffer, char *prompt);
int is_pressed(GPIO_TypeDef *port, uint16_t pin);
#endif /*__HELPERS_H__ */
