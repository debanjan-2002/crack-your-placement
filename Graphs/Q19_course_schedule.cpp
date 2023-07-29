// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return true if you can finish all courses. Otherwise, return false.

// Example 1:
// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: true
// Explanation: There are a total of 2 courses to take. 
// To take course 1 you should have finished course 0. So it is possible.

// Example 2:
// Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take. 
// To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

#include<bits/stdc++.h>
using namespace std;

// Topological Sort
// Kahn's Algorithm

class Solution {
private:
    void buildGraph(vector<vector<int>>& prerequisites, vector<int>& indegree, vector<int> adj[]) {
        for(auto &edge : prerequisites) {
            adj[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
        }
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> indegree(numCourses);
        queue<int> q;
        int count = 0;
        
        buildGraph(prerequisites, indegree, adj);

        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            count++;

            for(int &v : adj[u]) {
                if(--indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        return (count == numCourses);
    }
};

// Time Complexity  : O(V + E)
// Space Complexity : O(V)