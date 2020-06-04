/*Projekat Shape fitting radjen na predmetu Racunarska grafika*/
/* ** Tamara Stojkovic 178/2017** */
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#include "functions.h"
#include "image.h"

#define TIMER_INTERVAL 10
#define TIMER_ID 0


static float animation_parameter =0;
static float animation_ongoing =0;

/*Niz objekata na traci*/
Shapes shapes_array[100];
/*Niz objekata na slici*/
Shapes picture_array[9];

float niz[3];

int mouse_x;//x koordinata misa
int mouse_y;//y koordinata misa
//x i y koordinate misa na bilo kom ekranu(racunaru)
int x, y;

//promenljiva koja cuva tekuci broj poena 
int points=0;


int main(int argc, char ** argv){

	//na pocetku ni jedan oblik nije selektovan, ni uklopljen
	selector_active = 0;
	shape_placed = 0;

	/*Inicijalizacija objekata na traci*/
	srand(time(NULL));//postavlja seme
	for(int i=0; i<100; i++){
		//na pocetku se svi oblici iscrtavaju i krecu
		shapes_array[i].should_move = true;
		shapes_array[i].should_draw = true;
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

	
	//Ukljucivanje tekstura koje koristim
	 include_textures();


	/*Funkcije za obradu dogadjaja*/
	
	glutDisplayFunc(draw_start_screen);
	glutReshapeFunc(on_reshape);
	glutKeyboardFunc(on_keyboard);
	glutKeyboardUpFunc(on_upKeyboard);
	glutMouseFunc(on_click);
	glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);
	

	
	/*OpenGL inicijalizacije*/
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH);

	glutFullScreen();

	/*Postavljanje boje pozadine*/
	glClearColor(0.7,0.8,0.8,0.2);
	
	/*Podesavanje komponenata osvetljenja*/
	//Komponente uzete sa casa vezbi i postavljeni odgovarajuci parametri za ovaj projekat

	//Pozicija svetla(direkcionalno svtelo)
	GLfloat light_position[] = {0 ,0, 0, 0};
	//Ambijentalna boja svetla
    GLfloat light_ambient[] = { 0.8, 0.8, 0.8, 0.1 };
	//Difuzna boja svetla
   	GLfloat light_diffuse[] = { 1, 1, 1, 1 };
	//Spekularna boja svetla
  	GLfloat light_specular[] = { 0.6, 0.6, 0.6, 1 };

 	/*Podesavanje komponenata materijala*/

	//Koeficijent ambijentalne refleksije materijala
	GLfloat ambient_coeffs[] = { 0.9, 0.9, 0.9, 0.1 };
	//Koeficijent difuzne refleksije materijala
    GLfloat diffuse_coeffs[] = { 0.8, 0.8, 0.8, 0.1 };
	//Koeficijent glatkosti materijala
   	GLfloat shininess = 20;
	
	//Ukljucivanje odgovarajucih, prethodno definisanih  komponenata
	glEnable(GL_LIGHTING);
    	glEnable(GL_LIGHT0);
    	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
   		glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

    	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs);
    	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs);
        glMaterialf(GL_FRONT, GL_SHININESS, shininess);
	


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


