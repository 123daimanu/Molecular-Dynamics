#include "simulation.hpp"
#include "initialize.hpp"
#include "../maths/Vector3.hpp"











bool simulation::collisionFlag(atom a, atom b)
{
  Vector3 v12 = V12(a.getVelocity(),b.getVelocity());
  Vector3 r12 = V12(a.getPosition(),b.getPosition());
  float dotprod = dot(r12,v12);
  if dotprod<0
  {
    float disc = dotprod*dotprod - v12.square()*(r12.squre()-sigma*sigma)
    if disc>=0 return True;
  }
  return False;
}
float simulation::collisionTime(atom a, atom b)
{



}
void velocityUpdate(atom *a, atom *b);
void positionUpdate(atom *a);
void collisionTimeUpdate();
