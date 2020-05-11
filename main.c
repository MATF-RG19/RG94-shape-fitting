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

int mouse_x;//x koordinata misa
int mouse_y;//y koordinata misa
//x i y koordinate misa na bilo kom ekranu(racunaru)
int x, y;

//promenljiva koja cuva tekuci broj poena 
int poeni=0;



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

	/*Funkcije za obradu dogadjaja*/
	glutDisplayFunc(on_display);
	glutKeyboardFunc(on_keyboard);
	glutKeyboardUpFunc(on_upKeyboard);
	glutReshapeFunc(on_reshape);
	glutMouseFunc(on_click);
	glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);


	
	/*OpenGL inicijalizacije*/
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);

	glutFullScreen();

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

	glViewport(0, 0, window_width, window_height);


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

	/*Podesavanje komponenata osvetljenja*/

	//Pozicija svetla(direkcionalno svtelo)
	GLfloat light_position[] = { 0, 0, 0, 0 };
	//Ambijentalna boja svetla
    	GLfloat light_ambient[] = { 0.8, 0.8, 0.8, 0.1 };
	//Difuzna boja svetla
    	GLfloat light_diffuse[] = { 0.8, 0.8, 0.8, 1 };
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
	
	if(selector_active == 1){
		printf("Select\n");
	}

	/*Ispisivanje poena na ekranu*/
	glDisable(GL_LIGHTING);
	draw_text();
	glEnable(GL_LIGHTING);
	
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

void on_click(int button, int state, int mouse_x, int mouse_y){


	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		printf("Kliknuto: %d %d\n", mouse_x, mouse_y);
		//Racunanje koordinata misa za proizvoljni ekran
		x=calculate_x(mouse_x, window_width);
		y=calculate_y(mouse_y, window_height);
		printf("x:%d, y: %d\n",x,y);
		//printf("Sirina: %d visina: %d\n", window_width, window_height);

		//Sada odredjujem na osnovu klika misa(opsega oblika), koji je oblik izabran
		//plavi kvadrat-indikator 1
		if(x>=592 && x<=650 && y<=270 && y>=215){
			if(active_shape.type==1){
				poeni+=10;
			}
			else{
				poeni-=10;
				
			}			


		}
		//crveni kvadrat-indikator 3
		if(x>=650 && x<=710 && y<=270 && y>=215){
			if(active_shape.type==3){
				poeni+=10;
			}
			else{
				poeni-=10;
				
			}			


		}
		//zeleni kvadrat-indikator 10
		if(x>=710 && x<=770 && y<=270 && y>=215){
			if(active_shape.type==10){
				poeni+=10;
			}
			else{
				poeni-=10;
				
			}			


		}
		//roze kvadrat-indikator 9
		if(x>=650 && x<=708 && y<=215 && y>=155){
			if(active_shape.type==9){
				poeni+=10;
			}
			else{
				poeni-=10;
				
			}			


		}
		//svetlo plavi trougao-indikator 7
		if((x>=592 && x<=636 && y<=154 && y>=154-(x-592)) || (x>=636 && x<=680 && y<=154 && y>=154-(680-x))){
			
			if(active_shape.type==7){
				poeni+=10;
			}
			else{
				poeni-=10;
				
			}			


		}

		//tamno zeleni trougao-indikator 8
		if((x>=683 && x<=726 && y<=154 && y>=(154-(x-683))) || (x>=726 && x<=768 && y<=154 && y>=(154-(768-x)))){
			
			if(active_shape.type==8){
				poeni+=10;
			}
			else{
				poeni-=10;
				
			}			


		}
		//zeleni trougao-indikator 2
		if(x>=531 && x<=591 && y>=215 && y<=(215+(x-531))){
			if(active_shape.type==2){
				poeni+=10;
			}
			else{
				poeni-=10;
				
			}

		}
		//braon trougao-indikator 6
		if(x>=771 && x<=826 && y>=215 && y<=(215+(826-x))){
			if(active_shape.type==6){
				poeni+=10;
			}
			else{
				poeni-=10;
				
			}

		}
		//narandzasti cetvorougao-indikator 4
		if((x>=638 && x<=680 && y<=110 && y>=110-(x-638))|| (x>=680 && x<=724 && y<=110 && y>=110-(724-x))||(x>=638 && 				x<=680 && y>=110 && y<=(110+(x-638))) || ( x>=680 && x<=724 && y>=110 && y<=(110+(724-x) )) ){
			
			if(active_shape.type==4){
				poeni+=10;
			}
			else{
				poeni-=10;
				
			}			


		}
		
		
		
		printf("poeni:%d\n",poeni);

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


}

void on_timer(int id){
	if(id==TIMER_ID){
		animation_parameter = 0.03;

	}
	glutPostRedisplay();
	if(animation_ongoing)
		glutTimerFunc(TIMER_INTERVAL,on_timer,TIMER_ID);
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
			glRasterPos2f(70, window_height-50);
		sprintf(points_str,"POINTS: %d",poeni);
		int length=strlen(points_str);
		for(int i=0; i<length; i++){
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,points_str[i]);
		}
		glPopMatrix();

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
		glMatrixMode(GL_MODELVIEW);
		
		
}




