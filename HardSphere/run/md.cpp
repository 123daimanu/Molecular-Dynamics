#include<iostream>


#include "../sim/initialize.cpp"

using namespace std;


int main()
{
  int number_of_atoms=10;
  initialize system;
  system.setnumber(number_of_atoms);
  //system.Initial();
  cout<<"address of system"<<system.systemAtoms<<endl;
}
