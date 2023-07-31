// Given a weighted directed graph with n nodes and m edges. Nodes are labeled from 0 to n-1, the task is to check if it contains a negative weight cycle or not.
// Note: edges[i] is defined as u, v and weight.
 
// Example 1:
// Input: n = 3, edges = {{0,1,-1},{1,2,-2},
// {2,0,-3}}
// Output: 1
// Explanation: The graph contains negative weight
// cycle as 0->1->2->0 with weight -1,-2,-3.

// Example 2:
// Input: n = 3, edges = {{0,1,-1},{1,2,-2},
// {2,0,3}}
// Output: 0
// Explanation: The graph does not contain any
// negative weight cycle.

#include<bits/stdc++.h>
using namespace std;

// Application of Bellman Ford Algorithm

class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    vector<int> dist(n, INT_MAX);
	    dist[0] = 0;
	    
	    // Relax for (n - 1) times
	    for(int k = 0; k < n - 1; k++) {
	        for(auto &edge : edges) {
	            int src = edge[0];
	            int dest = edge[1];
	            int wt = edge[2];
	            
	            if(dist[src] == INT_MAX) continue;
	            if(dist[dest] > dist[src] + wt) dist[dest] = dist[src] + wt;
	        }    
	    }
	    for(auto &edge : edges) {
            int src = edge[0];
            int dest = edge[1];
            int wt = edge[2];
            
            if(dist[dest] > dist[src] + wt) return 1;
	   }
	   return 0;
	}
};

// Time Complexity  : O(V * E)
// Space Complexity : O(V)