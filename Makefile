
CFLAGS= -g -O3 -Wall 
LDFLAGS= -g

displaythread.o: displaythread.c displaythread.h
	gcc -c -o displaythread.o displaythread.c

.PHONY: clean
clean:
	-rm -f *.o

