PROGRAM = shape-fitting
CC      = gcc
CFLAGS  = -g -ansi -Wall -I/usr/X11R6/include -I/usr/pkg/include -std=c99
LDFLAGS = -L/usr/X11R6/lib -L/usr/pkg/lib
LDLIBS  = -lglut -lGLU -lGL -lm

$(PROGRAM): main.o shapes.o picture.o
	$(CC) $(LDFLAGS) $(CFLAGS) -o $(PROGRAM)  main.o shapes.o picture.o  $(LDLIBS)

main.o: main.c 
	$(CC) $(LDFLAGS) $(CFLAGS) -c main.c -o main.o

shapes.o: shapes.c functions.h
	$(CC) $(LDFLAGS) $(CFLAGS) -c shapes.c -o shapes.o

picture.o: picture.c functions.h
	$(CC) $(LDFLAGS) $(CFLAGS) -c picture.c -o picture.o

.PHONY: clean

clean:
	-rm *.o $(PROGRAM)