void on_display(void){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	
	/*Podesavanje pozicije kamere*/
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(
            0, 0, 3,
            0, 0, 0,
            0, 1, 0
        );


	//Podesavanje tekstura(fajlovi za  inicijalizaciju tekstura sa casova vezbi)*/
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	//Podesava se tekstura zida
	glBindTexture(GL_TEXTURE_2D, names[2]);
	glBegin(GL_QUADS);
	glNormal3f(0, 0, 1);


	    glTexCoord2f(0, 0);
    	glVertex3f(-6, -0.15 , 0);

    	glTexCoord2f(1, 0);
    	glVertex3f(6, -0.15, 0);

    	glTexCoord2f(1, 1);
    	glVertex3f(6, 3, 0);

    	glTexCoord2f(0, 1);
    	glVertex3f(-6, 3, 0);
    	glEnd();

		

	//Podesava se tekstura poda
	glBindTexture(GL_TEXTURE_2D, names[3]);
	glBegin(GL_QUADS);
	glNormal3f(0, 0, 1);


	    glTexCoord2f(0, 0);
    	glVertex3f(-6, -3, 1);

    	glTexCoord2f(1, 0);
    	glVertex3f(6, -3, 1);

    	glTexCoord2f(1, 1);
		glVertex3f(6, 0, -1);
    
		glTexCoord2f(0, 1);
		glVertex3f(-6, 0 ,-1);
    	glEnd();



	//Postavljanje vrata na zid
	glBindTexture(GL_TEXTURE_2D, names[0]);
    glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);

        glTexCoord2f(0, 0);
        glVertex3f(-3, -0.15, 0.01);

        glTexCoord2f(1, 0);
        glVertex3f(-2, -0.15, 0.01);

        glTexCoord2f(1, 1);
        glVertex3f(-2, 1.7, 0.01);

        glTexCoord2f(0, 1);
        glVertex3f(-3, 1.7, 0.01);
    glEnd();
	
	
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);


	/*Iscrtavanje objekata*/
	
	draw_picture_shapes(picture_array);
	draw_picture();

    /*Animacija kretanja objekata na traci*/
	glPushMatrix();
		move_shapes(-animation_parameter, 0, 0, shapes_array);
		draw_shapes(shapes_array);
	glPopMatrix();


    draw_path();
    /*Zbog postavljenje teksture poda*/
	//draw_floor();
	
	if(selector_active == 1){//Ispis aktivnosti selektora
		printf("Select\n");
	}

	/*Ispisivanje poena na ekranu*/
	glDisable(GL_LIGHTING);
	draw_text();
	glEnable(GL_LIGHTING);
	
	//draw_coordinate_system();



	glutSwapBuffers();
}


void on_keyboard(unsigned char key, int x, int  y){

	switch(key){
		case 'r':
		case 'R':
			//Resetovanje svega
	    	selector_active = 0;
	    	shape_placed = 0;

	    	for(int i=0; i<100; i++){
		    	shapes_array[i].should_move = true;
		    	shapes_array[i].should_draw = true;
		    	shapes_array[i].R = (rand()%100)/100.0;
		    	shapes_array[i].G = (rand()%100)/100.0;
		    	shapes_array[i].B = (rand()%100)/100.0;
		    	shapes_array[i].x = -0.9 + i*2;
		    	shapes_array[i].y = -2.3;
		    	shapes_array[i].z = 1;
		    	shapes_array[i].type = rand()%12;
	    	}
				animation_parameter = 0;
				points = 0;
				animation_ongoing=1;
				glutTimerFunc(TIMER_INTERVAL,on_timer,TIMER_ID);
	   		break;

		case 's':
		case 'S':
			animation_ongoing = 0;
			break;

		case 'g':
		case 'G':
			if(!animation_ongoing){
				
				glutDisplayFunc(on_display);
				for(int i=0; i<100; i++){
				shapes_array[i].should_move = true;
				shapes_array[i].should_draw = true;

				}
				
				animation_ongoing = 1;	
				glutTimerFunc(TIMER_INTERVAL,on_timer,TIMER_ID);

			}
			break;

		case ' ':
			selector_active++; //samo kad je 0 povecava se-kad je neaktivan
			shape_select(shapes_array);
			break;
		case 27:
			exit(0);
			break;
	}

}


void on_upKeyboard(unsigned char key, int x, int y){

    switch(key){

        case ' ':{
            selector_active = 0;
        }
       
  }

}

/* Napomene: 1) rad funkcije za klik misa sa sajta  https://www.opengl.org/resources/libraries/glut/spec3/node50.html
			 2)izvrseno izracunavanje x,y odgovarajucih koordinata- kako bi projekat radio za bilo koji ekran
			 3)korsicene matematicke formule za odredjivanje opsega oblika, kao i proporcija izracunavanja x i y */

