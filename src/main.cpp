#include <iostream>
#include <cassert>
#include <matrix.hpp>

using namespace std;

// TODO: use C++20 concepts

int main(int argc, char const *argv[])
{
    try
    {
        Matrix<int, -1> matrix; // бесконечная матрица int заполнена значениями -1
        assert(matrix.size() == 0); // все ячейки свободны
        auto a = matrix[0][0];
        assert(a == -1);
        assert(matrix.size() == 0);
        matrix[100][100] = 314;
        assert(matrix[100][100] == 314);
        assert(matrix.size() == 1);

        const Matrix<int, -1> cmatrix; // бесконечная матрица int заполнена значениями -1
        assert(cmatrix.size() == 0); // все ячейки свободны
        auto c = cmatrix[0][0];
        assert(c == -1);
        assert(cmatrix.size() == 0);
        // cmatrix[100][100] = 314;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}