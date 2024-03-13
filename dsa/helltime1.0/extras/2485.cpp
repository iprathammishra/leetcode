class Solution
{
public:
    int pivotInteger(int n)
    {
        int sum = n * (n + 1) / 2;
        int squareRoot = static_cast<int>(sqrt(sum));
        if (squareRoot * squareRoot == sum)
            return squareRoot;
        return -1;
    }
};