// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

// You must solve this problem without using the library's sort function.

// Example 1:
// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]

// Example 2:
// Input: nums = [2,0,1]
// Output: [0,1,2]

#include<bits/stdc++.h>
using namespace std;

// Dutch National Flag Algorithm
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        int lastIndexOfZero = -1;
        int firstIndexOfTwo = n;

        int i = 0;

        while(i < n && i < firstIndexOfTwo) {
            if(nums[i] == 0) {
                swap(nums[i], nums[++lastIndexOfZero]);
                i++;
            }
            else if(nums[i] == 2) {
                swap(nums[i], nums[--firstIndexOfTwo]);
            }
            else {
                i++;
            }
        }
    }
};

// Time Complexity  : O(n)
// Space Complexity : O(1)