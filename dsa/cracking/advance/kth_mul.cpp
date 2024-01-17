// 9. **Kth Multiple:** Design an algorithm to find the kth number such that the only prime factors are 3, 5, and 7. Note that 3, 5, and 7 do not have to be factors, but it should not have other prime factors. For example, the first several multiples would be (in order) 1, 3, 5, 7, 9, 15, 21
#include <iostream>
#include <vector>
#include <unordered_set>
int kthMultiple(int num)
{
    std::vector<int> vVec = {1};
    std::unordered_set<int> uVec;
    int count = 1;
    while (vVec.size() - 1 != num)
    {
        ++count;
        if (count == 3 || count == 5 || count == 7)
            vVec.push_back(count);
        else if (count % 2 != 0)
        {
            for (int j = 3; j < count; ++j)
                if (count % j == 0)
                    uVec.insert(j);
            if (uVec.size() > 0 && uVec.size() <= 3)
            {
                bool valid = true;
                for (int i : uVec)
                    if (i != 3 && i != 5 && i != 7)
                    {
                        valid = false;
                        break;
                    }
                if (valid)
                    vVec.push_back(count);
            }
            uVec.clear();
        }
    }
    return vVec[vVec.size() - 1];
}
int main()
{
    std::cout << kthMultiple(6);
    return 0;
}