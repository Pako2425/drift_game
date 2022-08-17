all: compile link

compile:
	g++ -c main.cpp controller.cpp -Isrc/include

link:
	g++ main.o controller.o -o main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system