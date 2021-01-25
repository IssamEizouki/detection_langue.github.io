CC = gcc -g
CFLAGS = -W -Wall
SOURCES = $(wildcard *.c)
TIME = $(wildcard *.time)
OBJETS = $(SOURCES:.c=.o)
EXEC = main

$(EXEC) : $(OBJETS)
	$(CC) $(CFLAGS) -o $@ $^ 
%.o : %.c
	$(CC) $(CFLAGS) -c $<
clean:
	rm $(EXEC) $(OBJETS) $(TIME)