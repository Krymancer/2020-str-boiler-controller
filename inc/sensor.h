#pragma once

#include "socket.h"
#include "util.h"

/**
 * Ta => Temperatura do ar ambiente em volta do recipiente [ºC]
 * T  => Temperatura da agua no interior do recipiente [ºC]
 * Ti => Temperatura da agua que entra no recipiente [ºC]
 * No => Fluxo de saida de agua do recipiente [Kg/s]
 * H  => Altura da coluna d'agua [m]
 */
enum sensors { Ta, T, Ti, No, H };

double sTa, sT, sTi, sNo, sH;

typedef enum sensors sensor_t;

#define INVALID_SENSOR -35;

double getSensor(sensor_t);
void setSenstor(sensor_t);

double getSocketSensorValue(char*);

void refreshSensorsValues();

void printSensor(sensor_t);
void showSensorsValues();
