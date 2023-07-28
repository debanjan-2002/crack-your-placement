// Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized, and return the distance. If no land or water exists in the grid, return -1.

// The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.

// Example 1:
// Input: grid = [[1,0,1],[0,0,0],[1,0,1]]
// Output: 2
// Explanation: The cell (1, 1) is as far as possible from all the land with distance 2.

// Example 2:
// Input: grid = [[1,0,0],[0,0,0],[0,0,0]]
// Output: 4
// Explanation: The cell (2, 2) is as far as possible from all the land with distance 4.

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isPointInsideGrid(int row, int col, int n) {
        return (row >= 0 && col >= 0 && row < n && col < n);
    }
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        vector<vector<int>> visited(n, vector<int> (n));
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};
        int ans = -1;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    q.push({i, j});
                    visited[i][j] = 1;
                }
            }
        }

        if(q.empty() || q.size() == n * n) return -1;

        while(!q.empty()) {
            int count = q.size();
            for(int i = 0; i < count; i++) {
                auto curr = q.front();
                int row = curr.first;
                int col = curr.second;
                q.pop();

                for(int i = 0; i < 4; i++) {
                    int newRow = row + dx[i];
                    int newCol = col + dy[i];

                    if(!isPointInsideGrid(newRow, newCol, n)) continue;
                    if(visited[newRow][newCol]) continue;
                    if(grid[newRow][newCol] == 1) continue;

                    q.push({newRow, newCol});
                    visited[newRow][newCol] = 1;
                }
            }
            ans++;
        }
        return ans;
    }
};

// Time Complexity  : O(n ^ 2)
// Space Complexity : O(n ^ 2)