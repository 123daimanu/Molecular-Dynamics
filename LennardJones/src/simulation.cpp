
#include<limits>
#include<iostream>
#include <cstdlib>

#include "simulation.hpp"
#include "initialize.hpp"
#include "atom.hpp"
#include "../maths/Vector3.hpp"

#define INF std::numeric_limits<float>::infinity();

simulation::simulation():initialize(){}

void simulation::setParams(int num,float l, float r, float ene, float m,float timeinterval, int Totaltime  )
{
  number = num;
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

    this->systemAtoms[i].vel = this->systemAtoms[i].vel + ((this->systemAtoms[i].force)/2)*(dt/2);
    this->systemAtoms[i].pos = this->systemAtoms[i].pos + (this->systemAtoms[i].vel)*dt;
    periodicBoundary(this->systemAtoms[i]);
  }

  //doforce
  for(int i = 0; i< number ; i++)
  {
    this->setForce(this->systemAtoms[i]);
  }

  //move B

  for(int i = 0; i< number ; i++)
  {

    this->systemAtoms[i].vel = this->systemAtoms[i].vel + ((this->systemAtoms[i].force)/2)*(dt/2);

  }
}

void simulation::runSimulation()
{
  Initial();
  while(simtime <= t)
  {
    update();
    velocityInCM();
    simtime += dt;
  }
}

//Restricted periodic boundary condition
void simulation::periodicBoundary(atom &A)
{
  A.setPosition(A.pos-((A.pos/length).Floor())*length);
}


void simulation::velocityInCM()
{
  Vector3 vcm(0,0,0);
  for(int i=0;i<number;i++)
  {
    vcm = vcm + this->systemAtoms[i].vel/number;

  }
  for(int i=0;i<number;i++)
  {
    this->systemAtoms[i].setVelocity(systemAtoms[i].vel-vcm);
    cout<<this->systemAtoms[i].pos<<endl;
  }
}
