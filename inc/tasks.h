#pragma once

#include "atuator.h"
#include "resources.h"
#include "sensor.h"
#include "util.h"
#include <stdio.h>
#include <time.h>

extern double hRef;
extern double tRef;

void temperatureControl(void);
void waterLevelControl(void);
void showSensorsInfo(void);
void refreshSensorsInfo(void);
void verifyTemperature(void);
void temperatureAlarm(void);
void saveInfoToFile(void);
