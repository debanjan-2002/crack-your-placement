// You are given a doubly linked list, which contains nodes that have a next pointer, a previous pointer, and an additional child pointer. This child pointer may or may not point to a separate doubly linked list, also containing these special nodes. These child lists may have one or more children of their own, and so on, to produce a multilevel data structure as shown in the example below.

// Given the head of the first level of the list, flatten the list so that all the nodes appear in a single-level, doubly linked list. Let curr be a node with a child list. The nodes in the child list should appear after curr and before curr.next in the flattened list.

// Return the head of the flattened list. The nodes in the list must have all of their child pointers set to null.

// Example 1:
// Input: head = [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
// Output: [1,2,3,7,8,11,12,9,10,4,5,6]

// Example 2:
// Input: head = [1,2,null,3]
// Output: [1,3,2]

// Example 3:
// Input: head = []
// Output: []

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

// Very Important question
// Recursive Implementation
// Nice problem to practice recursion

class Solution {
private:
    Node* flattenList(Node* head) {
        if(!head) return NULL;

        Node* runner = head;
        while(runner) {
            // If the current node doesn't have any child branch
            if(!runner->child) runner = runner->next;
            else {
                Node* nextNode = runner->next;

                // Attaching the head returned after flattening the child
                runner->next = flattenList(runner->child);
                runner->next->prev = runner;
                runner->child = NULL;

                // If there are no next nodes, then we are done
                if(!nextNode) break;

                // If there is a next node available
                // Then we have to attach the last node of the child branch to the next node
                Node* childEnd = runner;
                while(childEnd->next) childEnd = childEnd->next;
                childEnd->next = nextNode;
                nextNode->prev = childEnd;

                // Move the pointer to the next node
                runner = nextNode;
            }
        }
        return head;
    }
public:
    Node* flatten(Node* head) {
        return flattenList(head);
    }
};

// Time Complexity  : O(Total number of nodes)
// Space Complexity : O(Height of the multilevel structure)