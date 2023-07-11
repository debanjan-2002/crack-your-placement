// Given two strings S and P. Find the smallest window in the string S consisting of all the characters(including duplicates) of the string P.  Return "-1" in case there is no such window present. In case there are multiple such windows of same length, return the one with the least starting index.
// Note : All characters are in Lowercase alphabets. 

// Example 1:
// Input:
// S = "timetopractice"
// P = "toc"
// Output: 
// toprac
// Explanation: "toprac" is the smallest
// substring in which "toc" can be found.

// Example 2:
// Input:
// S = "zoomlazapzo"
// P = "oza"
// Output: 
// apzo
// Explanation: "apzo" is the smallest 
// substring in which "oza" can be found.

#include<bits/stdc++.h>
using namespace std;

// Sliding window + Hashing

class Solution {
private:
    bool isValid(vector<int>& patternHash, vector<int>& textHash) {
        for(int i = 0; i < 26; i++) {
            if(textHash[i] < patternHash[i]) return false;
        }
        return true;
    }
public:
    string smallestWindow (string s, string p) {
        vector<int> patternHash(26);
        vector<int> textHash(26);
        
        // Build pattern hash
        for(char c : p) patternHash[c - 'a']++; 
        
        int low = 0;
        int high = 0;
        int len = 1e9;
        int start = -1;
        
        while(high < s.length()) {
            textHash[s[high] - 'a']++;
            high++;
            
            if(isValid(patternHash, textHash)) {
                while(isValid(patternHash, textHash)) {
                    if(len > high - low) {
                        len = high - low;
                        start = low;
                    }
                    textHash[s[low] - 'a']--;
                    low++;
                }
            }
        }
        return len == 1e9 ? "-1" : s.substr(start, len);
    }
};

// Time Complexity  : O(string length)
// Space Complexity : O(26) = O(1)