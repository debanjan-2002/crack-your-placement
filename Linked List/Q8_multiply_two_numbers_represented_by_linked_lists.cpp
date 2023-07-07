// Given two numbers represented by linked lists, write a function that returns the multiplication of these two linked lists.

// Examples: 

// Input : 9->4->6
//         8->4
// Output : 79464

// Input : 3->2->1
//         1->2
// Output : 3852

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
    int multiplyLinkedListNodes(ListNode* list1, ListNode* list2) {
        int num1 = 0;
        int num2 = 0;

        ListNode* runner1 = list1;
        ListNode* runner2 = list2;

        while(runner1 || runner2) {
            if(runner1) {
                num1 = num1 * 10 + runner1->val;
                runner1 = runner1->next;
            }
            if(runner2) {
                num2 = num2 * 10 + runner2->val;
                runner2 = runner2->next;
            }
        }
        return (num1 * num2);
    }
};

// Time Complexity  : O(max(n, m))
// Space Complexity : O(1)