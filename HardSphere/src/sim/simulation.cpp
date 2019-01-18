#include<cmath>


#include "simulation.hpp"
#include "initialize.hpp"
#include "atom.hpp"
#include "../maths/Vector3.hpp"



void simulation::velocityUpdate(atom *a, atom *b)
{
  Vector3 v12 = a->getVelocity().V12(b->getVelocity());
  Vector3 r12 = a->getPosition().V12(b->getPosition());
  float dotprod = r12.dot(v12);
  float r12Squ =  r12.square();
  Vector3 deltaV = r12*(dotprod/r12Squ);
  a->setVelocity(a->getVelocity()-deltaV);
  b->setVelocity(b->getVelocity()+deltaV);

}
void simulation::positionUpdate(atom *a)
{
  Vector3 posNew = a->getPosition()+a->getVelocity()* ( simTime - a->getTinit());
  a->setPosition(posNew);

}
