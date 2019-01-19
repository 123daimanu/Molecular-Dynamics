#ifndef ATOM_HPP
#define ATOM_HPP

#include "../maths/Vector3.hpp"


class atom{
  public:
    int atomTag; //tag for the atom
    int number; // total number of atom in system
    float tI; // time at current confugration
    float *tC; // keeps track of collision time with the atoms
    Vector3 pos;// velocity at current configuration
    Vector3 vel; // velocity at current configuration
    bool *collisionWith; // keeps track with index of colliding atom

    atom(){
      tI = 0;
    };

    ~atom(){
    };

    void setTinit(float tinit);
    float getTinit();

    void setPosition(Vector3 pos);
    Vector3 getPosition();

    void setVelocity(Vector3 velocity);
    Vector3 getVelocity();

    void setCollisionWith(int index, float time);
    float getCollisionTime( int index);

    int getMinTimeIndex();

    void setnumberOfAtoms(int n);
    void setAtomTag(int tag);

};

#endif
