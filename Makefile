
CFLAGS= -g -O3 -Wall 
LDFLAGS= -g

.PHONY: all
all: displaytest

displaythread.o: displaythread.c displaythread.h
	gcc -c -o displaythread.o displaythread.c

displaytest: displaythread.o displaytest.c
	gcc -o displaytest displaytest.c displaythread.o

.PHONY: clean
clean:
	-rm -f *.o

