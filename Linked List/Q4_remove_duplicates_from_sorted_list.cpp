// Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

// Example 1:
// Input: head = [1,1,2]
// Output: [1,2]

// Example 2:
// Input: head = [1,1,2,3,3]
// Output: [1,2,3]

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* end = head;
        ListNode* runner = head;

        while(runner) {
            while(runner && runner->next && runner->val == runner->next->val) {
                runner = runner->next;
            } 
            end->next = runner->next;
            end = end->next;
            runner = runner->next;
        }
        return dummy->next;
    }
};

// Time Complexity  : O(n)
// Space Complexity : O(1)