// Given an adjacency list of a graph adj  of V no. of vertices having 0 based index. Check whether the graph is bipartite or not.
 
// Example 1:
// Input: 
// Output: 1
// Explanation: The given graph can be colored 
// in two colors so, it is a bipartite graph.

// Example 2:
// Input:
// Output: 0
// Explanation: The given graph cannot be colored 
// in two colors such that color of adjacent 
// vertices differs. 

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool dfs(vector<int> adj[], int src, vector<int>& colors) {
        for(int v : adj[src]) {
            if(colors[v] == -1) {
                colors[v] = !colors[src];
                if(!dfs(adj, v, colors)) return false;
            }
            if(colors[v] == colors[src]) return false;
        }
        return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> colors(V, -1);
	    
	    for(int i = 0; i < V; i++) {
	        if(colors[i] == -1) {
	            colors[i] = 1;
	            if(!dfs(adj, i, colors)) return false;
	        }
	    }
	    return true;
	}

};

// Time Complexity  : O(V + E)
// Space Complexity : O(V)