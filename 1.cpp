#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Function to find the maximum value among modes of rows or columns
int findModeMax(const vector<vector<int>>& matrix, bool isRow) {
    int maxMode = INT_MIN;
    int n = matrix.size();
    int m = matrix[0].size();

    // Iterate through rows or columns
    for (int i = 0; i < (isRow ? n : m); i++) {
        unordered_map<int, int> freq;
        for (int j = 0; j < (isRow ? m : n); j++) {
            int val = isRow ? matrix[i][j] : matrix[j][i];
            freq[val]++;
        }

        // Find the mode with the highest frequency and largest value
        int maxFreq = 0, modeVal = INT_MIN;
        for (auto& [key, value] : freq) {
            if (value > maxFreq || (value == maxFreq && key > modeVal)) {
                maxFreq = value;
                modeVal = key;
            }
        }
        maxMode = max(maxMode, modeVal);
    }
    return maxMode;
}

// Function to find the mode of the entire array
int findArrayMode(const vector<vector<int>>& matrix) {
    unordered_map<int, int> freq;
    for (const auto& row : matrix) {
        for (int val : row) {
            freq[val]++;
        }
    }

    int maxFreq = 0, modeVal = INT_MIN;
    for (auto& [key, value] : freq) {
        if (value > maxFreq || (value == maxFreq && key > modeVal)) {
            maxFreq = value;
            modeVal = key;
        }
    }
    return modeVal;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    // Calculate results
    int maxRowMode = findModeMax(matrix, true);
    int maxColMode = findModeMax(matrix, false);
    int arrayMode = findArrayMode(matrix);

    // Output the results
    cout << maxRowMode << " " << maxColMode << " " << arrayMode << endl;
    return 0;
}
