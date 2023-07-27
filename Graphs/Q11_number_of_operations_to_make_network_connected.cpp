// There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

// You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

// Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.

// Example 1:
// Input: n = 4, connections = [[0,1],[0,2],[1,2]]
// Output: 1
// Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.

// Example 2:
// Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
// Output: 2

// Example 3:
// Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
// Output: -1
// Explanation: There are not enough cables.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void makeGraph(vector<vector<int>>& connections, vector<int> adj[]){
        for(int i = 0; i < connections.size(); i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
    }
    void dfs(vector<int> adj[], int s, vector<int>& visited, int &nodes, int &paths){
        visited[s] = true;
        nodes++;
        paths += adj[s].size();
        for(int &v : adj[s]){
            if(!visited[v]){
                dfs(adj,v,visited,nodes,paths);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        vector<int> visited(n);
        int components = 0;
        int nodes = 0;
        int paths = 0;
        int availablePaths = 0;
        makeGraph(connections, adj);
        
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                components++;
                dfs(adj, i, visited, nodes, paths);
                availablePaths += (paths/2 - nodes + 1);
                nodes = 0;
                paths = 0;
            }
        }
        if(components == 1)
            return 0;
        int requiredPaths = components - 1;
        if(availablePaths >= requiredPaths)
            return requiredPaths;
        return -1;
        
    }
};

// Time Complexity  : O(V + E)
// Space Complexity : O(V + E)
// where, E = no. of edges and V = no. of vertices