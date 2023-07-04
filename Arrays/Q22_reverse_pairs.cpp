// Given an integer array nums, return the number of reverse pairs in the array.

// A reverse pair is a pair (i, j) where:

// 0 <= i < j < nums.length and
// nums[i] > 2 * nums[j].
 
// Example 1:
// Input: nums = [1,3,2,3,1]
// Output: 2
// Explanation: The reverse pairs are:
// (1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
// (3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1

// Example 2:
// Input: nums = [2,4,3,5,1]
// Output: 3
// Explanation: The reverse pairs are:
// (1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
// (2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
// (3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1

#include<bits/stdc++.h>
using namespace std;

// Important Question (Merge Sort Application)

class Solution {
private:
    int countAndMerge(vector<int>& nums, int low, int mid, int high) {
        int n = mid - low + 1;
        int m = high - mid;

        vector<int> left(n);
        vector<int> right(m);

        for(int k = 0; k < n; k++) left[k] = nums[low + k];
        for(int k = 0; k < m; k++) right[k] = nums[mid + k + 1];

        int p = 0;
        int ans = 0;

        for(int i = 0; i < n; i++) {
            while(p < m && left[i] > 2LL * right[p]) p++;
            ans += p;
        }

        int i = 0;
        int j = 0;
        int k = low;

        while(i < n && j < m) {
            if(left[i] <= right[j]) nums[k++] = left[i++];
            else nums[k++] = right[j++];
        }
        while(i < n) nums[k++] = left[i++];
        while(j < m) nums[k++] = right[j++];
        
        return ans;
    }
    int count(vector<int>& nums, int low, int high) {
        int ans = 0;
        if(low < high) {
            int mid = low + (high - low) / 2;
            ans += count(nums, low, mid);
            ans += count(nums, mid + 1, high);
            ans += countAndMerge(nums, low, mid, high);
        }
        return ans;
    }
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return count(nums, 0, n - 1);
    }
};

// Time Complexity  : O((n + n)logn) = O(nlogn) 
// Space Complexity : O(nlogn)