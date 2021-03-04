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
