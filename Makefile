CC=gcc
CFLAGS=-Wall -std=gnu99

app: main.c list.o node.o
	@echo Linking $@...
	@$(CC) $(CFLAGS) -o $@ $^

list.o: list.c
	@echo Linking $@...
	@$(CC) $(CFLAGS) -c $<

node.o: node.c
	@echo Linking $@...
	@$(CC) $(CFLAGS) -c $<

clean:
	@echo Cleaning...
	@rm list.o
	@rm node.o
	@rm app
        
