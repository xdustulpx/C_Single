CC = gcc #compiler
CFLAGS = -WALL #options
LDFLAGS = #links
SRC = calc.c pile.c # source C files
PROG = calc #
OBJS =$(SRC: .c=.o) # *.o files
.SUFFIXES: .c .o #links for suffixes
all: $(PROG)

$(PROG):$(OBJS)
		$(CC) $(LDFLAGS) -o $@ $^
calc.o:pile.h
pile.o:pile.h

%.o: %.c
		$(CC) $(CFLAGS) -c $<

.PHONY:clean
clean:
		rm -f *.o *~ core $(PROG)

