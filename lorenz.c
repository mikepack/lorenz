#include <GLUT/glut.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
int numPts = 200000;
double th=0;  //  Rotation angle
float pts[200000][3];
static GLfloat view_rotx = 25.0, view_roty = 50.0, view_rotz = 35.0;
static GLfloat view_posz = 60.0;
/*  Lorenz Parameters  */
double s  = 10;
double b  = 2.6666;
double r  = 28;

int iter = 0;
int iterInc = 10;

void display() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
		
	glRotatef(view_rotx, 1.0, 0.0, 0.0);
	glRotatef(view_roty, 0.0, 1.0, 0.0);
	glRotatef(view_rotz, 0.0, 0.0, 1.0);

	glBegin(GL_LINE_STRIP);
	int i = 0;
	
	while( i < iter && i < numPts ) {
		glColor3fv(pts[i]);
		glVertex3fv(pts[i++]);
	}
	glEnd();
	
	if( iter < numPts ) {
		if( iter + iterInc > numPts ) iter = numPts;
		else iter+=iterInc;
	}
	
	glFlush();
	glutSwapBuffers();
	
	glPopMatrix();
	
}

static void reshape(int width, int height) {
  GLfloat h = (GLfloat) height / (GLfloat) width;

  glViewport(0, 0, (GLint) width, (GLint) height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glFrustum(-5.0, 5.0, -h*2, h*2, 1.0, 300.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0.0, 0.0, -60.0);
}

static void special(int k, int x, int y) {
	switch (k) {
		case GLUT_KEY_UP:
			view_rotx += 5.0;
			break;
		case GLUT_KEY_DOWN:
			view_rotx -= 5.0;
			break;
		case GLUT_KEY_LEFT:
			view_roty += 5.0;
			break;
		case GLUT_KEY_RIGHT:
			view_roty -= 5.0;
			break;
		default:
			return;
	}
  glutPostRedisplay();
}

static void key(unsigned char k, int x, int y) {
	switch (k) {
		case 'q':
			view_rotx += 5.0;
			break;
		case 'a':
			view_rotx -= 5.0;
			break;
		case 'w':
			view_roty += 5.0;
			break;
		case 's':
			view_roty -= 5.0;
			break;
		case 'e':
			view_rotz += 5.0;
			break;
		case 'd':
			view_rotz -= 5.0;
			break;
		case 'r':
			iter = 0;
			break;
		case 'f':
			iter = numPts;
			break;
		case 't':
			iterInc += 5;
			break;
		case 'g':
			if( iterInc - 5 >- 0 ) iterInc -= 5;
			break;
		case 'y':
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			view_posz -= 1;
			gluLookAt(0,0,view_posz,0.0,0.0,0.0,0.0,1.0,0.0);
			break;
		case 'h':
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			view_posz += 1;
			gluLookAt(0,0,view_posz,0.0,0.0,0.0,0.0,1.0,0.0);
			break;
		default:
			return;
	}
	glutPostRedisplay();
}

static void idle(void) {
	iter+=iterInc;
	glutPostRedisplay();
}

static void lorenzGen(void) {
	int i;
	/*  Coordinates  */
	float x = pts[0][0] = 1;
	float y = pts[0][1] = 1;
	float z = pts[0][2] = 1;
	/*  Time step  */
	float dt = 0.001;

	for (i=0;i<numPts-1;i++)
	{	
		float dx = s*(y-x);
		float dy = x*(r-z)-y;
		float dz = x*y - b*z;
		x += dt*dx;
		y += dt*dy;
		z += dt*dz;
		
		pts[i+1][0] = x;
		pts[i+1][1] = y;
		pts[i+1][2] = z;
		
	}
}

int main(int argc,char* argv[]) {
	lorenzGen();
	
	glutInit(&argc,argv);
	
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(50, 50);
  glutInitWindowSize(500, 500);
	
	glutCreateWindow("Lorenz Attractor");
	
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutSpecialFunc(special);
	glutKeyboardFunc(key);
	glutIdleFunc(idle);
	
	glutMainLoop();
	
	return 0;
}
