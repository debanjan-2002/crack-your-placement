// You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

// On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

// Find and return the maximum profit you can achieve.

// Example 1:
// Input: prices = [7,1,5,3,6,4]
// Output: 7
// Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
// Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
// Total profit is 4 + 3 = 7.

// Example 2:
// Input: prices = [1,2,3,4,5]
// Output: 4
// Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
// Total profit is 4.

// Example 3:
// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Approach 1 - Recursion (TLE - Not accepted)
    int maxProfitRecursion(vector<int>& prices, int i, int canBuy) {
        if(i == prices.size()) {
            return 0;
        }
        if(canBuy) {
            int op1 = maxProfitRecursion(prices, i + 1, canBuy);
            int op2 = -prices[i] + maxProfitRecursion(prices, i + 1, !canBuy);
            return max(op1, op2);
        }
        else {
            int op1 = maxProfitRecursion(prices, i + 1, canBuy);
            int op2 = prices[i] + maxProfitRecursion(prices, i + 1, !canBuy);
            return max(op1, op2);
        }
    }
    // Approach 2 - Recursion + Memoization (Accepted)
    int maxProfitMemoized(vector<int>& prices, int i, int canBuy, vector<vector<int>>& dp) {
        if(i == prices.size()) {
            return 0;
        }
        if(dp[i][canBuy] != -1) {
            return dp[i][canBuy];
        }
        if(canBuy) {
            int op1 = maxProfitMemoized(prices, i + 1, canBuy, dp);
            int op2 = -prices[i] + maxProfitMemoized(prices, i + 1, !canBuy, dp);
            return dp[i][canBuy] = max(op1, op2);
        }
        else {
            int op1 = maxProfitMemoized(prices, i + 1, canBuy, dp);
            int op2 = prices[i] + maxProfitMemoized(prices, i + 1, !canBuy, dp);
            return dp[i][canBuy] = max(op1, op2);
        }
    }
    // Approach 3 - Dynamic Programming (DP)
    int maxProfitDP(vector<int>& prices, int n) {
        vector<vector<int>> dp(n + 1, vector<int> (2));

        for(int i = n - 1; i >= 0; i--) {
            dp[i][1] = max(dp[i + 1][1], -prices[i] + dp[i + 1][0]);
            dp[i][0] = max(dp[i + 1][0], prices[i] + dp[i + 1][1]);
        }
        return dp[0][1];
    }
    // Approach 4 - DP + Space Optimization
    int maxProfitDPSpaceOptimized(vector<int>& prices, int n) {
        vector<int> curr(2);
        vector<int> next(2);

        for(int i = n - 1; i >= 0; i--) {
            curr[1] = max(next[1], -prices[i] + next[0]);
            curr[0] = max(next[0], prices[i] + next[1]);
            next = curr;
        }
        return curr[1];
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>> dp(n, vector<int>(2, -1));

        // return maxProfitRecursion(prices, 0, 1);
        // return maxProfitMemoized(prices, 0, 1, dp);
        // return maxProfitDP(prices, n);
        return maxProfitDPSpaceOptimized(prices, n);
    }
};