void on_click(int button, int state, int mouse_x, int mouse_y){


	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		printf("Kliknuto: %d %d\n", mouse_x, mouse_y);
		//Racunanje koordinata misa za proizvoljni ekran
		//x=calculate_x(mouse_x, window_width);
		//y=calculate_y(mouse_y, window_height);
		x=mouse_x;
		y=mouse_y;
		printf("x:%d, y: %d\n",x,y);
		//printf("Sirina: %d visina: %d\n", window_width, window_height);

		//Sada odredjujem na osnovu klika misa(opsega oblika), koji je oblik izabran
		//plavi kvadrat-indikator 1
		if(x>=coordinate_x(592) && x<=coordinate_x(650) && y<=coordinate_y(270) && y>=coordinate_y(215)){
			if(active_shape.type==1){
				points+=10;
			}
			else{
				points-=10;
				
			}			


		}
		//crveni kvadrat-indikator 3
		if(x>=coordinate_x(650) && x<=coordinate_x(710) && y<=coordinate_y(270) && y>=coordinate_y(215)){
			if(active_shape.type==3){
				points+=10;
			}
			else{
				points-=10;
				
			}			


		}
		//zeleni kvadrat-indikator 10
		if(x>=coordinate_x(710) && x<=coordinate_x(770) && y<=coordinate_y(270) && y>=coordinate_y(215)){
			if(active_shape.type==10){
				points+=10;
			}
			else{
				points-=10;
				
			}			


		}
		//roze kvadrat-indikator 9
		if(x>=coordinate_x(650) && x<=coordinate_x(708) && y<=coordinate_y(215) && y>=coordinate_y(155)){
			if(active_shape.type==9){
				points+=10;
			}
			else{
				points-=10;
				
			}			


		}
		//svetlo plavi trougao-indikator 7
		if((x>=coordinate_x(592) && x<=coordinate_x(636) && y<=coordinate_y(154) &&  										   				y>= coordinate_y(154)-(x+coordinate_x(592))) || (x>=coordinate_x(636) && x<=coordinate_x(680) 
			&& y<=coordinate_y(154) && y>=coordinate_y(154)-(coordinate_x(680)-x))){
			
			if(active_shape.type==7){
				points+=10;
			}
			else{
				points-=10;
				
			}			


		}

		//tamno zeleni trougao-indikator 8
		if((x>=coordinate_x(683) && x<=coordinate_x(726) && y<=coordinate_y(154) &&											 				y>=(coordinate_y(154)-(x-coordinate_x(683)))) || (x>=coordinate_x(726) && x<=coordinate_x(768)						
			&& y<=coordinate_y(154) && y>=(coordinate_y(154)-(coordinate_x(768)+x)))){
			
			if(active_shape.type==8){
				points+=10;
			}
			else{
				points-=10;
				
			}			


		}
		//zeleni trougao-indikator 2
		if(x>=coordinate_x(531) && x<=coordinate_x(591) && y>=coordinate_y(215) && 											 	         y<=(coordinate_y(215)+(x+coordinate_x(531)))){
			if(active_shape.type==2){
				points+=10;
			}
			else{
				points-=10;
				
			}

		}
		//braon trougao-indikator 6
		if(x>=coordinate_x(771) && x<=coordinate_x(826) && y>=coordinate_y(215) &&
		        y<=(coordinate_y(215)+(coordinate_x(826)+x))){
			if(active_shape.type==6){
				points+=10;
			}
			else{
				points-=10;
				
			}

		}
		//narandzasti cetvorougao-indikator 4
		if((x>=coordinate_x(638) && x<=coordinate_x(680) && y<=coordinate_y(110) && y>= coordinate_y(110)-(x-coordinate_x(638)))
		||(x>=coordinate_x(680) && x<=coordinate_x(724) && y<=coordinate_y(110) && y>= coordinate_y(110)-(coordinate_x(724)-x)) 		||(x>=coordinate_x(638) && x<=coordinate_x(680) && y>=coordinate_y(110) && y<=(coordinate_y(110)+(x-coordinate_x(638))))
		||(x>=coordinate_x(680) && x<=coordinate_x(724) && y>=coordinate_y(110) && y<=coordinate_y(110)+(coordinate_x(724)-x)))
		{
			
			if(active_shape.type==4){
				points+=10;
			}
			else{
				points-=10;
				
			}			


		}
		
		
		
		printf("points:%d\n",points);

		for(int i=0; i<100; i++){
                	if(!shapes_array[i].should_move){//kad kliknem misem da mi nestane  oblik sa trake(uklopljeni)
                		shapes_array[i].should_draw = false;
                	}
                }
        if(shape_placed == 1){//ako postoji objekat koji nije postavljen onda na klik postavi
        	shape_placed = 0;
        	printf("shape type:%d\n", active_shape.type);

        }

	}

}

