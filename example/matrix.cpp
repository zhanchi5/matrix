#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    Matrix<int> A(2, 4);
    Matrix<int> B(2, 4);
    Matrix<int> D(4, 4);

    A.LoadFromFile("/home/theflash/Programming/CLionProjects/bmstu_lab7/Matrix1.txt");
    B.LoadFromFile("/home/theflash/Programming/CLionProjects/bmstu_lab7/Matrix2.txt");
    D.LoadFromFile("/home/theflash/Programming/CLionProjects/bmstu_lab7/Matrix3.txt");

    cout << A << endl;
    cout << B<< endl;
    cout << D << endl;

    if (A == A) cout << true << endl;
    cout << endl;

    Matrix<int> C(2,4);
    C = A + B;
    cout << C << endl;

    C = A * D;
    cout << C << endl;



    return 0;
}
