#pragma once

#include <pthread.h>

#define BUFFER_SIZE 3

static char* buffer0[BUFFER_SIZE];
static char* buffer1[BUFFER_SIZE];

static int usingBuffer = 0;
static int nextIndex = 0;
static int record = -1;

static pthread_mutex_t mutualExclusion = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t bufferFull = PTHREAD_COND_INITIALIZER;

/**
 * insert the information on a free buffer
 *
 * @param content an string contating the information
 */
void insertBuffer(char* content);

/**
 * insert the information on a free buffer
 *
 * @param content an string contating the information
 */
char** waitBufferFull(void);