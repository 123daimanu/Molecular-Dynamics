#ifndef INITIALIZE_HPP
#define INITIALIZE_HPP

#include "../maths/Vector3.hpp"
#include "atom.hpp"


class initialize{

  public:
    int number;
    atom *systemAtoms;
    float sigma;
    float epsilon;
    float mass;
    float length;
    float latConst;

    initialize(){};
    ~initialize(){};
    void setSystemAtoms();
    void setForce(atom &A);
    Vector3 calcForce(Vector3 r1, Vector3 r2);
    void Initial();
};


#endif
