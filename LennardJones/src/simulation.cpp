
#include<limits>
#include<iostream>
#include <cstdlib>

#include "simulation.hpp"
#include "initialize.hpp"
#include "atom.hpp"
#include "../maths/Vector3.hpp"

#define INF std::numeric_limits<float>::infinity();

simulation::simulation():initialize(){}

void simulaton::setParams(int num,float l, float r, float ene, float m,float timeinterval, int Totaltime  )
{
  t = Totaltime;
  dt = timeinterval;
  sigma = r;
  epsilon = ene;
  mass = m;
  length = l;


}

void simulation::update()
{

  //move A
  for(int i = 0; i< number ; i++)
  {

    this->systemAtoms[i].vel = this->systemAtoms[i].getVelocity() + ((this->systemAtoms[i].force)/2)*(dt/2));
    this->systemAtoms[i].pos = this->systemAtoms[i].getPosition() + (this->sysetmAtoms[i].getVelocity())*dt;
    periodicBoundary(this->systemAtoms[i]);
  }

  //doforce
  for(int i = 0; i< number ; i++)
  {
    this->systemAtoms[i].force = this->setForce(this->systemAtoms[i]);
  }

  //move B

  for(int i = 0; i< number ; i++)
  {

    this->systemAtoms[i].vel = this->systemAtoms[i].getVelocity() + ((this->systemAtoms[i].force)/2)*(dt/2));

  }
}

void simulaton::runSimulation()
{
  Initial();
  while(simtime <= t)
  {
    update()
    velocityInCM()
    simtime += dt;
  }
}


}
//Restricted periodic boundary condition
void simulation::periodicBoundary(atom &A)
{
  A.setPosition(A.getPosition()-A.getPosition().Floor());
}


void simulation::velocityInCM()
{
  Vector3 vcm(0,0,0);
  for(int i=0;i<number;i++)
  {
    vcm = vcm + systemAtoms[i].getVelocity()/number;

  }
  for(int i=0;i<number;i++)
  {
    systemAtoms[i].setVelocity(systemAtoms[i].getVelocity()-vcm);
  }
}
