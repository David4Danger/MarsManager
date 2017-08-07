#include <iostream>
#include "ManagerCore.h"
#include "ManagerCoreSteps.h"
using namespace std;

void startMarsManager () {
  cout << "Welcome to Mars Manager! Generating starting variables..." << endl;
  setStartingVariables();//Randomly generate starting resources etc
  
  cout << "Queuing up intial tasks" << endl;
  startTaskQ();
  tick(); 
}
