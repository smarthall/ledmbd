
CFLAGS= -g -O3 -Wall 
LDFLAGS= -g

.PHONY: all
all: displaytest

displaythread.o: displaythread.c displaythread.h
	gcc -c -o displaythread.o displaythread.c

displaytest.o: displaytest.c
	gcc -c -o displaytest.o displaytest.c

displaytest: displaythread.o displaytest.o
	gcc -o displaytest displaytest.o displaythread.o

.PHONY: clean
clean:
	-rm -f *.o

