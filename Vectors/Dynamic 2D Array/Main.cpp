#include <iostream>
using namespace std;

int main()
{
    int rows, cols;

    cout << "Enter Rows: ";
    cin >> rows;
    cout << "Enter Cols: ";
    cin >> cols;

    int **martrix = new int *[rows];

    for (int i = 0; i < rows; i++)
    {
        martrix[i] = new int[cols];
    }

    // data store
    int x = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            martrix[i][j] = x++;
            cout << martrix[i][j] << " ";
        }
        cout << endl;
    }
}