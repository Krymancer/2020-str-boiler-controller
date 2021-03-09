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

// Socket port
int port;
// Local Socket
int localSocket;
// Java Application address
struct sockaddr_in endpoint;

// Create an local socket
int createLocalSocket(void);
// Create an endpoint to acess the socket
struct sockaddr_in createEndpointAddress(char*, int);

/**
 * send an message via socket to the endpoint
 *
 * @param message the message to send
 */
void sendMessage(char* message);

/**
 * recive an message via socket to the endpoint
 * @param buffer the vuffer to store the message
 * @param bufferSize the size of buffer
 *
 * @return the total of bytes recived
 */
int reciveMessage(char* buffer, int bufferSize);

void messageSocket(const char* message);
void messageSocketR(const char* message, char* buffer);