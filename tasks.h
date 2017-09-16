/*            
 * Header file for all marsTask functions
 * All functions defined must work with the marsTask signature in Utility/priorityQueue.h
 *     typedef void (*marsTask)();
 * 
 * David Skudra 2017
*/

#ifndef tasks_h_
#define tasks_h_
#endif

/**************************************************************/
/*                                                            */
/* dailyInventoryReport: Output the current inventory status  */
/* at the beginning of each mars day (tick 0, tick 1479, etc) */
/* and send the update to Earth. Wait for message response.   */
/*                                                            */
/* Params:                                                    */
/*    None                                                    */
/*                                                            */
/* Returns: Nothing                                           */
/*                                                            */
/**************************************************************/
void dailyInventoryReport();


/**************************************************************/
/*                                                            */
/* sendEarthConfirmation: Send a confirmation message based   */
/* messageDelay argument in solarSystem obj, delay can be     */
/* 3 to 22 tick delay (3 to 22 minute delay like real life)   */
/*                                                            */
/* Params:                                                    */
/*    None                                                    */
/*                                                            */
/* Returns: Nothing                                           */
/*                                                            */
/**************************************************************/
void sendEarthConfirmation();

/**************************************************************/
/*                                                            */
/* sendMarsConfirmation: Send a confirmation message based    */
/* messageDelay argument in solarSystem obj, delay can be     */
/* 3 to 22 tick delay (3 to 22 minute delay like real life)   */
/*                                                            */
/* Params:                                                    */
/*    None                                                    */
/*                                                            */
/* Returns: Nothing                                           */
/*                                                            */
/**************************************************************/
void sendMarsConfirmation();
