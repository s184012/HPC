CC = gcc
OPT = -g -O3
WARN = -Wall
CFLAGS = $(OPT) $(WARN)
OBJECTS = main.o data.o io.o

excer2: $(OBJECTS)
	$(CC) $(CFLAGS) -o excer2 $(OBJECTS)

clean:
	rm -f *.o

data.o: data.c data.h
io.o: io.c io.h
main.o: main.c io.h data.h