#include<iostream>
#include<cmath>
#include "atom.hpp"
#include "../maths/Vector3.hpp"




float atom::getTinit()
{

  return(tI);
}

void atom::setPosition(Vector3 pos)
{
  pos = pos;
}

void atom::setVelocity(Vector3 vel)
{
  vel = vel;
}

void atom::setTinit(float tI)
{
  tI=tI;
}
/*
void atom::setTcol(float tC)
{

  tC=tC;
}
*/
