// Given a string s, return true if the s can be palindrome after deleting at most one character from it.

// Example 1:
// Input: s = "aba"
// Output: true

// Example 2:
// Input: s = "abca"
// Output: true
// Explanation: You could delete the character 'c'.

// Example 3:
// Input: s = "abc"
// Output: false

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isPalindrome(string &s, int l, int h) {
        while(l < h) {
            if(s[l++] != s[h--]) return false;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int n = s.length();
        int low = 0;
        int high = n - 1;
        
        while(low < high) {
            if(s[low] == s[high]) {
                low++;
                high--;
            }
            else{
                bool ans1 = isPalindrome(s, low, high - 1);
                bool ans2 = isPalindrome(s, low + 1,high);
                return (ans1 || ans2);
            }
        }
        return true;
    }
};

// Time Complexity  : O(n)
// Space Complexity : O(1)