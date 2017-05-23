OBJS=gpio.o
CFLAGS=-I../ -g
LDFLAGS=-shared

libgpio.so: $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@
