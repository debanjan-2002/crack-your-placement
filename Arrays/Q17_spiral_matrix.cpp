// Given an m x n matrix, return all elements of the matrix in spiral order.

// Example 1:
// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]

// Example 2:
// Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans;

        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = m - 1;

        while(top <= bottom && left <= right) {
            // Top Row
            for(int i = left; i <= right; i++) ans.push_back(matrix[top][i]);
            top++;
            
            // Right Column
            for(int i = top; i <= bottom; i++) ans.push_back(matrix[i][right]);
            right--;

            // Bottom Row
            if(top <= bottom) {
                for(int i = right; i >= left; i--) ans.push_back(matrix[bottom][i]);
                bottom--;
            }

            // Left Column
            if(left <= right) {
                for(int i = bottom; i >= top; i--) ans.push_back(matrix[i][left]);
                left++;
            }
        }
        return ans;
    }
};

// Time Complexity  : O(n ^ 2)
// Space Complexity : O(1) [The vector "ans" is just for returning the answer]