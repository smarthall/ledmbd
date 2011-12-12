
CFLAGS= -g -Wall 
LDFLAGS= -lpthread

.PHONY: all
all: displaytest

displaythread.o: displaythread.c displaythread.h
	gcc -c $(CFLAGS) -o displaythread.o displaythread.c

displaytest.o: displaytest.c
	gcc -c $(CFLAGS) -o displaytest.o displaytest.c

animthread.o: animthread.c animthread.h
	gcc -c $(CFLAGS) -o animthread.o animthread.c

displaytest: displaythread.o displaytest.o animthread.o
	gcc $(LDFLAGS) -o displaytest displaytest.o displaythread.o animthread.o

.PHONY: clean
clean:
	-rm -f *.o

