// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

// Example 1:
// Input: heights = [2,1,5,6,2,3]
// Output: 10
// Explanation: The above is a histogram where width of each bar is 1.
// The largest rectangle is shown in the red area, which has an area = 10 units.

// Example 2:
// Input: heights = [2,4]
// Output: 4

#include<bits/stdc++.h>
using namespace std;

// Stack Solution
// Application of next smaller and previous smaller element in an array

class Solution {
private:
    void prevSmaller(vector<int>& prev,vector<int>& heights){
        stack<int> st;
        prev[0] = 0;
        st.push(0);
        for(int i = 1; i < heights.size(); i++){
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            prev[i] = st.empty() ? i : i - st.top() - 1;
            st.push(i);
        }
    }
    void nextSmaller(vector<int>& next,vector<int>& heights){
        int n = heights.size();
        stack<int> st;
        next[n - 1] = 0;
        st.push(n - 1);
        for(int i = n - 2; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            next[i] = st.empty() ? n - i - 1 : st.top() - i - 1;
            st.push(i);
        }
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        vector<int> prev(n);
        vector<int> next(n);
        prevSmaller(prev, heights);
        nextSmaller(next, heights);
        
        for(int i = 0; i < n; i++){
            ans = max(ans, (prev[i] + next[i] + 1) * heights[i]);
        }

        return ans;
    }
};

// Time Complexity  : O(2n) + O(2n) + O(n) = O(n) 
// Space Complexity : O(n) + O(n) = O(n)