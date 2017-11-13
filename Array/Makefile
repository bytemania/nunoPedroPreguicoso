CC = gcc

CFLAGS = -g -Wall -pthread

main: main.c string_array.o
	$(CC) $(CFLAGS) -o main main.c string_array.o

string_array.o: string_array.c string_array.h
	$(CC) $(CFLAGS) -c string_array.c string_array.h

clean:
	rm -f main *.o core *.gch
