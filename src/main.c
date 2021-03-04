#include "main.h"

int main(int argc, char** argv) {
  if (argc < 3) {
    fprintf(stderr, "Uso: controlemanual <endereco> <porta>\n");
    fprintf(stderr, "<endereco> eh o endereco IP da caldeira\n");
    fprintf(stderr, "<porta> eh o numero da porta UDP da caldeira\n");
    fprintf(stderr, "Exemplo de uso:\n");
    fprintf(stderr, "   controlemanual localhost 12345\n");
    return FAILED;
  }

  port = atoi(argv[2]);
  localSocket = createLocalSocket();
  endpoint = createEndpointAddress(argv[1], port);

  setAtuator(Na, 1.00);
  setAtuator(Nf, 2.00);
  setAtuator(Ni, 3.00);
  setAtuator(Q, 4.00);
}