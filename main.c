#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#include "functions.h"

#define TIMER_INTERVAL 10
#define TIMER_ID 0

static float animation_parameter =0;
static float animation_ongoing =0;

/*Niz objekata na traci*/
Shapes shapes_array[100];
/*Niz objekata na slici*/
Shapes picture_array[9];


int main(int argc, char ** argv){

	/*Inicijalizacija objekata na traci*/
	srand(time(NULL));//postavlja seme
	for(int i=0; i<100; i++){
		shapes_array[i].R = (rand()%100)/100.0;
		shapes_array[i].G = (rand()%100)/100.0;
		shapes_array[i].B = (rand()%100)/100.0;
		shapes_array[i].x = -0.9 + i*2; //svaki naredni je na rastojanju 2 u odnosu na prvi objekat na traci
		shapes_array[i].y = -2.3;
		shapes_array[i].z = 1;
		shapes_array[i].type = rand()%12;
	}

	/*Glut inicijalizacija*/
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
	
	/*Kreiranje prozora*/
	glutInitWindowSize(800,800);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Shape-fitting");

	/*Funkcije za obradu dogadjaja*/
	glutDisplayFunc(on_display);
	glutKeyboardFunc(on_keyboard);
	glutReshapeFunc(on_reshape);

	glutFullScreen();
	
	/*OpenGL inicijalizacije*/
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);

	/*Postavljanje boje pozadine*/
	glClearColor(0.7,0.8,0.8,0.2);


	glutMainLoop();

return 0;
}


/*void draw_coordinate_system(){
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

}*/


void on_display(void){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/*Podesavanje projekcije*/
	glMatrixMode(GL_PROJECTION);
    	glLoadIdentity();
    	gluPerspective(
            60,
            window_width/(float)window_height,
            1, 50);
	
	/*Podesavanje pozicije kamere*/
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(
            0, 0, 3,
            0, 0, 0,
            0, 1, 0
        );
	

	/*Iscrtavanje objekata*/
	
	draw_picture_shapes(picture_array);
	draw_picture();

    /*Animacija kretanja objekata na traci*/
	glPushMatrix();
		move_shapes(-animation_parameter, 0, 0, shapes_array);
		draw_shapes(shapes_array);
	glPopMatrix();

    draw_path();
	draw_floor();
	
	//draw_coordinate_system();

	/*glColor3f(1,1,1);
	glBegin(GL_POLYGON);
		glVertex3f(9,9,0);
		glVertex3f(9,5,0);
		glVertex3f(5,9,0);
	glEnd();*/

	glutSwapBuffers();
}


void on_keyboard(unsigned char key, int x, int  y){

	switch(key){
		case 'r':
		case 'R':
			animation_parameter = 0;
			glutPostRedisplay();
			break;

		case 's':
		case 'S':
			animation_ongoing = 0;
			break;

		case 'g':
		case 'G':
			if(!animation_ongoing){
				animation_ongoing = 1;	
				glutTimerFunc(TIMER_INTERVAL,on_timer,TIMER_ID);

			}
			break;
		case 27:
			exit(0);
			break;
	}

}

void on_reshape(int width, int height){
	/*Podesavanje sirine i visine*/
	window_width=width;
	window_height=height;

	
	glViewport(0, 0, window_width, window_height);


}

void on_timer(int id){
	if(id==TIMER_ID){
		animation_parameter = 0.03;

	}
	glutPostRedisplay();
	if(animation_ongoing)
		glutTimerFunc(TIMER_INTERVAL,on_timer,TIMER_ID);
}


