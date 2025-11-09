#include<bits/stdc++.h>
using namespace std;

int linearSearch(int* arr, int size, int t) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == t) {
            return i;
        }
    }

    return -1;
}


int main() {
    int arr[5] = {10, 5, 20, 15, 30};

    // int size = sizeof(arr) / sizeof(int);
    int target = 20;
    int result = linearSearch(arr, 5, target);

    if(result == -1) {
        cout << "Target Element Not Found" << endl;
    } else {
        cout << "Target Element Found at " << result << endl;
    }

    return 0;
}