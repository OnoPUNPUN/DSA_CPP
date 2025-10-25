#include<bits/stdc++.h>
using namespace std;


int clearIthBit(int n, int i) {
    /*
        To clear the ith bit of a number n using bit manipulation,
        we can use the bitwise AND operator (&) along with the NOT operator (~) and a left shift operator (<<).

        Steps:
        1. Create a mask by left shifting 1 by i positions: (1 << i)
        2. Invert the mask using the NOT operator: ~(1 << i)
        3. Perform bitwise AND between n and the inverted mask: n & ~(1 << i)
        4. This operation clears the ith bit to 0, regardless of its previous value.

        Example:
        n = 5 (binary 101), i = 0
        Mask = 1 << 0 = 1 (binary 001)
        Inverted Mask = ~1 = ...11111110 (binary)
        n & Inverted Mask = 101 & ...11111110 = 100 (the 0th bit is now cleared to 0)
    */

    int mask = 1 << i;
    return n & ~mask; // Clear the ith bit
}

int main() {
    int n, i;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Enter the bit position to clear (0-indexed): ";
    cin >> i;

    int result = clearIthBit(n, i);
    cout << "After clearing the " << i << "th bit, the number is: " << result << endl;

    return 0;
}