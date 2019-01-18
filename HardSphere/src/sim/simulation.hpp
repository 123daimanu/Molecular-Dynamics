#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include "atom.hpp"
#include "initialize.hpp"

class simulation: public initialize
{
public:
  float *minColtime;
  int *minColtimeIndex;
  float simTime = 0.0;

  simulation():initialize(){
    minColtime = new float[number];
    minColtimeIndex = new int[number];
  };
  ~simulation(){};

  void velocityUpdate(atom *a, atom *b);
  void positionUpdate(atom *a);
};
#endif
