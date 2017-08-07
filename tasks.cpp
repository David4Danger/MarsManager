#include <iostream>
#include "tasks.h"
#include "planets.h"
using namespace std;

void dailyInventoryReport() {
  cout << "Daily Mars Inventory Report" << endl << "---------------------------" << endl;
  cout << "Oxygen: " << sol.mars.inventory.oxygen << endl;
  cout << "Hydrogen: " << sol.mars.inventory.hydrogen << endl;
  cout << "Food: " << sol.mars.inventory.food << endl;
  cout << "Water: " << sol.mars.inventory.water << endl;
  
  //Add a message with sol.messageDelay delay to earth later & earth confirmation
}


