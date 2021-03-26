#include "atom.hpp"

#include <cmath>
#include <iostream>
#include <limits>

#include "../maths/Vector3.hpp"

#define INF std::numeric_limits<float>::infinity();

float atom::getTinit() { return (tI); }

void atom::setPosition(Vector3 pos1) { this->pos = pos1; }

void atom::setVelocity(Vector3 vel1) { this->vel = vel1; }

void atom::setTinit(float ti) { this->tI = ti; }

Vector3 atom::getPosition() { return pos; }
Vector3 atom::getVelocity() { return vel; }
void atom::setCollisionWith(int index, float time) {
  this->tC[index] = time;
  this->collisionWith[index] = 0;
}

float atom::getCollisionTime(int index) { return tC[index]; }

int atom::getMinTimeIndex() {
  float time = INF;
  int index = -1;
  int i = 0;
  while (i < number) {
    if (tC[i] < time && collisionWith[i] == true) {
      time = tC[i];
      index = i;
    }
    i++;
  }
  return index;
}

void atom::setnumberOfAtoms(int n) {
  this->number = n;
  this->tC = new float[n];
  this->collisionWith = new bool[n];
}

void atom::setAtomTag(int tag) { this->atomTag = tag; }
