class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<int> res;
        for (int i = 0; i < numbers.size(); i++)
        {
            if (i > 0 && numbers[i] == numbers[i - 1])
                continue;
            int left = i;
            int right = numbers.size() - 1;
            while (left < right)
            {
                int sum = numbers[left] + numbers[right];
                if (sum > target)
                    right--;
                else if (sum < target)
                    left++;
                else
                {
                    res.push_back(left + 1);
                    res.push_back(right + 1);
                    break;
                }
            }
            if (res.size() == 2)
                break;
        }
        return res;
    }
};