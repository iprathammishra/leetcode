// A new way to sort an array.

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> A = {3, 5, -1, 0};
    int n = A.size();
    for (int i = 0; i < n; ++i)
        while (A[i] > 0 && A[i] <= n && A[A[i] - 1] != A[i])
            swap(A[i], A[A[i] - 1]);
    return 0;
}
