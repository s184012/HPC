CC	= gcc
OPT	= -g -Ofast -ftree-parallelize-loops=8 #-fopenmp
CHIP = 
ISA	= 
DEFS	= 
LIBS	= -lm
CFLAGS  = $(OPT) $(CHIP) $(ISA) $(DEFS) $(XOPT)

SOURCES = calc_pi.c
OBJECTS = $(SOURCES:.c=.o)
TARGETS = calc_pi
	

calc_pi: clean $(OBJECTS)
	$(CC) -o $@ $(CFLAGS) $(OBJECTS) $(LIBS)

clean:
	@/bin/rm -f $(OBJECTS) core

realclean: clean
	@/bin/rm -f $(TARGETS)


# DO NOT DELETE
