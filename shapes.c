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
		glTranslatef(0,-1.2,0);
		glScalef(10,1,1);
	   	glColor3f(0.91,0.76,0.65);
		glutSolidCube(1);
	glPopMatrix();

}

/*Funkcija koja iscrtava sliku na zidu sa okvirom*/
void draw_picture(){
	glPushMatrix();
		glLineWidth(20);
		glTranslatef(0,1,0);
		glColor3f(0.52,0.37,0.26);
		glutWireCube(2);
		glColor3f(0.91,0.76,0.65);
		glutSolidCube(2);
	glPopMatrix();

	
}

/*Funkcija koja iscrtava oblike koji su na traci*/
void draw_shapes(){
	/*Crveni kvadrat*/
	glPushMatrix();
		glTranslatef(0,-0.6,1);
		glScalef(0.2,0.2,0);
		glBegin(GL_POLYGON);
			glColor3f(1,0,0);
			glVertex3f(0.5,-0.5,0);
			glVertex3f(-0.5,-0.5,0);
			glVertex3f(-0.5,0.5,0);
			glVertex3f(0.5,0.5,0);
		glEnd();
	glPopMatrix();

	/*Crveni trougao*/
	glPushMatrix();
		glTranslatef(-1.9,-0.24,1);
		glScalef(0.5,0.5,0);
		glBegin(GL_POLYGON);
			glColor3f(1,0,0);
			glVertex3f(-0.9,-0.9,0);
			glVertex3f(-0.9,-0.5,0);
			glVertex3f(-0.5,-0.9,0);
		glEnd();
	glPopMatrix();

	/*Plavi kvadrat*/
	glPushMatrix();
		glTranslatef(-1.8,-0.6,1);
		glScalef(0.2,0.2,0);
		glBegin(GL_POLYGON);
			glColor3f(0,0,1);
			glVertex3f(0.5,-0.5,0);
			glVertex3f(-0.5,-0.5,0);
			glVertex3f(-0.5,0.5,0);
			glVertex3f(0.5,0.5,0);
		glEnd();
	glPopMatrix();

	/*Zeleni trougao*/
	glPushMatrix();
		glTranslatef(-1.65,-0.95,1);
		glScalef(0.5,0.5,0);
		glBegin(GL_POLYGON);
			glColor3f(0,1,0);
			glVertex3f(0.9,0.9,0);
			glVertex3f(0.9,0.5,0);
			glVertex3f(0.5,0.9,0);
		glEnd();
	glPopMatrix();

	/*Narandzast cetvorougao*/	
	glPushMatrix();
		glTranslatef(-0.65,-0.75,1);
		glScalef(0.3,0.3,0.3);
		glColor3f(1, 0.5, 0);
    	glBegin(GL_POLYGON);
    	    glVertex3f(0, 0, 0);
    	    glVertex3f(-0.5, 0.5, 0);
    	    glVertex3f(0, 1, 0);
    	    glVertex3f(0.5, 0.5, 0);
    	glEnd();
	glPopMatrix();

	/*Pink trougao*/
	glPushMatrix();
		glTranslatef(0.2,-0.25,1);
		glScalef(0.5,0.5,0);
		glBegin(GL_POLYGON);
			glColor3f(5, 0, 1);
			glVertex3f(0.9,-0.9,0);
			glVertex3f(0.9,-0.5,0);
			glVertex3f(0.5,-0.9,0);
		glEnd();
	glPopMatrix();

	/*Braon trougao*/
	glPushMatrix();
		glTranslatef(1.5,-0.95,1);
		glScalef(0.5,0.5,0);
		glBegin(GL_POLYGON);
			glColor3f(0.5,0.3,0.2);
			glVertex3f(-0.9,0.9,0);
			glVertex3f(-0.9,0.5,0);
			glVertex3f(-0.5,0.9,0);
		glEnd();
	glPopMatrix();

	/*Svetlo plavi trougao*/
	glPushMatrix();
		glTranslatef(1,-0.45,1.9);
		glScalef(0.32,0.32,0);
   		glColor3f(0, 2, 1);
    	glBegin(GL_POLYGON);
    	    glVertex3f(-0.25, 0.25, 0);
    	    glVertex3f(-0.5, 0.5, 0);
    	    glVertex3f(0, 0.5, 0);
    	glEnd();
	glPopMatrix();

	/*Tamno zeleni trougao*/
	glPushMatrix();
		glTranslatef(2.2,-0.55,1);
		glScalef(0.32,0.32,0.32);
		glColor3f(0, 0.6, 0);
    	glBegin(GL_POLYGON);
    	    glVertex3f(0.5, -0.5, 0);
    	    glVertex3f(-0.5, -0.5, 0);
    	    glVertex3f(-0, 0, 0);
    	glEnd();
	glPopMatrix();
	
}

