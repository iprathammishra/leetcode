// Algorithm for Cyclic Sort || In-place Sorting
#include <iostream>
#include <vector>
using namespace std;
void cyclicSortM1(vector<int> &m)
{
    int i = 0;
    while (i < m.size())
    {
        int index = m[i];
        if (m[i] != m[index])
            swap(m[i], m[index]);
        else
            i++;
    }
}
void cyclicSortM2(vector<int> &m)
{
    int i = 0;
    while (i < m.size())
        if (m[i] != i)
        {
            int correctIndex = m[i];
            if (correctIndex < m.size() && m[i] != m[correctIndex])
                swap(m[i], m[correctIndex]);
            else
                i++;
        }
        else
            i++;
}
int main()
{
    // Method 1: This method is only applicable when given array values or elements are in the range of 1 to N or 0 to N. In this method, we do not need to rotate an array.
    vector<int> m1 = {6, 4, 0, 3, 5, 1, 2};
    cyclicSortM1(m1);
    for (const int &i : m1)
        cout << i << " ";
    cout << endl;

    // Method 2: For any order array.
    vector<int> m2 = {4, 6, 2, 8, 0, 1};
    cyclicSortM2(m2);
    for (const int &i : m2)
        cout << i << " ";
    cout << endl;
}