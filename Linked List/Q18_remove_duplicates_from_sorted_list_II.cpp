// Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

// Example 1:
// Input: head = [1,2,3,3,4,4,5]
// Output: [1,2,5]

// Example 2:
// Input: head = [1,1,1,2,3]
// Output: [2,3]

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
        ListNode* end = dummy;
        ListNode* runner = head;

        while(runner) {
            bool isDuplicate = false;
            while(runner && runner->next && runner->val == runner->next->val) {
                runner = runner->next;
                isDuplicate = true;
            } 
            if(!isDuplicate) {
                end->next = runner;
                end = end->next;
            }
            runner = runner->next;
        }
        end->next = NULL;
        return dummy->next;
    }
};

// Time Complexity  : O(n)
// Space Complexity : O(1)