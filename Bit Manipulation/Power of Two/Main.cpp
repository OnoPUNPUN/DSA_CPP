#include<bist/stdc++.h>

using namespace std;

bool isPowerOfTwo(int n) {
    /*
        A number n is a power of two if it has exactly one bit set in its binary representation.
        This can be checked using the property that for any power of two, n & (n - 1) == 0.

        Steps:
        1. Check if n is greater than 0 (since powers of two are positive).
        2. Perform the bitwise AND operation between n and (n - 1).
        3. If the result is 0, then n is a power of two; otherwise, it is not.

        Example:
        n = 8 (binary 1000)
        n - 1 = 7 (binary 0111)
        n & (n - 1) = 1000 & 0111 = 0000 (which is 0, so 8 is a power of two)

        n = 10 (binary 1010)
        n - 1 = 9 (binary 1001)
        n & (n - 1) = 1010 & 1001 = 1000 (which is not 0, so 10 is not a power of two)
    */

    return n > 0 && (n & (n - 1)) == 0;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (isPowerOfTwo(n)) {
        cout << n << " is a power of two." << endl;
    } else {
        cout << n << " is not a power of two." << endl;
    }

    return 0;
}