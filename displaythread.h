#ifndef _DISPLAYTHREAD_H
#define _DISPLAYTHREAD_H

#include <stdint.h>

#define X_SIZE 21
#define Y_SIZE 7

#define GETLED(x,y) (x)

typedef struct struct_led_display {
	uint8_t data[21];
} led_display;


#endif

