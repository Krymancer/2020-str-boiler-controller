#include "resources.h"

pthread_mutex_t screenMutex = PTHREAD_MUTEX_INITIALIZER;

inline void allocateScreen(void) { pthread_mutex_lock(&screenMutex); }

inline void freeScreen(void) { pthread_mutex_unlock(&screenMutex); }
