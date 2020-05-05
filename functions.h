#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

/*Struktura koja cuva podatke o pojedinacnim oblicima*/
typedef struct Shape{

	double x,y,z; //koordinate polozaja oblika
	double R,G,B; //parametri boje oblika
	int type;   //tip oblika

}Shapes;



/*Deklaracije callback funkcija-premestene ovde*/
extern void on_display(void);
extern void on_reshape(int width, int height);
extern void on_keyboard(unsigned char key, int x, int y);
extern void on_timer(int id);


extern void draw_picture_shapes(Shapes picture_array[]);
extern void draw_floor();
extern void draw_path();
extern void draw_picture();
extern void draw_shapes(Shapes shapes_array[]);
void move_shapes(double x, double y, double z, Shapes shapes_array[]);
 
int window_width, window_height;

#endif

