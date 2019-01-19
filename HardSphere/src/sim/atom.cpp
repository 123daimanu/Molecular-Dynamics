#include<iostream>
#include<cmath>
#include<limits>
#include "atom.hpp"
#include "../maths/Vector3.hpp"

#define INF std::numeric_limits<float>::infinity();




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
  return this->pos;
}
Vector3 atom::getVelocity()
{
  return this->vel;
}
void atom::setCollisionWith(int index, float time){
  tC[index] = time;
  collisionWith[index] = 1;
}

float atom::getCollisionTime( int index){

  return tC[index];

}

int atom::getMinTimeIndex(){
  float time = INF;
  int index = 0;
  int i=0;
  while(i < number)
  {
    if(tC[i]>0 && tC[i]<time)
    {
      time = tC[i];
      index = i;
    }
    i++;
  }
  return index;
}


void atom::setnumberOfAtoms(int n)
{
  number = n;
  tC = new float[n];
  collisionWith = new bool[n];

}

void atom::setAtomTag(int tag)
{
  atomTag = tag;
}
