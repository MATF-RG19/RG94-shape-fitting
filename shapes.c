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
	glScalef(7.5,0.15,1);
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
	glPushMatrix();
		glScalef(2.2,1.5,0.2);
		glLineWidth(20);
		glTranslatef(0,0.55,0);
		glColor3f(0.52,0.37,0.26);
		glutWireCube(1);
		//glColor3f(0.91,0.76,0.65);
		//glutSolidCube(1);
	glPopMatrix();
	glEnable(GL_TEXTURE_2D);

      /* Tekstura za postavljanje slike u ram*/
     
    glBindTexture(GL_TEXTURE_2D, names[7]);
    glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);

        glTexCoord2f(0, 0);
        glVertex3f(-1.13, 0.08, 0.05);

        glTexCoord2f(1, 0);
        glVertex3f(1.13, 0.08, 0.05);

        glTexCoord2f(1, 1);
        glVertex3f(1.13, 1.6, 0.05);

        glTexCoord2f(0, 1);
        glVertex3f(-1.13, 1.6, 0.05);
    glEnd();

    /* Iskljucujemo aktivnu teksturu */
    glBindTexture(GL_TEXTURE_2D, 0);

    glPopMatrix();

 

	
}

/*Funkcija koja vrsi pomeranje objekata na traci za prosledjene vrednosti*/
void move_shapes(double x, double y, double z, Shapes shapes_array[]){

	for(int i=0; i<100; i++){
		if(shapes_array[i].should_move){//ako oblik treba da se krece
			shapes_array[i].x += x;
			shapes_array[i].y += y;
			shapes_array[i].z += z;
		}
	}

}

