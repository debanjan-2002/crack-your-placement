// On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

// A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

// Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.

// Example 1:
// Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
// Output: 5
// Explanation: One way to remove 5 stones is as follows:
// 1. Remove stone [2,2] because it shares the same row as [2,1].
// 2. Remove stone [2,1] because it shares the same column as [0,1].
// 3. Remove stone [1,2] because it shares the same row as [1,0].
// 4. Remove stone [1,0] because it shares the same column as [0,0].
// 5. Remove stone [0,1] because it shares the same row as [0,0].
// Stone [0,0] cannot be removed since it does not share a row/column with another stone still on the plane.

// Example 2:
// Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
// Output: 3
// Explanation: One way to make 3 moves is as follows:
// 1. Remove stone [2,2] because it shares the same row as [2,0].
// 2. Remove stone [2,0] because it shares the same column as [0,0].
// 3. Remove stone [0,2] because it shares the same row as [0,0].
// Stones [0,0] and [1,1] cannot be removed since they do not share a row/column with another stone still on the plane.

// Example 3:
// Input: stones = [[0,0]]
// Output: 0
// Explanation: [0,0] is the only stone on the plane, so you cannot remove it.

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isValid(vector<int>& curr, vector<int>& next) {
        if(curr[0] == next[0]) return true;
        if(curr[1] == next[1]) return true;
        return false;
    }
    void dfs(vector<vector<int>>& stones, vector<int>& visited, int currIdx) {
        visited[currIdx] = 1;

        for(int i = 0; i < stones.size(); i++) {
            if(i != currIdx && !visited[i] && isValid(stones[currIdx], stones[i])) {
                dfs(stones, visited, i);
            }
        }
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> visited(n, 0);
        int componentCount = 0;

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                dfs(stones, visited, i);
                componentCount++;
            }
        }
        return (n - componentCount);
    }
};

// Time Complexity  : O(n)
// Space Complexity : O(n)