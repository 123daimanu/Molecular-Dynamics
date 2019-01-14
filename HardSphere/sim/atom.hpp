#ifndef ATOM_HPP
#define ATOM_HPP

#include "maths/Vector3.hpp"


struct propAtom{

  float tInit;
  float tCol;
  Vector3 pos;
  Vector3 vel;
  int collisionWith;

};


class atom{

  struct propAtom atom1;

  atom(float tInit, float tCol, Vector3 pos, Vector3 vel, int collisionWith):atom1()
  {
      atom1.tInit=tInit;
      atom1.tCol=tCol;
      atom1.pos = pos;
      atom1.vel = vel;
      atom1.collisionWith = collisionWith;
  }

  ~atom{};

    void setTinit(double tinit);
    double getTinit();

    void setTcol(double tCol);
    double getTcol();

    void setPos(Vector3 pos);
    Vector3 getPos();

    void setVelocity(Vector3 velocity);
    Vector3 getVelocity();

    void setCollisionWith(int);
    int getCollisionWith();
}

#endif