/*Funkcija koja iscrtava oblike koji su na traci*/
void draw_shapes(Shapes shapes_array[]){

	if(selector_active){//ako je aktivan selektor je crveni
		glColor3f(1,0,0);
	}
	else{ //beo inace
		glColor3f(1,1,1);
	}
	//Iscrtavanje selektora oblika na traci
	glPushMatrix();
		glLineWidth(5.0);
		glBegin(GL_LINES);
			glVertex3f(0,-0.7,0);
			glVertex3f(0,-0.2,0);

			glVertex3f(0,-0.2,0);
			glVertex3f(0.5,-0.2,0);

			glVertex3f(0.5,-0.2,0);
			glVertex3f(0.5,-0.7,0);
			
			glVertex3f(0.5,-0.7,0);
			glVertex3f(0,-0.7,0);
		glEnd();

	glPopMatrix();
	
	for(int i=0; i<100; i++){
		
		if(!shapes_array[i].should_draw)//ako ne treba da crtam oblik,nastavi 
			continue;

		glPushMatrix();
		//Crveni trougao
		if(shapes_array[i].type == 0){ 
			glPushMatrix();
				glScalef(0.3,0.3,0);
				glBegin(GL_POLYGON);
					glColor3f(1,0,0);
					glVertex3f(shapes_array[i].x,shapes_array[i].y,shapes_array[i].z);
					glVertex3f(shapes_array[i].x+1,shapes_array[i].y,shapes_array[i].z);
					glVertex3f(shapes_array[i].x+1,shapes_array[i].y+1,shapes_array[i].z);
				glEnd();
			glPopMatrix();
		}
		else if(shapes_array[i].type == 1){//Plavi kvadrat
			glPushMatrix();
				glScalef(0.3,0.3,0);
				glBegin(GL_POLYGON);
					glColor3f(0,0,1);
					glVertex3f(shapes_array[i].x,shapes_array[i].y,shapes_array[i].z);
					glVertex3f(shapes_array[i].x+1,shapes_array[i].y,shapes_array[i].z);
					glVertex3f(shapes_array[i].x+1,shapes_array[i].y+1,shapes_array[i].z);
					glVertex3f(shapes_array[i].x,shapes_array[i].y+1,shapes_array[i].z);
				glEnd();
			glPopMatrix();
		}
		else if(shapes_array[i].type == 2){//Zeleni trougao
			glPushMatrix();
			glScalef(0.3,0.3,0);
			glTranslatef(1,0,0);
				glBegin(GL_POLYGON);
					glColor3f(0,1,0);
					glVertex3f(shapes_array[i].x,shapes_array[i].y,shapes_array[i].z);
					glVertex3f(shapes_array[i].x,shapes_array[i].y+1,shapes_array[i].z);
					glVertex3f(shapes_array[i].x-1,shapes_array[i].y+1,shapes_array[i].z);
				glEnd();
			glPopMatrix();
		}
		else if(shapes_array[i].type == 3){//Crveni kvadrat
			glPushMatrix();
				glScalef(0.3,0.3,0);
				glBegin(GL_POLYGON);
					glColor3f(1,0,0);
					glVertex3f(shapes_array[i].x,shapes_array[i].y,shapes_array[i].z);
					glVertex3f(shapes_array[i].x+1,shapes_array[i].y,shapes_array[i].z);
					glVertex3f(shapes_array[i].x+1,shapes_array[i].y+1,shapes_array[i].z);
					glVertex3f(shapes_array[i].x,shapes_array[i].y+1,shapes_array[i].z);
				glEnd();
			glPopMatrix();
		}
		else if(shapes_array[i].type == 4){//Narandzasti cetvorougao
			glPushMatrix();
				glTranslatef(0.15,0,0);
				glScalef(0.3,0.3,0);
				glBegin(GL_POLYGON);
					glColor3f(1,0.5,0);
					glVertex3f(shapes_array[i].x,shapes_array[i].y,shapes_array[i].z);
					glVertex3f(shapes_array[i].x+0.75,shapes_array[i].y+0.75,shapes_array[i].z);
					glVertex3f(shapes_array[i].x,shapes_array[i].y+1.5,shapes_array[i].z);
					glVertex3f(shapes_array[i].x-0.75,shapes_array[i].y+0.75,shapes_array[i].z);
				glEnd();
			glPopMatrix();
		}
		else if(shapes_array[i].type == 5){ //Roze trougao
			glPushMatrix();
				glScalef(0.3,0.3,0);
				glBegin(GL_POLYGON);
					glColor3f(5,0,1);
					glVertex3f(shapes_array[i].x,shapes_array[i].y,shapes_array[i].z);
					glVertex3f(shapes_array[i].x+1,shapes_array[i].y,shapes_array[i].z);
					glVertex3f(shapes_array[i].x,shapes_array[i].y+1,shapes_array[i].z);
				glEnd();
			glPopMatrix();
		}
		else if(shapes_array[i].type == 6){//Braon trougao
			glPushMatrix();
			glScalef(0.3,0.3,0);
				glBegin(GL_POLYGON);
					glColor3f(0.5,0.3,0.2);
					glVertex3f(shapes_array[i].x,shapes_array[i].y,shapes_array[i].z);
					glVertex3f(shapes_array[i].x,shapes_array[i].y+1,shapes_array[i].z);
					glVertex3f(shapes_array[i].x+1,shapes_array[i].y+1,shapes_array[i].z);
				glEnd();
			glPopMatrix();
		}
		else if(shapes_array[i].type == 7){//Svetlo plavi trougao
			glPushMatrix();
			glTranslatef(-0.05,0,0);
			glScalef(0.3,0.3,0);
				glBegin(GL_POLYGON);
					glColor3f(0,2,1);
					glVertex3f(shapes_array[i].x,shapes_array[i].y,shapes_array[i].z);
					glVertex3f(shapes_array[i].x+1.5,shapes_array[i].y,shapes_array[i].z);
					glVertex3f(shapes_array[i].x+0.75,shapes_array[i].y+0.75,shapes_array[i].z);
				glEnd();
			glPopMatrix();
		}
		else if(shapes_array[i].type == 8){//Tamno zeleni trougao
			glPushMatrix();
			glTranslatef(-0.05,0,0);
			glScalef(0.3,0.3,0);
				glBegin(GL_POLYGON);
					glColor3f(0,0.6,0);
					glVertex3f(shapes_array[i].x,shapes_array[i].y,shapes_array[i].z);
					glVertex3f(shapes_array[i].x+1.5,shapes_array[i].y,shapes_array[i].z);
					glVertex3f(shapes_array[i].x+0.75,shapes_array[i].y+0.75,shapes_array[i].z);
				glEnd();
			glPopMatrix();
		}
		else if(shapes_array[i].type == 9){//Roze kvadrat
			glPushMatrix();
				glScalef(0.3,0.3,0);
				glBegin(GL_POLYGON);
					glColor3f(5,0,1);
					glVertex3f(shapes_array[i].x,shapes_array[i].y,shapes_array[i].z);
					glVertex3f(shapes_array[i].x+1,shapes_array[i].y,shapes_array[i].z);
					glVertex3f(shapes_array[i].x+1,shapes_array[i].y+1,shapes_array[i].z);
					glVertex3f(shapes_array[i].x,shapes_array[i].y+1,shapes_array[i].z);
				glEnd();
			glPopMatrix();
		}
		else if(shapes_array[i].type == 10){//Zeleni kvadrat
			glPushMatrix();
				glScalef(0.3,0.3,0);
				glBegin(GL_POLYGON);
					glColor3f(0,0.7,0);
					glVertex3f(shapes_array[i].x,shapes_array[i].y,shapes_array[i].z);
					glVertex3f(shapes_array[i].x+1,shapes_array[i].y,shapes_array[i].z);
					glVertex3f(shapes_array[i].x+1,shapes_array[i].y+1,shapes_array[i].z);
					glVertex3f(shapes_array[i].x,shapes_array[i].y+1,shapes_array[i].z);
				glEnd();
			glPopMatrix();
		}
		else {//Kvadrat proizvoljne boje
			glPushMatrix();
			glScalef(0.3,0.3,0);
				glBegin(GL_POLYGON);
					glColor3f(shapes_array[i].R,shapes_array[i].G,shapes_array[i].B);
					glVertex3f(shapes_array[i].x,shapes_array[i].y,shapes_array[i].z);
					glVertex3f(shapes_array[i].x+1,shapes_array[i].y,shapes_array[i].z);
					glVertex3f(shapes_array[i].x+1,shapes_array[i].y+1,shapes_array[i].z);
					glVertex3f(shapes_array[i].x,shapes_array[i].y+1,shapes_array[i].z);
				glEnd();
			glPopMatrix();
		}
		
		glPopMatrix();

	
	}
}
//oznacava 1 objekat iz niza
void shape_select(Shapes shapes_array[]){

	double min_distance_from_selector=100000000.0;//neko proizvoljno min rastojanje
	int shape_index = -1;// na pocetku indeks
	for(int i=0; i<100; i++){//trazim onaj koji  je najblizi selektor kvadratu(u odnosu na levu ivicu)
		//trebalo bi da bude oblik - x koordinata leve ivice ali je leva ivica na koordinati 0
		if(abs(shapes_array[i].x) < min_distance_from_selector && shapes_array[i].should_move
			&& abs(shapes_array[i].x) < 0.5){
			//azuriram oblik sa min rastojanje i indeks oblika
			min_distance_from_selector = abs(shapes_array[i].x);
			shape_index = i;
		}
	}

	if(shape_placed == 0){
		shapes_array[shape_index].should_move = false;//zaustavim taj koji sam nasla
		shape_placed = 1;//ako nisam postavila oblik- oznacim ga
		active_shape = shapes_array[shape_index];//trenutni zaustavljeni oblik(selektovani)
	}


}	

