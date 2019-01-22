#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include "atom.hpp"
#include "initialize.hpp"

#define T(time) ((time) < 0.0001) ? (0.0) : (time)

class simulation: public initialize
{
public:
  float t = 0.0;
  float simtime = 0.0;
  float dt = 0.0;
  int iterations = 0;

  simulation();
  ~simulation(){};
  void setParams(int num,float l, float r, float ene, float m,float timeinterval, int Totaltime  );
  void update();
  void periodicBoundary(atom &A);
  void velocityInCM();
  void runSimulation();
  float orderParameter();
};
#endif
