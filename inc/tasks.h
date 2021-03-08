#pragma once

#include "resources.h"
#include "sensor.h"
#include "util.h"
#include <stdio.h>
#include <time.h>

// TODO
void temperatureControl(void);
void waterLevelControl(void);
void showSensorsInfo(void);
void refreshSensorsInfo(void);
void verifyTemperature(void);
void temperatureAlarm(void);
void saveInfoToFile(void);
