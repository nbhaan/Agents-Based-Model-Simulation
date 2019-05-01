CC = g++-8
CXXFLAGS = -Wall -g -O

simulator: main.o simulator.o parameters.o firm.o human.o machine.o
	$(CC) $(CXXFLAGS) -o simulator main.o simulator.o parameters.o firm.o human.o machine.o

main.o: main.cpp
	$(CC) $(CXXFLAGS) -c main.cpp

simulator.o: simulator.cpp simulator.h parameters.h
	$(CC) $(CXXFLAGS) -c simulator.cpp

parameters.o: parameters.cpp parameters.h
	$(CC) $(CXXFLAGS) -c parameters.cpp

firm.o: firm.cpp firm.h
	$(CC) $(CXXFLAGS) -c firm.cpp

human.o: human.cpp human.h
	$(CC) $(CXXFLAGS) -c human.cpp

machine.o: machine.cpp machine.h
	$(CC) $(CXXFLAGS) -c machine.cpp

clean:
	rm -f simulator main.o simulator.o parameters.o firm.o human.o machine.o

	