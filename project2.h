//This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.
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
