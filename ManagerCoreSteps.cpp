#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "ManagerCoreSteps.h"
using namespace std;

priority_queue_t *marsTaskQ;
marsInventory marsInv;

marsInventory::marsInventory() {
  oxygen = hydrogen = water = food = 0;
}

void setStartingVariables () {
  srand(time(NULL));

  //Start with 100 to 200kg of oxygen, water, food and 0 to 50kg of hydrogen
  marsInv.oxygen = (rand() % 100) + 100;
  marsInv.water = (rand() % 100) + 100;
  marsInv.food = (rand() % 100) + 100;
  marsInv.hydrogen = rand() % 50;
}

void startTaskQ () {
  marsTaskQ = (priority_queue_t*)calloc(1,sizeof(priority_queue_t));
  marsTaskQ->len = 0;
  marsTaskQ->maxNodes = 0;
}

void tick () {
  ;
}