void on_reshape(int width, int height){
	/*Podesavanje sirine i visine*/
	window_width=width;
	window_height=height;

	glViewport(0, 0, window_width, window_height);


	/*Podesavanje projekcije*/
	glMatrixMode(GL_PROJECTION);
    	glLoadIdentity();
    	gluPerspective(
            60,
            window_width/(float)window_height,
            1, 50);


}

void on_timer(int id){
	if(id==TIMER_ID){
		animation_parameter = 0.03;

	}
	glutPostRedisplay();
	if(animation_ongoing){
		glutTimerFunc(TIMER_INTERVAL,on_timer,TIMER_ID);
	
	}
	
	/*Ako su poeni manji ili jednaki 50-gameover ekran*/
	/*Na g moguce ponovo pokretanje igrice*/
	if(points <= -50){
		for(int i=0; i<100; i++){
		    shapes_array[i].should_move = true;
		    shapes_array[i].should_draw = true;
		    shapes_array[i].R = (rand()%100)/100.0;
		    shapes_array[i].G = (rand()%100)/100.0;
		    shapes_array[i].B = (rand()%100)/100.0;
		    shapes_array[i].x = -0.9 + i*2;
		    shapes_array[i].y = -2.3;
		    shapes_array[i].z = 1;
		    shapes_array[i].type = rand()%12;
	    }
	    animation_ongoing=0;
	    animation_parameter = 0;
	    points = 0;
	    selector_active = 0;
	    shape_placed = 0;
		glutDisplayFunc(draw_end_screen);
	}

	/*Uslov pobede(zavrsetka igrice) je ostvariti bar 150 poena */
	if(points >= 150)
		glutDisplayFunc(draw_win_screen);

	
}



//funkcije koje prevodi koordinate misa na mom ekranu, u koordinate na bilo kom drugom ekranu(sa bilo kojom sirinom/visinom)
int calculate_x(int mouse_x, int window_width){
	x=(int)window_width*mouse_x/1360;

	return x;
}

int calculate_y( int mouse_y, int window_height){

	y=(int)window_height*mouse_y/663;


	return y;
}

//x:p=window_width:1360
int coordinate_x(int p){
	int first=(int)window_width*p/1360;
	return first;
}

int coordinate_y(int q){
	int second=(int)window_height*q/663;
	return second;
	
}

/*Funkacija koja ispisuje poene na ekranu*/
void draw_text(){
	char points_str[50];
	glColor3f(0,0,0);

	//Menjanje projekcije na ortografsku, postavljanje ravni na velicinu ekrana
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0, window_width,0, window_height);
		
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
			glLoadIdentity();
	//Ispisivanje skora na ekranu
		glPushMatrix();
		glRasterPos2f(window_width-200,window_height-70);
		sprintf(points_str,"POINTS: %d",points);
		int length=strlen(points_str);
		for(int i=0; i<length; i++){
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,points_str[i]);
		}

	
	/*Postavljanje teksture za poene*/
	glEnable(GL_TEXTURE_2D);

      	glBindTexture(GL_TEXTURE_2D, names[1]);  
    

      	glBegin(GL_QUADS);
        	glTexCoord2f(0, 0);
        	glVertex2f(window_width-230,window_height-100);

        	glTexCoord2f(0, 1);
        	glVertex2f(window_width-230,window_height-20);

        	glTexCoord2f(1, 1);
        	glVertex2f(window_width-50,window_height-20);

        	glTexCoord2f(1, 0);
        	glVertex2f(window_width-50,window_height-100);
      glEnd();
      

   	glPopMatrix();

    glMatrixMode(GL_PROJECTION);    
  	glPopMatrix();

	glMatrixMode(GL_MODELVIEW);


		
}
/*Iscrtavanje pocetnog ekrana*/
 void draw_start_screen(){
                                                                                                                                         
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, names[5]);

    glMatrixMode(GL_PROJECTION);
	glPushMatrix();
    glLoadIdentity();
  
		gluOrtho2D(0, window_width,0, window_height);
		
		glMatrixMode(GL_MODELVIEW);
  		glLoadIdentity();

		glBegin(GL_QUADS);
			glTexCoord2f(0, 0);
			glVertex2f(0,0);

			glTexCoord2f(0, 1);
			glVertex2f(0, window_height);

			glTexCoord2f(1, 1);
			glVertex2f(window_width,window_height);

			glTexCoord2f(1, 0);
			glVertex2f(window_width,0);
		glEnd();
		
		glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	
	glMatrixMode(GL_MODELVIEW);

	glDisable(GL_TEXTURE_2D);

    glutSwapBuffers();

}

