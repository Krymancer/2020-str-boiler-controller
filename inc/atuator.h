#pragma once

#include "socket.h"
#include "util.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Na => Fluxo de entrada de agua a 80ºC [Kg/s]
 * Ni => Fluxo de entrada de agua a (sTiºC) [Kg/s]
 * Nf => Fluxo de saida de agua para o esgoto [Kg/s]
 * Q => Aquecedor dentro do Recipiente [J/s]
 */
enum atuators { Na, Ni, Nf, Q };

double aNa, aNi, aNf, aQ;

typedef enum atuators atuator_t;

#define INVALID_ATUATOR -36;

void setSocketAtuatorValue(char*, double);
double setAtuator(atuator_t, double);