all: detab reverse fsm

detab: detab.c
	gcc -o detab detab.c -Wall

reverse: reverse.c
	gcc -o reverse reverse.c -Wall

fsm: main.c fsm.c fsm.h
	gcc -c main.c fsm.c -Wall
	gcc -o fsm main.o fsm.o -Wall

clean:
	rm -f detab reverse fsm *.o