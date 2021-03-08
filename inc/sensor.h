#pragma once

#include "socket.h"
#include "util.h"
#include <math.h>
#include <pthread.h>

static pthread_mutex_t sensorMutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t alarmCondition = PTHREAD_COND_INITIALIZER;
static double temperatureLimit;

/**
 * Enumerate sensors
 * Ta => Temperatura do ar ambiente em volta do recipiente [ºC]
 * T  => Temperatura da agua no interior do recipiente [ºC]
 * Ti => Temperatura da agua que entra no recipiente [ºC]
 * No => Fluxo de saida de agua do recipiente [Kg/s]
 * H  => Altura da coluna d'agua [m]
 */
enum sensors { Ta, T, Ti, No, H };

/**
 * Variable to store sensors values
 * sTa => Temperatura do ar ambiente em volta do recipiente [ºC]
 * sT  => Temperatura da agua no interior do recipiente [ºC]
 * sTi => Temperatura da agua que entra no recipiente [ºC]
 * sNo => Fluxo de saida de agua do recipiente [Kg/s]
 * sH  => Altura da coluna d'agua [m]
 */
double sTa, sT, sTi, sNo, sH;

// Sensor type
typedef enum sensors sensor_t;

/**
 * Get the value of an sensor
 *
 * @param sensor sensor to get value from
 *
 * @return the value of sensor
 */
double getSensor(sensor_t sensor);

/**
 * Set the value of an sensor
 *
 * @param sensor sensor to set value from
 */
void setSenstor(sensor_t sensor);

// Auxiliar function, create an string and sent to socket
double getSocketSensorValue(char*);

/**
 * Refresh the value of all sensors
 * getting from the Java Application
 */
void refreshSensorsValues();

/**
 * Print the value of an sensor
 *
 * @param sensor sensor to print value from
 */
void printSensor(sensor_t);

/**
 * Print the value of all sensors
 */
void showSensorsValues();

void sensorAlarm(double limit);
