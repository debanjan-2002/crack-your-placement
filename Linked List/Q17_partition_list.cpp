// Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

// You should preserve the original relative order of the nodes in each of the two partitions.

// Example 1:
// Input: head = [1,4,3,2,5,2], x = 3
// Output: [1,2,2,4,3,5]

// Example 2:
// Input: head = [2,1], x = 2
// Output: [1,2]

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Dummy Node concept
// Very Important question

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* lessStart = new ListNode();
        ListNode* lessEnd = lessStart;

        ListNode* greaterStart = new ListNode();
        ListNode* greaterEnd = greaterStart;

        ListNode* runner = head;

        while(runner) {
            if(runner->val < x) {
                lessEnd->next = runner;
                lessEnd = lessEnd->next;
            }
            else {
                greaterEnd->next = runner;
                greaterEnd = greaterEnd->next;
            }
            runner = runner->next;
        }

        lessEnd->next = greaterStart->next;
        greaterEnd->next = NULL;

        return lessStart->next;
    }
};

// Time Complexity  : O(n)
// Space Complexity : O(1)