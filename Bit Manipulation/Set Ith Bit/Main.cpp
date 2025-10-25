#include<bits/stdc++.h>
using namespace std;


void setIthBit(int &n, int i) {
    /*
        To set the ith bit of a number n using bit manipulation,
        we can use the bitwise OR operator (|) along with a left shift operator (<<).

        Steps:
        1. Create a mask by left shifting 1 by i positions: (1 << i)
        2. Perform bitwise OR between n and the mask: n | (1 << i)
        3. This operation sets the ith bit to 1, regardless of its previous value.

        Example:
        n = 5 (binary 101), i = 1
        Mask = 1 << 1 = 2 (binary 010)
        n | Mask = 101 | 010 = 111 (the 1st bit is now set to 1)
    */

    int mask = 1 << i;
    n = n | mask; // Set the ith bit
}

int main() {
    int n, i;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Enter the bit position to set (0-indexed): ";
    cin >> i;

    setIthBit(n, i);
    cout << "After setting the " << i << "th bit, the number is: " << n << endl;

    return 0;
}