#include <GL/glut.h>
#include "functions.h"

/*Funkcija koja iscrtava pod*/
void draw_floor(){
	
	glPushMatrix();    
		glColor3f(0.5, 0.3, 0.4);
		glTranslatef(0, -1, 0);
		glScalef(200, 0,60);
		glutSolidCube(1);
	glPopMatrix();

}

/*Funkcija koja iscrtava put*/
void draw_path(){
	glPushMatrix();
	glRotatef(6,1,0,0);
	glScalef(7,0.15,1);
	glPushMatrix();
		glLineWidth(1);
		glTranslatef(0,-5.2,0);
		glColor3f(0,0,0);
		glutWireCube(1);
	   	glColor3f(0.91,0.76,0.65);
		glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();

}


/*Funkcija koja iscrtava sliku na zidu sa okvirom*/
void draw_picture(){
	glPushMatrix();
		glScalef(2.2,1.5,0.2);
		glLineWidth(20);
		glTranslatef(0,0.55,0);
		glColor3f(0.52,0.37,0.26);
		glutWireCube(1);
		glColor3f(0.91,0.76,0.65);
		glutSolidCube(1);
	glPopMatrix();

	
}

/*Funkcija koja iscrtava oblike koji su na traci*/

void draw_shapes(){
	/*Crveni trougao*/
	glPushMatrix();
	for(int i=0; i<100; i++){

		glTranslatef(5,0,0);
		glPushMatrix();
			glPushMatrix();
			glTranslatef(-1.9,-0.10,1);
			glScalef(0.5,0.5,0);
			glBegin(GL_POLYGON);
				glColor3f(1,0,0);
				glVertex3f(-0.9,-0.9,0);
				glVertex3f(-0.9,-0.5,0);
				glVertex3f(-0.5,-0.9,0);
			glEnd();

		glPopMatrix();

	}
	glPopMatrix();

	/*Plavi kvadrat*/
	glPushMatrix();
	for(int i=0; i<100; i++){

		glTranslatef(5,0,0);
		glPushMatrix();
			glTranslatef(-1.8,-0.45,1);
			glScalef(0.2,0.2,0);
			glBegin(GL_POLYGON);
				glColor3f(0,0,1);
				glVertex3f(0.5,-0.5,0);
				glVertex3f(-0.5,-0.5,0);
				glVertex3f(-0.5,0.5,0);
				glVertex3f(0.5,0.5,0);
			glEnd();
		glPopMatrix();

	}
	glPopMatrix();


	/*Zeleni trougao*/
	glPushMatrix();
	for(int i=0; i<100; i++){
		glTranslatef(5,0,0);
		glPushMatrix();
			glTranslatef(-1.65,-0.8,1);
			glScalef(0.5,0.5,0);
			glBegin(GL_POLYGON);
				glColor3f(0,1,0);
				glVertex3f(0.9,0.9,0);
				glVertex3f(0.9,0.5,0);
				glVertex3f(0.5,0.9,0);
			glEnd();
		glPopMatrix();
	}
	glPopMatrix();



	/*Crveni kvadrat*/
	glPushMatrix();
	for(int i=0; i<100; i++){
		glTranslatef(5,0,0);
		glPushMatrix();
			glTranslatef(0,-0.45,1);
			glScalef(0.2,0.2,0);
			glBegin(GL_POLYGON);
				glColor3f(1,0,0);
				glVertex3f(0.5,-0.5,0);
				glVertex3f(-0.5,-0.5,0);
				glVertex3f(-0.5,0.5,0);
				glVertex3f(0.5,0.5,0);
			glEnd();
		glPopMatrix();
	}
	glPopMatrix();



	/*Narandzast cetvorougao*/	
	glPushMatrix();
	for(int i=0; i<100; i++){	
		glTranslatef(5,0,0);
		glPushMatrix();
			glTranslatef(-0.65,-0.58,1);
			glScalef(0.3,0.3,0.3);
			glColor3f(1, 0.5, 0);
    		glBegin(GL_POLYGON);
    		    glVertex3f(0, 0, 0);
    		    glVertex3f(-0.5, 0.5, 0);
    		    glVertex3f(0, 1, 0);
    		    glVertex3f(0.5, 0.5, 0);
    		glEnd();
		glPopMatrix();
	}
	glPopMatrix();

	/*Pink trougao*/
	glPushMatrix();
	for(int i=0; i<100; i++){
		glTranslatef(5,0,0);
		glPushMatrix();
			glTranslatef(0.2,-0.10,1);
			glScalef(0.5,0.5,0);
			glBegin(GL_POLYGON);
				glColor3f(5, 0, 1);
				glVertex3f(0.9,-0.9,0);
				glVertex3f(0.9,-0.5,0);
				glVertex3f(0.5,-0.9,0);
			glEnd();
		glPopMatrix();
	}
	glPopMatrix();

	/*Braon trougao*/
	glPushMatrix();
	for(int i=0; i<100; i++){
		glTranslatef(5,0,0);
	 	glPushMatrix();
	  		glTranslatef(1.5,-0.80,1);
			glScalef(0.5,0.5,0);
			glBegin(GL_POLYGON);
				glColor3f(0.5,0.3,0.2);
				glVertex3f(-0.9,0.9,0);
				glVertex3f(-0.9,0.5,0);
				glVertex3f(-0.5,0.9,0);
			glEnd();
		glPopMatrix();
	}
	glPopMatrix();

	/*Svetlo plavi trougao*/
	glPushMatrix();
	for(int i=0; i<100; i++){
		glTranslatef(5,0,0);
		glPushMatrix();
			glTranslatef(1.65,-0.40,1);
			glScalef(0.32,0.32,0.32);
			glColor3f(0, 2, 1);
    		glBegin(GL_POLYGON);
    		    glVertex3f(0.5, -0.5, 0);
    		    glVertex3f(-0.5, -0.5, 0);
    		    glVertex3f(-0, 0, 0);
    		glEnd();
		glPopMatrix();
	}
	glPopMatrix();
	/*Tamno zeleni trougao*/
	glPushMatrix();
	for(int i=0; i<100; i++){
		glTranslatef(5,0,0);
		glPushMatrix();
			glTranslatef(2.2,-0.40,1);
			glScalef(0.32,0.32,0.32);
			glColor3f(0, 0.6, 0);
    		glBegin(GL_POLYGON);
    		    glVertex3f(0.5, -0.5, 0);
    		    glVertex3f(-0.5, -0.5, 0);
    		    glVertex3f(-0, 0, 0);
    		glEnd();
		glPopMatrix();
	}
	glPopMatrix();

}


