#ifndef ATOM_HPP
#define ATOM_HPP

#include "../maths/Vector3.hpp"

#define T(time) ((time) < 0.0001) ? (0.0) : (time)

class atom{
  public:
    int atomTag; //tag for the atom
    int number; // total number of atom in system
    Vector3 pos;// velocity at current configuration
    Vector3 vel; // velocity at current configuration
    Vector3 force; //force on atom

    atom():force(Vector3(0,0,0)){
    };

    ~atom(){
    };


    void setPosition(Vector3 pos);
    Vector3 getPosition();

    void setVelocity(Vector3 velocity);
    Vector3 getVelocity();

    void setnumberOfAtoms(int n);
    void setAtomTag(int tag);

};

#endif
