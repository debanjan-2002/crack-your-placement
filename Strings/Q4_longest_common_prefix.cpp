// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

// Example 1:
// Input: strs = ["flower","flow","flight"]
// Output: "fl"

// Example 2:
// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int mini = INT_MAX;
        for(int i = 0; i < strs.size(); i++){
            if(strs[i].length() < mini)
                mini = strs[i].length();
        }

        string ans = "";
        for(int i = 0; i < mini; i++){
            bool check = true;
            for(int j = 0; j < strs.size() - 1; j++){
                if(strs[j][i] != strs[j + 1][i]){
                    check = false;
                    break;
                }
            }
            if(check)
                ans.push_back(strs[0][i]);
            else
                return ans;
        }
        return ans;
    }
};

// Time Complexity  : O(n)
// Space Complexity : O(1)