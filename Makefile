all:
	gcc -c morpion.c
	gcc -o morpion main.c morpion.o

clean: 
	rm morpion *.o *~
