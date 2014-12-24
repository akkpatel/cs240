CC=gcc
CFLAGS=-std=c99
all: memory perf

memory:	memory.c
	$(CC) $(CFLAGS) -c memory.c
	$(CC) $(CFLAGS) -o memory memory.o

perf:	perf.c
	$(CC) $(CFLAGS) -c perf.c
	$(CC) $(CFLAGS) -o perf perf.o

clean:	
	rm -f *.o *.out memory perf
