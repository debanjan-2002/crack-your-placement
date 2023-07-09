// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.

// Example 1:
// Input: s = "()"
// Output: true

// Example 2:
// Input: s = "()[]{}"
// Output: true

// Example 3:
// Input: s = "(]"
// Output: false

#include<bits/stdc++.h>
using namespace std;

// Stack Solution

class Solution {
private:
    bool isPair(char c1, char c2) {
        bool op1 = c1 == '(' && c2 == ')';
        bool op2 = c1 == '{' && c2 == '}';
        bool op3 = c1 == '[' && c2 == ']';
        return (op1 || op2 || op3);
    }
public:
    bool isValid(string s) {
        stack<char> st;

        for(char c : s) {
            if(c == '(' || c == '{' || c == '[') st.push(c);
            else if(st.empty() || !isPair(st.top(), c)) return false;
            else st.pop();
        }
        return st.empty();
    }
};

// Time Complexity  : O(n)
// Space Complexity : O(n)