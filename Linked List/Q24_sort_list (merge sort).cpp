// Given the head of a linked list, return the list after sorting it in ascending order.

// Example 1:
// Input: head = [4,2,1,3]
// Output: [1,2,3,4]

// Example 2:
// Input: head = [-1,5,3,4,0]
// Output: [-1,0,3,4,5]

// Example 3:
// Input: head = []
// Output: []

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
private:
    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* dummy = new ListNode();
        ListNode* end = dummy;
        ListNode* runner1 = head1;
        ListNode* runner2 = head2;

        while(runner1 && runner2) {
            if(runner1->val <= runner2->val) {
                end->next = runner1;
                end = end->next;
                runner1 = runner1->next;
            }
            else {
                end->next = runner2;
                end = end->next;
                runner2 = runner2->next;
            }
        }
        if(runner1) end->next = runner1;
        if(runner2) end->next = runner2;

        return dummy->next;
    }

    ListNode* mergeSort(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHead = slow->next;
        slow->next = NULL;

        ListNode* firstHalf = mergeSort(head);
        ListNode* secondHalf = mergeSort(secondHead);

        return merge(firstHalf, secondHalf);
    }
public:
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};

// Time Complexity  : O(nlogn)
// Space Complexity : O(n)