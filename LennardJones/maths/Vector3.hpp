#ifndef VECTOR3_HPP
#define VECTOR3_HPP

#include <iostream>
using namespace std;
template<typename T>
class Vector3
{
	private:
	   T x,y,z;

    public:


    Vector3():x(static_cast<T>(0)),y(static_cast<T>(0)),z(static_cast<T>(0)){};
    Vector3(T xcomp,T ycomp,T zcomp):x(xcomp),y(ycomp),z(zcomp){};
	~Vector3(){};

T X()const
{
    return x;
};
T Y()const
{
    return y;
};
T Z()const
{
    return z;
};
//bool operator==(Vector3& rhs) const;

/*
	auto operator*(Vector3 v1);

    auto operator+(Vector3 v);

	auto operator/(float s);

	Vector3	operator-(Vector3 v);

	Vector3 operator*(float s);
	void operator=(const Vector3 v);
  float dot(Vector3 A);

  float square();
	Vector3 V12(Vector3 V2);
	Vector3 unit();
	friend ostream & operator <<(ostream &output, const Vector3 &V);

	Vector3 Floor();

*/





};

#endif
