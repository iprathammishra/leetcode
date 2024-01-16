// 3. **Random Set:** Write a method to randomly generate a set of m integers from an array of size n. Each element must have equal probability of being chosen.

// Fisher Yates Algorithm

#include <iostream>
#include <vector>
#include <ctime>
void randomSet(std::vector<int> &v)
{
    for (int i = v.size() - 1; i > 0; --i)
    {
        int j = rand() % (i + 1);
        std::swap(v[i], v[j]);
    }
}
int main()
{
    int m = 6;
    srand(static_cast<unsigned int>(time(nullptr)));
    std::vector<int> v = {2, 4, 2, 1, 6, 7, 8, 9, 6, 7, 8, 9, 1, 0};
    randomSet(v);
    v.resize(m);
    for (int i : v)
        std::cout << i << ", ";
    return 0;
}