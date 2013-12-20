CC=gcc -g
test : test.c file.o sorts.o
	$(CC) -o test test.c file.o sorts.o

file.o : file.h file.c
	$(CC) -c -o file.o file.c

sorts.o : sorts.h sorts.c
	$(CC) -c -o sorts.o sorts.c

clean :
	-rm -f  *.o test
