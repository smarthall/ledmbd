#include "displaythread.h"
#include "animthread.h"

#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

typedef struct struct_thread_globals {
  // Screen details
  led_display *screen;
  pthread_mutex_t screenlock;
  
  // Animation details
  display_ll *head;
  display_ll *tail;
  sem_t framecount;

} thread_globals;

thread_globals globals;

const uint8_t testpattern[PIXELS] =
    {0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};       

int main(int argc, char * argv[]) {
   led_display test;

   // Init globals
   sem_init(&(globals.framecount), 0, 0);
   pthread_mutex_init(&(globals.screenlock), NULL);

   memcpy(test.data, testpattern, sizeof(testpattern));

   displayupdate(&test, 1);

   // Cleanup globals
   sem_destroy(&(globals.framecount));
   pthread_mutex_destroy(&(globals.screenlock));

   return EXIT_SUCCESS;
}

