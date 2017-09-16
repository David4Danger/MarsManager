/*            
 * Header file for manager core steps functionalities.
 * Defines all pre and post tick functions, as well as tick itself.
 * David Skudra 2017
*/

#ifndef ManagerCoreSteps_h_
#define ManagerCoreSteps_h_
#endif
#include "Utility/priorityQueue.h"

extern priority_queue_t *marsTaskQ;
static const int maxthreads = 10;

/**************************************************************/
/*                                                            */
/* setStartingVariables: Randomly generate starting resources */
/* for the colony and initial solar distances. Any additional */
/* game variables that need to be determined prior to the     */
/* start of play should be defined here.                      */
/*                                                            */
/* Params:                                                    */
/*    None                                                    */
/*                                                            */
/* Returns: Nothing                                           */
/*                                                            */
/**************************************************************/
void setStartingVariables();

/**************************************************************/
/*                                                            */
/* startTaskQ: Initialize the marsTask based priority queue,  */
/* see Utility/priorityQueue.h for queue definiton.           */
/*                                                            */
/* Params:                                                    */
/*    None                                                    */
/*                                                            */
/* Returns: Nothing                                           */
/*                                                            */
/**************************************************************/
void startTaskQ();

/**************************************************************/
/*                                                            */
/* tick: Fundamental quantum of time used by Mars Manager. A  */
/* single game tick occurs every second, and represents one   */
/* minute of real time. All actions that require processing   */
/* by the game are governed by tick, and as such each action  */
/* registed by the player will begin to take place at the     */
/* beginning of the next tick.                                */
/*                                                            */
/* Quick tick values                                          */
/* 1 tick     = 1 minute                                      */
/* 60 ticks   = 1 hour                                        */
/* 1440 ticks = 1 standard EARTH day                          */
/* 1479 ticks = 1 standard MARS day                           */
/*                                                            */
/* Tick processing time is tbd. The goal is to keep a maximum */
/* tick to 1 second (real time) of processing. One can dream. */
/*                                                            */
/* Params:                                                    */
/*    None                                                    */
/*                                                            */
/* Returns: Nothing                                           */
/*                                                            */
/**************************************************************/
void tick();
