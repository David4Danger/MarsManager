CXX = g++ # compiler (Swap to 4.9 or 4.7 on system as necessary)
CXXFLAGS = -g -Wall -std=c++0x

all: ManagerInit.o ManagerCore.o ManagerCoreSteps.o tasks.o planets.o printer/printer.o Utility/priorityQueue.o
	${CXX} ${CXXFLAGS} -o MarsManager ManagerInit.o ManagerCore.o ManagerCoreSteps.o tasks.o planets.o printer/printer.o Utility/priorityQueue.o

ManagerInit.o: ManagerInit.cpp ManagerInit.h ManagerCore.h
	${CXX} ${CXXFLAGS} -c ManagerInit.cpp

ManagerCore.o: ManagerCore.cpp ManagerCore.h ManagerCoreSteps.h Utility/priorityQueue.h

ManagerCoreSteps.o: ManagerCoreSteps.cpp ManagerCoreSteps.h printer/printer.h planets.h Utility/priorityQueue.h tasks.h

tasks.o: tasks.cpp tasks.h

Utility/priorityQueue.o: Utility/priorityQueue.c Utility/priorityQueue.h

planets.o: planets.cpp planets.h

printer/printer.o: printer/printer.cpp printer/printer.h

clean:
	rm *.o MarsManager Utility/*.o printer/*.o