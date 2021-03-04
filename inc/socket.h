#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <errno.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int port;
int localSocket;
struct sockaddr_in endpoint;

int createLocalSocket(void);
struct sockaddr_in createEndpointAddress(char*, int);
void sendMessage(char*);
int reciveMessage(char*, int);