#include <stdio.h>
#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;



void MaxSubarraySum3(int *arr, int n) // KADANE'S ALLGORITHM
{
    int maxSum = INT_MIN;
    int currenSum = 0;

    for (int i = 0; i < n; i++) // start = 2
    {
        currenSum += arr[i];
        maxSum = max(maxSum, currenSum);
        if(currenSum < 0){
            currenSum = 0;
        }
    }

    cout << "MAX SUM OF SUBARRAY: " << maxSum << endl;
}
void MaxSubarraySum2(int *arr, int n) // more Optizimed
{
    int maxSum = INT_MIN;

    for (int st = 0; st < n; st++) // start = 2
    {
        int currentSum = 0;
        for (int end = st; end < n; end++) // end = 2, 3, 4, 5
        {
            currentSum += arr[end];
            maxSum = max(maxSum, currentSum);
        }
    }

    cout << "MAX SUM OF SUBARRAY: " << maxSum << endl;
}

void MaxSubarraySum(int *arr, int n)
{
    int maxSum = INT_MIN;

    for (int st = 0; st < n; st++)
    {
        for (int end = st; end < n; end++)
        {
            int currentSum = 0;
            for (int i = st; i <= end; i++)
            {
                currentSum += arr[i];
            }
            cout << currentSum << ", ";
            maxSum = max(maxSum, currentSum);
        }
        cout << endl;
    }

    cout << "MAX SUM OF SUBARRAY: " << maxSum << endl;
}

int main()
{
    int arr[6] = {2, -3, 6, -5, 4, 2};
    int n = sizeof(arr) / sizeof(int);

    MaxSubarraySum3(arr, n);

    return 0;
}