// 1. **Add Without Plus:** Write a function that adds two numbers. You should not use + or any arithmetic operators.
#include <iostream>
int addWithoutPlus(int a, int b)
{
    while (b != 0)
    {
        int carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }
    return a;
}
int main()
{
    std::cout << addWithoutPlus(2, 3);
    return 0;
}

// https://chat.openai.com/share/fff7db20-aa7a-4c24-b755-18fd3836ab82