
C=clang
CFLAGS = -Wall -std=c11 

all: main

main: main.o file_io.o race_officer.o
	$(C) $(CFLAGS) -o main main.o file_io.o race_officer.o

main.o: main.c file_io.h types.h race_officer.h
	$(C) $(CFLAGS) -c main.c

file_io.o: file_io.c file_io.h
	$(C) $(CFLAGS) -c file_io.c

race_officer.o: race_officer.c race_officer.h types.h
	$(C) $(CFLAGS) -c race_officer.c

clean: 
	rm -rf *.o *.h.gch main