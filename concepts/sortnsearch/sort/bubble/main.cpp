#include <iostream>
using namespace std;
void bubbleSort(int array[], int size)
{
    // loop to access each array element
    for (int step = 0; step < size; ++step)
    {
        // loop to compare array elements
        for (int i = 0; i < size - step; ++i)
        {
            // compare two adjacent elements
            // change > to < to sort in descending order
            if (array[i] > array[i + 1])
            {
                // swappping elements if elements are not in intended order
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
}
// print array
void printArray(int array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << " " << array[i];
    }
    cout << endl;
}
int main()
{
    int data[] = {-2, 32, 0, 22, -9};
    // find array's length
    int size = sizeof(data) / sizeof(data[0]);
    bubbleSort(data, size);
    cout << "Sorted array in ascending order: " << endl;
    printArray(data, size);
    return 0;
}