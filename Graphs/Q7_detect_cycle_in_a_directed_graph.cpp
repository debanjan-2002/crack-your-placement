// Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.

// Example 1:
// Input:
// Output: 1
// Explanation: 3 -> 3 is a cycle

// Example 2:
// Input:
// Output: 0
// Explanation: no cycle in the graph

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool doesCycleExist(vector<int> adj[], int src, vector<int>& visited, vector<int>& callStack) {
        visited[src] = 1;
        callStack[src] = 1;
        
        for(int v : adj[src]) {
            if(!visited[v]) {
                if(doesCycleExist(adj, v, visited, callStack)) {
                    return true;
                }
            }
            else if(callStack[v]) return true;
        }
        
        callStack[src] = 0;
        
        return false;
    }
public:
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> visited(V);
        vector<int> callStack(V);
        
        for(int i = 0; i < V; i++) {
            if(!visited[i] && doesCycleExist(adj, i, visited, callStack)) {
                return true;
            }
        }
        return false;
    }
};

// Time Complexity  : O(V + E)
// Space Complexity : O(V)
// where, E = no. of edges and V = no. of vertices