// Given a weighted, undirected and connected graph of V vertices and E edges. The task is to find the sum of weights of the edges of the Minimum Spanning Tree.

// Example 1:
// Input:
// 3 3
// 0 1 5
// 1 2 3
// 0 2 1
// Output:
// 4
// Explanation:
// The Spanning Tree resulting in a weight
// of 4 is shown above.

// Example 2:
// Input:
// 2 1
// 0 1 5
// Output:
// 5
// Explanation:
// Only one Spanning Tree is possible
// which has a weight of 5.

#include<bits/stdc++.h>
using namespace std;

// Prim's Algorithm

class Solution {
private:
    int prims(vector<vector<int>> adj[], int V) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> visited(V);
        int sum = 0;
        
        pq.push({0, 0});
        
        while(!pq.empty()) {
            auto curr = pq.top();
            int currDist = curr.first;
            int currNode = curr.second;
            pq.pop();
            
            if(visited[currNode]) continue;
            visited[currNode] = 1;
            
            sum += currDist;
            
            for(auto &v : adj[currNode]) {
                int nextNode = v[0];
                int nextDist = v[1];
                
                if(visited[nextNode]) continue;
                
                pq.push({nextDist, nextNode});
            }
        }
        return sum;
    }
public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        return prims(adj, V);
    }
};

// Time Complexity  : O(ElogV)
// Space Complexity : O(V)