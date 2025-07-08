#include <iostream>
#include <stdio.h>

using namespace std;

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSortAss(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool isUnOrdered = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                isUnOrdered = true;
            }
        }
        if (!isUnOrdered)
        {
            return;
        }
    }
    print(arr, n);
}

void bubbleSortDes(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool isUnOrdered = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
        if (!isUnOrdered)
        {
            return;
        }
    }
    print(arr, n);
}

int main()
{
    int arr[5] = {5, 4, 1, 3, 2};

    bubbleSortAss(arr, 5);
    bubbleSortDes(arr, 5);

    return 0;
}