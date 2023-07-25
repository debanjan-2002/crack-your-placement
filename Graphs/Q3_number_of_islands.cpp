// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

// Example 1:
// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1

// Example 2:
// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// Output: 3

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isValidPoint(int row, int col, int n, int m) {
        return (row >= 0 && col >= 0 && row < n && col < m);
    }
    void markLand(vector<vector<char>>& grid, int row, int col) {
        if(!isValidPoint(row, col, grid.size(), grid[0].size())) return;
        if(grid[row][col] == '0') return;

        grid[row][col] = '0';

        markLand(grid, row + 1, col);
        markLand(grid, row - 1, col);
        markLand(grid, row, col + 1);
        markLand(grid, row, col - 1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    ans++;
                    markLand(grid, i, j);
                }
            }
        }
        return ans;
    }
};

// Time Complexity  : O(m * n)
// Space Complexity : O(m * n)