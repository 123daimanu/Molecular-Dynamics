#include<iostream>
#define T(time) ((time) < 0.0001) ? (0.0) : (time)

#include "../src/sim/initialize.hpp"
#include "../src/sim/atom.hpp"
#include "../src/maths/Vector3.hpp"
#include "../src/sim/simulation.hpp"
#include "../src/sim/run.hpp"
using namespace std;


int main(int argc, char **argv)
{

  int number_of_atoms=32;
  float radius = .1;
  int iter = 3;


  simulation system;
  system.setSystem(number_of_atoms,radius);
  system.Initial();
  for(int i = 0; i<iter ; i++)
  {
    system.getCollision();
    cout<<"Before: "<<system.systemAtoms[0].getPosition()<<endl;
    system.update();
    cout<<"After: "<<system.systemAtoms[0].getPosition()<<endl;
    cout<< system.collT<<endl;
  }




  // float packingFraction =0.2;
  // int number_of_iteration = 2;
  //
  // run hardSphere;
  // hardSphere.setparams(packingFraction, number_of_iteration, number_of_atoms);
  // hardSphere.runSimulation();

  return 0;
}
