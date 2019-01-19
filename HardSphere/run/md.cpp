#include<iostream>


#include "../src/sim/initialize.hpp"
#include "../src/sim/atom.hpp"
#include "../src/maths/Vector3.hpp"
#include "../src/sim/simulation.hpp"
#include "../src/sim/run.hpp"
using namespace std;


int main(int argc, char **argv)
{

  int number_of_atoms=2;
  float packingFraction =0.2;
  int number_of_iteration = 2;

  run hardSphere;
  hardSphere.setparams(packingFraction, number_of_iteration, number_of_atoms);
  hardSphere.runSimulation();
}
