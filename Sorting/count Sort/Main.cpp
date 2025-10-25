#include<bits/stdc++.h>
using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void countSort(int *arr, int n)
{
    int freq[10000] = {0}; // range on leetcode

    int minVlaue = INT_MAX, maxValue = INT_MIN;

    // 1st step O(n)
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
        minVlaue = min(minVlaue, arr[i]);
        maxValue = max(maxValue, arr[i]);
    }

    // 2nd step O(range) = max - min
    for (int i = minVlaue, j = 0; i <= maxValue; i++)
    {
        while (freq[i] > 0)
        {
            arr[j++] = i;
            freq[i]--;
        }
    }
    print(arr, n);
}

int main()
{
    int arr[8] = {1, 4, 1, 3, 2, 4, 3, 7};

    countSort(arr, 8);

    return 0;
}