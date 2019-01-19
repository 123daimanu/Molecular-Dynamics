#include<iostream>
#include<cmath>
#include<random>

#include "initialize.hpp"
#include "../maths/Vector3.hpp"

void initialize::Initial()
{
  std::mt19937 g1;
  std::default_random_engine g2;
  std::ranlux48 g3;
  std::normal_distribution<float> d1(0,0.1);
  std::normal_distribution<float> d3(0,0.1);
  std::normal_distribution<float> d2(0,0.1);
  float noLattice = std::ceil(pow(number,1/3.));
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
              systemAtoms[i-1].setAtomTag(i-1);
              if(i%4==0) systemAtoms[i-1].setPosition((coord+Vector3(0.0,0.0,0.0))*a);
              else if(i%3==0) systemAtoms[i-1].setPosition((coord+Vector3(0.0,0.5,0.5))*a);
              else if(i%2) systemAtoms[i-1].setPosition((coord+Vector3(0.5,0.5,0.0))*a);
              else systemAtoms[i-1].setPosition((coord+Vector3(0.5,0,0.5))*a);
              Vector3 velocity(d1(g1),d2(g2),d3(g3));
              systemAtoms[i-1].setVelocity(velocity);
              systemAtoms[i-1].setTinit(0);
              systemAtoms[i-1].tC[i-1] = 0;
              systemAtoms[i-1].collisionWith[i-1] = false;

              i=i+1;

          }
        }
      }
    }
    for(int i =0; i<number; i++) CollisionTimeInitialize(systemAtoms[i]);


  }

void initialize::CollisionTimeInitialize(atom A)
{
  for(int i=0;i<number;i++)
  {
    bool colFlag = collisionFlag(A,systemAtoms[i]);
    if (colFlag){
      float coltime = collisionTime(A, systemAtoms[i]);
      if(coltime > 0){
        A.tC[i] = coltime;
        A.collisionWith[i] = true;
      }
    }
    else{
      A.tC[i] = 0;
      A.collisionWith[i] = false;
    }

  }

}


void initialize::CollisionTimeUpdate(atom A)
{
  for(int i=0;i<number;i++)
  {
    bool colFlag = collisionFlag(A,systemAtoms[i]);
    if (colFlag){
      float coltime = collisionTime(A, systemAtoms[i]);
      if(coltime > 0){
        A.tC[i] = coltime + A.tI;
        A.collisionWith[i] = true;
      }
    }
    else{
      A.tC[i] = A.tI;
      A.collisionWith[i] = false;
    }

  }
}



bool initialize::collisionFlag(atom A, atom B)
{
  Vector3 v12 = A.getVelocity().V12(B.getVelocity());
  Vector3 r12 = A.getPosition().V12(B.getPosition());
  float dotprod = r12.dot(v12);
  if (dotprod<0)
  {
    float disc = dotprod*dotprod - v12.square()*(r12.square()-sigma*sigma);
    if (disc >=0) return true;
  }
  return false;
}

//returns time between collision of a and b before previous configuration
float initialize::collisionTime(atom A, atom B)
{
  Vector3 v12 = A.getVelocity().V12(B.getVelocity());
  Vector3 r12 = A.getPosition().V12(B.getPosition());
  float dotprod = r12.dot(v12);
  float disc = dotprod*dotprod - v12.square()*(r12.square()-sigma*sigma);
  float deltaT;
  deltaT = (-dotprod - sqrt(disc))/(v12.square());
  return deltaT;
}

void initialize::setSystem(int num,float radius)
{
  number = num;
  systemAtoms =  new atom[num];
  sigma = radius;
}
