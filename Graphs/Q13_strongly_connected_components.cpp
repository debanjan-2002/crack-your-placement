// Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, Find the number of strongly connected components in the graph.

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void topologicalSort(vector<vector<int>>& adj, int src, vector<int>& visited, stack<int>& st) {
        visited[src] = 1;
        
        for(int v : adj[src]) {
            if(!visited[v]) {
                topologicalSort(adj, v, visited, st);
            }
        }
        st.push(src);
    }
    void dfs(vector<int> adj[], int src, vector<int>& visited) {
        visited[src] = 1;
        
        for(int v : adj[src]) {
            if(!visited[v]) {
                dfs(adj, v, visited);
            }
        }
    }
public: 
    int kosaraju(int V, vector<vector<int>>& adj) {
        // Steps 1 : Sort the nodes in terms of finish time (Topological sort - dfs)
        stack<int> st;
        vector<int> visited(V, 0);
        
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                topologicalSort(adj, i, visited, st);
            }
        }
        
        // Step 2 : Reverse the graph
        vector<int> reverseAdj[V];
        for(int i = 0; i < V; i++) {
            visited[i] = 0;
            for(int j = 0; j < adj[i].size(); j++) {
                reverseAdj[adj[i][j]].push_back(i);
            }
        }
        
        // Step 3 : Do DFS in reversed graph in order of the nodes received in step 1
        int ans = 0;
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            
            if(!visited[node]) {
                dfs(reverseAdj, node, visited);
                ans++;
            }
        }
        return ans;
    }
};

// Time Complexity  : O(V + E)
// Space Complexity : O(V + E)
// where, E = no. of edges and V = no. of vertices