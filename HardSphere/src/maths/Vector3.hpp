#ifndef VECTOR3_HPP
#define VECTOR3_HPP

#include <iostream>
using namespace std;


class Vector3
{
	public:
	float x,y,z;



	Vector3(float xcomp=0,float ycomp=0,float zcomp=0):x(xcomp),y(ycomp),z(zcomp){}
	~Vector3(){};


	float operator*(Vector3 v1);

	Vector3 operator+(Vector3 v);

	Vector3 operator/(float s);

	Vector3	operator-(Vector3 v);

	Vector3 operator*(float s);
	void operator=(const Vector3 v);
  float dot(Vector3 A);

  float square();
	Vector3 V12(Vector3 V2);
	Vector3 unit();
	friend ostream & operator <<(ostream &output, const Vector3 &V);

	Vector3 Floor();







};

#endif
