// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

// A subarray is a contiguous non-empty sequence of elements within an array.

// Example 1:
// Input: nums = [1,1,1], k = 2
// Output: 2

// Example 2:
// Input: nums = [1,2,3], k = 3
// Output: 2

#include<bits/stdc++.h>
using namespace std;

// Hashmap Approach (Important Question)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int ans = 0;
        int curr = 0;

        mp[0] = 1;

        for(int i = 0; i < n; i++) {
            curr += nums[i];
            if(mp.count(curr - k)) ans += mp[curr - k];
            mp[curr]++;
        }
        return ans;
    }
};

// Time Complexity  : O(n) [Considering insertion/lookup in hashmap as constant operation]
// Space Complexity : O(n)