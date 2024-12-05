#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

namespace Matrices
{
    class Matrix
    {
    public:
        /// Construct a matrix of the specified size.
        /// Initialize each element to 0.
        Matrix(int _rows, int _cols);

        ///************************************
        /// Inline accessors/mutators, these are done:

        /// Read element at row i, column j
        /// usage: double x = a(i, j);
        const double &operator()(int i, int j) const
        {
            return a.at(i).at(j);
        }

        /// Write element at row i, column j
        /// usage: a(i, j) = x;
        double &operator()(int i, int j)
        {
            return a.at(i).at(j);
        }

        int getRows() const { return rows; }
        int getCols() const { return cols; }
        ///************************************

    private:
        vector<vector<double>> a; ///< 2D array to store matrix elements
        int rows;                 ///< Number of rows
        int cols;                 ///< Number of columns
    };

    /// Add each corresponding element.
    /// usage: c = a + b;
    Matrix operator+(const Matrix &a, const Matrix &b);

    /// Matrix multiply. See description.
    /// usage: c = a * b;
    Matrix operator*(const Matrix &a, const Matrix &b);

    /// Matrix comparison. See description.
    /// usage: a == b
    bool operator==(const Matrix &a, const Matrix &b);

    /// Matrix comparison. See description.
    /// usage: a != b
    bool operator!=(const Matrix &a, const Matrix &b);

    /// Output matrix.
    /// Separate columns by ' ' and rows by '\n'
    ostream &operator<<(ostream &os, const Matrix &a);
}

#endif // MATRIX_H_INCLUDED
