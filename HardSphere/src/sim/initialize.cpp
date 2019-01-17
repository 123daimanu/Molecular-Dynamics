#include<iostream>
#include<cmath>
#include<random>

#include "initialize.hpp"
#include "../maths/Vector3.hpp"

void initialize::Initial()
{
  std::default_random_engine generator;
  std::normal_distribution<float> distributions(0,0.1);
  float noLattice = std::ceil(pow(number,1/3.));
  float a = 1/float(noLattice);
  int i = 1;
  while(i<number)
  {
    if(i<=number){
      for(int ix=0; ix<=noLattice;ix++){
          for(int iy=0; iy<=noLattice; iy++){
            for(int iz=0;iz<=noLattice; iz++){
              Vector3 coord(ix,iy,iz);
              if(i%4==0) systemAtoms[i-1].setPosition((coord+Vector3(0.0,0.0,0.0))*a);
              else if(i%3==0) systemAtoms[i-1].setPosition((coord+Vector3(0.0,0.5,0.5))*a);
              else if(i%2) systemAtoms[i-1].setPosition((coord+Vector3(0.5,0.5,0.0))*a);
              else systemAtoms[i-1].setPosition((coord+Vector3(0.5,0,0.5))*a);

              systemAtoms[i-1].setVelocity((distributions(generator),distributions(generator),distributions(generator)));

              systemAtoms[i-1].setTinit(0);
              timeCollisionInitialize(systemAtoms[i-1]);
              collisionWithInitalize(systemAtoms[i-1]);
              i++;
            }
          }
        }
      }
    }
  }



  void initialize::timeCollisionInitialize(atom a)
  {
    for(int i=0;i<number;i++)
    {
      a.tC[i]=-1;
    }
    a.tC[number]=-999;
  }
  void initialize::collisionWithInitalize(atom a)
  {
    for(int i=0;i<number;i++)
    {
      a.collisionWith[i]=0;
    }
    a.collisionWith[number]=-999;
  }
