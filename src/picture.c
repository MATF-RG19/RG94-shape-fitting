#include <GL/glut.h>
#include "functions.h"

void draw_picture_shapes(Shapes picture_array[]){
		/*Camac*/
		//Crveni kvadrat
		picture_array[0].R = 1;
		picture_array[0].G = 0;
		picture_array[0].B = 0;
		picture_array[0].x = -0.5;
		picture_array[0].y = 1;
		picture_array[0].z = 0.1;
		picture_array[0].type = 3;
		glPushMatrix();
				glTranslatef(0,0,0.1);
				glScalef(0.3,0.3,0);
				glBegin(GL_POLYGON);
					glColor3f(picture_array[0].R,picture_array[0].G,picture_array[0].B);
					glVertex3f(picture_array[0].x,picture_array[0].y,picture_array[0].z);
					glVertex3f(picture_array[0].x+1,picture_array[0].y,picture_array[0].z);
					glVertex3f(picture_array[0].x+1,picture_array[0].y+1,picture_array[0].z);
					glVertex3f(picture_array[0].x,picture_array[0].y+1,picture_array[0].z);
				glEnd();
			glPopMatrix();

		//Zeleni kvadrat
		picture_array[1].R = 0;
		picture_array[1].G = 0.7;
		picture_array[1].B = 0;
		picture_array[1].x = 0.5;
		picture_array[1].y = 1;
		picture_array[1].z = 0.1;
		picture_array[1].type = 10;
		glPushMatrix();
				glTranslatef(0,0,0.1);
				glScalef(0.3,0.3,0);
				glBegin(GL_POLYGON);
					glColor3f(picture_array[1].R,picture_array[1].G,picture_array[1].B);
					glVertex3f(picture_array[1].x,picture_array[1].y,picture_array[1].z);
					glVertex3f(picture_array[1].x+1,picture_array[1].y,picture_array[1].z);
					glVertex3f(picture_array[1].x+1,picture_array[1].y+1,picture_array[1].z);
					glVertex3f(picture_array[1].x,picture_array[1].y+1,picture_array[1].z);
				glEnd();
			glPopMatrix();

		//Plavi kvadrat
		picture_array[2].R = 0;
		picture_array[2].G = 0;
		picture_array[2].B = 1;
		picture_array[2].x = -1.5;
		picture_array[2].y = 1;
		picture_array[2].z = 0.1;
		picture_array[2].type = 1;
		glPushMatrix();
				glTranslatef(0,0,0.1);
				glScalef(0.3,0.3,0);
				glBegin(GL_POLYGON);
					glColor3f(picture_array[2].R,picture_array[2].G,picture_array[2].B);
					glVertex3f(picture_array[2].x,picture_array[2].y,picture_array[2].z);
					glVertex3f(picture_array[2].x+1,picture_array[2].y,picture_array[2].z);
					glVertex3f(picture_array[2].x+1,picture_array[2].y+1,picture_array[2].z);
					glVertex3f(picture_array[2].x,picture_array[2].y+1,picture_array[2].z);
				glEnd();
			glPopMatrix();

		//Braon trougao
		picture_array[3].R = 0.5;
		picture_array[3].G = 0.3;
		picture_array[3].B = 0.2;
		picture_array[3].x = 1.5;
		picture_array[3].y = 1;
		picture_array[3].z = 0.1;
		picture_array[3].type = 6;
		glPushMatrix();
				glTranslatef(0,0,0.1);
				glScalef(0.3,0.3,0);
				glBegin(GL_POLYGON);
					glColor3f(picture_array[3].R,picture_array[3].G,picture_array[3].B);
					glVertex3f(picture_array[3].x,picture_array[3].y,picture_array[3].z);
					glVertex3f(picture_array[3].x,picture_array[3].y+1,picture_array[3].z);
					glVertex3f(picture_array[3].x+1,picture_array[3].y+1,picture_array[3].z);
				glEnd();
			glPopMatrix();

		//Svetlo zeleni trouao
		picture_array[4].R = 0;
		picture_array[4].G = 1;
		picture_array[4].B = 0;
		picture_array[4].x = -1.5;
		picture_array[4].y = 1;
		picture_array[4].z = 0.1;
		picture_array[4].type = 2;
		glPushMatrix();
				glTranslatef(0,0,0.1);
				glScalef(0.3,0.3,0);
				glBegin(GL_POLYGON);
					glColor3f(picture_array[4].R,picture_array[4].G,picture_array[4].B);
					glVertex3f(picture_array[4].x,picture_array[4].y,picture_array[4].z);
					glVertex3f(picture_array[4].x,picture_array[4].y+1,picture_array[4].z);
					glVertex3f(picture_array[4].x-1,picture_array[4].y+1,picture_array[4].z);
				glEnd();
			glPopMatrix();

		/*Jarbol*/

		//Roze kvadrat
		picture_array[5].R = 5;
		picture_array[5].G = 0;
		picture_array[5].B = 1;
		picture_array[5].x = -0.5;
		picture_array[5].y = 2;
		picture_array[5].z = 0.1;
		picture_array[5].type = 9;
		glPushMatrix();
				glTranslatef(0,0,0.1);
				glScalef(0.3,0.3,0);
				glBegin(GL_POLYGON);
					glColor3f(picture_array[5].R,picture_array[5].G,picture_array[5].B);
					glVertex3f(picture_array[5].x,picture_array[5].y,picture_array[5].z);
					glVertex3f(picture_array[5].x+1,picture_array[5].y,picture_array[5].z);
					glVertex3f(picture_array[5].x+1,picture_array[5].y+1,picture_array[5].z);
					glVertex3f(picture_array[5].x,picture_array[5].y+1,picture_array[5].z);
				glEnd();
			glPopMatrix();

		//Narandzasti cetvorougao
		picture_array[6].R = 1;
		picture_array[6].G = 0.5;
		picture_array[6].B = 0;
		picture_array[6].x = 0;
		picture_array[6].y = 3;
		picture_array[6].z = 0.1;
		picture_array[6].type = 4;
		glPushMatrix();
				glTranslatef(0,0,0.1);
				glScalef(0.3,0.3,0);
				glBegin(GL_POLYGON);
					glColor3f(picture_array[6].R,picture_array[6].G,picture_array[6].B);
					glVertex3f(picture_array[6].x,picture_array[6].y,picture_array[6].z);
					glVertex3f(picture_array[6].x+0.75,picture_array[6].y+0.75,picture_array[6].z);
					glVertex3f(picture_array[6].x,picture_array[6].y+1.5,picture_array[6].z);
					glVertex3f(picture_array[6].x-0.75,picture_array[6].y+0.75,picture_array[6].z);
				glEnd();
			glPopMatrix();

		//Svetlo plavi trougao
		picture_array[7].R = 0;
		picture_array[7].G = 2;
		picture_array[7].B = 1;
		picture_array[7].x = 0;
		picture_array[7].y = 3;
		picture_array[7].z = 0.1;
		picture_array[7].type = 7;
		glPushMatrix();
				glTranslatef(0,0,0.1);
				glScalef(0.3,0.3,0);
				glBegin(GL_POLYGON);
					glColor3f(picture_array[7].R,picture_array[7].G,picture_array[7].B);
					glVertex3f(picture_array[7].x,picture_array[7].y,picture_array[7].z);
					glVertex3f(picture_array[7].x-0.75,picture_array[7].y+0.75,picture_array[7].z);
					glVertex3f(picture_array[7].x-1.5,picture_array[7].y,picture_array[7].z);
				glEnd();
			glPopMatrix();

		//Tamno zeleni trougao
		picture_array[8].R = 0;
		picture_array[8].G = 0.6;
		picture_array[8].B = 0;
		picture_array[8].x = 0;
		picture_array[8].y = 3;
		picture_array[8].z = 0.1;
		picture_array[8].type = 8;
		glPushMatrix();
				glTranslatef(0,0,0.1);
				glScalef(0.3,0.3,0);
				glBegin(GL_POLYGON);
					glColor3f(picture_array[8].R,picture_array[8].G,picture_array[8].B);
					glVertex3f(picture_array[8].x,picture_array[8].y,picture_array[8].z);
					glVertex3f(picture_array[8].x+0.75,picture_array[8].y+0.75,picture_array[8].z);
					glVertex3f(picture_array[8].x+1.5,picture_array[8].y,picture_array[8].z);
				glEnd();
			glPopMatrix();


}
	

