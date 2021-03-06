#pragma once

#include <string.h>

// Invalid atuator error code
#define INVALID_ATUATOR -36;
// Invalid sensor error code
#define INVALID_SENSOR -35;
// Sucess code
#define OK 0;
// Fail code
#define FAILED -1

/*
 *      Remove given section from string. Negative len means remove
 *      everything up to the end.
 */
int strcut(char*, int, int);