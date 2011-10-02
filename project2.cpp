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
  glTranslatef( 0, 0, -12 );

  // Hidden surface z-buffering
  glEnable( GL_DEPTH_TEST );

  // Callbacks
  glutDisplayFunc( draw );
  glutKeyboardFunc( keyboard );

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

	// Rotate entire system
	for(int n = 0; n < MAXNUMSATELLITES; n++)
		if(satellites[n]) satellites[n]->draw(t);
//	glPushMatrix();
//	glRotatef(t, 0, 0, 1);
//	glutWireSphere(1.0, 20, 16);

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
	cout << "q - exit" << endl;
	return;
}

void createUniverse(void)
{
	// Create sample universe of only MAXNUMSATELLITES satellites
	for(int n = 0; n < MAXNUMSATELLITES; n++) satellites[n] = 0;	// Initialize
	// Create the sun first
	satellites[0] = new Satellite(1, 0, 0.0, 0.5);
	satellites[1] = new Satellite(0.5, 4.0, 0.5, 10);
	satellites[2] = new Satellite(0.25, 2.0, 2, 5);
	satellites[3] = new Satellite(0.1, 1.0, 4, 2);
	satellites[4] = new Satellite(0, 0, 0, 0);	// Serve as a matrix pop
	satellites[5] = new Satellite(0, 0, 0, 0);	// Serve as a matrix pop
	satellites[6] = new Satellite(0, 0, 0, 0);	// Serve as a matrix pop
	satellites[6] = new Satellite(0, 0, 0, 0);	// Serve as a matrix pop
	return;
}
