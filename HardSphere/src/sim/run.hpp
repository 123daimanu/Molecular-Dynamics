#include<cmath>

#include "simulation.hpp"

#ifndef RUN_HPP
#define RUN_HPP

#define pi 3.141592653589793

class run
{
public:
  float eta;
  int iterations;
  simulation system;

  run(){};
  ~run(){};
  void setparams(float packing, int iter,int num);
  void runSimulation();
};
#endif
