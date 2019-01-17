#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include "atom.hpp"

class simulation
{
public:
  float minColtime[1000];
  int minColtimeIndex[1000];
  int number;
  float sigma;
  float simTime;

  simulation(int num,float sig):number(num),sigma(sig),simTime(0){}
  ~simulation(){};

  bool collisionFlag(atom a, atom b);
  float collisionTime(atom a, atom b);
  void velocityUpdate(atom *a, atom *b);
  void positionUpdate(atom *a);
  void collisionTimeUpdate();
    
};









#endif
