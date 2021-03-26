
#include "Vector3.hpp"

#include <cmath>

Vector3 Vector3::operator*(const Vector3& v1) {
  return Vector3(x * v1.X(), y * v1.Y(), z * v1.Z());
}

void Vector3::operator=(const Vector3& v) {
  x = v.X();
  y = v.Y();
  z = v.Z();
}
Vector3 Vector3::operator+(const Vector3& v1) {
  return Vector3(v1.X() + x, v1.Y() + y, v1.Z() + z);
}

Vector3 Vector3::operator*(float s) { return Vector3(s * x, s * y, s * z); }

Vector3 Vector3::operator/(float s) { return Vector3(x / s, y / s, z / s); }

Vector3 Vector3::operator-(Vector3 v) { return ((*this) + (v * (-1.0))); }

float Vector3::square() { return ((*this).dot(*this)); }

float Vector3::dot(Vector3 A) { return A.x * x + A.y * y + A.z * z; }
Vector3 Vector3::V12(Vector3 V2) { return V2 - *this; }
Vector3 Vector3::unit() { return *this / sqrt(this->square()); }

ostream& operator<<(ostream& output, const Vector3& V) {
  output << "[" << V.x << ", " << V.y << ", " << V.z << "]";
  return output;
}

Vector3 Vector3::Floor() {
  return Vector3(floor(this->x), floor(this->y), floor(this->z));
}
