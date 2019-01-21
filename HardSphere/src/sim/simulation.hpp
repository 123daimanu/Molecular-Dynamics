#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include "atom.hpp"
#include "initialize.hpp"

#define T(time) ((time) < 0.0001) ? (0.0) : (time)

class simulation: public initialize
{
public:
  float simTime = 0.0;
  int collisionPair[2]={-1,-1};
  float collT = 0.0 ;

  simulation();
  ~simulation(){};

  void velocityUpdate(atom &a, atom &b);
  void positionUpdate(atom &a, float time);
  void getCollision();
  void update();
  void periodicBoundary(atom &A);
  void velocityInCM();

};
#endif
