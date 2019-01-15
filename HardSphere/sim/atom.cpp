#include<iostream>
#include<cmath>
#include "atom.hpp"
#include "../maths/Vector3.hpp"




float atom::getTinit()
{

  return(tI);
}

void atom::setPosition(Vector3 pos1)
{
  pos = pos1;
}

void atom::setVelocity(Vector3 vel1)
{
  vel = vel1;
}

void atom::setTinit(float ti)
{
  tI=ti;
}

Vector3 atom::getPosition()
{
  return pos;
}
Vector3 atom::getVelocity()
{
  return vel;
}
void atom::setCollisionWith(int index, float time){
  tC[index] = time;
  collisionWith[index] = 1;
}
float atom::getCollisionTime( int index){

  return tC[index];

}

int atom::getMinTcIndex(){
  float time = 10000000;
  int index = 0;
  int i = 0;
  while(tC[i]!= -999)
  {
    if(tC[i]>=0 && tC[i]<time)
    {
      time = tC[i];
      index = i;
    }
  }
  return index;
}
