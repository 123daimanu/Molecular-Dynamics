#ifndef ATOM_HPP
#define ATOM_HPP

#include "../maths/Vector3.hpp"


class atom{
  public:
    float tI;
    float* tC;
    Vector3 pos;
    Vector3 vel;
    int* collisionWith;

    atom(){}

    ~atom(){};

    void setTinit(float tinit);
    float getTinit();
/*
    void setTcol(float tCol,int index);
    float* getTcol();
*/
    void setPosition(Vector3 pos);
    Vector3 getPosition();

    void setVelocity(Vector3 velocity);
    Vector3 getVelocity();

    void setCollisionWith(int index);
    int* getCollisionWith();

    int getMinTc();
};

#endif
