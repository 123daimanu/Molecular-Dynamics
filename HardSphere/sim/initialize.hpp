#ifndef INITIALIZE_HPP
#define INITIALIZE_HPP

#include "../maths/Vector3.hpp"
#include "atom.hpp"
class initialize{

  public:
    int number;
    atom *systemAtoms;

    initialize(){}
    ~initialize(){};
    void Initial();
    void setnumber(int num);

    //void velocityInitial()
    //void timeInitialize()
    //void timeCollisionInitialize()
    //void collisionWithInitalize()


};


#endif
