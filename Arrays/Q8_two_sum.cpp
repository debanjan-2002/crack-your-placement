// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

// Example 1:
// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

// Example 2:
// Input: nums = [3,2,4], target = 6
// Output: [1,2]

// Example 3:
// Input: nums = [3,3], target = 6
// Output: [0,1]

#include<bits/stdc++.h>
using namespace std;

// There are various approaches to solve this question
// This implementation uses hashing
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        unordered_set<int> s;
        vector<int> ans(2);

        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        for(int i = 0; i < n; i++) {
            if(s.count(target - nums[i])) {
                ans[0] = i;
                ans[1] = mp[target - nums[i]][0];
                return ans;
            }
            s.insert(nums[i]);
        }
        return ans;
    }
};

// Time Complexity  : O(n) + O(n) = O(n)
// Space Complexity : O(n) + O(n) + O(2) = O(n)