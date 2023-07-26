// Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
// Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.

// Example 1:
// Input:
// N = 4
// m[][] = {{1, 0, 0, 0},
//          {1, 1, 0, 1}, 
//          {1, 1, 0, 0},
//          {0, 1, 1, 1}}
// Output:
// DDRDRR DRDDRR
// Explanation:
// The rat can reach the destination at 
// (3, 3) from (0, 0) by two paths - DRDDRR 
// and DDRDRR, when printed in sorted order 
// we get DDRDRR DRDDRR.

// Example 2:
// Input:
// N = 2
// m[][] = {{1, 0},
//          {1, 0}}
// Output:
// -1
// Explanation:
// No path exists and destination cell is 
// blocked.

#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
    vector<string> ans;
    
    bool isPointInsideGrid(int row, int col, int n) {
        return (row >= 0 && col >= 0 && row < n && col < n);
    }
    void dfs(vector<vector<int>>& grid, int row, int col, int n, string currPath) {
        if(!isPointInsideGrid(row, col, n)) return;
        if(grid[row][col] == 0) return;
        
        if(row == n - 1 && col == n - 1) {
            ans.push_back(currPath);
            return;
        }
        
        grid[row][col] = 0;
        
        dfs(grid, row + 1, col, n, currPath + 'D');
        dfs(grid, row - 1, col, n, currPath + 'U');
        dfs(grid, row, col + 1, n, currPath + 'R');
        dfs(grid, row, col - 1, n, currPath + 'L');
        
        grid[row][col] = 1;
    }
public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        dfs(m, 0, 0, n, "");
        return ans;
    }
};

// Time Complexity  : O(4^(n^2))
// Space Complexity : O(1)