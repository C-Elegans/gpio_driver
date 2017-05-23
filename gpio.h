#ifndef _GPIO_H
#define _GPIO_H

enum mode{
  GPIO_MODE_INPUT,
  GPIO_MODE_OUTPUT,
  GPIO_MODE_RESERVED
};

int gpio_init(void);

void gpio_cleanup(void);

void gpio_set_pinmode(int pin, enum mode mode);

void gpio_set_pin(int pin);

void gpio_clear_pin(int pin);

int gpio_read_pin(int pin);

int gpio_read_adc(void);

#endif
