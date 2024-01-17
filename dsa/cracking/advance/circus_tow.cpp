// 8. **Circus Tower:** A circus is designing a tower routine consisting of people standing atop one another's shoulders. For practical and aesthetic reasons, each person must be both shorter and lighter than the person below him or her. Given the heights and weights of each person in the circus, write a method to compute the largest possible number of people in such a tower.

// Example:
// Input (ht, wt): (65, 100) (70, 150), (56, 90) (75, 190) (60, 95) (68, 110)
// Output: The longest tower is length of 6 and includes from top to bottom:
// (56, 90) (60, 95) (65, 100) (68, 110) (70, 150) (75, 190)
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
std::vector<std::pair<int, int>> circusTower(const std::unordered_map<int, int> &ht_wt)
{
    std::vector<int> rVec;
    for (const auto &pair : ht_wt)
        rVec.push_back(pair.first);
    std::sort(rVec.begin(), rVec.end());
    std::vector<std::pair<int, int>> r;
    for (const int i : rVec)
        r.emplace_back(i, ht_wt.at(i));
    return r;
}
int main()
{
    std::unordered_map<int, int> ht_wt = {
        {65, 100},
        {70, 150},
        {56, 90},
        {75, 190},
        {60, 95},
        {68, 110}};
    std::vector<std::pair<int, int>> r = circusTower(ht_wt);
    for (const auto &pair : r)
        std::cout << "{" << pair.first << ", " << pair.second << "}" << std::endl;
    return 0;
}