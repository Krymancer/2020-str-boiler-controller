#pragma once

#include "util.h"
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <errno.h>
#include <netdb.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern pthread_mutex_t socketMutex;

double messageSocket(const char* message);

void createSocket(char* destination, char* portStr);