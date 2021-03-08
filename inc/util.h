#pragma once

#include "buffer.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

// Error opening file code
#define OPENING_FILE_ERROR -20
// Invalid atuator error code
#define INVALID_ATUATOR -36;
// Invalid sensor error code
#define INVALID_SENSOR -35;
// Sucess code
#define OK 0;
// Fail code
#define FAILED -1

// True = 1
#define TRUE 1

// Nanoseconds in a second
#define NANOSECONDS_PER_SECOND ((long)1000000000)
#define MICROSECONDS_PER_SECOND ((long)1000000)
#define NANOSECONDS_PER_MICROSECONDS ((long)1000)

// Clear screen
#define clear() printf("\033[H\033[J")

/*
 * Remove given section from string. Negative len means remove
 * everything up to the end.
 */
int strcut(char*, int, int);

/**
 * Write the buffer content into a file
 */
void writeInDisk();

#define secToMicro(X) (X * MICROSECONDS_PER_SECOND)
#define secToNano(X) (X * NANOSECONDS_PER_SECOND)
#define nsecToMicro(X) (X * NANOSECONDS_PER_MICROSECONDS)

/**
 * Calulate the time difference between 2 timespec
 *
 * @param start the timespec in start
 * @param end the timespec in the end
 *
 * @return the time spent in microseconds
 */
long timeDifference(struct timespec start, struct timespec end);

/**
 * Insert the response time of a tasnk in buffer
 *
 * @param task the task code id
 * @param responseTime the time spendend in the task
 */
void insertResponseTimeInBuffer(char* task, long responseTime);
