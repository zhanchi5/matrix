#include "catch.hpp"
#include "matrix.hpp"


SCENARIO("testing +"){
  Matrix<int> A(2,4);
  Matrix<int> B(2,4);
  A.LoadFromFile("Matrix1.txt");
  B.LoadFromFile("Matrix2.txt");
  
  Matrix<int> C(2,4);
  C = A + B;
  
  bool rv = true;

  if ((A+B == C)){
    return rv;
   }
   else{
     return rv = false;
   }
  REQUIRE(rv == true);
}
