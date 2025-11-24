#include <bits/stdc++.h>
using namespace std;

int recursiveBinarySearch(int *arr, int start, int end, int key)
{
    if (start > end)
        return -1;

    int mid = start + (end - start) / 2;

    if (arr[mid] == key)
        return mid;
    else if (arr[mid] < key)
        return recursiveBinarySearch(arr, mid + 1, end, key);
    else
        return recursiveBinarySearch(arr, start, mid - 1, key);
}

int main()
{
    int arr[] = {2, 4, 6, 8, 10, 12, 15, 16};
    int n = sizeof(arr) / sizeof(int);

    cout << recursiveBinarySearch(arr, 0, n - 1, 12) << endl;
}
