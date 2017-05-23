#include <stdio.h>
#include "gpio.h"
int main(int argc, char** argv){
  printf("Testing\n");
  printf("Gpio_init: %d\n", gpio_init());

  gpio_set_pinmode(16, GPIO_MODE_OUTPUT);
  gpio_clear_pin(16);
  sleep(1);
  gpio_set_pin(16);
  sleep(1);
  return 0;

}