/*Iscrtavanje ekrana za kraj igre(gameover)*/
void draw_end_screen(){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, names[4]);

    glMatrixMode(GL_PROJECTION);
	glPushMatrix();
    glLoadIdentity();
  
		gluOrtho2D(0, window_width,0, window_height);
		
		glMatrixMode(GL_MODELVIEW);
  		glLoadIdentity();

		glBegin(GL_QUADS);
			glTexCoord2f(0, 0);
			glVertex2f(0,0);

			glTexCoord2f(0, 1);
			glVertex2f(0, window_height);

			glTexCoord2f(1, 1);
			glVertex2f(window_width,window_height);

			glTexCoord2f(1, 0);
			glVertex2f(window_width,0);
		glEnd();
		
		glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	
	glMatrixMode(GL_MODELVIEW);

	glDisable(GL_TEXTURE_2D);

    glutSwapBuffers();

}



/*Iscrtavanje ekrana za pobedu*/
void draw_win_screen() {

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 

  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, names[6]);
  glMatrixMode(GL_PROJECTION);

  glPushMatrix();
	  glLoadIdentity();
	  gluOrtho2D(0, window_width,0, window_height);
	    
	  glMatrixMode(GL_MODELVIEW);
	  glLoadIdentity();

	  glBegin(GL_QUADS);
		  glTexCoord2f(0, 0);
		  glVertex2f(0,0);

		  glTexCoord2f(0, 1);
		  glVertex2f(0, window_height);

		  glTexCoord2f(1, 1);
		  glVertex2f(window_width,window_height);

		  glTexCoord2f(1, 0);
		  glVertex2f(window_width,0);
	  glEnd();
	    
	  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  
  glMatrixMode(GL_MODELVIEW);

  

  glutSwapBuffers();

}

//vektor normale se mora normalizovati(jedinicni)
void normalize(float niz[3]){
    float length = sqrt(niz[1]*niz[1] + niz[2]*niz[2] + niz[3]*niz[3]);
    
    niz[1]=niz[1]/length;
    niz[2]=niz[2]/length;
    niz[3]=niz[3]/length;
    
    
}

//formula za vektorski proizvod dva vektora
float * cross_product(float a0, float a1, float a2, float b0, float b1, float b2){
    
    float x1,x2,x3;
    x1=a1*b2 - a2*b1;
    x2=a2*b1 - a0*b2;
    x3=a0*b1 - a1*b0;
    
    
    
    niz[0]=x1;
    niz[1]=x2;
    niz[3]=x3;
    
    
    return niz;
    
}

//na osnovu vektorskog proizvoda dva vektora dobicemo vektor normale
float* calculate_normal(float a[3], float b[3], float c[3]){
    float x[3];
    x[0]=b[0]-a[0];
    x[1]=b[1]-a[1];
    x[2]=b[2]-a[2];
    
    
    float y[3];
    y[0]=c[0]-a[0];
    y[1]=c[1]-a[1];
    y[2]=c[2]-a[2];
    
    float *result=cross_product(x[0],x[1],x[2],y[0],y[1],y[2]);
    
     normalize(result);
    
    return result;
    
    
    
}







