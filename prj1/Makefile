CC=gcc
CFLAGS=-std=c99
all: order_book

order_book:	order_book.c
		$(CC) $(CFLAGS) -c order_book.c
		$(CC) $(CFLAGS) -o order_book order_book.o

clean:	
	rm -f *.o *.out order_book
