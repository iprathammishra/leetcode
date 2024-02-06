class Solution
{
public:
    long maximumSumSubarray(int K, vector<int> &Arr, int N)
    {
        long current_sum = 0;
        for (int i = 0; i < K; ++i)
            current_sum = current_sum + Arr[i];
        long max_sum = current_sum;
        int start_pointer = 0;
        for (int i = K; i < N; ++i)
        {
            current_sum = current_sum + Arr[i] - Arr[start_pointer++];
            if (current_sum > max_sum)
                max_sum = current_sum;
        }
        return max_sum;
    }
};