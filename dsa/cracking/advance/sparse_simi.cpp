// 26. **Sparse Similarity:** The similarity of two documents (each with distinct words) is defined to be the size of the intersection divided by the size of the union. For example, if the document consist of integers, the similarity of {1, 5, 3} and {1, 7, 2, 3} is 0.4, because the intersection has size 2 and the union has size 5.

// We have a long list documents (with distinct values and each with an associated ID) where the similarity is believed to be "sparse". That is, any two arbitrarily selected documents are very likely to have similarity 0. Design an algorithm that returns a list of pairs of document IDs and the associated similarity.

// Print only the pairs with similarity greater than 0. Empty documents should not be printed at all. For simplicity, you may assume each document is represented as an array of distinct integers.

// Example: <br>
// Input:<br>
// 13: {14, 15, 100, 9, 3}<br>
// 16: {32, 1, 9, 3, 5}<br>
// 19: {15, 29, 2, 6, 8, 7}<br>
// 24: {7, 10}<br>
// Output: <br>
// ID1, ID2 : SIMILARITY<br>
// 13, 19 : 0.1<br>
// 13, 16 : 0.25 <br>
// 19, 24 : 0.14285714285714285 <br>
#include <iostream>
#include <unordered_map>
#include <vector>
void findSparseSimilarity(const std::unordered_map<int, std::vector<int>> &documents)
{
}
int main()
{
    std::unordered_map<int, std::vector<int>> documents = {
        {13, {14, 15, 100, 9, 3}},
        {16, {32, 1, 9, 3, 5}},
        {19, {15, 29, 2, 6, 8, 7}},
        {24, {7, 10}}};

    findSparseSimilarity(documents);

    return 0;
}

// https://chat.openai.com/share/c26fe10a-610b-4071-8451-b5911104fb6c