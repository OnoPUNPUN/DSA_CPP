#include<iostream>
#include<stdio.h>

using namespace std;

int main() {
    int arr[3][4];
    int row = 3;
    int col = 4;

    for(int i = 0; i < row; i ++) {
        for(int j = 0; j < col; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < row; i ++) {     
        for(int j = 0; j < col; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}