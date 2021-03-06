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
  printf("INFO: Write in file\n");
  for (int i = 0; i < BUFFER_SIZE; i++) {
    fprintf(file, "%s\n", buffer[i]);
  }
  fflush(file);
  fclose(file);
}

double timeDifference(struct timespec start, struct timespec end) {
  double nano = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec);
  double seconds = nano / (double)1000;
  double micro = (double)1000000 * nano;

  return micro;
}
