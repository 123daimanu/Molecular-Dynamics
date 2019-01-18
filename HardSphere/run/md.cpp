#include<iostream>


#include "../src/sim/initialize.hpp"
#include "../src/sim/atom.hpp"
#include "../src/maths/Vector3.hpp"
#include "../src/sim/simulation.hpp"
using namespace std;


int main(int argc, char **argv)
{

  int number_of_atoms=2;
  float sigma =0.2;
  simulation system;
  system.setSystem(number_of_atoms,sigma);
  system.Initial();
  system.systemAtoms[0].setVelocity(Vector3(0,0,0));
  system.systemAtoms[1].setVelocity(Vector3(0,0.25,-0.75));
  system.CollisionInitialize(system.systemAtoms[0]);
  system.CollisionInitialize(system.systemAtoms[1]);
  system.getCollision();

}
