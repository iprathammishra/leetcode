// Vectors are sequence containers representing arrays that can change in size.

#include <iostream>
#include <vector>
using namespace std;
vector<int> sort(vector<int> root)
{
    int temp;
    vector<int> result;
    for (int i = 0; i < root.size(); i++)
    {
        for (int j = i + 1; j < root.size(); j++)
        {
            if (root[i] > root[j])
            {
                temp = root[j];
                root[j] = root[i];
                root[i] = temp;
            }
        }
    }
    for (int element : root)
    {
        result.push_back(element);
    }
    return result;
}
int main()
{
    vector<int> myVector = {6, 2, 3, 4};
    myVector = sort(myVector);
    for (int element : myVector)
    {
        cout << element << " ";
    }
    cout << endl;

    myVector.push_back(5);
    for (int element : myVector)
    {
        cout << element << " ";
    }
    cout << endl;

    myVector.pop_back();
    for (int element : myVector)
    {
        cout << element << " ";
    }
    cout << endl;
    cout << myVector.size() << endl;
    cout << myVector.at(2) << endl;
}