LIBS=driver/libgpio.so

all: $(LIBS) test/test
	sudo ./test/test

driver/libgpio.so: FORCE
	$(MAKE) -C driver
test/test: FORCE
	$(MAKE) -C test LIB=$(abspath driver/libgpio.so)


FORCE:
.PHONY: FORCE
