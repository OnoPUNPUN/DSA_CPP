#include<iostream>
#include<stdio.h>
using namespace std;


void PrintSubarrays(int *arr, int n){ // 1, 12, 123, 1234, 12345
    for(int start = 0; start < n; start++){
        for(int end = start; end < n; end++){ // got the index of the elements
            for(int i = start; i <= end; i++){
                cout << arr[i]; // printing the subarrays
            }
            cout << ", ";
        }
        cout << endl;
    }
}

int main(){
    int arr[5] = {1, 2, 3, 4, 5};
    int n = 5; 
    PrintSubarrays(arr, n);
    
}