#include <iostream>
#include "tasks.h"
#include "planets.h"
#include "printer/printer.h"
#include <chrono>
#include <thread>
#include <string>
using namespace std;

void dailyInventoryReport() {
  safePrint(
  "---------------------------\n"
  "Daily Mars Inventory Report\n"
  "Oxygen: " + to_string(sol.mars.inventory.oxygen) + "\n"
  "Hydrogen: " + to_string(sol.mars.inventory.hydrogen) + "\n"
  "Food: " + to_string(sol.mars.inventory.food) + "\n"
  "Water: " + to_string(sol.mars.inventory.water) + "\n"  );
  //Add a message with sol.messageDelay delay to earth later & earth confirmation
}

void sendEarthConfirmation() {
  safePrint(
  "------------------------------------------------\n"
  "Sending inventory confirmation message to Earth\n"
  "Current time delay: " + to_string(sol.messageDelay) + " minutes.\n"  );
  using namespace std::this_thread;
  using namespace std::chrono;

  sleep_for(nanoseconds(10));
  sleep_until(system_clock::now() + seconds(sol.messageDelay));
  safePrint(
  "-----------------------------------------------\n"
  "Inventory confirmation message received by Earth\n"  );
}

void sendMarsConfirmation() {
  safePrint(
  "------------------------------------------------\n"
  "Sending inventory confirmation message to Mars\n"
  "Current time delay: " + to_string(sol.messageDelay) + " minutes.\n"  );
  using namespace std::this_thread;
  using namespace std::chrono;

  sleep_for(nanoseconds(10));
  sleep_until(system_clock::now() + seconds(sol.messageDelay));
  safePrint(
  "-----------------------------------------------\n"
  "Earth reports reception of inventory message.\n"  );
}

  
