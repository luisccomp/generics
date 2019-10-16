all: generics

generics: main.o list.o
	g++ main.o list.o -o main.exe

main.o: main.c
	g++ -c main.c

list.o: list.c
	g++ -c list.c