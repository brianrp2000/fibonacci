all: fib

fib: fib.c
	gcc -Wall -std=gnu99 -pthread -o fib fib.c

clean:
	rm fib