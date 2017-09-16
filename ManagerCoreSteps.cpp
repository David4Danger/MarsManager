#include <iostream>
#include <thread>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "printer/printer.h"
#include "ManagerCoreSteps.h"
#include "planets.h"
#include "tasks.h"
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

  /* Randomly decide the time between Earth and Mars, 3 to 22 minutes */
  sol.messageDelay = (rand() % 19) + 3;
}

void startTaskQ () {
  marsTaskQ = (priority_queue_t*)calloc(1,sizeof(priority_queue_t));
  marsTaskQ->len = 0;
  marsTaskQ->maxNodes = 0;
}

//compiler flags for threads: -std=c++0x -pthread

void tick () {
  thread t[maxthreads];

  pq_insert(marsTaskQ, 50, &dailyInventoryReport);
  pq_insert(marsTaskQ, 55, &sendEarthConfirmation);
  pq_insert(marsTaskQ, 56, &sendMarsConfirmation);
  for (int i = 0; i < 3; ++i) {
    t[i] = thread(pq_deleteMax(marsTaskQ));
  }

  for (int i = 0; i < 3; ++i) {
    t[i].join();//Join thread to execution
  }

  safePrint(
  "-----------------------------------------------\n"
  );
}
