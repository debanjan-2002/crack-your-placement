// Given a Linked List of integers, write a function to modify the linked list such that all even numbers appear before all the odd numbers in the modified linked list. Also, keep the order of even and odd numbers the same.

// Examples: 

// Input: 17->15->8->12->10->5->4->1->7->6->NULL
// Output: 8->12->10->4->6->17->15->5->1->7->NULL

// Input: 8->12->10->5->4->1->6->NULL
// Output: 8->12->10->4->6->5->1->NULL

// If all numbers are even then do not change the list

// Input: 8->12->10->NULL
// Output: 8->12->10->NULL

// If all numbers are odd then do not change the list

// Input: 1->3->5->7->NULL
// Output: 1->3->5->7->NULL

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
// Important Question

class Solution {
public:
    ListNode* segregateOddAndEvenNodes(ListNode* head) {
        ListNode* oddStart = new ListNode();
        ListNode* evenStart = new ListNode();
        ListNode* oddEnd = oddStart;
        ListNode* evenEnd = evenStart;
        ListNode* runner = head;

        while(runner) {
            if(runner->val % 2 == 0) {
                evenEnd->next = runner;
                evenEnd = evenEnd->next;
            }
            else {
                oddEnd->next = runner;
                oddEnd = oddEnd->next;
            }
            runner = runner->next;
        }

        evenEnd->next = oddStart->next;
        oddEnd->next = NULL;

        return evenStart->next;
    }
};

int main() {
    // Example
    ListNode* head = new ListNode(11);
    head->next = new ListNode(10);
    head->next->next = new ListNode(8);
    head->next->next->next = new ListNode(6);
    head->next->next->next->next = new ListNode(9);
    head->next->next->next->next->next = new ListNode(11);
    head->next->next->next->next->next->next = new ListNode(12);
    head->next->next->next->next->next->next->next = new ListNode(1);
    head->next->next->next->next->next->next->next->next = new ListNode(2);

    Solution s;
    ListNode* newHead = s.segregateOddAndEvenNodes(head);

    ListNode* runner = newHead;
    while(runner) {
        cout << runner->val << " ";
        runner = runner->next;
    }
}

// Time Complexity  : O(n)
// Space Complexity : O(1)