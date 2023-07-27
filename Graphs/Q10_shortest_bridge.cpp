// You are given an n x n binary matrix grid where 1 represents land and 0 represents water.

// An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.

// You may change 0's to 1's to connect the two islands to form one island.

// Return the smallest number of 0's you must flip to connect the two islands.

// Example 1:
// Input: grid = [[0,1],[1,0]]
// Output: 1

// Example 2:
// Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
// Output: 2

// Example 3:
// Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
// Output: 1

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isPointInsideGrid(int row, int col, int n) {
        return (row >= 0 && col >= 0 && row < n && col < n);
    }
    void dfs(vector<vector<int>>& grid, int row, int col, int n, queue<pair<int,int>>& q, vector<vector<int>>& visited) {
        if(!isPointInsideGrid(row, col, n)) return;
        if(grid[row][col] == 2 || grid[row][col] == 0) return;

        vector<int> dx = {1, 0, -1, 0};
        vector<int> dy = {0, 1, 0, -1};

        grid[row][col] = 2;
        q.push({row, col});
        visited[row][col] = 1;

        for(int i = 0; i < 4; i++) {
            int newRow = row + dx[i];
            int newCol = col + dy[i];

            dfs(grid, newRow, newCol, n, q, visited);
        } 
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,int>> q;
        vector<vector<int>> visited(n, vector<int> (n));
        int len = -1;

        for(int i = 0; i < n; i++) {
            bool flag = false;
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    dfs(grid, i, j, n, q, visited);
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }

        while(!q.empty()) {
            int count = q.size();
            for(int i = 0; i < count; i++) {
                auto curr = q.front();
                int row = curr.first;
                int col = curr.second;
                q.pop();

                if(grid[row][col] == 1) return len;

                vector<int> dx = {1, 0, -1, 0};
                vector<int> dy = {0, 1, 0, -1};

                for(int i = 0; i < 4; i++) {
                    int newRow = row + dx[i];
                    int newCol = col + dy[i];

                    if(!isPointInsideGrid(newRow, newCol, n)) continue;
                    if(visited[newRow][newCol]) continue;

                    q.push({newRow, newCol});
                    visited[newRow][newCol] = 1;
                }
            }
            len++;
        }
        return len;
    }
}; 

// Time Complexity  : O(n ^ 2)
// Space Complexity : O(n ^ 2)