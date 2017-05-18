#include "catch.hpp"
#include "matrix.hpp"


SCENARIO("testing +"){
  Matrix<int> A(2,4);
  Matrix<int> B(2,4);
  A.LoadFromFile("Matrix1.txt");
  B.LoadFromFile("Matrix2.txt");
  
  Matrix<int> C(2,4);
  C = A + B;
  
  bool rv;

  if ((A+B == C)){
      rv == true;
   }
   else{
     rv == false;
   }
  REQUIRE(rv == true);
}
