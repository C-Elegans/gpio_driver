#include <stdint.h>
#include <stdlib.h>
#include "gpio.h"
volatile uint32_t *gpio;
int map_gpio(void);


int gpio_init(void){
  if(map_gpio() != 0){
    return 1;
  }
}


int map_gpio(void){
  return 0;
}
