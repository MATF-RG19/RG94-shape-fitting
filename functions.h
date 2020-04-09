#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

/*Deklaracije callback funkcija-premestene ovde*/
extern void on_display(void);
extern void on_reshape(int width, int height);
extern void on_keyboard(unsigned char key, int x, int y);

extern void draw_floor();
extern void draw_path();
extern void draw_picture();
extern void draw_shapes();
 
int window_width, window_height;

#endif
