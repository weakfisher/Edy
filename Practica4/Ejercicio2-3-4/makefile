# Makefile para P2E6
# ejecutar desde la terminal escribiendo "make" 
# genera automáticamente el ejecutable del programa

CC = gcc
CFLAGS = -Wall -Wextra -std=c99

SRC =   btree.c  text.c 
OBJ = $(SRC:.c=.o)
HEADER = cola.h btree.h  
EXECUTABLE = programa


$(EXECUTABLE): $(OBJ)
	$(CC) $(OBJ) -o $(EXECUTABLE)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXECUTABLE)