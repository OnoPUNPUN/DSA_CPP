#include <iostream>
using namespace std;

void pypart2(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j < i)
                cout << "  ";
            else
                cout << "* ";
        }
        cout << endl;
    }
}

int main() {
    int n = 5;
    pypart2(n);
    return 0;
}
