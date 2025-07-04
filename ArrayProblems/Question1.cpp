/*Given an integer array nums, return true if any value appears at least
twice in the array, and return false if every element is distinct
Examples :
Input: nums = [1,2,3,4]
Output: false
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true*/

#include<iostream>
#include<stdio.h>
using namespace std;

bool checker(int* arr, int n){
    bool isTwice = false;

    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i] == arr[j]){
                return true;
            }
        }
    }
    return false;
}


int main(){
    int arr[] = {1,1,1,3,3,4,3,2,4,2};
    int n = sizeof(arr) / sizeof(int);

    cout << checker(arr, n);
}