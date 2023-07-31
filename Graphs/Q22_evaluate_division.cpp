// You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.

// You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.

// Return the answers to all queries. If a single answer cannot be determined, return -1.0.

// Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.

// Note: The variables that do not occur in the list of equations are undefined, so the answer cannot be determined for them.

// Example 1:
// Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
// Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
// Explanation: 
// Given: a / b = 2.0, b / c = 3.0
// queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? 
// return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
// note: x is undefined => -1.0

// Example 2:
// Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
// Output: [3.75000,0.40000,5.00000,0.20000]

// Example 3:
// Input: equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
// Output: [0.50000,2.00000,-1.00000,-1.00000]

#include<bits/stdc++.h>
using namespace std;

// Good application of Graph
// DFS

class Solution {
private:
    void buildGraph(map<string, map<string, double>> &adj, vector<vector<string>>& equations, vector<double>& values, int n) {
        for(int i=0; i<n; i++) {
            string operand_1 = equations[i][0];
            string operand_2 = equations[i][1];
            adj[operand_1][operand_2] = values[i];
            adj[operand_2][operand_1] = 1.0 / values[i];
        }
    }
    double dfs(string &numerator, string &denominator, map<string, map<string, double>> &adj, set<string>& visited) {
        if(!adj.count(numerator)) return -1.0;
        if(adj[numerator].count(denominator)) return adj[numerator][denominator];
        
        visited.insert(numerator);
        for(auto it : adj[numerator]) {
            string start = it.first;
            if(!visited.count(start)) {
                double product = dfs(start, denominator, adj, visited);
                if(product != -1.0) 
                    return (it.second * product);
            }
        }
        return -1.0;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        int m = queries.size();
        map<string, map<string, double>> adj;
        buildGraph(adj, equations, values, n);
        set<string> visited;
        vector<double> ans(m, -1.0);
        
        for(int i=0; i<m; i++) {
            visited.clear();
            ans[i] = dfs(queries[i][0], queries[i][1], adj, visited);
        }
        return ans;
    }
};

// Time Complexity  : O(No of equations * No of queries)
// Space Complexity : O(No of unique strings in the equations)