# Simples makefile para compilar o projeto todo. =D

all: trabalho
trabalho: trabalho.o main.o
	g++ -o trabalho trabalho.o main.o
main.o: main.cpp
	g++ -c main.cpp -Wall
trabalho.o: trabalho.cpp
	g++ -c trabalho.cpp -Wall
clean:
	rm -rf *.o
