all: compile link

compile:
	g++ -c main.cpp controller.cpp car.cpp map.cpp driving_physic.cpp steering_wheel.cpp dashboard.cpp game_hud.cpp -Isrc/include

link:
	g++ main.o controller.o car.o map.o driving_physic.o -o main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio