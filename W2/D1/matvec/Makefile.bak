CC	= gcc
OPT	= -g -ffast-math -fopenmp
CHIP = 
ISA	= 
DEFS	= 
LIBS	= -lm
CFLAGS  = $(OPT) $(CHIP) $(ISA) $(DEFS) $(XOPT)

OBJECTS = main.o io.o matrix_fns.o 
TARGETS = calc_mxv

calc_mxv: clean $(OBJECTS)
	$(CC) -o $@ $(CFLAGS) $(OBJECTS) $(LIBS)

clean:
	@/bin/rm -f $(OBJECTS) core

realclean: clean
	@/bin/rm -f $(TARGETS)


# DO NOT DELETE
io.o: matrix_fns.h