#include<iostream>
#include<cmath>
#include <cstdlib>


#define T(time) ((time) < 0.0001) ? (0.0) : (time)
#define pi 3.141592653589793



#include "../src/initialize.hpp"
#include "../src/atom.hpp"
#include "../maths/Vector3.hpp"
#include "../src/simulation.hpp"
using namespace std;


int main(int argc,  char *argv[])
{

  int number_of_atoms = 4;
  float radius = 0.3;
  float epsilon = 1;
  float timeTotal = 3;
  float dt = 1;
  float length = 10;
  float mass = 1;


  simulation system;
  system.setParams(number_of_atoms,length,radius,epsilon,mass,dt,timeTotal);
  system.runSimulation();

  return 0;
}
