#include <iostream>
#include <stdio.h>
using namespace std;

// O(n ^ 2)
void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertionSortAss(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int curr = arr[i];
        int perv = i - 1;

        while (perv >= 0 && arr[perv] > curr)
        {
            swap(arr[perv], arr[perv + 1]);

            perv--;
        }
        arr[perv + 1] = curr;
    }

    print(arr, n);
}

void insertionSortDesc(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int curr = arr[i];
        int perv = i - 1;

        while (perv >= 0 && arr[perv] < curr)
        {
            swap(arr[perv], arr[perv + 1]);

            perv--;
        }
        arr[perv + 1] = curr;
    }

    print(arr, n);
}

int main()
{
    int arr[5] = {5, 4, 1, 3, 2};

    insertionSortAss(arr, 5);
    insertionSortDesc(arr, 5);

    return 0;
}