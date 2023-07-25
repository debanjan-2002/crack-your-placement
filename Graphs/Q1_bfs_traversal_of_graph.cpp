// Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.
// Note: One can move from node u to node v only if there's an edge from u to v. Find the BFS traversal of the graph starting from the 0th vertex, from left to right according to the input graph. Also, you should only take nodes directly or indirectly connected from Node 0 in consideration.

// Example 1:
// Input:
// Output: 0 1 2 3 4
// Explanation: 
// 0 is connected to 1 , 2 , 3.
// 2 is connected to 4.
// so starting from 0, it will go to 1 then 2
// then 3. After this 2 to 4, thus bfs will be
// 0 1 2 3 4.

// Example 2:
// Input:
// Output: 0 1 2
// Explanation:
// 0 is connected to 1 , 2.
// so starting from 0, it will go to 1 then 2,
// thus bfs will be 0 1 2. 

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        queue<int> q;
        vector<int> ans;
        vector<int> visited(V, 0);
        
        q.push(0);
        visited[0] = 1;
        
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            
            for(int neighbour : adj[curr]) {
                if(!visited[neighbour]) {
                    q.push(neighbour);
                    visited[neighbour] = 1;
                }
            }
        }
        return ans;
    }
};

// Time Complexity  : O(V + E)
// Space Complexity : O(V)
// where, E = no. of edges and V = no. of vertices