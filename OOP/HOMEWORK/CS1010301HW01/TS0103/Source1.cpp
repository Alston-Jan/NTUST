#include <iostream>
#include <vector>
using namespace std;

void printSnakeMatrix(int N) {
    vector<vector<int>> matrix(N, vector<int>(N, 0));
    int num = 1;

    for (int col = 0; col < N; ++col) {
        for (int row = 0; row <= col; ++row) {
            matrix[row][col - row] = num++;
        }
    }

    for (int col = 0; col < N; ++col) {
        for (int row = 0; row < N; ++row) {
            if (col - row >= 0) {
                cout << matrix[row][col - row];
                if (row + 1 < N && col - row - 1 >= 0) {
                    cout << " ";
                }
            }
        }
        cout << endl;
    }
}

int main() {
    int N;
    bool firstCase = true;

    while (cin >> N) {
        if (!firstCase) {
            cout << endl;
        }
        firstCase = false;
        printSnakeMatrix(N);
    }

    return 0;
}
