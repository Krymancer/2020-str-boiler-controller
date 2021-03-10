#include "sensor.h"
#include <stdio.h>

double getSocketSensorValue(char* sensor) {
  char* recivedMessage = malloc(1024 * sizeof(char));
  messageSocketR(sensor, recivedMessage);
  strcut(recivedMessage, 3, -1);
  double sensorValue = atof(recivedMessage);
  return sensorValue;
}

double getSensor(sensor_t sensor) {
  switch (sensor) {
    case Ta: {
      return getSocketSensorValue("sta0");
      break;
    }
    case T: {
      return getSocketSensorValue("st-0");
      break;
    }
    case Ti: {
      return getSocketSensorValue("sti0");
      break;
    }
    case No: {
      return getSocketSensorValue("sno0");
      break;
    }
    case H: {
      return getSocketSensorValue("sh-0");
      break;
    }
    default: {
      return INVALID_SENSOR;
      break;
    }
  }
}

void setSenstor(sensor_t sensor) { printf("sensor: %d", sensor); }

void refreshSensorsValues() {
  pthread_mutex_lock(&msTa);
  sTa = getSensor(Ta);
  pthread_mutex_unlock(&msTa);

  pthread_mutex_lock(&msTi);
  sTi = getSensor(Ti);
  pthread_mutex_unlock(&msTi);

  pthread_mutex_lock(&msT);
  sT = getSensor(T);
  pthread_mutex_unlock(&msT);

  pthread_mutex_lock(&msNo);
  sNo = getSensor(No);
  pthread_mutex_unlock(&msNo);

  pthread_mutex_lock(&msH);
  sH = getSensor(H);
  pthread_mutex_unlock(&msH);
}

void printSensor(sensor_t sensor) {
  switch (sensor) {
    case Ta: {
      pthread_mutex_lock(&msTa);
      printf("sTa: %f\n", sTa);
      pthread_mutex_unlock(&msTa);
      break;
    }
    case T: {
      pthread_mutex_lock(&msT);
      printf("sT: %f\n", sT);
      pthread_mutex_unlock(&msT);
      break;
    }
    case Ti: {
      pthread_mutex_lock(&msTi);
      printf("sTi: %f\n", sTi);
      pthread_mutex_unlock(&msTi);
      break;
    }
    case No: {
      pthread_mutex_lock(&msNo);
      printf("sNo: %f\n", sNo);
      pthread_mutex_unlock(&msNo);
      break;
    }
    case H: {
      pthread_mutex_lock(&msH);
      printf("sH: %f\n", sH);
      pthread_mutex_unlock(&msH);
      break;
    }
    default: {
      break;
    }
  }
}

void showSensorsValues() {
  clear();
  printf(GRN "--------------------\n");
  printf("Sensors:\n");
  printSensor(Ta);
  printSensor(T);
  printSensor(Ti);
  printSensor(No);
  printSensor(H);
  printf("--------------------\n" RESET);
}

void sensorAlarm(double limit) {
  pthread_mutex_lock(&sensorMutex);
  temperatureLimit = limit;
  while (sT < temperatureLimit) {
    pthread_cond_wait(&alarmCondition, &sensorMutex);
  }
  temperatureLimit = HUGE_VAL;
  pthread_mutex_unlock(&sensorMutex);
}