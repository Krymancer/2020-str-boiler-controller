#include "resources.h"

void allocateScreen(void) { pthread_mutex_lock(&screenMutex); }

void freeScreen(void) { pthread_mutex_unlock(&screenMutex); }
