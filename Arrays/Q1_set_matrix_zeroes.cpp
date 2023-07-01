// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
// You must do it in place.

 // Example 1:
// Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
// Output: [[1,0,1],[0,0,0],[1,0,1]]

// Example 2:
// Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
// Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

#include<bits/stdc++.h>
using namespace std;

// Solution using O(n + m) space
class Approach1 {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> dummyRow(n);
        vector<int> dummyCol(m);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 0) {
                    dummyRow[i] = 1;
                    dummyCol[j] = 1;
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(dummyRow[i] || dummyCol[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

// Time Complexity  : O(n * m) + O(n * m) = O(n * m)
// Space Complexity : O(n) + O(m) = O(n + m)

// Optimal Solution (in-place)
class Approach2 {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        // For keeping track of the first element (matrix[0][0]) separately
        int col0 = 1;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;

                    if(j != 0) matrix[0][j] = 0;
                    else col0 = 0;
                }
            }
        }

        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(matrix[i][j] != 0) {
                    // Checking the first row and column
                    if(matrix[0][j] == 0 || matrix[i][0] == 0) {
                        matrix[i][j] = 0;
                    }
                }
            }
        }

        // Handling the first row and column
        if(matrix[0][0] == 0) {
            for(int j = 0; j < m; j++) {
                matrix[0][j] = 0;
            }
        }

        if(col0 == 0) {
            for(int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};

// Time Complexity  : O(n * m) + O(n * m) + O(n) + O(m) = O(n * m)
// Space Complexity : O(1)