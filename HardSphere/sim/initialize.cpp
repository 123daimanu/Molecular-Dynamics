#include<iostream>
#include<cmath>
#include<random>

#include "initialize.hpp"
#include "../maths/Vector3.hpp"

void initialize::Initial()
{
  //int latticeNumbers = ceil(std::pow(number,1/3.));
  //float a = 1/latticeNumbers;
  for(int i=0;i<=number;i++)
  {
    std::cout<<&systemAtoms<<std::endl;
    (systemAtoms+i)->setPosition((1,2,3));
    (systemAtoms+i)->setVelocity((0,0,0));
    (systemAtoms+i)->setTinit(0);

  }

}


void initialize::setnumber(int num)
{
  number=num;
}
