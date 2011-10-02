#ifndef PROJECT2_H_
#define PROJECT2_H_

#include <iostream>
using namespace std;

#include "Satellite.h"
#include <stdlib.h>			// Used for exit()

#define MAXNUMSATELLITES 10

void draw();
void keyboard( unsigned char, int, int);
void printInstructions(void);
void createUniverse(void);

float t = 0.0;

#endif
