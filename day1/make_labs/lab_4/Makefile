CC	= gcc
DEBUG	= -g -Wall
OPT	= -O3
CFLAGS	= $(DEBUG) $(OPT)
OBJECTS = data.o main.o io.o
LDFLAGS = $(CFLAGS)

project1: $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ $(LDLIBS) -lm

clean:
	/bin/rm -f *.o core 

realclean: clean
	/bin/rm -f project1

# DO NOT DELETE

data.o: /usr/include/stdio.h /usr/include/math.h data.h
io.o: /usr/include/stdio.h io.h
main.o: /usr/include/stdio.h /usr/include/stdlib.h io.h data.h
