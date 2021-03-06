#include "buffer.h"

void insertBuffer(char* content) {
  pthread_mutex_lock(&mutualExclusion);
  if (usingBuffer == 0) {
    buffer0[nextIndex++] = content;
  } else {
    buffer1[nextIndex++] = content;
  }
  if (nextIndex == BUFFER_SIZE) {
    record = usingBuffer;
    usingBuffer = (usingBuffer + 1) % 2;
    nextIndex = 0;
    pthread_cond_signal(&bufferFull);
  }
  pthread_mutex_unlock(&mutualExclusion);
}

char* waitBufferFull(void) {
  char* buffer;
  pthread_mutex_lock(&mutualExclusion);
  while (record == -1) pthread_cond_wait(&bufferFull, &mutualExclusion);
  if (record == 0)
    buffer = buffer0;
  else
    buffer = buffer1;
  record = -1;
  pthread_mutex_unlock(&mutualExclusion);
  return buffer;
}
