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
