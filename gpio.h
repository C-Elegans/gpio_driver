#ifndef _GPIO_H
#define _GPIO_H

enum mode{
  GPIO_MODE_INPUT=0,
  GPIO_MODE_OUTPUT=1,
  GPIO_MODE_RESERVED=2
};

int gpio_init(void);

void gpio_cleanup(void);

void gpio_set_pinmode(int pin, enum mode mode);

void gpio_set_pin(int pin);

void gpio_clear_pin(int pin);

int gpio_read_pin(int pin);

int gpio_read_adc(void);

#endif
