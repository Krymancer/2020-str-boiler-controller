#include "atuator.h"

void setSocketAtuatorValue(char* atuator, double value) {
  char* message[256];
  char* recivedMessage = malloc(1024 * sizeof(char));
  sprintf(message, "%s%lf", atuator, value);
  messageSocketR(message, recivedMessage);
}

double setAtuator(atuator_t atuator, double value) {
  pthread_mutex_lock(&atuatorMutex);
  switch (atuator) {
    case Na: {
      aNa = value;
      setSocketAtuatorValue("ana", value);
      break;
    }
    case Ni: {
      aNi = value;
      setSocketAtuatorValue("ani", value);
      break;
    }
    case Nf: {
      aNf = value;
      setSocketAtuatorValue("anf", value);
      break;
    }
    case Q: {
      aQ = value;
      setSocketAtuatorValue("aq-", value);
      break;
    }
    default: {
      return INVALID_ATUATOR;
      break;
    }
  }
  pthread_mutex_unlock(&atuatorMutex);
  return OK;
}