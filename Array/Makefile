CC = gcc
#CFLAGS = -g -Wall -pthread
CFLAGS = -O0 -pthread -march=native

main: main.c string_array.o kbtree.h 
	$(CC) $(CFLAGS) -o main main.c string_array.o kbtree.h

string_array.o: string_array.c string_array.h
	$(CC) $(CFLAGS) -c string_array.c string_array.h

clean:
	rm -f main *.o core *.gch

