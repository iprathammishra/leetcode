// **Word Transform:** Given two words of equal length that are in a dictionary, write a method to transform one word into another word by changing only one letter at a time. The new word you get in each step must be in the dictionary.

// Example: <br>
// Input: DAMP, LIKE<br>
// Output: DAMP -> LAMP -> LIMP -> LIME -> LIKE
#include <iostream>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

bool isOneLetterApart(const string &word1, const string &word2)
{
    int diffCount = 0;
    for (size_t i = 0; i < word1.length(); ++i)
    {
        if (word1[i] != word2[i])
        {
            ++diffCount;
            if (diffCount > 1)
            {
                return false; // More than one letter is different
            }
        }
    }
    return diffCount == 1;
}

void wordTransform(const string &startWord, const string &endWord, const unordered_set<string> &dictionary)
{
    queue<string> q;
    unordered_map<string, string> parent; // To reconstruct the transformation path
    q.push(startWord);
    parent[startWord] = "";

    while (!q.empty())
    {
        string currentWord = q.front();
        q.pop();

        if (currentWord == endWord)
        {
            // Transformation path found, reconstruct and print
            vector<string> transformation;
            while (currentWord != "")
            {
                transformation.push_back(currentWord);
                currentWord = parent[currentWord];
            }
            reverse(transformation.begin(), transformation.end());

            cout << "Transformation Path:" << endl;
            for (const string &word : transformation)
            {
                cout << word << " -> ";
            }
            cout << endl;
            return;
        }

        for (const string &nextWord : dictionary)
        {
            if (isOneLetterApart(currentWord, nextWord) && parent.find(nextWord) == parent.end())
            {
                q.push(nextWord);
                parent[nextWord] = currentWord;
            }
        }
    }

    cout << "No transformation path found." << endl;
}

int main()
{
    unordered_set<string> dictionary = {"DAMP", "LAMP", "LIMP", "LIME", "LIKE"};

    string startWord = "DAMP";
    string endWord = "LIKE";

    wordTransform(startWord, endWord, dictionary);

    return 0;
}
