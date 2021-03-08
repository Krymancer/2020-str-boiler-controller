#include "sensor.h"
#include <stdio.h>

double getSocketSensorValue(char* sensor) {
  sendMessage(sensor);
  char* revicedMessage[1024];
  int recivedBytes = 0;
  recivedBytes = reciveMessage(revicedMessage, 1024);
  strcut(revicedMessage, 3, -1);
  double sensorValue = atof(revicedMessage);
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
  pthread_mutex_lock(&sensorMutex);
  sTa = getSensor(Ta);
  sTi = getSensor(Ti);
  sT = getSensor(T);
  sNo = getSensor(No);
  sH = getSensor(H);

  if (sT >= temperatureLimit) {
    pthread_cond_signal(&alarmCondition);
  }

  pthread_mutex_unlock(&sensorMutex);
}

void printSensor(sensor_t sensor) {
  switch (sensor) {
    case Ta: {
      printf("sTa: %f\n", sTa);
      break;
    }
    case T: {
      printf("sT: %f\n", sT);
      break;
    }
    case Ti: {
      printf("sTi: %f\n", sTi);
      break;
    }
    case No: {
      printf("sNo: %f\n", sNo);
      break;
    }
    case H: {
      printf("sH: %f\n", sH);
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