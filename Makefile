all: compile link

compile:
	g++ -c main.cpp controller.cpp car.cpp map.cpp driving_physic.cpp Game.cpp State.cpp Game_State.cpp CarDimensionsComponent.cpp GearboxComponent.cpp Entity.cpp Player.cpp PositionComponent.cpp SpriteComponent.cpp SteeringComponent.cpp VelocityComponent.cpp EngineComponent.cpp -Isrc/include

link:
	g++ main.o controller.o car.o map.o driving_physic.o Game.o State.o Game_State.o CarDimensionsComponent.o GearboxComponent.o Entity.o Player.o PositionComponent.o SpriteComponent.o SteeringComponent.o VelocityComponent.o EngineComponent.o -o main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
