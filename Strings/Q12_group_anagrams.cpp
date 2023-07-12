// Given an array of strings strs, group the anagrams together. You can return the answer in any order.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

// Example 1:
// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

// Example 2:
// Input: strs = [""]
// Output: [[""]]

// Example 3:
// Input: strs = ["a"]
// Output: [["a"]]

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> ans;
        
        for(int i = 0; i < n; i++){
            string curr = strs[i];
            string temp(26,'0');
            
            for(char c : curr){
                temp[c - 'a'] = temp[c - 'a'] + 1;
            }
            mp[temp].push_back(curr);
        }
        
        for(auto it : mp){
            vector<string> temp;
            for(auto st : it.second) temp.push_back(st);
            ans.push_back(temp);
        }
        return ans;
    }
};

// Time Complexity  : O(n)
// Space Complexity : O(n)