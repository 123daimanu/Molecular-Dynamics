#ifndef INITIALIZE_HPP
#define INITIALIZE_HPP

#include "../maths/Vector3.hpp"
#include "atom.hpp"


class initialize{

  public:
    int number;
    atom *systemAtoms;
    float sigma;
    float energy;
    float mass;
    float length;

    initialize(){};
    ~initialize(){};
    void setSystemAtoms()
    void setForce(atom &A)
    Vector3 calcForce(Vector3 r1, Vector r2)
    void Initial();
};


#endif
