// Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. Graph is in the form of adjacency list where adj[i] contains all the nodes ith node is having edge with.

// Example 1:
// Input:  
// V = 5, E = 5
// adj = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}} 
// Output: 1
// Explanation: 
// 1->2->3->4->1 is a cycle.

// Example 2:
// Input: 
// V = 4, E = 2
// adj = {{}, {2}, {1, 3}, {2}}
// Output: 0
// Explanation: 
// No cycle in the graph.

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool doesCycleExist(vector<int> adj[], int src, vector<int>& visited, int parent) {
        visited[src] = 1;
        
        for(int v : adj[src]) {
            if(!visited[v]) {
                if(doesCycleExist(adj, v, visited, src))
                    return true;
            }
            else if(v != parent) return true;
        }
        return false;
    }
public:
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visited(V);
        
        for(int i = 0; i < V; i++) {
            if(!visited[i] && doesCycleExist(adj, i, visited, -1)) 
                return true;
        }
        return false;
    }
};

// Time Complexity  : O(V + E)
// Space Complexity : O(V)
// where, E = no. of edges and V = no. of vertices