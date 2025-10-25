#include<bits/stdc++.h>

using namespace std;


int getIthBit(int n, int i) {
    /*
        To get the ith bit of a number n using bit manipulation,
        we can use the bitwise AND operator (&) along with a left shift operator (<<).

        Steps:
        1. Create a mask by left shifting 1 by i positions: (1 << i)
        2. Perform bitwise AND between n and the mask: n & (1 << i)
        3. If the result is non-zero, the ith bit is 1; otherwise, it is 0.

        Example:
        n = 5 (binary 101), i = 0
        Mask = 1 << 0 = 1 (binary 001)
        n & Mask = 101 & 001 = 001 (non-zero, so ith bit is 1)

        n = 5 (binary 101), i = 1
        Mask = 1 << 1 = 2 (binary 010)
        n & Mask = 101 & 010 = 000 (zero, so ith bit is 0)
    */

    int mask = 1 << i;
    if (n & mask) {
        return 1; // ith bit is set
    } else {
        return 0; // ith bit is not set
    }
}

int main() {
    int n, i;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Enter the bit position (0-indexed): ";
    cin >> i;

    int result = getIthBit(n, i);
    if (result) {
        cout << "The " << i << "th bit of " << n << " is 1." << endl;
    } else {
        cout << "The " << i << "th bit of " << n << " is 0." << endl;
    }

    return 0;
}