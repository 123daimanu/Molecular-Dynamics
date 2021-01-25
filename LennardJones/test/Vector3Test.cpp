#include "gmock/gmock.h"


#include "../maths/Vector3.hpp"

using namespace testing;

class VectorTest: public Test{
    public:
    Vector3 v_zero; 
    Vector3 v{1.0,2.0,3.0};
    Vector3 vv{2.0,4.0,6.0};
    float scale{2.0};

};


TEST_F(VectorTest,CheckComponentTypes){
    ASSERT_THAT(typeid(v_zero.X()).name(), Eq(typeid(double).name()));
}


TEST_F(VectorTest, CheckComponents){
    ASSERT_THAT(v_zero.X(),Eq(0));
    ASSERT_THAT(v_zero.Y(),Eq(0));
    ASSERT_THAT(v_zero.Z(),Eq(0));
    ASSERT_THAT(v.X(),Eq(1));
    ASSERT_THAT(v.Y(),Eq(2));
    ASSERT_THAT(v.Z(),Eq(3));


}

TEST_F(VectorTest, CheckEquality){
   bool equals{v_zero == v_zero};
   bool unequal{v_zero == v};
    ASSERT_THAT(equals,Eq(true));
    ASSERT_THAT(unequal,Eq(false));
}



TEST_F(VectorTest, CheckVectorSum){
    Vector3 v_sum = v + v;
    bool equals{v_sum == vv};
    ASSERT_THAT(equals, Eq(true));

}

TEST_F(VectorTest, CheckVectorScalarMultiply){
    Vector3 v2 = v*scale;
    bool equals{v2 == vv};
    ASSERT_THAT(equals, Eq(true));

}

TEST_F(VectorTest, CheckVectorDivisionByScalar){
    Vector3 vd2 = vv/scale;
    bool equals{vd2 == v};
    ASSERT_THAT(equals, Eq(true));

}

