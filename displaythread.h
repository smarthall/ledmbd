#ifndef _DISPLAYTHREAD_H
#define _DISPLAYTHREAD_H

#include <stdint.h>

#define X_SIZE 21
#define Y_SIZE 7

#define PIXELS ((X_SIZE) * (Y_SIZE))

typedef struct struct_led_display {
	uint8_t data[PIXELS];
} led_display;



#endif

