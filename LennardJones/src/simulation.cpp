
#include<limits>
#include<iostream>
#include <cstdlib>
#include<cmath>
#include<fstream>

#include "simulation.hpp"
#include "initialize.hpp"
#include "atom.hpp"
#include "../maths/Vector3.hpp"

#define INF std::numeric_limits<float>::infinity();
#define PI 3.141592654

simulation::simulation():initialize(){}

void simulation::setParams(int num,float l, float r, float ene, float m,float timeinterval, int Totaltime  )
{
  number = num;
  t = Totaltime; // in fs
  dt = timeinterval; // in fs
  sigma = r;  // in ang
  epsilon = ene; // in kcal/mol
  mass = m; // in amu
  length = l; // in ang
  systemAtoms = new atom [num];


}

void simulation::update()
{

  //move A
  for(int i = 0; i< number ; i++)
  {

    this->systemAtoms[i].vel = this->systemAtoms[i].vel + ((this->systemAtoms[i].force)/2)*(dt/2);
    this->systemAtoms[i].pos = this->systemAtoms[i].pos + (this->systemAtoms[i].vel)*dt;
    periodicBoundary(this->systemAtoms[i]);
  }

  //doforce
  for(int i = 0; i< number ; i++)
  {
    this->setForce(this->systemAtoms[i]);
  }

  //move B

  for(int i = 0; i< number ; i++)
  {

    this->systemAtoms[i].vel = this->systemAtoms[i].vel + ((this->systemAtoms[i].force)/2)*(dt/2);

  }
}

void simulation::runSimulation()
{
  ofstream outfile;
  outfile.open("order.dat");
  outfile<<"## time\t order"<<endl;
  Initial();
  while(simtime <= t)
  {
    outfile.open("order.dat",std::ios_base::app);
    velocityInCM();
    update();
    velocityInCM();
    //writefile
    outfile<<simtime<<"\t"<<orderParameter()<<endl;
    simtime += dt;
    outfile.close();
  }
}

//Restricted periodic boundary condition
void simulation::periodicBoundary(atom &A)
{
  A.setPosition(A.pos-((A.pos/length).Floor())*length);
}


void simulation::velocityInCM()
{
  Vector3 vcm(0,0,0);
  for(int i=0;i<number;i++)
  {
    vcm = vcm + this->systemAtoms[i].vel/number;

  }
  for(int i=0;i<number;i++)
  {
    this->systemAtoms[i].setVelocity(systemAtoms[i].vel-vcm);

  }
}

float simulation::orderParameter()
{
  float lx(0),ly(0),lz(0);
  for(int i = 0; i < number ; i++)
  {
    lx = lx + cos(4*PI*(this->systemAtoms[i].pos.x)/latConst);
    ly = ly + cos(4*PI*(this->systemAtoms[i].pos.y)/latConst);
    lz = lz + cos(4*PI*(this->systemAtoms[i].pos.z)/latConst);
  }
  return((lx+ly+lz)/(3*number));
}
