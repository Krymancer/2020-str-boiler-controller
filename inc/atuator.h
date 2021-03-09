#pragma once

#include "socket.h"
#include "util.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Enumerate atuators
 * Na => Fluxo de entrada de agua a 80ºC [Kg/s]
 * Ni => Fluxo de entrada de agua a (sTiºC) [Kg/s]
 * Nf => Fluxo de saida de agua para o esgoto [Kg/s]
 * Q => Aquecedor dentro do Recipiente [J/s]
 */
enum atuators { Na,
                Ni,
                Nf,
                Q };

/**
 * Store value of atuators
 * aNa => Fluxo de entrada de agua a 80ºC [Kg/s]
 * aNi => Fluxo de entrada de agua a (sTiºC) [Kg/s]
 * aNf => Fluxo de saida de agua para o esgoto [Kg/s]
 * aQ => Aquecedor dentro do Recipiente [J/s]
 */
double aNa, aNi, aNf, aQ;

// Atuator type
typedef enum atuators atuator_t;

// Auxiliar function, create an string and sent to socket
void setSocketAtuatorValue(char* atuator, double value);

/**
 * Set the value of an atuator and send it to the Java Application
 *  via socket
 *
 * @param atuator the disered atuator
 * @param value the value of the atuator
 * @return OK if sucess, otherwhise retunr an error code
 */
double setAtuator(atuator_t atuator, double value);