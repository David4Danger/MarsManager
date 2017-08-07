#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "ManagerCoreSteps.h"
#include "planets.h"
using namespace std;

priority_queue_t *marsTaskQ;
solarSystem sol;

void setStartingVariables () {
  srand(time(NULL));

  /* Start with 100 to 200kg of oxygen, water, food and 0 to 50kg of hydrogen */
  sol.mars.inventory.oxygen = (rand() % 100) + 100;
  sol.mars.inventory.water = (rand() % 100) + 100;
  sol.mars.inventory.food = (rand() % 100) + 100;
  sol.mars.inventory.hydrogen = rand() % 50;

  /* Randomly decide the time between Earth and Mars, 3 to 22s */
  sol.messageDelay = (rand() % 19) + 3;
}

void startTaskQ () {
  marsTaskQ = (priority_queue_t*)calloc(1,sizeof(priority_queue_t));
  marsTaskQ->len = 0;
  marsTaskQ->maxNodes = 0;
}

void tick () {
  ;
}
