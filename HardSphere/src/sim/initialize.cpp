#include<iostream>
#include<cmath>
#include<random>

#include "initialize.hpp"
#include "../maths/Vector3.hpp"

void initialize::Initial()
{
  std::default_random_engine g1,g2,g3;
  std::normal_distribution<float> d1(0,0.1),d3(0,0.1),d2(0,0.1);
  float noLattice = std::ceil(pow(number,1/3.));
  cout<<noLattice<<endl;
  float a = 1/float(noLattice);
  int i = 1;
  while(i<number)
  {

      for(int ix=0; ix<=noLattice;ix++){
          for(int iy=0; iy<=noLattice; iy++){
            for(int iz=0;iz<=noLattice; iz++){
              Vector3 coord(ix,iy,iz);
              if (i>number) break;
              systemAtoms[i-1].setnumberOfAtoms(number);
              if(i%4==0) systemAtoms[i-1].setPosition((coord+Vector3(0.0,0.0,0.0))*a);
              else if(i%3==0) systemAtoms[i-1].setPosition((coord+Vector3(0.0,0.5,0.5))*a);
              else if(i%2) systemAtoms[i-1].setPosition((coord+Vector3(0.5,0.5,0.0))*a);
              else systemAtoms[i-1].setPosition((coord+Vector3(0.5,0,0.5))*a);
              Vector3 velocity(d1(g1),d2(g2),d3(g3));
              systemAtoms[i-1].setVelocity(velocity);

              systemAtoms[i-1].setTinit(0);
              timeCollisionInitialize(systemAtoms[i-1]);
              collisionWithInitalize(systemAtoms[i-1]);
              i=i+1;

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
  }
  void initialize::collisionWithInitalize(atom a)
  {
    for(int i=0;i<number;i++)
    {
      a.collisionWith[i]=0;
    }
  }


  bool initialize::collisionFlag(atom a, atom b)
  {
    Vector3 v12 = a.getVelocity().V12(b.getVelocity());
    Vector3 r12 = a.getPosition().V12(b.getPosition());
    float dotprod = r12.dot(v12);
    if (dotprod<0)
    {
      float disc = dotprod*dotprod - v12.square()*(r12.square()-sigma*sigma);
      if (disc >=0) return true;
    }
    return false;
  }

//returns time between collision of a and b before previous configuration
  float initialize::collisionTime(atom a, atom b)
  {
    Vector3 v12 = a.getVelocity().V12(b.getVelocity());
    Vector3 r12 = a.getPosition().V12(b.getPosition());
    float dotprod = r12.dot(v12);
    float disc = dotprod*dotprod - v12.square()*(r12.square()-sigma*sigma);
    float deltaT;
    deltaT = (-dotprod - sqrt(disc))/(v12.square());
    return deltaT;



  }


  void initialize::setSystem(int num)
  {
    number = num;
    systemAtoms =  new atom[num];

  }
