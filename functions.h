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
	bool should_move;//svi objekti se pomeraju na pocetku, a stopira se odabrani
	bool should_draw;//svi se iscrtavaju, a kad klikem misem taj objekat se dalje preskace

}Shapes;

int selector_active;//povecava se za 1 kad kliknem space
int shape_placed;//uklopljen oblik
Shapes active_shape;//cuva tekuci aktivan oblik



/*Deklaracije callback funkcija-premestene ovde*/
extern void on_display(void);
extern void on_reshape(int width, int height);
extern void on_keyboard(unsigned char key, int x, int y);
extern void on_upKeyboard(unsigned char key, int x, int y);
extern void on_timer(int id);
extern void glutMouseFunc(void (*func)(int button, int state, int x, int y));
extern void on_click(int button, int state, int x, int y);
extern int calculate_x( int mouse_x, int window_width);
extern int calculate_y( int mouse_y, int window_height);

extern void draw_text();
extern void draw_picture_shapes(Shapes picture_array[]);
extern void draw_floor();
extern void draw_path();
extern void draw_picture();
extern void draw_shapes(Shapes shapes_array[]);
void move_shapes(double x, double y, double z, Shapes shapes_array[]);
extern void shape_select(Shapes shapes_array[]);
 
int window_width, window_height;

#endif

