CPPFLAGS=-c -O2

all: trafficjam

trafficjam: car.o coordinates.o grid.o controlauto.o
	g++ car.o coordinates.o grid.o controlauto.o -o trafficjam

car.o: car.cpp car.h coordinates.h
	g++ $(CPPFLAGS) car.cpp

coordinates.o: coordinates.cpp coordinates.h
	g++ $(CPPFLAGS) coordinates.cpp

grid.o: grid.cpp grid.h car.h coordinates.h
	g++ $(CPPFLAGS) grid.cpp

controlauto.o: controlauto.cpp car.h grid.h coordinates.h
	g++ $(CPPFLAGS) controlauto.cpp

clean:
	rm -rf *o trafficjam
