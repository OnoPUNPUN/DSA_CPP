// Sort this array of chracters usign insertion sort in desc order
//      char ch[] = {'f', 'b', 'a', 'e', 'e', 'c', 'd'}

#include <iostream>
#include <stdio.h>
using namespace std;

void print(char *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

void insertionSort(char *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int current = arr[i];
        int prev = i - 1;

        while (prev >= 0 && arr[prev] < current)
        {
            swap(arr[prev], arr[prev + 1]);
            prev--;
        }

        arr[prev + 1] = current;
    }

    print(arr, n);
}

int main()
{
    char ch[6] = {'f', 'b', 'a', 'e', 'c', 'd'};

    insertionSort(ch, 6);

    return 0;
}