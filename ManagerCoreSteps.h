/*            
 * Header file for manager core steps functionalities.
 * Defines all pre and post tick functions, as well as tick itself.
 * David Skudra 2017
*/

#ifndef ManagerCoreSteps_h_
#define ManagerCoreSteps_h_
#endif
#include "Utility/priorityQueue.h"

struct marsInventory {
  int oxygen, hydrogen;//measured in kg
  int food, water;//measured in kg
  //Add more resources later (metals, etc), start with necessities
  marsInventory();
};

extern priority_queue_t *marsTaskQ;
extern marsInventory marsInv;

void setStartingVariables();
void startTaskQ();
void tick();
