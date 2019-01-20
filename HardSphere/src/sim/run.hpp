#include<cmath>

#include "simulation.hpp"
#define T(time) ((time) < 0.0001) ? (0.0) : (time)
#define pi 3.141592653589793

#ifndef RUN_HPP
#define RUN_HPP





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
