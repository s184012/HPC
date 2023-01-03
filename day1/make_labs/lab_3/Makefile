CC = gcc
OPT = -g -O3
WARN = -Wall
CFLAGS = $(OPT) $(WARN)
OBJECTS = main.o data.o io.o

excer2: $(OBJECTS)
	$(CC) $(CFLAGS) -o excer2 $(OBJECTS)

clean:
	rm -f *.o
# DO NOT DELETE

data.o: /usr/include/stdio.h data.h
io.o: /usr/include/stdio.h io.h
main.o: /usr/include/stdio.h /usr/include/stdlib.h io.h data.h
