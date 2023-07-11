// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// Example 1:
// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]

// Example 2:
// Input: n = 1
// Output: ["()"]

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void generate(int open, int close, string &curr, vector<string>& ans) {
        if(open == 0 && close == 0) {
            ans.push_back(curr);
            return;
        }
        if(open <= close && open > 0) {
            curr.push_back('(');
            generate(open - 1, close, curr, ans);
            curr.pop_back();
        }
        if(close > 0) {
            curr.push_back(')');
            generate(open, close - 1, curr, ans);
            curr.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string curr = "";
        vector<string> ans;
        generate(n, n, curr, ans);
        return ans;
    }
};

// Time Complexity  : O(2 ^ n)
// Space Complexity : O(n)