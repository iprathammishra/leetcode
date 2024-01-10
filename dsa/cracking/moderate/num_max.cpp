// 7. **Number Max:** Write a method that finds the maximum of two numbers. You should not use if-else or any other comparison operator.
#include <iostream>
int findMax(const int& a, const int& b)
{
    int diff = a - b;
    int signDiff = (diff >> 31) & 1;
    return (a - signDiff*diff);
}
int main()
{
    std::cout << findMax(45, 5) << std::endl;
    return 0;
}

// https://chat.openai.com/share/00afc13f-a961-4f62-b53e-8668ce107856