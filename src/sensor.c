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