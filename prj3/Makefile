CC=gcc
CFLAGS=-std=c99 -g
all: order_book 

order_book:	order_book.c hash.c
		$(CC) $(CFLAGS) -c order_book.c hash.c
		$(CC) $(CFLAGS) -o order_book order_book.o hash.c
clean:	
	rm -f *.o *.out order_book
	rm -f *.o *.out hash
