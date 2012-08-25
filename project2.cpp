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
#include "project2.h"

Satellite *satellites[MAXNUMSATELLITES];

int main( int argc, char *argv[] )
{
	// Print menu
	printInstructions();

  // Initialize window system
  glutInit( &argc, argv );
  glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
  glutInitWindowSize( 800, 600 );
  glutCreateWindow( "Satellites" );

  // Projection
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity();
  gluPerspective( 45.0, 1.333, 0.01, 10000.0 );

	// View transformation (move scene away from camera at origin)
  glMatrixMode( GL_MODELVIEW );
  glLoadIdentity();
  glTranslatef( 0, 0, tz );

  // Hidden surface z-buffering
  glEnable( GL_DEPTH_TEST );

  // Callbacks
  glutDisplayFunc( draw );
  glutKeyboardFunc( keyboard );
	glutSpecialFunc( special );

  // Create all satellites
  createUniverse();

	// Main loop
  glutMainLoop();
  return 0;
}

// Display callback
void draw()
{
	// Clear the screen
	glClearColor( 0.0, 0.0, 0.0, 1.0);
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	// Save view translation matrix
	glPushMatrix();
	glTranslatef( tx, ty, 0.0 );

	// Draw entire system
	for(int n = 0; n < MAXNUMSATELLITES; n++)
		if(satellites[n]) satellites[n]->draw(t);

	// Restore view translation
	glPopMatrix();

	// Execute draw commands
	glutSwapBuffers();
	return;
}

// Keyboard callback
void keyboard( unsigned char key, int x, int y )
{
  switch( key )
    {
			case 'a':
				t += 1;
				break;
			case 'z':
				t -= 1;
				break;
			case 's':
				t += 0.1;
				break;
			case 'x':
				t -= 0.1;
				break;
			case '+':
				// View transformation (move scene away from camera at origin)
			  glMatrixMode( GL_MODELVIEW );
			  glLoadIdentity();
			  tz *= 0.95;
			  glTranslatef( 0, 0, tz );
			  break;
			case '-':
				// View transformation (move scene away from camera at origin)
			  glMatrixMode( GL_MODELVIEW );
			  glLoadIdentity();
			  tz /= 0.95;
			  glTranslatef( 0, 0, tz );
			  break;
			case 'q':
				for(int n = 0; n < MAXNUMSATELLITES; n++)
					if(satellites[n]) delete satellites[n];
				exit(1);
				break;
    }

  // Redraw the scene
  glutPostRedisplay();
}

void printInstructions()
{
	cout << "Keyboard commands" << endl;
	cout << "-----------------" << endl;
	cout << "a - advance time quickly" << endl;
	cout << "z - reverse time quickly" << endl;
	cout << "s - advance time slowly" << endl;
	cout << "x - reverse time slowly" << endl;
	cout << "+ - move camera closer" << endl;
	cout << "- - move camera farther away" << endl;
	cout << "move system with arrow keys" << endl;
	cout << "q - exit" << endl;
	return;
}

// Special function callback
void special( int key, int x, int y )
{
  // Process entries */
  switch( key )
  {
		case GLUT_KEY_RIGHT:
			tx += 0.1;
			break;
		case GLUT_KEY_LEFT:
			tx -= 0.1;
			break;
		case GLUT_KEY_UP:
			ty += 0.1;
			break;
		case GLUT_KEY_DOWN:
			ty -= 0.1;
			break;
	}

	// Redraw the scene
  glutPostRedisplay();
}

void createUniverse(void)
{
	// Create sample universe of only MAXNUMSATELLITES satellites
	for(int n = 0; n < MAXNUMSATELLITES; n++) satellites[n] = 0;	// Initialize
	// Create the sun first
	satellites[0] = new Satellite(1, 0, 0.0, 0.5);
	// Next create a system of planets and moons

	// Add planet
	satellites[1] = new Satellite(0.5, 4.0, 0.5, 10);
	// Add moon
	satellites[2] = new Satellite(0.25, 2.0, 2, 5);

	// Add mini-moon
	satellites[3] = new Satellite(0.1, 1.0, 4, 6);
	satellites[4] = new Satellite(0, 0, 0, 0);	// Serve as a matrix pop
	// End of mini-moon

	// Add another mini-moon
	satellites[5] = new Satellite(0.12, 0.7, 5, 8);
	satellites[6] = new Satellite(0, 0, 0, 0);	// Serve as a matrix pop
	// End of mini-moon

	satellites[7] = new Satellite(0, 0, 0, 0);	// Serve as a matrix pop
	// End of moon

	satellites[8] = new Satellite(0, 0, 0, 0);	// Serve as a matrix pop
	// End of planet

	// Add planet
	satellites[9] = new Satellite(0.75, -11.0, 0.3, 8);
	// Add moon
	satellites[10] = new Satellite(0.3, 2.5, 3, -6);

	// Add mini-moon
	satellites[11] = new Satellite(0.15, 1.0, 6, -12);
	satellites[12] = new Satellite(0, 0, 0, 0);	// Serve as a matrix pop
	// End of mini-moon

	// Add another mini-moon
	satellites[13] = new Satellite(0.1, 0.7, 8, -16);
	satellites[14] = new Satellite(0, 0, 0, 0);	// Serve as a matrix pop
	// End of mini-moon

	satellites[15] = new Satellite(0, 0, 0, 0);	// Serve as a matrix pop
	// End of moon

	satellites[16] = new Satellite(0, 0, 0, 0);	// Serve as a matrix pop
	// End of planet

	satellites[17] = new Satellite(0, 0, 0, 0);	// Serve as a matrix pop
	// End of system
	return;
}
