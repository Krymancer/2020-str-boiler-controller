#pragma once

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <errno.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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