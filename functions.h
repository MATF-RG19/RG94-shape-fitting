#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

/*Slike za teksture*/
#define FILENAME0 "Textures/door.bmp"
#define FILENAME1 "Textures/points.bmp"
#define FILENAME2 "Textures/wall.bmp"
#define FILENAME3 "Textures/floor.bmp"
#define FILENAME4 "Textures/gameover.bmp"
#define FILENAME5 "Textures/start.bmp"
#define FILENAME6 "Textures/win.bmp"
#define FILENAME7 "Textures/sea.bmp"

/*Identifikatori tekstura*/
GLuint names[8];
extern void include_textures();

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
extern int coordinate_x(int p);
extern int coordinate_y(int q);
extern void include_textures();

extern void draw_win_screen();
extern void draw_start_screen();
extern void draw_end_screen();
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

