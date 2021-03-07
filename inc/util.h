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
#define NANOSECONDS_PER_SECOND 1000000000

// Clear screen
#define clear() printf("\033[H\033[J")

/*
 * Remove given section from string. Negative len means remove
 * everything up to the end.
 */
int strcut(char*, int, int);

/*
 * Write the buffer content into a file
 */
void writeInDisk();

/**
 * Calulate the time difference between 2 timespec
 *
 * @param start the timespec in start
 * @param end the timespec in the end
 *
 * @return the time spend in microseconds
 */
double timeDifference(struct timespec start, struct timespec end);