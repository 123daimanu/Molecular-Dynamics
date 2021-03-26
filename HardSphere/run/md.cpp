#include <cmath>
#include <cstdlib>
#include <iostream>

#define T(time) ((time) < 0.0001) ? (0.0) : (time)
#define pi 3.141592653589793

//#include "../src/sim/initialize.hpp"
//#include "../src/sim/atom.hpp"
//#include "../src/maths/Vector3.hpp"
#include "../src/sim/run.hpp"
#include "../src/sim/simulation.hpp"
using namespace std;

int main(int argc, char *argv[]) {
  if (argc != 4) {
    cerr << "There must be two inputs: first is no of atoms, second is packing "
            "fraction and third is iterations"
         << endl;
    exit(1);
  }
  int number_of_atoms = atoi(argv[1]);
  float eta = atof(argv[2]);
  float radius = pow((number_of_atoms * pi) / (6 * eta), -0.33333);
  cout << "Sigma: " << radius << endl;
  int iter = atof(argv[3]);

  simulation system;
  system.setSystem(number_of_atoms, radius);
  system.Initial();
  for (int i = 0; i < iter; i++) {
    cout << i << "th collision:" << endl;
    system.getCollision();
    system.update();
    cout << "+++++++++++++++++++++++" << endl;
  }

  // int number_of_atoms=3;
  // float packingFraction =0.01;
  // int number_of_iteration = 2;
  //
  // run hardSphere;
  // hardSphere.setparams(packingFraction, number_of_iteration,
  // number_of_atoms); hardSphere.runSimulation();

  return 0;
}
