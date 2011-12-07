#include "displaythread.h"

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <usb.h>

#define PIXEL(X,Y,display) display->data[(X) + ((Y) * (X_SIZE))]

void displayupdate(led_display * display, int level) {
    int x, y;

    for (y = 0; y < Y_SIZE; y++) {
        for (x = 0; x < X_SIZE; x++) {
            if (PIXEL(x,y,display) >= level) {
                 printf("1");
            } else {
                 printf("0");
            }
        }
        printf("\n");
    }
}


