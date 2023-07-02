// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

// Find two lines that together with the x-axis form a container, such that the container contains the most water.

// Return the maximum amount of water a container can store.

// Notice that you may not slant the container.

// Example 1:
// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

// Example 2:
// Input: height = [1,1]
// Output: 1

#include<bits/stdc++.h>
using namespace std;

// IMPORTANT QUESTION
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int left = 0;
        int right = n - 1;
        int area = 0;

        while(left < right) {
            int currArea = (right - left) * min(height[left], height[right]);
            area = max(area, currArea);

            if(height[left] < height[right]) left++;
            else if(height[left] > height[right]) right--;
            else {
                left++;
                right--;
            }
        }
        return area;
    }
};

// Key Points - 
// 1. We move pointer with the lower height is because we already have the max area with that height - since it is the lower pointer that means that every other distance that is closer will always be a smaller distance with the same or less height which means smaller area. 
// 2. Therefore we do not need to look at every other combination with that pointer.
// 3. If both heights are equal you can move both pointers because you're already bound to at most that height anyways so that max couldn't be any more than that position anyways since moving either pointer in will yield an area either less than or equal to the area at your current positions.

// Time Complexity  : O(n)
// Space Complexity : O(1)