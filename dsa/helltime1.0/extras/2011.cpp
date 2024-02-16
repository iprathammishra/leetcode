class Solution
{
public:
    int finalValueAfterOperations(vector<string> &operations)
    {
        int x = 0;
        for (const string &operation : operations)
        {
            if (operation == "--X")
            {
                --x;
            }
            else if (operation == "X--")
            {
                --x;
            }
            else if (operation == "++X")
            {
                ++x;
            }
            else
            {
                ++x;
            }
        }
        return x;
    }
};