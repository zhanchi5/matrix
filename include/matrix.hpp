#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

template <typename type>
class Matrix
{
private:
    unsigned int Rows_;
    unsigned int Columns_;
    type ** Mtrx_;
public:
    Matrix() {
        Rows_ = 0;
        Columns_ = 0;
        Mtrx_ = nullptr;
    }
    Matrix(unsigned int r, unsigned int c) {
        Rows_ = r;
        Columns_ = c;
        Mtrx_ = new type*[Rows_];
        for (unsigned int i = 0; i < Columns_; ++i) Mtrx_[i] = new type[Columns_];
    }
    ~Matrix() {

    }
    void LoadFromFile(string filename)
    {
        ifstream in(filename);
        try {
            if (in) {
                for (unsigned int i = 0; i < Rows_; ++i)
                    for (unsigned int j = 0; j < Columns_; ++j)
                        in >> Mtrx_[i][j];
            }
            else throw false;
        }
        catch (bool i) {
            cout << "Error" << endl;

        }
    }
    void Output(ostream&) {
        for (unsigned int i = 0; i < Rows_; ++i) {
            for (unsigned int j = 0; j < Columns_; ++j)
                cout << Mtrx_[i][j] << " ";
            cout << endl;
        }

    }
    Matrix operator+ (const Matrix& buf) const {
        try {
            if ((Rows_ == buf.Rows_) && (Columns_ == buf.Columns_)) {
                Matrix getRes(Rows_, Columns_);
                for (unsigned int i = 0; i < Rows_; ++i)
                    for (unsigned int j = 0; j < Columns_; ++j)
                        getRes.Mtrx_[i][j] = Mtrx_[i][j] + buf.Mtrx_[i][j];
                return getRes;
            }
            else {
                throw false;
            }
        }
        catch (bool i) {
            cout << "Error: " << endl;
            return *this;
        }
    }
    Matrix operator* (const Matrix& buf) const {
        try {
            if ((Columns_ == buf.Rows_)) {
                Matrix Result(Rows_, buf.Columns_);
                for (unsigned int i = 0; i < Rows_; ++i) {
                    for (unsigned int j = 0; j < buf.Columns_; ++j) {
                        Result.Mtrx_[i][j] = 0;
                        for (unsigned int k = 0; k < Columns_; ++k)
                            Result.Mtrx_[i][j] += Mtrx_[i][k] * buf.Mtrx_[k][j];
                    }
                }
                return Result;
            }
            else {
                throw false;
            }
        }
        catch (bool i) {
            cout << "Error" << endl;
            return *this;
        }
    }
    Matrix & operator = (const Matrix& buf) {
        Mtrx_ = new int*[buf.Rows_];
        for (unsigned int i = 0; i < buf.Rows_; ++i) {
            Mtrx_[i] = new int[buf.Columns_];
            for (unsigned int j = 0; j < buf.Columns_; ++j)
                Mtrx_[i][j] = buf.Mtrx_[i][j];
        }
        Rows_ = buf.Rows_;
        Columns_ = buf.Columns_;
        return *this;
    }
    bool operator == (const Matrix& buf) const {
        if ((Rows_ == buf.Rows_) && (Columns_ == buf.Columns_)) {
            for (unsigned int i = 0; i < Rows_; ++i)
                for (unsigned int j = 0; j < Columns_; ++j) {
                    if (Mtrx_[i][j] != buf.Mtrx_[i][j]) { return false; }
                }
            return true;
        }
        else return false;
    }
    template <typename K>friend ostream& operator << (ostream& out, const Matrix<K> & buf);
    template <typename U> friend istream& operator >> (istream& in, Matrix<U> & buf);


};
template <typename type> istream & operator >> (istream & in, Matrix<type> & buf)
{
    for (unsigned int i = 0; i < buf.Rows_; ++i)
        for (unsigned int j = 0; j < buf.Columns_; ++j)
            in >> buf.Mtrx_[i][j];
    return in;
}
template <typename type> ostream& operator<< (ostream& out, const Matrix<type> & buf) {
    for (unsigned int i = 0; i < buf.Rows_; ++i) {
        for (unsigned int j = 0; j < buf.Columns_; ++j)
            cout << setw(8) << buf.Mtrx_[i][j] << " ";
        cout << endl;
    }
    return out;
}
