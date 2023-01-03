CC	= gcc
DEBUG	= -g -Wall
OPT	= -O3
CFLAGS	= $(DEBUG) $(OPT)
OBJECTS = main.o io.o matrix_fns.o test.o
LDFLAGS = $(CFLAGS)
LDLIBS = -lm -L /usr/lib64/atlas -lsatlas

main: $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ $(LDLIBS)

clean:
	/bin/rm -f *.o core 

realclean: clean
	/bin/rm -f matsum

# DO NOT DELETE

io.o: /usr/include/stdio.h /usr/include/stdlib.h io.h
main.o: /usr/include/stdlib.h io.h /usr/include/stdio.h matrix_fns.h
matrix_fns.o: /usr/include/stdlib.h matrix_fns.h
test.o: /usr/include/stdlib.h io.h /usr/include/stdio.h matrix_fns.h
