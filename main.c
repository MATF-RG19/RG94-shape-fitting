#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

static int window_width,window_height;

static void on_display(void);
static void on_reshape(int width, int height);
static void on_keyboard(unsigned char key, int x, int y);

int main(int argc, char ** argv){

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
	
	glutInitWindowSize(800,800);
	glutInitWindowPosition(100,100);
	glutCreateWindow(argv[0]);

	glutDisplayFunc(on_display);
	glutKeyboardFunc(on_keyboard);
	glutReshapeFunc(on_reshape);

	glutFullScreen();
	
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glClearColor(0.7,0.8,0.8,0.2);

	glutMainLoop();
return 0;
}


void draw_coordinate_system(){
	glDisable(GL_LIGHTING);

	glBegin(GL_LINES);
		glColor3f(0.7,0,0);
		glVertex3f(0,0,0);
		glVertex3f(150,0,0);

		glColor3f(0,0.7,0);
		glVertex3f(0,0,0);
		glVertex3f(0,150,0);

		glColor3f(0,0,0.7);
		glVertex3f(0,0,0);
        glVertex3f(0,0,150);
    glEnd();

	glEnable(GL_LIGHTING);

}


static void on_display(void){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(20, 20, 20,
		       0, 0, 0,
		       0, 1, 0);

	draw_coordinate_system();

	glColor3f(1,1,1);
	glBegin(GL_POLYGON);
		glVertex3f(9,9,0);
		glVertex3f(9,5,0);
		glVertex3f(5,9,0);
	glEnd();

	glutSwapBuffers();
}


static void on_keyboard(unsigned char key, int x, int  y){

	switch(key){
		case 27:
			exit(0);
			break;
	}

}

static void on_reshape(int width, int height){
	window_width=width;
	window_height=height;
	
	glViewport(0,0,window_width, window_height);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective( 60,
			window_width/(float)window_height,
			1,50);

}


