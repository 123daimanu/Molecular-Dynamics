#include<iostream>
#include<cmath>
#include<limits>
#include "atom.hpp"
#include "../maths/Vector3.hpp"

#define INF std::numeric_limits<float>::infinity();


void atom::setPosition(Vector3 pos1)
{
  this->pos = pos1;
}

void atom::setVelocity(Vector3 vel1)
{
  this->vel = vel1;
}

Vector3 atom::getPosition()
{
  return pos;
}
Vector3 atom::getVelocity()
{
  return vel;
}

void atom::setnumberOfAtoms(int n)
{
  this->number = n;
  this->tC = new float[n];
  this->collisionWith = new bool[n];

}

void atom::setAtomTag(int tag)
{
  this->atomTag = tag;
}
