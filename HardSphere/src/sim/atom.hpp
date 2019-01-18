#ifndef ATOM_HPP
#define ATOM_HPP

#include "../maths/Vector3.hpp"


class atom{
  public:
    int number; // total number of atom in system
    float tI; // time at current confugration
    float *tC; // keeps track of collision time with the atoms
    Vector3 pos;// velocity at current configuration
    Vector3 vel; // velocity at current configuration
    int *collisionWith; // keeps track with index of colliding atom

    atom(){}

    ~atom(){};

    void setTinit(float tinit);
    float getTinit();

    void setPosition(Vector3 pos);
    Vector3 getPosition();

    void setVelocity(Vector3 velocity);
    Vector3 getVelocity();

    void setCollisionWith(int index, float time);
    float getCollisionTime( int index);

    int getMinTcIndex();

    void setnumberOfAtoms(int n);

};

#endif
