
#include<limits>
#include<iostream>
#include <cstdlib>

#include "simulation.hpp"
#include "initialize.hpp"
#include "atom.hpp"
#include "../maths/Vector3.hpp"

#define INF std::numeric_limits<float>::infinity();

void simulation::velocityUpdate(atom a, atom b)
{
  Vector3 v12 = a.getVelocity().V12(b.getVelocity());
  Vector3 r12 = a.getPosition().V12(b.getPosition());
  float dotprod = r12.dot(v12);
  float r12Squ =  r12.square();
  Vector3 deltaV = r12*(dotprod/r12Squ);
  a.setVelocity(a.getVelocity()-deltaV);
  b.setVelocity(b.getVelocity()+deltaV);

}



void simulation::positionUpdate(atom a, float time)
{
  Vector3 posNew = a.getPosition() + a.getVelocity() * time;
  a.setPosition(posNew);

}



void simulation::getCollision()
{
  for(int i=0;i<number;i++)
  {
    int indexTag = systemAtoms[i].getMinTimeIndex();
    float timeCollision = systemAtoms[i].getCollisionTime(indexTag);
    minColtime[i] = timeCollision;
    minColtimeIndex[i] = indexTag;
  }
    float time = INF;
    int i = 0;
    while(i < number)
    {
      if(minColtime[i]>0 && minColtime[i]<time)
      {
        collT = minColtime[i];
        collisionPair[0] = i;
        collisionPair[1] = minColtimeIndex[i];
      }
      i++;
    }
}


void simulation::update()
{
  float deltaT =  collT-simTime;
  simTime = collT;
  int pair1 =  collisionPair[0];
  int pair2 = collisionPair[1];
  if (pair1 != -1 and pair2 != -1)
  {
    for(int i=0; i< number; i++)
    {
      positionUpdate(systemAtoms[i],deltaT);

      systemAtoms[i].tI = simTime;
      periodicBoundary(systemAtoms[i]);
    }
    velocityUpdate(systemAtoms[pair1],systemAtoms[pair2]);
    CollisionTimeUpdate(systemAtoms[pair1]);
    CollisionTimeUpdate(systemAtoms[pair2]);
    velocityInCM();
  }
  else
  {
    std::cerr << "There is no collision between any pair." << '\n';
    std::exit(1);
  }




}
//Restricted periodic boundary condition
void simulation::periodicBoundary(atom A)
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
