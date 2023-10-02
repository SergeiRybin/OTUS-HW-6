#define BOOST_TEST_MODULE static library test // Defines the name of the program which is used in the messages
#include <boost/test/unit_test.hpp>
#include <matrix.hpp>

BOOST_AUTO_TEST_SUITE(MainSuite)

BOOST_AUTO_TEST_CASE(copyTest)
{
    // Matrix<int, -1> matrix; // бесконечная матрица int заполнена значениями -1
    // BOOST_TEST(matrix.size() == 0); // все ячейки свободны
    // const auto a = matrix[0][0];
    // BOOST_TEST(a == -1);
    // BOOST_TEST(matrix.size() == 0);
    // matrix[100][100] = 314;
    // BOOST_TEST(matrix[100][100] == 314);
    // BOOST_TEST(matrix.size() == 1);
}

BOOST_AUTO_TEST_SUITE_END()