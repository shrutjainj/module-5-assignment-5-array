#include <vector>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    bool firstRowHasZero = false, firstColHasZero = false;

    // Check if the first row has any zeros
    for (int j = 0; j < n; ++j) {
        if (matrix[0][j] == 0) {
            firstRowHasZero = true;
            break;
        }
    }

    // Check if the first column has any zeros
    for (int i = 0; i < m; ++i) {
        if (matrix[i][0] == 0) {
            firstColHasZero = true;
            break;
        }
    }

    // Use the first row and column as markers
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Set elements to zero based on markers
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    // Zero out the first row if needed
    if (firstRowHasZero) {
        for (int j = 0; j < n; ++j) {
            matrix[0][j] = 0;
        }
    }

    // Zero out the first column if needed
    if (firstColHasZero) {
        for (int i = 0; i < m; ++i) {
            matrix[i][0] = 0;
        }
    }
}