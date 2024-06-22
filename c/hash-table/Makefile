build:
	gcc -c lib/data.c -o data.o
	gcc -I lib/ -c main.c -o main.o
	gcc main.o data.o -o main

clean:
	rm *.o main