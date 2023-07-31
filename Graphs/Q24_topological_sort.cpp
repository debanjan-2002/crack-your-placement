// Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find any Topological Sorting of that Graph.

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(vector<int> adj[], int src, vector<int>& visited, stack<int>& st) {
        visited[src] = 1;
        
        for(int v : adj[src]) {
            if(!visited[v]) {
                dfs(adj, v, visited, st);
            }
        }
        
        st.push(src);
    }
public:
	vector<int> topoSort(int V, vector<int> adj[]) {
	    vector<int> indegree(V);
	    vector<int> ans;
	    queue<int> q;

        // DFS Approach
        // vector<int> visited(V);
        // stack<int> st;

        // for(int i = 0; i < V; i++) {
	    //     if(!visited[i]) {
	    //         dfs(adj, i, visited, st);
	    //     }
	    // }
	    
	    // while(!st.empty()) {
	    //     ans.push_back(st.top());
	    //     st.pop();
	    // }
	    
	    for(int i = 0; i < V; i++) {
	        for(int v : adj[i]) {
	            indegree[v]++;
	        }
	    }
	    
	    for(int i = 0; i < V; i++) {
	        if(indegree[i] == 0) {
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty()) {
	        int count = q.size();
	        for(int i = 0; i < count; i++) {
	            int curr = q.front();
	            q.pop();
	            
	            ans.push_back(curr);
	            
	            for(int v : adj[curr]) {
	               if(--indegree[v] == 0) {
	                    q.push(v);
	                }     
	            }
	        }
	    }
	    return ans;
	}
};

// Time Complexity  : O(V + E)
// Space Complexity : O(V)