#include "socket.h"

pthread_mutex_t socketMutex = PTHREAD_MUTEX_INITIALIZER;

// Socket port
static int port;
// Local Socket
static int localSocket;
// Java Application address
static struct sockaddr_in endpoint;

int createLocalSocket(void) {
  int socket_local; /* Socket usado na comunicacao */

  socket_local = socket(PF_INET, SOCK_DGRAM, 0);
  if (socket_local < 0) {
    perror("socket");
    return -1;
  }
  return socket_local;
}

struct sockaddr_in createEndpointAddress(char* destino, int porta_destino) {
  struct sockaddr_in servidor;   /* Endereco do servidor incluindo ip e porta */
  struct hostent* dest_internet; /* Endereco destino em formato proprio */
  struct in_addr dest_ip;        /* Endereco destino em formato ip numerico */

  if (inet_aton(destino, &dest_ip))
    dest_internet = gethostbyaddr((char*)&dest_ip, sizeof(dest_ip), AF_INET);
  else
    dest_internet = gethostbyname(destino);

  if (dest_internet == NULL) {
    fprintf(stderr, "Endereco de rede invalido\n");
    exit(EXIT_SUCCESS);
  }

  memset((char*)&servidor, 0, sizeof(servidor));
  memcpy(&servidor.sin_addr, dest_internet->h_addr_list[0],
         sizeof(servidor.sin_addr));
  servidor.sin_family = AF_INET;
  servidor.sin_port = htons(porta_destino);

  return servidor;
}

void sendMessage(int localSocket, struct sockaddr_in endpoint, char* mensagem) {
  /* Envia msg ao servidor */
  if (sendto(localSocket, mensagem, strlen(mensagem) + 1, 0, (struct sockaddr*)&endpoint, sizeof(endpoint)) < 0) {
    perror("sendto");
  }
}

int reciveMessage(int localSocket, char* buffer, int TAM_BUFFER) {
  int bytes_recebidos; /* Numero de bytes recebidos */

  /* Espera pela msg de resposta do servidor */
  bytes_recebidos = recvfrom(localSocket, buffer, TAM_BUFFER, 0, NULL, 0);

  if (bytes_recebidos < 0) {
    printf("error");
    perror("recvfrom");
    exit(FAILED);
  }

  return bytes_recebidos;
}

void createSocket(char* destination, char* portStr) {
  pthread_mutex_lock(&socketMutex);
  port = atoi(portStr);
  localSocket = createLocalSocket();
  endpoint = createEndpointAddress(destination, port);
  pthread_mutex_unlock(&socketMutex);
}

double messageSocket(const char* message) {
  char recivedMessage[256];
  int recivedBytes = 0;

  pthread_mutex_lock(&socketMutex);

  sendMessage(localSocket, endpoint, message);
  recivedBytes = reciveMessage(localSocket, recivedMessage, 256);
  recivedMessage[recivedBytes] = "\0";

  pthread_mutex_unlock(&socketMutex);

  return atof(&recivedMessage[3]);
}