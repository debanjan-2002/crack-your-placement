// Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

// Example 1:
// Input: n = 3
// Output: 5

// Example 2:
// Input: n = 1
// Output: 1

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int dp[20];
    int catalan(int n) {
        if(n <= 1) return 1;
        if(dp[n] != -1) return dp[n];
        
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            ans += (catalan(i - 1) * catalan(n - i));
        }
        return dp[n] = ans;
    }
    int catalanIterative(int n) {
        vector<int> dp(n + 1, 1);

        for(int i = 2; i <= n; i++) {
            int ans = 0;
            for(int j = 1; j <= i; j++) {
                ans += (dp[j - 1] * dp[i - j]);
            }
            dp[i] = ans;
        }
        return dp[n];
    }
public:
    int numTrees(int n) {
        memset(dp, -1, sizeof dp);
        int ans = catalan(n);
        return ans;
    }
};

// Time Complexity  : O(n ^ 2) 
// Space Complexity : O(n)