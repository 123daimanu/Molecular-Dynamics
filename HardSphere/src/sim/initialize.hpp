#ifndef INITIALIZE_HPP
#define INITIALIZE_HPP

#include "../maths/Vector3.hpp"
#include "atom.hpp"


class initialize{

  public:
    int number;
    atom systemAtoms[1000];

    initialize(int num):number(num)
	{
	}
    ~initialize(){};
    void Initial();
    void timeCollisionInitialize(atom a);
    void collisionWithInitalize(atom a);


};


#endif
