#ifndef INITIALIZE_HPP
#define INITIALIZE_HPP

#include "../maths/Vector3.hpp"
#include "atom.hpp"


class initialize{

  public:
    int number;
    atom *systemAtoms;
    float sigma;

    initialize():number(0){};
    ~initialize(){};
    void Initial();
    void setSystem(int num, float radius);
    void CollisionTimeUpdate(atom a);
    void CollisionTimeInitialize(atom A);
    bool collisionFlag(atom a, atom b);
    float collisionTime(atom a, atom b);



};


#endif
