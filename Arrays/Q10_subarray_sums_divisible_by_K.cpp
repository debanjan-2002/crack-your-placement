// Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

// A subarray is a contiguous part of an array.

// Example 1:
// Input: nums = [4,5,0,-2,-3,1], k = 5
// Output: 7
// Explanation: There are 7 subarrays with a sum divisible by k = 5:
// [4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]

// Example 2:
// Input: nums = [5], k = 9
// Output: 0

#include<bits/stdc++.h>
using namespace std;

// Important Hashing question
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int currSum = 0;
        int ans = 0;
        
        mp[0] = 1;
        
        for(int i = 0; i < n; i++) {
            currSum = (currSum + nums[i]) % k;
            if(currSum < 0) currSum += k;
            
            if(mp.count(currSum)) ans += mp[currSum];
            mp[currSum]++;
        }
        return ans;
    }
};

// Time Complexity  : O(n)
// Space Complexity : O(n)