#include "atuator.h"

void setSocketAtuatorValue(char* atuator, double value) {
  char* message[256];
  sprintf(message, "%s%lf", atuator, value);
  messageSocket(message);
}

double setAtuator(atuator_t atuator, double value) {
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
  return OK;
}