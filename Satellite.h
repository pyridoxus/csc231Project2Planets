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
#ifndef SATELLITE_H_
#define SATELLITE_H_

#include <GL/glut.h>

class Satellite
{
	public:
		Satellite(float radius, float distance, float orbitSpeed, float axisSpeed);
		virtual ~Satellite();
		void draw(float t);
	private:
		float radius;			// Radius of the satellite
		float distance;		// Distance of the satellite from its parent
		float orbitSpeed;	// Speed of orbit around its parent (as factor of t)
		float axisSpeed;	// Speed of rotating about its axis (as factor of t)
};

#endif
