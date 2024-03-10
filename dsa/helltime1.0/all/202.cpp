class Solution
{
public:
    bool isHappy(int n)
    {
        set<int> s;
        int count = 0;
        function<bool(int)> dfs = [&](int n) -> bool
        {
            if (n == 1)
                return true;
            s.insert(n);
            count++;
            if (s.size() != count)
                return false;
            int sum = 0;
            while (n != 0)
            {
                int digit = n % 10;
                sum += digit * digit;
                n /= 10;
            }
            return dfs(sum);
        };
        return dfs(n);
    }
};