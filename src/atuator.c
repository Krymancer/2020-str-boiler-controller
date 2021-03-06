#include "atuator.h"

void setSocketAtuatorValue(char* atuator, double value) {
  char* message[256];
  sprintf(message, "%s%lf", atuator, value);
  printf("atuator: %s\n", message);
  sendMessage(message);
}

double setAtuator(atuator_t atuator, double value) {
  switch (atuator) {
    case Na: {
      setSocketAtuatorValue("ana", value);
      break;
    }
    case Ni: {
      setSocketAtuatorValue("ani", value);
      break;
    }
    case Nf: {
      setSocketAtuatorValue("anf", value);
      break;
    }
    case Q: {
      setSocketAtuatorValue("aq-", value);
      break;
    }
    default: {
      return INVALID_ATUATOR;
      break;
    }
  }
  return OK;
}