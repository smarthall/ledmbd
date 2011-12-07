
CFLAGS= -g -Wall 
LDFLAGS=

.PHONY: all
all: displaytest

displaythread.o: displaythread.c displaythread.h
	gcc -c $(CFLAGS) -o displaythread.o displaythread.c

displaytest.o: displaytest.c
	gcc -c $(CFLAGS) -o displaytest.o displaytest.c

displaytest: displaythread.o displaytest.o
	gcc -o $(LDFLAGS) displaytest displaytest.o displaythread.o

.PHONY: clean
clean:
	-rm -f *.o

