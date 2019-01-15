#include<iostream>
#include<cmath>
#include<random>

#include "initialize.hpp"
#include "../maths/Vector3.hpp"

void initialize::Initial()
{
  for(int i=1;i<=number;i++)
  {
    
    systemAtoms[i].setPosition((1,2,3));
    systemAtoms[i].setVelocity((0,0,0));
    systemAtoms[i].setTinit(3);
    std::cout<<systemAtoms[i].getTinit()<<std::endl;
  }

}


void initialize::setnumber(int num)
{
  number=num;
}
