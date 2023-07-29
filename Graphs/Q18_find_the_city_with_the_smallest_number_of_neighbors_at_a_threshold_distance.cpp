// There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.

// Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.

// Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.

// Example 1:
// Input: n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
// Output: 3
// Explanation: The figure above describes the graph. 
// The neighboring cities at a distanceThreshold = 4 for each city are:
// City 0 -> [City 1, City 2] 
// City 1 -> [City 0, City 2, City 3] 
// City 2 -> [City 0, City 1, City 3] 
// City 3 -> [City 1, City 2] 
// Cities 0 and 3 have 2 neighboring cities at a distanceThreshold = 4, but we have to return city 3 since it has the greatest number.

// Example 2:
// Input: n = 5, edges = [[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]], distanceThreshold = 2
// Output: 0
// Explanation: The figure above describes the graph. 
// The neighboring cities at a distanceThreshold = 2 for each city are:
// City 0 -> [City 1] 
// City 1 -> [City 0, City 4] 
// City 2 -> [City 3, City 4] 
// City 3 -> [City 2, City 4]
// City 4 -> [City 1, City 2, City 3] 
// The city 0 has 1 neighboring city at a distanceThreshold = 2.

#include<bits/stdc++.h>
using namespace std;

// Shortest Path Algorithm Application
// Dijkstra's Algorithm

class Solution {
private:
    void buildGraph(vector<vector<int>>& edges, vector<pair<int,int>> adj[]) {
        for(auto &edge : edges) {
            int node1 = edge[0];
            int node2 = edge[1];
            int wt = edge[2];
            adj[node1].push_back({node2, wt});
            adj[node2].push_back({node1, wt});
        }
    }
    void dijkstra(vector<pair<int,int>> adj[], int src, vector<vector<int>>& dist) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        pq.push({ 0, src });
        dist[src][src] = 0;

        while(!pq.empty()) {
            int currDist = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();

            for(auto &v : adj[currNode]) {
                int nextNode = v.first;
                int nextDist = v.second;

                if(dist[src][nextNode] > dist[src][currNode] + nextDist) {
                    dist[src][nextNode] = dist[src][currNode] + nextDist;
                    pq.push({ dist[src][nextNode], nextNode });
                }
            }
        }
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<pair<int,int>> adj[n];
        vector<vector<int>> dist(n, vector<int> (n, INT_MAX));
        buildGraph(edges, adj);

        for(int i = 0; i < n; i++) {
            dijkstra(adj, i, dist);
        }

        int ans = 0;
        int minCityCount = 1e9;

        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = 0; j < n; j++) {
                if(i != j && dist[i][j] <= distanceThreshold) count++;
            }
            if(minCityCount > count) {
                minCityCount = count;
                ans = i;
            }
            else if(minCityCount == count) ans = max(ans, i);
        }
        return ans;
    }
};

// Time Complexity  : O(n ^ 3)
// Space Complexity : O(n ^ 2)