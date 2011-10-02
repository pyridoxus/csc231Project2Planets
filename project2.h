#ifndef PROJECT2_H_
#define PROJECT2_H_

#include <iostream>
using namespace std;

#include "Satellite.h"
#include <stdlib.h>			// Used for exit()

#define MAXNUMSATELLITES 20

void draw();
void keyboard( unsigned char, int, int);
void special( int, int, int );
void printInstructions(void);
void createUniverse(void);

float t = 0.0;
float tx = 0.0;		// Position of the sun
float ty = 0.0;		// Position of the sun
float tz = -30.0;		// Camera distance from sun

#endif
