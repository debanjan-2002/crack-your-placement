// In this problem, a tree is an undirected graph that is connected and has no cycles.

// You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

// Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

// Example 1:
// Input: edges = [[1,2],[1,3],[2,3]]
// Output: [2,3]

// Example 2:
// Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
// Output: [1,4]

#include<bits/stdc++.h>
using namespace std;

class DSU {
private:
    vector<int> parent;
    vector<int> rank;
public:
    DSU(int n) {
        parent = vector<int>(n + 1);
        rank = vector<int>(n + 1);
        for(int i = 1; i <= n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int find(int x) {
        if(x == parent[x]) return x;
        parent[x] = find(parent[x]);
        return parent[x];
    }
    bool _union(int x, int y) {
        int parentX = find(x);
        int parentY = find(y);
        if(parentX == parentY) return false;

        if(rank[parentX] < rank[parentY]) parent[parentX] = parentY;
        else if(rank[parentX] > rank[parentY]) parent[parentY] = parentX;
        else {
            parent[parentY] = parentX;
            rank[parentX]++;
        }
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);

        for(int i = 0; i < n; i++) {
            int node1 = edges[i][0];
            int node2 = edges[i][1];
            if(!dsu._union(node1, node2)) {
                return {node1, node2};
            }
        }
        return {};
    }
};

// Time Complexity  : O(n * a(n)) [where n is the number of edges / nodes]
// a(n) is Inverse Ackermann function and it can be approximated to O(1) 
// Space Complexity : O(n)