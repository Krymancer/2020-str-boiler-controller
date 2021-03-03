#pragma once

#include <sys/types.h>
#include <pthread.h>

void bufduplo_insereLeitura(double leitura);
double* bufduplo_esperaBufferCheio(void);
