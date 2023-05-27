# Makefile para P2E6
# ejecutar desde la terminal escribiendo "make" 
# genera automáticamente el ejecutable del programa

CC = gcc
CFLAGS = -Wall -Wextra -std=c99

SRC = dglist.c  ejercicio9.c
OBJ = $(SRC:.c=.o)
HEADER = dglist.h  
EXECUTABLE = programa


$(EXECUTABLE): $(OBJ)
	$(CC) $(OBJ) -o $(EXECUTABLE)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXECUTABLE)