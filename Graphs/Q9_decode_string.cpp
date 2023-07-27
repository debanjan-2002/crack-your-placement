// Given an encoded string, return its decoded string.

// The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

// You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

// The test cases are generated so that the length of the output will never exceed 105.

// Example 1:
// Input: s = "3[a]2[bc]"
// Output: "aaabcbc"

// Example 2:
// Input: s = "3[a2[c]]"
// Output: "accaccacc"

// Example 3:
// Input: s = "2[abc]3[cd]ef"
// Output: "abcabccdcdcdef"

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    string helper(string &s, int &index) {
        int count = 0;
        string ans = "";

        for(; index < s.length(); index++) {
            char c = s[index];
            if(c == '[') {
                string curr = helper(s, ++index);
                for(int i = 0; i < count; i++) ans += curr;
                count = 0;
            }
            else if(isdigit(c)) count = count * 10 + (c - '0');
            else if(c == ']') return ans;
            else ans += c;
        }
        return ans;
    }
public:
    string decodeString(string s) {
        int index = 0;
        return helper(s, index); 
    }
};

// Time Complexity  : O(n)
// Space Complexity : O(n)