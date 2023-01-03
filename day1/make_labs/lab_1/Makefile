excer1: main.o io.o data.o
	cc -o excer1 main.o io.o data.o
main.o: main.c io.h data.h
io.o: io.c io.h
data.o: data.c data.h
clean: 
	rm -f *.o