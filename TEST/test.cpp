#include <iostream>
#include <vector>
#include <iomanip>

using std::cout, std::vector, std::setw;

// A function that multiplies matrix A by vector x
vector<double> MatrixMultiplication(vector<vector<double>> &A, vector<double> &x)
{
    vector<double> result;
    result.reserve(4);

    for (int i = 0; i < A.size(); i++)
        for (int j = 0; j < A[i].size(); j++)
            result[i] += A[i][j] * x[j];

    return result;
}

// A function that prints matrix A
void PrintMatrix(vector<vector<double>> &matrix)
{
    for (auto &row : matrix)
    {
        for (auto &element : row)
            cout << setw(12) << element;

        cout << '\n';
    }
}

// A function that prints vector x
void PrintMatrix(vector<double> &array)
{
    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i] << ' ';
    }
}

int main()
{
    // A matrix A
    vector<vector<double>> A = {{0.0625, -0.0379, -0.0713, 0.0932},
                                {-0.0379, 0.0322, 0.0419, -0.0746},
                                {-0.0713, 0.0419, 0.1018, -0.1204},
                                {0.0932, -0.0746, -0.1204, 0.2317}};

    // A vector x0
    vector<double> x0 = {1, 0, 0, 0}, r0;

    // A vector b
    vector<double> b = {0.1528, -0.0985, -0.2474, 0.3872};

    // An accuracy epsilon
    const double eps = 0.0000012;

    // Initialize r0
    r0.reserve(4);
    r0 = MatrixMultiplication(A, x0);

    // Print r0
    for (int i = 0; i < r0.size(); i++)
    {
        cout << r0[i] << ' ';
    }

    return 0;
}

