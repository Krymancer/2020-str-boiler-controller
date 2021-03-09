#include "tasks.h"

double tRef = 0;
double hRef = 0;

void temperatureControl(void) {
  struct timespec t_start, t_end;
  long period = 50000000;  // 50ms
  clock_gettime(CLOCK_MONOTONIC, &t_start);
  t_start.tv_sec++;

  int samples = 0;

  while (samples++ <= N_SAMPLES) {
    clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &t_start, NULL);

    // Do task

    clock_gettime(CLOCK_MONOTONIC, &t_end);

    long responseTime = timeDifference(t_start, t_end);
    insertResponseTimeInBuffer("TC", responseTime);

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
  long period = 70000000;  // 70ms
  clock_gettime(CLOCK_MONOTONIC, &t_start);
  t_start.tv_sec++;

  int samples = 0;

  while (samples++ <= N_SAMPLES) {
    clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &t_start, NULL);

    // Do Task
    if (sH < hRef) {
      setAtuator(Ni, 10);
      setAtuator(Nf, 0);
    } else {
      setAtuator(Ni, 0);
      setAtuator(Nf, 10);
    }

    clock_gettime(CLOCK_MONOTONIC, &t_end);

    long responseTime = timeDifference(t_start, t_end);
    insertResponseTimeInBuffer("WL", responseTime);

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
    if (sT >= temperatureLimit) {
      pthread_cond_signal(&alarmCondition);
    }

    clock_gettime(CLOCK_MONOTONIC, &t_end);

    long responseTime = timeDifference(t_start, t_end);
    insertResponseTimeInBuffer("VT", responseTime);

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
    showSensorsValues();
    freeScreen();
  }
}

void refreshSensorsInfo(void) {
  struct timespec t_start, t_end;
  long period = 10000000;  // 10ms
  clock_gettime(CLOCK_MONOTONIC, &t_start);
  t_start.tv_sec++;

  while (1) {
    clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &t_start, NULL);

    // Do Task
    refreshSensorsValues();

    char* sensorsString[1024];
    sprintf(sensorsString, "SI[sT] %f\nSI[sNo] %f\nSI[sH] %f", sT, sNo, sH);
    insertBuffer(sensorsString);

    clock_gettime(CLOCK_MONOTONIC, &t_end);

    long responseTime = timeDifference(t_start, t_end);
    insertResponseTimeInBuffer("RS", responseTime);

    // Wait until next period
    t_start.tv_nsec += period;
    while (t_start.tv_nsec >= NANOSECONDS_PER_SECOND) {
      t_start.tv_nsec -= NANOSECONDS_PER_SECOND;
      t_start.tv_sec++;
    }
  }
}

void temperatureAlarm(void) {
  while (TRUE) {
    sleep(1);
    sensorAlarm(30);
    allocateScreen();
    printf(RED "--------------------\n");
    printf("TEMPERATURE WARNING\n");
    printf("--------------------\n" RESET);
    freeScreen();
  }

  pthread_mutex_unlock(&sensorMutex);
}

void saveInfoToFile(void) {
  while (TRUE) {
    writeInDisk();
  }
}