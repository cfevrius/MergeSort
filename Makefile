CC=gcc
CFLAGS=-Wall -std=gnu99

app: main.c list.o node.o
	$(CC) $(CFLAGS) -o $@ $^

list.o: list.c
	$(CC) $(CFLAGS) -c $<

node.o: node.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm list.o
	rm node.o
	rm app
        
