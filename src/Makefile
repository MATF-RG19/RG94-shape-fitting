PROGRAM = shape-fitting
CC      = gcc
CFLAGS  = -g -ansi -Wall -I/usr/X11R6/include -I/usr/pkg/include -std=c99
LDFLAGS = -L/usr/X11R6/lib -L/usr/pkg/lib
LDLIBS  = -lglut -lGLU -lGL -lm

$(PROGRAM): main.o shapes.o picture.o image.o textures.o
	$(CC) $(LDFLAGS) $(CFLAGS) -o $(PROGRAM)  main.o shapes.o picture.o image.o textures.o $(LDLIBS)

shapes.o: shapes.c functions.h
	$(CC) $(LDFLAGS) $(CFLAGS) -c shapes.c -o shapes.o

picture.o: picture.c functions.h
	$(CC) $(LDFLAGS) $(CFLAGS) -c picture.c -o picture.o


textures.o: textures.c image.h functions.h
	$(CC) $(LDFLAGS) $(CFLAGS) -c textures.c -o textures.o

image.o: image.c image.h
	$(CC) $(LDFLAGS) $(CFLAGS) -c image.c -o image.o

main.o: main.c functions.h image.h
	$(CC) $(LDFLAGS) $(CFLAGS) -c main.c -o main.o


.PHONY: clean

clean:
	-rm *.o $(PROGRAM)
