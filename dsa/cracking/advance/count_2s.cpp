// 6. **Count of 2s:** Write a method to count the number of 2s that appear in all the numbers between 0 and n (inclusive).

// Example:

// Input: 25
// Output: 9 (2, 12, 20, 21, 22, 23, 24 and 25. Note that 22 counts for two 2s).
#include <iostream>
int count2s(int n)
{
    int count = 0;
    for (int i = 2; i <= n; ++i)
    {
        int num = i;
        while (num > 0)
        {
            if (num % 10 == 2)
                ++count;
            num /= 10;
        }
    }
    return count;
}
int main()
{
    std::cout << count2s(25) << std::endl;
    return 0;
}