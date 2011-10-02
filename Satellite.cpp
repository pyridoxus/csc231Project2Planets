#include "Satellite.h"

Satellite::Satellite(	float radius, float distance,
											float orbitSpeed, float axisSpeed)
{
	this->radius = radius;
	this->distance = distance;
	this->orbitSpeed = orbitSpeed;
	this->axisSpeed = axisSpeed;
	return;
}

Satellite::~Satellite()
{
}

void Satellite::draw(float t)
{
	// This function assumes that the previously used matrix refers to the parent
	// satellite and will leave the matrix referring to this satellite. To change
	// the hierarchy, popping must occur after this function is called for as
	// many times it takes to get to the desired branch of the hierarchy.
	// A "null satellite" has radius of 0.0 and causes the hierarchy to be
	// popped up one level.
	if(this->radius == 0.0) glPopMatrix();	// Encountered "null satellite".
	else
	{
		glPushMatrix();
		glRotatef( t * this->orbitSpeed, 0, 0, 1 );		// rotate about parent
		glTranslatef( this->distance, 0, 0 );					// move away from parent
	//	glPushMatrix();																// save current matrix
	//  glLoadIdentity();															// reset to apply unique scaling
	//	glScalef( this->radius, this->radius, this->radius );	// add scaling to matrix
		glRotatef( t * this->axisSpeed, 0, 0, 1 );		// rotate about axis
		glColor3f( 1.0, 1.0, 1.0 );
		if(this->radius < 1.0) glutWireSphere(this->radius, 10, 8);
		else glutWireSphere(this->radius, 16, 12);
	}
//	glPopMatrix();										// discard effect of scaling, restore previous matrix
//
//	// Draw lower arm
//	glTranslatef( 2, 0, 0 );					// move to end of upper arm
//	glTranslatef( -1.0, 0, 0 );				// move back to origin
//	glRotatef( lowerRot, 0, 0, 1 );		// rotate about pivot point
//	glTranslatef( 1.0, 0, 0 );				// move to pivot point
//	glPushMatrix();										// save current matrix, make copy
//	glScalef( 2.0, 0.5, 1.0 );				// add scaling to matrix
//	glColor3f( 1.0, 1.0, 0.0 );
//	glutWireCube( 1.0 );
//	glPopMatrix();										// discard effect of scaling, restore previous matrix
//
//	// Draw hand
//	glTranslatef( 1.5, 0, 0 );				// move to end of lower arm
//	glRotatef( handRot, 1, 0, 0 );		// swivel (rotate around x axis)
//	glPushMatrix();										// save current matrix, make copy
//	glScalef( 1.0, 1.0, 0.5 );				// add scaling to matrix
//	glColor3f( 1.0, 0.0, 0.0 );
//	glutWireCube( 1.0 );
//	glPopMatrix();										// discard effect of scaling, restore previous matrix

	return;
}
