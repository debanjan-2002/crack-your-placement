// There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

// A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

// Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

// Example 1:
// Illustration of graph
// Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
// Output: [2,4,5,6]
// Explanation: The given graph is shown above.
// Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them.
// Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.

// Example 2:
// Input: graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
// Output: [4]
// Explanation:
// Only node 4 is a terminal node, and every path starting at node 4 leads to node 4.

#include<bits/stdc++.h>
using namespace std;

// Important question
// Topological Sort

class Solution {
public:
    void reverseGraph(vector<int> adj[], vector<int> &indegree, vector<vector<int>>& graph){
        for(int i = 0; i < graph.size(); i++){
            for(int &v : graph[i]){
                adj[v].push_back(i);
                indegree[i]++;
            }
        }
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ans;
        vector<int> adj[n];
        vector<int> indegree(n);
        reverseGraph(adj, indegree, graph);
        
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int u = q.front();
            q.pop();
            ans.push_back(u);
            for(int &v: adj[u]) {
                if(--indegree[v] == 0) q.push(v);
            }
        }   
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// Time Complexity  : O(V + E)
// Space Complexity : O(V + E)
// where, E = no. of edges and V = no. of vertices