// 19. **Missing Two:** You are given an array with all the numbers from 1 to N appearing exactly once, except for one number that is missing. How can you find the missing number in O(N) time and O(1) space? What if there were two numbers missing?
#include <iostream>
#include <vector>
std::vector<int> missingTwo(const std::vector<int> &vec)
{
    std::vector<int> out;
    int count = 1;
    int i = 0;
    while (true)
    {
        if (vec[i] != count)
        {
            out.push_back(count);
            ++count;
        }
        else
        {
            ++count;
            ++i;
        }
        if (i == vec.size())
            break;
    }
    return out;
}
int main()
{
    std::vector<int> vec = {1, 2, 3, 4, 7, 8, 10, 12, 15};
    std::vector<int> out = missingTwo(vec);
    for (const int i : out)
        std::cout << i << " ";
    return 0;
}