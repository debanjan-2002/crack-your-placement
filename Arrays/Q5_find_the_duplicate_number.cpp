// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

// There is only one repeated number in nums, return this repeated number.

// You must solve the problem without modifying the array nums and uses only constant extra space.

// Example 1:
// Input: nums = [1,3,4,2,2]
// Output: 2

// Example 2:
// Input: nums = [3,1,3,4,2]
// Output: 3

#include<bits/stdc++.h>
using namespace std;

// Binary Search Approach (Uses constant space + no modification in input array)
class Approach1 {
private:
    int countValuesLessThanK(vector<int>& nums, int k) {
        int cnt = 0;
        for(int num : nums) {
            if(num <= k) {
                cnt++;
            }
        }
        return cnt;
    }
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();

        int low = 1;
        int high = n - 1;
        int ans = -1;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(countValuesLessThanK(nums, mid) <= mid) {
                low = mid + 1;
            }
            else {
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};

// Time Complexity  : O(nlogn)
// Space Complexity : O(1)

// Slow and fast pointer technique (Uses constant space + no modification in input array)
// Similar to detecting and removing loop from a linked list
// Idea is to treat the repeating element as the element of a linked list which is causing the loop 
class Approach2 {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);

        fast = nums[0];

        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};

// Time Complexity  : O(n) + O(n) = O(n)
// Space Complexity : O(1)