#include "tasks.h"

void temperatureControl(void) {
  struct timespec t_start, t_end;
  long period = 50000000;  // 50ms
  clock_gettime(CLOCK_MONOTONIC, &t_start);
  t_start.tv_sec++;

  while (1) {
    clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &t_start, NULL);

    // Do Task

    clock_gettime(CLOCK_MONOTONIC, &t_end);

    double responseTime = timeDifference(t_start, t_end);

    char* responseTimeString[1024];
    sprintf(responseTimeString, "RT[TC] %f", responseTime);
    insertBuffer(responseTimeString);

    // Wait until next period
    t_start.tv_nsec += period;
    while (t_start.tv_nsec >= NANOSECONDS_PER_SECOND) {
      t_start.tv_nsec -= NANOSECONDS_PER_SECOND;
      t_start.tv_sec++;
    }
  }
}

void waterLevelControl(void) {
  struct timespec t_start, t_end;
  long period = 50000000;  // 50ms
  clock_gettime(CLOCK_MONOTONIC, &t_start);
  t_start.tv_sec++;

  while (1) {
    clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &t_start, NULL);

    // Do Task

    clock_gettime(CLOCK_MONOTONIC, &t_end);

    double responseTime = timeDifference(t_start, t_end);

    char* responseTimeString[1024];
    sprintf(responseTimeString, "RT[WL] %f", responseTime);
    insertBuffer(responseTimeString);

    // Wait until next period
    t_start.tv_nsec += period;
    while (t_start.tv_nsec >= NANOSECONDS_PER_SECOND) {
      t_start.tv_nsec -= NANOSECONDS_PER_SECOND;
      t_start.tv_sec++;
    }
  }
}

void verifyTemperature(void) {
  struct timespec t_start, t_end;
  long period = 10000000;  // 10ms
  clock_gettime(CLOCK_MONOTONIC, &t_start);
  t_start.tv_sec++;

  while (1) {
    clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &t_start, NULL);

    // Do Task

    clock_gettime(CLOCK_MONOTONIC, &t_end);

    double responseTime = timeDifference(t_start, t_end);

    char* responseTimeString[1024];
    sprintf(responseTimeString, "RT[VT] %f", responseTime);
    insertBuffer(responseTimeString);

    // Wait until next period
    t_start.tv_nsec += period;
    while (t_start.tv_nsec >= NANOSECONDS_PER_SECOND) {
      t_start.tv_nsec -= NANOSECONDS_PER_SECOND;
      t_start.tv_sec++;
    }
  }
}

void showSensorsInfo(void) {
  while (TRUE) {
    sleep(1);
    allocateScreen();
    refreshSensorsValues();
    showSensorsValues();
    char* sensorsString[1024];
    sprintf(sensorsString, "SI[sT] %f\nSI[sNo] %f\nSI[sH] %f", sT, sNo, sH);
    insertBuffer(sensorsString);
    freeScreen();
  }
}

void temperatureAlarm(void) {
  while (1) {
    if (2 < 1) {
      printf("TEMPERATURE WARNING!!");
    }
  }
}

void saveInfoToFile(void) {
  while (TRUE) {
    writeInDisk();
  }
}