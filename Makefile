CC=gcc
CFLAGS=-Wall -g -O2
BINS=listinode

all: $(BINS)

util.o: util.c util.h
	$(CC) $(CFLAGS) -c util.c

listinode: listinode.c util.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm *.o listinode
