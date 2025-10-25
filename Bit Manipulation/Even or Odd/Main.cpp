#include<bits/stdc++.h>

using namespace std;


void checkEvenOdd(int n) {
    /*
        To check if a number is even or odd using bit manipulation,
        we can use the bitwise AND operator (&) with 1.
        
        If (n & 1) is 0, then n is even.
        If (n & 1) is 1, then n is odd.

        Example:
        4 in binary: 100
        4 & 1 = 0 (even)

        5 in binary: 101
        5 & 1 = 1 (odd)
    */

    if (n & 1) {
        cout << n << " is Odd" << endl;
    } else {
        cout << n << " is Even" << endl;
    }
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    checkEvenOdd(num);
    return 0;
}