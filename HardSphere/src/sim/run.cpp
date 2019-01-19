#include<cmath>


#include "run.hpp"



void run::runSimulation()
{
  system.Initial();


  for(int i=0;i<iterations;i++)
  {
    system.getCollision();
    system.update();
  }

}

void run::setparams(float packing, int iter,int num)
{
  eta = packing;
  iterations = iter;
  system.number = num;
  system.sigma = pow((num*pi)/(6*eta),-0.33333);
}
