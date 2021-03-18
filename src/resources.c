#include "resources.h"

pthread_mutex_t screenMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t keyboardMutex = PTHREAD_MUTEX_INITIALIZER;

inline void allocateScreen(void) {
  pthread_mutex_lock(&screenMutex);
}

inline void freeScreen(void) {
  pthread_mutex_unlock(&screenMutex);
}

double setReferenceTemperature() {
  printf(BLU "Temperature Referece: ");
  double value;
  scanf("%lf", &value);
  printf(RESET);
  return value;
}

double setReferenceHeight() {
  printf(BLU "Water Level Referece: ");
  double value;
  scanf("%lf", &value);
  printf(RESET);

  return value;
}
