#include<cmath>


#include "simulation.hpp"
#include "initialize.hpp"
#include "atom.hpp"
#include "../maths/Vector3.hpp"

bool simulation::collisionFlag(atom a, atom b)
{
  Vector3 v12 = V12(a.getVelocity(),b.getVelocity());
  Vector3 r12 = V12(a.getPosition(),b.getPosition());
  float dotprod = dot(r12,v12);
  if (dotprod<0)
  {
    float disc = dotprod*dotprod - v12.square()*(r12.square()-sigma*sigma)
    if (disc >=0) return True;
  }
  return false;
}
float simulation::collisionTime(atom a, atom b)
{
  Vector3 v12 = V12(a.getVelocity(),b.getVelocity());
  Vector3 r12 = V12(a.getPosition(),b.getPosition());
  float dotprod = dot(r12,v12);
  float disc = dotprod*dotprod - v12.square()*(r12.square()-sigma*sigma);
  float deltaT;
  deltaT = (-dotprod - sqrt(disc))/(v12.square());
  return simTime+deltaT;



}
void velocityUpdate(atom *a, atom *b)
{
  Vector3 v12 = V12(a->getVelocity(),b->getVelocity());
  Vector3 r12 = V12(a->getPosition(),b->getPosition());
  float dotprod = dot(r12,v12);
  float r12Squ =  r12.square();
  Vector3 deltaV = r12*(dotprod/r12Squ);
  a->setVelocity(a->getVelocity()-deltaV);
  b->setVelocity(b->getVelocity()+deltaV);

}
void positionUpdate(atom *a)
{
  Vector3 posNew = a->getPosition()+a->getVelocity()* ( simTime - a->getTinit());
  a->setPosition(posNew);

}
void collisionTimeUpdate();
