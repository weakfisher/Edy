# Makefile para P2E6
# ejecutar desde la terminal escribiendo "make" 
# genera automáticamente el ejecutable del programa

FLAGS = -Wall -Wextra -std=c99

programa: main.o contacto.o
	$(CC) -o $@ $^ $(FLAGS)

main.o: main.c contacto.h
	$(CC) -c $< $(FLAGS)


contacto.o: contacto.c contacto.h
	$(CC) -c $< $(FLAGS)

clean:
	rm *.o
	rm programa

.PHONY = clean