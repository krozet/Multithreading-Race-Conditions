#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>

#define NUM_THREADS 10
int inc = 1;

struct timespec;
void* incrementThread(void *varg);



int main() {
  pthread_t threadID;

  for(int i = 0; i < NUM_THREADS; i++) {
    pthread_create(&threadID, NULL, incrementThread, NULL);
    printf("ThreadID: %ld\tinc: %d\n", (long)threadID, inc);
  }

  pthread_exit(NULL);
  return 0;
}

struct timespec ts = {2, 0 };

void* incrementThread(void *varg) {

  for (int i = 0; i < 10; i++) {
    inc++;
    nanosleep(&ts, NULL);
  }
}
