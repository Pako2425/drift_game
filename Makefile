all: compile link

compile:
	g++ -c main.cpp controller.cpp car.cpp map.cpp driving_physic.cpp Game.cpp dashboard.cpp steering_wheel.cpp -Isrc/include

link:
	g++ main.o controller.o car.o map.o driving_physic.o Game.o dashboard.o steering_wheel.o -o main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio