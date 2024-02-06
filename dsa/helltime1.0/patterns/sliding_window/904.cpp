class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        map<int, int> fruitsCount;
        int left = 0;
        int total = 0;
        int res = 0;
        for (int i = 0; i < fruits.size(); ++i)
        {
            ++fruitsCount[fruits[i]];
            ++total;

            while (fruitsCount.size() > 2)
            {
                --fruitsCount[fruits[left]];
                --total;
                if (fruitsCount[fruits[left]] == 0)
                    fruitsCount.erase(fruits[left]);
                ++left;
            }

            res = max(res, total);
        }
        return res;
    }
};