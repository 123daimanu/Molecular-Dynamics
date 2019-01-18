#ifndef VECTOR3_HPP
#define VECTOR3_HPP

#include <iostream>
using namespace std;


class Vector3
{
	public:
	double x,y,z;



	Vector3(double xcomp=0,double ycomp=0,double zcomp=0):x(xcomp),y(ycomp),z(zcomp){}
	~Vector3(){};


	double operator*(Vector3 v1);

	Vector3 operator+(Vector3 v);

	Vector3 operator/(double s);

	Vector3	operator-(Vector3 v);

	Vector3 operator*(double s);
	void operator=(const Vector3 &v);
  double dot(Vector3 A);

  double square();
	Vector3 V12(Vector3 V2);
	Vector3 unit();
	friend ostream & operator <<(ostream &output, const Vector3 &V);







};

#endif
