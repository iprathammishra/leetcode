// 9. **Operations:** Write methods to implement the multiply, subtract, and divide operations for integers. The result of all these are integers. Use only the add operator.
#include <iostream>
int multiply(int a, int b)
{
    int result = 0;
    for (int i = 0; i < b; i++)
        result += a;
    return result;
}
int substract(int a, int b)
{
    return a + (-b);
}
int divide(int a, int b)
{
    int quotient = 0;
    while (a >= b)
    {
        a -= b;
        ++quotient;
    }
    return quotient;
}
int main()
{
    std::cout << multiply(3, 12) << std::endl;
    std::cout << substract(3, 12) << std::endl;
    std::cout << divide(12, 4) << std::endl;
    return 0;
}

// https://bard.google.com/chat/507b3ff76840d408