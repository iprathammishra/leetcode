// 1. **Number Swapper:** Write a function to swap a number in place (that is, without temporary variables).
#include <iostream>
void swapThemInPlace(int &a, int &b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}
int main() 
{
    int a = 10;
    int b = 15;
    std::cout << "Before swap: a = " << a << " and b = " << b << "." << std::endl;
    swapThemInPlace(a, b);
    std::cout << "After swap: a = " << a << " and b = " << b << "." << std::endl;
    return 0;
}