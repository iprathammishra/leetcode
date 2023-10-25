#include <iostream>
#include <vector> // new
using namespace std;
// function to get the largest element from an array
int getMax(int array[], int n)
{
    int max = array[0];
    for (int i = 1; i < n; i++)
        if (array[i] > max)
            max = array[i];
    return max;
}
// using counting sort to sort the elements in the basis of significant places
void countingSort(int array[], int size, int place)
{
    const int max = 10;
    // int output[size];
    vector<int> output(size); // new
    int count[max];

    for (int i = 0; i < max; ++i)
        count[i] = 0;
    // calculate count of elements
    for (int i = 0; i < size; i++)
        count[(array[i] / place) % 10]++;
    // calculate cumulative count
    for (int i = 1; i < max; i++)
        count[i] += count[i - 1];
    // place the elements in sorted order
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
    }
    for (int i = 0; i < size; i++)
        array[i] = output[i];
}
// main function to implement radix sort
void radixSort(int array[], int size)
{
    // get maximum element
    int max = getMax(array, size);
    // apply counting sort to sort elements based on place value
    for (int place = 1; max / place > 0; place *= 10)
        countingSort(array, size, place);
}
// print an array
void printArray(int array[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}
int main()
{
    int array[] = {121, 432, 564, 23, 1, 45, 788};
    int n = sizeof(array) / sizeof(array[0]);
    radixSort(array, n);
    printArray(array, n);
    return 0;
}