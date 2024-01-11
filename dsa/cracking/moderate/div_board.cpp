// 11. **Diving Board:** You are building a diving board by placing a bunch of planks of wood end-to-end. There are two types of planks, one of length shorter and one length longer. You must use exactly k planks of wood. Write a method to generate all possible lengths for the diving board.
#include <iostream>
#include <vector>
std::vector<int> generateLengths(const int& shorter, const int& longer, const int& k)
{
    std::vector<int> lengths;
    if (k == 0)
        {lengths.push_back(0);
        return lengths;}
    for (int i = 0; i <= k; i++)
        lengths.push_back(
            i * shorter + (k - i) * longer
        );
    return lengths;
}
int main()
{
    std::vector<int> length = generateLengths(2, 3, 4);
    for (const int l : length)
        std::cout << l << " ";
    std::cout << std::endl;
    return 0;
}

// https://chat.openai.com/share/91a484ed-f921-461a-a8d1-f45d7e77d2f1