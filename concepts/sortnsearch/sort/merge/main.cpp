#include <iostream>
using namespace std;
// merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r)
{
    // create L <- A[p...q] and M <- A[q+1...r]
    int n1 = q - p + 1;
    int n2 = r - q;
    int *L = new int[n1]; // mew
    int *M = new int[n2]; // new
    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    // maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    // until we reach end of either L or M, pick larger among elements L and M and place them in the correct position at A[p...r]
    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    // when we run out of element in either L or M, pick up the remaining elements and put in A[p...r]
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}
// divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // m is the point where the array is divided into two
        int m = l + (r - l) / 2;
        mergeSort(arr, 1, m);
        mergeSort(arr, m + 1, r);

        // merge the sorted subarrays
        merge(arr, 1, m, r);
    }
}
// print the array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    int arr[] = {6, 5, 12, 10, 9, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, size - 1);
    cout << "Sorted array: " << endl;
    printArray(arr, size);
    return 0;
}