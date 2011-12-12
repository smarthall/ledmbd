
#ifndef _AMINTHREAD_H
#define _AMINTHREAD_H
#include "displaythread.h"

typedef struct struct_display_ll {
  struct struct_display_ll *next;
  led_display disp;
  int delay;
} display_ll;

#endif

