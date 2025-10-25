#include<bist/stdc++.h>

using namespace std;

void updateIthBit(int &num, int i, int v) {
    /*
        To update the ith bit of a number num to a value v (where v can be either 0 or 1),
        we can use a combination of bitwise operations: clearing the ith bit and then setting it if needed.

        Steps:
        1. Create a mask by left shifting 1 by i positions: (1 << i)
        2. Clear the ith bit of num using the AND operator with the inverted mask: num & ~(1 << i)
        3. If v is 1, set the ith bit by performing a bitwise OR with the mask: num | (1 << i)
        4. If v is 0, the ith bit remains cleared.

        Example:
        num = 5 (binary 101), i = 1, v = 1
        Mask = 1 << 1 = 2 (binary 010)
        Clear ith bit: 101 & ~010 = 101 & 101 = 101
        Set ith bit: 101 | 010 = 111 (the 1st bit is now updated to 1)

        num = 5 (binary 101), i = 0, v = 0
        Mask = 1 << 0 = 1 (binary 001)
        Clear ith bit: 101 & ~001 = 101 & 110 = 100 (the 0th bit is now updated to 0)
    */

    int mask = 1 << i;
    num = num & ~mask; // Clear the ith bit
    if (v == 1) {
        num = num | mask; // Set the ith bit if v is 1
    }
}

int main() {
    int num, i, v;
    cout << "Enter a number: ";
    cin >> num;
    cout << "Enter the bit position to update (0-indexed): ";
    cin >> i;
    cout << "Enter the value to set (0 or 1): ";
    cin >> v;

    updateIthBit(num, i, v);
    cout << "After updating, the number is: " << num << endl;

    return 0;
}