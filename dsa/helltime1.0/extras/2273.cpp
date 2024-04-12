class Solution
{
private:
    string createSignature(string word)
    {
        sort(word.begin(), word.end());
        return word;
    }

public:
    vector<string> removeAnagrams(vector<string> &words)
    {
        vector<string> res;
        res.push_back(words[0]);

        string previousWord = createSignature(words[0]);

        for (size_t i = 1; i < words.size(); i++)
        {
            string currentWord = createSignature(words[i]);
            if (previousWord != currentWord)
            {
                res.emplace_back(words[i]);
                previousWord = currentWord;
            }
        }
        return res;
    }
};