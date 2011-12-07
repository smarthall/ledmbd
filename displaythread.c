#include "displaythread.h"

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <hid.h>

// USB constants
#define VENDOR 0x1d34
#define PRODUCT 0x0013

// Get the pixels from the display
#define PIXEL(X,Y,display) (display)->data[(X) + ((Y) * (X_SIZE))]

typedef struct struct_ledscreen {
    HIDInterface *hid;
    led_display *buffer;
} ledscreen;


void displayupdate(led_display * display, int level) {
    int x, y;

    for (y = 0; y < Y_SIZE; y++) {
        for (x = 0; x < X_SIZE; x++) {
            if (PIXEL(x,y,display) >= level) {
                 printf("0");
            } else {
                 printf("~");
            }
        }
        printf("\n");
    }
}


