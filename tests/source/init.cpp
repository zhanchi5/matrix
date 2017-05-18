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
  for (unsigned int =0; i < 2; ++i){
    for (unsigned int j=0; j < 4; ++j){
      if ((A[i][j]+B[i][j])==C[i][j]){
        return rv;
      }
      else{
        return rv = false;
      }
    }
  }
  REQUIRE(rv == true);

}
