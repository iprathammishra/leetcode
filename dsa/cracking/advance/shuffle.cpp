// 2. **Shuffle:** Write a method to shuffle a deck of cards. It must be a perfect shuffle - in other words, each of the 52! permutations of the deck has to be equally likely. Assume that you are given a random number generator which is perfect.

// Fisher-Yates Shuffle Algorithm

#include <iostream>
#include <vector>
#include <ctime>
void shuffle(std::vector<int> &vec)
{
    for (int i = vec.size() - 1; i > 0; --i)
    {
        int r = rand() % (i + 1);
        std::swap(vec[r], vec[i]);
    }
}
int main()
{
    srand(static_cast<unsigned int>(time(nullptr))); // seeding the random generator
    std::vector<int>
        deck(52);
    for (int i = 0; i < 52; ++i)
        deck[i] = i + 1;
    shuffle(deck);
    for (int i : deck)
        std::cout << i << ", ";

    return 0;
}

// https://chat.openai.com/share/6f5781d1-3dd9-4613-bd69-2e3c784a410d
