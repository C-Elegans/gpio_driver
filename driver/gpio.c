#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <assert.h>
#include "gpio.h"
#define BLOCK_SIZE (4*1024)
#define BCM2708_PERI_BASE 0x20000000
#define GPIO_BASE (BCM2708_PERI_BASE + 0x200000)

#define GPIO_SET_REG 0x1C/4
#define GPIO_CLR_REG 0x28/4

volatile uint32_t *gpio;
void* gpio_map;
int map_gpio(void);


int gpio_init(void){
  if(map_gpio() != 0){
    return 1;
  }
}


void gpio_cleanup(void){

}

void gpio_set_pinmode(int pin, enum mode mode){
  if(pin > 53){
    fprintf(stderr, "Pin number out of range [0,53]: %d\n", pin);
  }
  volatile uint32_t* reg = pin/10 + gpio;
  uint32_t cur_mode = *reg;
  cur_mode &= ~(0b111 << (pin%10));
  cur_mode |= mode << (pin%10);
  *reg = cur_mode;
}
void gpio_set_pin(int pin){
  assert(pin <= 53);
  *(gpio+GPIO_SET_REG+pin/32) = 1 << (pin&31);
}
void gpio_clear_pin(int pin){
  assert(pin <= 53);
  *(gpio+GPIO_CLR_REG+pin/32) = 1 << (pin&31);
}



int map_gpio(void){
  int mem_fd;
  if((mem_fd = open("/dev/mem", O_RDWR|O_SYNC)) < 0){
    fprintf(stderr, "Cannot open /dev/mem, try running as root?\n");
    return 1;
  }
  gpio_map = mmap(
		  NULL,			/* Any address */
		  BLOCK_SIZE,		/* Map length */
		  PROT_READ|PROT_WRITE, /* Read and write */
		  MAP_SHARED,		/* Shared */
		  mem_fd,		/* file */
		  GPIO_BASE
		  );
  close(mem_fd);

  if(gpio_map == MAP_FAILED){
    return 2;
  }
  gpio = (volatile uint8_t*) gpio_map;
  return 0;
}
