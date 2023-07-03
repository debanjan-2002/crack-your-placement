// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.

// Example 1:
// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

// Example 2:
// Input: nums = [2,2,2,2,2], target = 8
// Output: [[2,2,2,2]]

#include<bits/stdc++.h>
using namespace std;

// Sorting based solution

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        if(n < 4) return {};

        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int p = j + 1;
                int q = n - 1;
                long long currSum = nums[i] + nums[j];
                long long remSum = target - currSum;
                while(p < q) {
                    long long sum = nums[p] + nums[q];
                    if(sum == remSum) {
                        ans.push_back({nums[i], nums[j], nums[p], nums[q]});
                        p++;
                        q--;

                        while(p < q && nums[p] == nums[p - 1]) p++;
                        while(p < q && nums[q] == nums[q + 1]) q--;
                    }
                    else if(sum > remSum) q--;
                    else p++;
                }
                while(j < n - 1 && nums[j] == nums[j + 1]) j++;
            }
            while(i < n - 1 && nums[i] == nums[i + 1]) i++;
        }
        return ans;
    }
};

// Time Complexity  : O(nlogn) + O(n ^ 3) = O(n ^ 3)
// Space Complexity : O(1) [The vector "ans" is just for returning the answer]