#include "socket.h"

pthread_mutex_t socketMutex = PTHREAD_MUTEX_INITIALIZER;

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
    exit(EXIT_FAILURE);
  }

  memset((char*)&servidor, 0, sizeof(servidor));
  memcpy(&servidor.sin_addr, dest_internet->h_addr_list[0],
         sizeof(servidor.sin_addr));
  servidor.sin_family = AF_INET;
  servidor.sin_port = htons(porta_destino);

  return servidor;
}

void sendMessage(char* mensagem) {
  /* Envia msg ao servidor */
  if (sendto(localSocket, mensagem, strlen(mensagem) + 1, 0, (struct sockaddr*)&endpoint, sizeof(endpoint)) < 0) {
    perror("sendto");
  }
}

int reciveMessage(char* buffer, int TAM_BUFFER) {
  int bytes_recebidos; /* Numero de bytes recebidos */

  /* Espera pela msg de resposta do servidor */
  bytes_recebidos = recvfrom(localSocket, buffer, TAM_BUFFER, 0, NULL, 0);

  if (bytes_recebidos < 0) {
    perror("recvfrom");
  }
  return bytes_recebidos;
}

void messageSocket(const char* message) {
  pthread_mutex_lock(&socketMutex);
  sendMessage(message);
  pthread_mutex_unlock(&socketMutex);
}

void messageSocketR(const char* message, char* buffer) {
  pthread_mutex_lock(&socketMutex);
  sendMessage(message);
  char recivedMessage[1024];
  memset(recivedMessage, 1024, '\0');
  int recivedBytes = 0;
  recivedBytes = reciveMessage(recivedMessage, 1024);
  recivedMessage[recivedBytes] = "\0";
  strcpy(buffer, recivedMessage);
  pthread_mutex_unlock(&socketMutex);
}