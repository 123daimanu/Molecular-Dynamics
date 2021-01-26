#ifndef VECTOR3_HPP
#define VECTOR3_HPP

#include <iostream>
using namespace std;
class Vector3
{

    public:

	double x,y,z;

    Vector3():x(0),y(0),z(0){}
    Vector3(double xcomp, double ycomp,double zcomp):x(xcomp),y(ycomp),z(zcomp){}

    //copy constructor
    Vector3(const Vector3& v){
        x = v.x;
        y = v.y;
        z = v.z; 
    }

	~Vector3(){};

    double X()const
    {
        return x;
    }
    double Y()const
    {
        return y;
    }
    double Z()const
    {
        return z;
    }

bool operator==(Vector3& rhs) const
{
    return (x == rhs.X() && y == rhs.Y() && z == rhs.Z());
}

Vector3 operator*(const Vector3& v1);



void operator=(const Vector3& v);

Vector3 operator+ (const Vector3& v);
Vector3 operator*(float s);

Vector3 operator/(float s);

	Vector3	operator-(Vector3 v);

  float dot(Vector3 A);

 float square();
	Vector3 V12(Vector3 V2);
	Vector3 unit();
	friend ostream & operator <<(ostream &output, const Vector3 &V);

	Vector3 Floor();






};

#endif
