#include <stdio.h>
#include "helpers.h"
#include "usart.h"


volatile int __io_putchar(int ch) {
	if (ch == '\n') {
		uint8_t cr = '\r';
		HAL_UART_Transmit(&huart2, &cr, 1, HAL_MAX_DELAY);
	}

	HAL_UART_Transmit(&huart2, (uint8_t *)&ch, 1, HAL_MAX_DELAY);
	return 1;
}

__attribute__((weak)) int _write(int file, char *ptr, int len)
{
	(void)file;
	int DataIdx;

	for (DataIdx = 0; DataIdx < len; DataIdx++)
		__io_putchar(*ptr++);
	return len;
}


int input(char *buffer, char *prompt) {
	uint8_t value = -1;
	int line_length = 0;

	if (prompt == NULL)
		printf("> ");
	else
		printf("%s", prompt);
	fflush(stdout);

	while (value != '\r' && value != '\n') {
		HAL_UART_Receive_IT(&huart2, &value, 1);
		if (value == BACKSPACE) {
			printf("\b \b");
			fflush(stdout);
			line_length--;
		} else if (line_length <= MAX_LINE_LEN) {
			printf("%c", value);
			fflush(stdout);
			buffer[line_length++] = value;
		} else {
			buffer[line_length] = '\0';
			printf("\nERROR\n");
			return 1;
		}
	}
	printf("\n");

	buffer[line_length - 1] = '\0';
	return 0;
}

void HAL_Delay(uint32_t Delay)
{
	uint32_t tickstart = HAL_GetTick();
	uint32_t wait = Delay;
	/* Add a period to guaranty minimum wait */
	if (wait < HAL_MAX_DELAY)
		wait += (uint32_t)uwTickFreq;
	while ((HAL_GetTick() - tickstart) < wait)
		__WFI();
}

int is_pressed(GPIO_TypeDef *port, uint16_t pin)
{
    int count = 0;
    int state = (pin == GPIO_PIN_13) ? GPIO_PIN_RESET : GPIO_PIN_SET;
    if (HAL_GPIO_ReadPin(port, pin) == state) {
        count++;
        while (HAL_GPIO_ReadPin(port, pin) == state)
            ;

        HAL_Delay(100);
        if (HAL_GPIO_ReadPin(port, pin) == state) {
            count++;
            while (HAL_GPIO_ReadPin(port, pin) == state)
                ;
        }
    }
    return count;
}
