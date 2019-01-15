#ifndef ATOM_HPP
#define ATOM_HPP

#include "../maths/Vector3.hpp"


class atom{
  public:
    float tI;
    float tC[1000];
    Vector3 pos;
    Vector3 vel;
    int collisionWith[1000];

    atom(){}

    ~atom(){};

    void setTinit(float tinit);
    float getTinit();

    void setPosition(Vector3 pos);
    Vector3 getPosition();

    void setVelocity(Vector3 velocity);
    Vector3 getVelocity();

    void setCollisionWith(int index, float time);
    float getCollisionTime( int index);

    int getMinTcIndex();

};

#endif
