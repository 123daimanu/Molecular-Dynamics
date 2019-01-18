#include<iostream>


#include "../src/sim/initialize.hpp"
#include "../src/sim/atom.hpp"
#include "../src/maths/Vector3.hpp"
#include "../src/sim/simulation.hpp"
using namespace std;


int main(int argc, char **argv)
{

  int number_of_atoms=1000;
  float sigma =0.2;
  simulation system;
  system.setSystem(number_of_atoms,sigma);
  system.Initial();
  system.getCollision();
  cout<<system.collT<<endl;
  cout<<system.collisionPair[0]<<endl;
  cout<<system.collisionPair[1]<<endl;
}
