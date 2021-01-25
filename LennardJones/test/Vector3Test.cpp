#include "gmock/gmock.h"


#include "../maths/Vector3.hpp"

using namespace testing;

class VectorTest: public Test{
    public:
    Vector3<int> v_int_zero;
    Vector3<float> v_float_zero;
    Vector3<int> v_int{1,2,3};
    Vector3<float> v_float{1.0,2.0,3.0};
    float scale{2.0};

};


TEST_F(VectorTest,CheckComponentTypes){
    ASSERT_THAT(typeid(v_int_zero.X()).name(), Eq(typeid(int).name()));
    ASSERT_THAT(typeid(v_float_zero.X()).name(), Eq(typeid(float).name()));
    ASSERT_THAT(typeid(v_int.X()).name(), Eq(typeid(int).name()));
    ASSERT_THAT(typeid(v_float.X()).name(), Eq(typeid(float).name()));
}


TEST_F(VectorTest, CheckComponents){
    ASSERT_THAT(v_int_zero.X(),Eq(0));
    ASSERT_THAT(v_int_zero.Y(),Eq(0));
    ASSERT_THAT(v_int_zero.Z(),Eq(0));
    ASSERT_THAT(v_int.X(),Eq(1));
    ASSERT_THAT(v_int.Y(),Eq(2));
    ASSERT_THAT(v_int.Z(),Eq(3));


}
