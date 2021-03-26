#include <cmath>

#include "../maths/Vector3.hpp"
#include "gmock/gmock.h"

using namespace testing;

class VectorTest : public Test {
 public:
  Vector3 v_zero;
  Vector3 v{1.0, 2.0, 3.0};
  Vector3 vv{2.0, 4.0, 6.0};
  float scale{2.0};
};

TEST_F(VectorTest, CheckComponentTypes) {
  ASSERT_THAT(typeid(v_zero.X()).name(), Eq(typeid(double).name()));
}

TEST_F(VectorTest, CheckComponents) {
  ASSERT_THAT(v_zero.X(), Eq(0));
  ASSERT_THAT(v_zero.Y(), Eq(0));
  ASSERT_THAT(v_zero.Z(), Eq(0));
  ASSERT_THAT(v.X(), Eq(1));
  ASSERT_THAT(v.Y(), Eq(2));
  ASSERT_THAT(v.Z(), Eq(3));
}

TEST_F(VectorTest, CheckEquality) {
  bool equals{v_zero == v_zero};
  bool unequal{v_zero == v};
  ASSERT_THAT(equals, Eq(true));
  ASSERT_THAT(unequal, Eq(false));
}

TEST_F(VectorTest, CheckVectorSum) {
  Vector3 v_sum = v + v;
  bool equals{v_sum == vv};
  ASSERT_THAT(equals, Eq(true));
}

TEST_F(VectorTest, CheckVectorScalarMultiply) {
  Vector3 v2 = v * scale;
  bool equals{v2 == vv};
  ASSERT_THAT(equals, Eq(true));
}

TEST_F(VectorTest, CheckVectorDivisionByScalar) {
  Vector3 vd2 = vv / scale;
  bool equals{vd2 == v};
  ASSERT_THAT(equals, Eq(true));
}

TEST_F(VectorTest, CheckVectorSubtraction) {
  Vector3 v0 = v - v;
  Vector3 vtest0;
  bool equals{v0 == vtest0};
  ASSERT_THAT(equals, Eq(true));
}

TEST_F(VectorTest, CheckVectorDot) {
  float dotV = v.dot(v);
  ASSERT_THAT(dotV, Eq(14));
}

TEST_F(VectorTest, CheckV12) {
  Vector3 v12{v_zero.V12(v)};
  Vector3 v21{v.V12(v_zero)};
  Vector3 negV{v * (-1)};

  bool v12Equals{v12 == v};
  bool v21Equals{v21 == negV};

  ASSERT_THAT(v12Equals, Eq(true));
  ASSERT_THAT(v21Equals, Eq(true));
}

TEST_F(VectorTest, CheckUnitDistance) {
  Vector3 v_unit{v.unit()};
  Vector3 vUnitTest{v / sqrt(v.dot(v))};

  bool vUnitEquals{v_unit == vUnitTest};

  ASSERT_THAT(vUnitEquals, Eq(true));
}
