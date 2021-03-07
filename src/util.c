#include "util.h";

int strcut(char* str, int begin, int end) {
  int l = strlen(str);

  if (end <= 0) {
    end = l - 1;
  }

  int cutedlen = end - begin;
  char* aux = malloc(cutedlen * sizeof(char));

  for (int i = begin, j = 0; i <= end; i++, j++) {
    aux[j] = str[i];
  }
  aux[end] = '\0';

  strcpy(str, aux);
}

void writeInDisk() {
  FILE* file;
  file = fopen("data.txt", "a");
  if (file == NULL) {
    printf("ERROR: couldn't open the file\n");
    exit(OPENING_FILE_ERROR);
  }

  char** buffer = waitBufferFull();
  printf("--------------------\n");
  printf("INFO: Write in file\n");
  printf("--------------------\n");
  for (int i = 0; i < BUFFER_SIZE; i++) {
    fprintf(file, "%s\n", buffer[i]);
  }
  fflush(file);
  fclose(file);
}

double timeDifference(struct timespec start, struct timespec end) {
  double nano = ((end.tv_sec - start.tv_sec) * NANOSECONDS_PER_SECOND) +
                (end.tv_nsec - start.tv_nsec);
  double seconds = nano / 1e9;
  double micro = (double)1000000 * seconds;

  return micro;
}
