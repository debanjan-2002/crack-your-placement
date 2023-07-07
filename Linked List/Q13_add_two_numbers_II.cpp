// You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Example 1:
// Input: l1 = [7,2,4,3], l2 = [5,6,4]
// Output: [7,8,0,7]

// Example 2:
// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [8,0,7]

// Example 3:
// Input: l1 = [0], l2 = [0]
// Output: [0]

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Stack Solution

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1;
        stack<int> s2;

        ListNode* runner1 = l1;
        ListNode* runner2 = l2;

        while(runner1 || runner2) {
            if(runner1) {
                s1.push(runner1->val);
                runner1 = runner1->next;
            }
            if(runner2) {
                s2.push(runner2->val);
                runner2 = runner2->next;
            }
        }

        int sum = 0;
        ListNode* dummy = new ListNode();

        while(!s1.empty() || !s2.empty()) {
            if(!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }

            if(!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }
            dummy->val = sum % 10;
            ListNode* prev = new ListNode(sum / 10);
            prev->next = dummy;
            dummy = prev;
            sum = sum / 10;
        }
        if(dummy->val == 0) return dummy->next;
        return dummy;
    }
};

// Time Complexity  : O(n + m)
// Space Complexity : O(n + m)