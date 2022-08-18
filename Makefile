all: compile link

compile:
	g++ -c main.cpp controller.cpp car.cpp -Isrc/include

link:
	g++ main.o controller.o car.o -o main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system