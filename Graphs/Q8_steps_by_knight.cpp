// Given a square chessboard, the initial position of Knight and position of a target. Find out the minimum steps a Knight will take to reach the target position.

// Note:
// The initial and the target position coordinates of Knight have been given according to 1-base indexing.

// Example 1:
// Input:
// N=6
// knightPos[ ] = {4, 5}
// targetPos[ ] = {1, 1}
// Output:
// 3
// Explanation:
// Knight takes 3 step to reach from 
// (4, 5) to (1, 1):
// (4, 5) -> (5, 3) -> (3, 2) -> (1, 1).

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isPointInsideGrid(int row, int col, int n) {
        return (row >= 1 && col >= 1 && row <= n && col <= n);
    }
public:
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N) {
	    queue<pair<int, int>> q;
	    vector<vector<int>> visited(N + 1, vector<int> (N + 1));
	    vector<vector<int>> dirs = {
	        {-2, -1},
	        {-2, 1},
	        {-1, -2},
	        {-1, 2},
	        {2, 1},
	        {2, -1},
	        {1, 2},
	        {1, -2}
	    };
	    int steps = 0;
	    int targetX = TargetPos[0];
	    int targetY = TargetPos[1];
	    
	    q.push({KnightPos[0], KnightPos[1]});
	    visited[KnightPos[0]][KnightPos[1]] = 1;
	    
	    while(!q.empty()) {
	        int count = q.size();
	        for(int i = 0; i < count; i++) {
	            auto curr = q.front();
	            q.pop();
	            
	            int row = curr.first;
	            int col = curr.second;
	            
	            if(row == targetX && col == targetY) return steps;
	            
	            for(auto d : dirs) {
	                int newRow = row + d[0];
	                int newCol = col + d[1];
	                
	                if(!isPointInsideGrid(newRow, newCol, N)) continue;
	                if(visited[newRow][newCol]) continue;
	                
	                q.push({newRow, newCol});
	                visited[newRow][newCol] = 1;
	            }
	        }
	        steps++;
	    }
	    return -1;
	}
};

// Time Complexity  : O(n ^ 2)
// Space Complexity : O(n ^ 2)