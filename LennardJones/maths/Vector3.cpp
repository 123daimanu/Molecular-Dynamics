
#include<cmath>

#include"Vector3.hpp"

/*
bool Vector3::operator==(Vector3 rhs)
{
    return ( x==rhs.x && y == rhs.y && z==rhs.z);

}



float Vector3::operator*(Vector3 v1)
{
	return(x*v1.x+y*v1.y+v1.z*z);
}



Vector3 Vector3::operator+(Vector3 v1)
{
	return Vector3(v1.x+x,v1.y+y,v1.z+z);

}


Vector3 Vector3::operator/(float s)
{
	return Vector3(this->x/(s),this->y/(s),this->z/(s));
}


Vector3 Vector3::operator-(Vector3 v)
{
  return ((*this)+(v*(-1.0)));
}
void Vector3::operator=(const Vector3 v)
{
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;

}

float Vector3::square()
{
	return((*this)*(*this));

}

Vector3 Vector3::operator*(float s)
{
	return Vector3(s*this->x,s*this->y,s*this->z);

}

float Vector3::dot(Vector3 A)
{
  return A.x*this->x + A.y*this->y + A.z*this->z;
}
Vector3 Vector3::V12(Vector3 V2)
{
	return V2-*this;
}
Vector3 Vector3::unit(){
	return *this/sqrt(this->square());
}

ostream &operator <<(ostream &output, const Vector3 &V)
{
	output<<"["<<V.x<<", "<<V.y<<", "<<V.z<<"]";
	return output;

}

Vector3 Vector3::Floor()
{
	return Vector3(floor(this->x),floor(this->y),floor(this->z));
}
*/
