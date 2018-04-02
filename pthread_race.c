#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>

#define NUM_THREADS 10
int inc = 0;

struct timespec;
void* incrementThread(void *varg);

int main() {
  struct timespec ts2 = {.5, 0};

  pthread_t threadID;


  for(int i = 1; i <= NUM_THREADS; i++) {
    void *ptr = malloc(sizeof(int)*i);
    ptr = &i;

    pthread_create(&threadID, NULL, incrementThread, ptr);
    nanosleep(&ts2, NULL);
  }
  return 0;
}

struct timespec ts = {2, 0};

void* incrementThread(void *varg) {
  int value = *((int *)varg);
  for (int i = 0; i < 10; i++) {
    inc++;
    printf("This is Thread #%d\tinc: %d\n", value, inc);
    nanosleep(&ts, NULL);
  }
  pthread_exit(NULL);
}
