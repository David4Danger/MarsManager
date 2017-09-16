/*            
 * Header file for planet class definitions.
 * David Skudra 2017
*/

struct marsInventory {
  int oxygen, hydrogen;//measured in kg
  int food, water;//measured in kg
  //Add more resources later (metals, etc), start with necessities
  marsInventory();
};

class earthHome {
public:
  earthHome();
};

class marsColony {
public:
  marsInventory inventory;
  marsColony();
};

struct solarSystem {
  /* messageDelay is measured in minutes. Will eventually make this value 
     dynamic, although it'll take a lot of ticks to change. */
  int messageDelay;
  marsColony mars;
  earthHome earth;

  solarSystem();
};

extern solarSystem sol;
