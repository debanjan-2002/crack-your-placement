// You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

// Return true if you can reach the last index, or false otherwise.

// Example 1:
// Input: nums = [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

// Example 2:
// Input: nums = [3,2,1,0,4]
// Output: false
// Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Approach 1 - Recursion (TLE)
    bool canReachEndRecursion(vector<int>& nums, int index) {
        if(index >= nums.size() - 1) return true;

        int maxJump = nums[index];
        for(int i = 1; i <= maxJump; i++) {
            if(canReachEndRecursion(nums, index + i)) {
                return true;
            }
        }
        return false;
    }
    // Approach 2 - Recursion + Memoization (Barely Accepted)
    bool canReachEndMemoized(vector<int>& nums, int index, vector<int>& dp) {
        if(index >= nums.size() - 1) return true;
        if(dp[index] != -1) return dp[index];

        int maxJump = nums[index];
        for(int i = 1; i <= maxJump; i++) {
            if(canReachEndMemoized(nums, index + i, dp)) {
                return dp[index] = true;
            }
        }
        return dp[index] = false;
    }
    // Approach 3 - DP (Accepted) 
    bool canReachEndDP(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[n - 1] = 1;

        for(int index = n - 2; index >= 0; index--) {
            int maxJump = nums[index];
            for(int i = 1; i <= maxJump; i++) {
                if(dp[index + i]) {
                    dp[index] = 1;
                    break;
                }
            }
        }
        return dp[0];
    }
    // Approach 4 - Best approach
    bool canReachEnd(vector<int>& nums) {
        int n = nums.size();
        int lastIndexToEnd = n - 1;

        for(int index = n - 2; index >= 0; index--) {
            if(index + nums[index] >= lastIndexToEnd) {
                lastIndexToEnd = index;
            }
        }
        return lastIndexToEnd == 0;        
    }
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);

        // return canReachEndRecursion(nums, 0);
        // return canReachEndMemoized(nums, 0, dp);
        // return canReachEndDP(nums);
        return canReachEnd(nums);
    }
};

// Time Complexity  : O(n) [The complexity of DP/Memoization solution is O(n * maxJump)]
// Space Complexity : O(1)