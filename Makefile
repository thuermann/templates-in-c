#
# $Id: Makefile,v 1.1 2014/01/17 13:08:49 urs Exp $
#

RM     = rm -f
CFLAGS = -O3 -Wall -Wextra

programs = t

.PHONY: all
all: $(programs)

t: template.o
	$(CC) -o $@ template.o

.PHONY: clean
clean:
	$(RM) $(programs) *.o core
