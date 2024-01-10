// 5. **Factorial Zeros:** Write an algorithm which computes the number of trailing zeros in n factorial.
#include <iostream>
int countTrailingZeros(const int& n)
{
    int count = 0;
    for (int i = 5; n / i > 0; i *= 5)
        count += n/i;
    return count;
}
int main()
{
    std::cout << "Number of trailing zeros are: " << countTrailingZeros(25) << std::endl;
    return 0;
}

// Approach:

// Trailing zeros in a factorial come from the multiplication of 2 and 5. Since 2s are usually more common, we only need to count the number of 5s.

// We'll loop through multiples of 5, starting from 5, then 25, 125, and so on. At each step, we count how many times our number n can be divided by the current multiple of 5.

// The sum of these counts gives us the total number of trailing zeros in the factorial of n.