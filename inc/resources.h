#pragma once

#include "util.h"
#include <pthread.h>

extern pthread_mutex_t screenMutex;

/**
 * Allocate the screen to print something
 */
void allocateScreen(void);

/**
 * Free the screen after use
 */
void freeScreen(void);

/**
 * get Input from Keyborad to set Temperature Reference
 * 
 * @param tRef the variable to store Temperature Reference
 */
double setReferenceTemperature();

/**
 * get Input from Keyborad to set Water Height Reference
 * 
 * @param hRef the variable to store Whater Height Reference
 */
double setReferenceHeight();