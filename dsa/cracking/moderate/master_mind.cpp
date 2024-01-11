// 15. **Master Mind:** The Game of Master Mind is played as follows:

// The computer has four slots, an each slot will contain a ball that is red (R), yellow (Y), green (G) or blue (B). For example, the computer might have RGGB (Slot #1 is red, Slots #2 and #3 are greem, Slot #4 is blue).

// You, the user, are trying to guess the solution. You might, for example, guess YRGB.

// When you guess the correct color for the correct slot, you get a "hit". If you guess a color that exists but is in the wrong slot, you get a "pseudo-hit". Note that a slot that is a hit can never count as a pseudo-hit.

// For example, if the actual solution is RGBY and you guess GGRR, you have one hit and one pseudo-hit. Write a method that, given a guess and solution, return the number of hits and pseduo-hits.
#include <iostream>
#include <unordered_map>
std::pair<int, int> calculateMasterMindResult(const std::string& solution, const std::string& guess)
{
    if (solution.length() != guess.length())
    {
        std::cerr << "Error: Solution and guess must have the same length." << std::endl;
        return std::make_pair(0, 0);
    }
    std::unordered_map<char, int> colorFrequency;

    int hits = 0;
    for (int i = 0; i < solution.length(); ++i)
        if (solution[i] == guess[i])
            hits++;
        else
            ++colorFrequency[solution[i]];

    int pseduoHits = 0;
    for (int i = 0; i < guess.length(); ++i)
        if (solution[i] != guess[i] && colorFrequency.find(guess[i]) != colorFrequency.end() && colorFrequency[guess[i]] > 0)
        {
            pseduoHits++;
            colorFrequency[guess[i]]--;
        }
    return std::make_pair(hits, pseduoHits);
}
int main()
{
    std::string solution = "RGBY";
    std::string guess;

    std::cout << "Enter your guess: ";
    std::cin >> guess;

    std::pair<int, int> pair = calculateMasterMindResult(solution, guess);

    std::cout << "Hits: " << pair.first << std::endl;
    std::cout << "Pseudo-Hits: "<< pair.second << std::endl;
    return 0;
}