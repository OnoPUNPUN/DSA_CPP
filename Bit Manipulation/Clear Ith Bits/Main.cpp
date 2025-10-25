#include<bits/stdc++.h>

using namespace std;

void clearIthBits(int &num, int i) {
/*
    To clear all bits from the 0th bit to the (i-1)th bit of a number num using bit manipulation,
    we can use the bitwise AND operator (&) along with a left shift operator (<<) and the NOT operator (~).

    Steps:
    1. Create a mask by left shifting -1 (which is all bits set to 1) by i positions: (~0) << i
    2. Perform bitwise AND between num and the mask: num & ((~0) << i)
    3. This operation clears all bits from the 0th to the (i-1)th bit to 0, regardless of their previous values.

    Example:
    num = 29 (binary 11101), i = 3
    Mask = (~0) << 3 = ...11111000 (binary)
    num & Mask = 11101 & ...11111000 = 11100 (the bits from 0 to 2 are now cleared to 0)
*/

    int mask = (~0) << i; // Create a mask with bits from i to MSB set to 1

    num = num & mask; // Clear bits from 0 to i-1
}

int main() {
    int num, i;
    cout << "Enter a number: ";
    cin >> num;
    cout << "Enter the bit position up to which to clear (0-indexed): ";
    cin >> i;

    clearIthBits(num, i);
    cout << "After clearing bits from 0 to " << i - 1 << ", the number is: " << num << endl;

    return 0;
}