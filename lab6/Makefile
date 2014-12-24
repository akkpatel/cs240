CC=gcc
CFLAGS=-m32 -O0
all: badguy1 badguy2

badguy1:	badguy1.c callstack.c
	$(CC) $(CFLAGS) -o badguy1 badguy1.c callstack.c

badguy2:	badguy2.c callstack.c
	$(CC) $(CFLAGS) -o badguy2 badguy2.c callstack.c

clean:	
	rm -f *.o *.out badguy1 badguy2


