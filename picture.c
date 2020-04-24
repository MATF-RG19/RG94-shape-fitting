#include <GL/glut.h>
#include "functions.h"

void draw_picture_shapes(){
	
		//camac
	glPushMatrix();
		glTranslatef(0,0.3,1);
		glScalef(0.2,0.2,0);
		glBegin(GL_POLYGON);
			glColor3f(1,0,0);
			glVertex3f(0.5,-0.5,0);
			glVertex3f(-0.5,-0.5,0);
			glVertex3f(-0.5,0.5,0);
			glVertex3f(0.5,0.5,0);
		glEnd();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.2,0.3,1);
		glScalef(0.2,0.2,0);
		glBegin(GL_POLYGON);
			glColor3f(0,0.7,0);
			glVertex3f(0.5,-0.5,0);
			glVertex3f(-0.5,-0.5,0);
			glVertex3f(-0.5,0.5,0);
			glVertex3f(0.5,0.5,0);
		glEnd();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-0.2,0.3,1);
		glScalef(0.2,0.2,0);
		glBegin(GL_POLYGON);
			glColor3f(0,0,1);
			glVertex3f(0.5,-0.5,0);
			glVertex3f(-0.5,-0.5,0);
			glVertex3f(-0.5,0.5,0);
			glVertex3f(0.5,0.5,0);
		glEnd();
	glPopMatrix();


	glPushMatrix();
		glTranslatef(0.75,-0.05,1);
		glScalef(0.5,0.5,0);
		glBegin(GL_POLYGON);
			glColor3f(0.5,0.3,0.2);
			glVertex3f(-0.9,0.9,0);
			glVertex3f(-0.9,0.5,0);
			glVertex3f(-0.5,0.9,0);
		glEnd();
	glPopMatrix();


	glPushMatrix();
		glTranslatef(-0.75,-0.05,1);
		glScalef(0.5,0.5,0);
		glBegin(GL_POLYGON);
			glColor3f(0,1,0);
			glVertex3f(0.9,0.9,0);
			glVertex3f(0.9,0.5,0);
			glVertex3f(0.5,0.9,0);
		glEnd();
	glPopMatrix();

	//jarbol


	glPushMatrix();
		glTranslatef(0,0.5,1);
		glScalef(0.2,0.2,0);
		glBegin(GL_POLYGON);
			glColor3f(5,0,1);
			glVertex3f(0.5,-0.5,0);
			glVertex3f(-0.5,-0.5,0);
			glVertex3f(-0.5,0.5,0);
			glVertex3f(0.5,0.5,0);
		glEnd();
	glPopMatrix();


	glPushMatrix();
		glTranslatef(0,0.6,1);
		glScalef(0.3,0.3,0.3);
		glColor3f(1, 0.5, 0);
    	glBegin(GL_POLYGON);
    	    glVertex3f(0, 0, 0);
    	    glVertex3f(-0.5, 0.5, 0);
    	    glVertex3f(0, 1, 0);
    	    glVertex3f(0.5, 0.5, 0);
    	glEnd();
	glPopMatrix();


	glPushMatrix();
		glTranslatef(-0.15,0.75,1);
		glScalef(0.3,0.3,0.3);
		glColor3f(0, 0.6, 0);
    	glBegin(GL_POLYGON);
    	    glVertex3f(0.5, -0.5, 0);
    	    glVertex3f(-0.5, -0.5, 0);
    	    glVertex3f(-0, 0, 0);
    	glEnd();
	glPopMatrix();
	

	glPushMatrix();
		glTranslatef(0.15,0.75,1);
		glScalef(0.3,0.3,0.3);
		glColor3f(0, 2, 1);
    	glBegin(GL_POLYGON);
    	    glVertex3f(0.5, -0.5, 0);
    	    glVertex3f(-0.5, -0.5, 0);
    	    glVertex3f(-0, 0, 0);
    	glEnd();
	glPopMatrix();
	


}
