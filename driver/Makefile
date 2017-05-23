OBJS=gpio.o
CFLAGS=-I../
LDFLAGS=-shared

libgpio.so: $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@
