// class Solution {
// public:
//     vector<int> findSubstring(string s, vector<string>& words) {
//         if (words.empty()) return {};

//         unordered_map<string, int> wordCount;
//         for (const auto& word : words) {
//             ++wordCount[word];
//         }

//         int wordLen = words[0].size();
//         int allWordsLen = wordLen * words.size();
//         vector<int> result;

//         for (int i = 0; i <= (int)s.size() - allWordsLen; ++i) {
//             unordered_map<string, int> windowWords;
//             int j = 0;
//             for (; j < words.size(); ++j) {
//                 string word = s.substr(i + j * wordLen, wordLen);
//                 if (wordCount.find(word) == wordCount.end()) {
//                     break;
//                 }
//                 ++windowWords[word];
//                 if (windowWords[word] > wordCount[word]) {
//                     break;
//                 }
//             }
//             if (j == words.size()) {
//                 result.push_back(i);
//             }
//         }
//         return result;
//     }
// };

class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        if (words.empty())
            return {};

        unordered_map<string, int> wordCount;
        for (const auto &word : words)
        {
            ++wordCount[word];
        }

        int wordLen = words[0].size();
        vector<int> result;

        for (int i = 0; i < wordLen; i++)
        {
            int left = i, count = 0;
            unordered_map<string, int> currentCount;
            for (int j = i; j <= (int)s.size() - wordLen; j += wordLen)
            {
                string word = s.substr(j, wordLen);
                if (wordCount.count(word))
                {
                    currentCount[word]++;
                    if (currentCount[word] <= wordCount[word])
                        count++;
                    else
                    {
                        while (currentCount[word] > wordCount[word])
                        {
                            string temp = s.substr(left, wordLen);
                            currentCount[temp]--;
                            if (currentCount[temp] < wordCount[temp])
                                count--;
                            left += wordLen;
                        }
                    }
                    if (count == words.size())
                    {
                        result.push_back(left);
                        string temp = s.substr(left, wordLen);
                        currentCount[temp]--;
                        count--;
                        left += wordLen;
                    }
                }
                else
                {
                    currentCount.clear();
                    count = 0;
                    left = j + wordLen;
                }
            }
        }
        return result;
    }
};