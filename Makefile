CC:= gcc

SRCFILES := $(wildcard *.c)

all: $(SRCFILES:%.c=%.o)
	$(CC) $(CFLAGS) *.o -o prog

run: prog
	./prog
clean:
	rm -rf *.o
