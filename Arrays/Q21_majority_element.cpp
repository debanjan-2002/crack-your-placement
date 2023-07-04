// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

// Example 1:
// Input: nums = [3,2,3]
// Output: 3

// Example 2:
// Input: nums = [2,2,1,1,1,2,2]
// Output: 2

#include<bits/stdc++.h>
using namespace std;

// Moore's Voting Algorithm

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int possibleMajority = nums[0];
        int count = 1;

        for(int i = 1; i < n; i++) {
            if(nums[i] == possibleMajority) count++;
            else count--;

            if(count == 0) {
                possibleMajority = nums[i];
                count = 1;
            }
        }
        return possibleMajority;
    }
};

// Time Complexity  : O(n) 
// Space Complexity : O(1)