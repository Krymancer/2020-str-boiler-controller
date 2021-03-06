#pragma once

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