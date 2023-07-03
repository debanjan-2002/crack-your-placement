// You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

// Merge nums1 and nums2 into a single array sorted in non-decreasing order.

// The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

// Example 1:
// Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
// Output: [1,2,2,3,5,6]
// Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
// The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

// Example 2:
// Input: nums1 = [1], m = 1, nums2 = [], n = 0
// Output: [1]
// Explanation: The arrays we are merging are [1] and [].
// The result of the merge is [1].

// Example 3:
// Input: nums1 = [0], m = 0, nums2 = [1], n = 1
// Output: [1]
// Explanation: The arrays we are merging are [] and [1].
// The result of the merge is [1].
// Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Approach 1 - Extra space
    void mergeSortedArray1(vector<int>& nums1, vector<int>& nums2, int m, int n) {
        int k = 0;
        int i = 0;
        int j = 0;
        vector<int> temp(n + m);

        while(i < m && j < n) {
            if(nums1[i] <= nums2[j]) temp[k++] = nums1[i++];
            else temp[k++] = nums2[j++];
        }
        while(i < m) temp[k++] = nums1[i++];
        while(j < n) temp[k++] = nums2[j++];

        for(int i = 0; i < m + n; i++) nums1[i] = temp[i];
    }
    // Approach 2 - No Extra Space (Backward traversal)
    void mergeSortedArray2(vector<int>& nums1, vector<int>& nums2, int m, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = n + m - 1;

        while(i >= 0 && j >= 0) {
            if(nums1[i] >= nums2[j]) nums1[k--] = nums1[i--];
            else nums1[k--] = nums2[j--];
        }
        while(j >= 0) nums1[k--] = nums2[j--];
        // We don't need to check for (i >= 0) case here, because if i >= 0 
        // which means obviously j == 0, then all the left elements of nums1
        // will already be in correct place
    }
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // mergeSortedArray1(nums1, nums2, m, n);
        mergeSortedArray2(nums1, nums2, m, n);
    }
};

// Time Complexity  : O(m + n) 
// Space Complexity : O(1)