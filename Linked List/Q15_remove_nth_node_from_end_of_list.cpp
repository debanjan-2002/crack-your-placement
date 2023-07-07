// Given the head of a linked list, remove the nth node from the end of the list and return its head.

// Example 1:
// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]

// Example 2:
// Input: head = [1], n = 1
// Output: []

// Example 3:
// Input: head = [1,2], n = 1
// Output: [1]

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// One Pass solution

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* runner1 = head;
        ListNode* runner2 = head;

        for(int i = 0; i < n; i++) {
            runner2 = runner2->next;
        }
        if(!runner2) {
            ListNode* temp = head->next;
            delete head;
            return temp;
        }
        while(runner2->next) {
            runner1 = runner1->next;
            runner2 = runner2->next;
        }

        ListNode* temp = runner1->next;
        runner1->next = runner1->next->next;
        delete temp;
        return head;
    }
};

// Time Complexity  : O(n)
// Space Complexity : O(1)