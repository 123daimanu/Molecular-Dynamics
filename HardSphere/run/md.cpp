#include<iostream>


#include "../src/sim/initialize.hpp"
#include "../src/sim/atom.hpp"
#include "../src/maths/Vector3.hpp"
using namespace std;


int main(int argc, char **argv)
{

  int number_of_atoms=100;
  initialize system;
  system.setSystem(number_of_atoms);
  system.Initial();
    cout<<"address of system "<<(system.systemAtoms)<<endl;

  for(int i=0;i<number_of_atoms;i++)
  {
    cout<<"Velocity of "<< i+1 <<"atom : " << (system.systemAtoms[i]).getVelocity()<< endl;
  }

}
