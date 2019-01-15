#include<iostream>


#include "../sim/initialize.hpp"

using namespace std;


int main()
{
  int number_of_atoms=10;
  initialize system(number_of_atoms);
  system.setnumber(number_of_atoms);
  system.Initial();
  cout<<"address of system "<<(system.systemAtoms)<<endl;

  /*for(int i=1;i<=number_of_atoms;i++)
  {
    cout<<"Position of "<< i <<"atom : " << (system.systemAtoms[i]).getPosition().x<< endl;
  }*/
}
