// A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

// Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

// For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

// Return the head of the copied linked list.

// The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

// val: an integer representing Node.val
// random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
// Your code will only be given the head of the original linked list.

// Example 1:
// Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
// Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]

// Example 2:
// Input: head = [[1,1],[2,1]]
// Output: [[1,1],[2,1]]

// Example 3:
// Input: head = [[3,null],[3,0],[3,null]]
// Output: [[3,null],[3,0],[3,null]]

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// Special question
// Need to know the algorithm to solve this beforehand
 
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        
        // Step 1 : Inserting the same node after each existing node in the list
        // Ex - 7->13->11->10->1 will become 7->7->13->13->11->11->10->10->1->1
        Node* runner = head;
        while(runner) {
            Node* nextNode = runner->next;
            runner->next = new Node(runner->val);
            runner->next->next = nextNode;
            runner = nextNode;
        }

        // Step 2 : Setting the random pointer of the newly added nodes
        runner = head;
        while(runner) {
            runner->next->random = runner->random ? runner->random->next : NULL;
            runner = runner->next->next;
        }

        // Step 3 : Segregate the old and new list
        Node* oldList = head;
        Node* newList = head->next;
        Node* newHead = head->next;

        while(newList && newList->next) {
            oldList->next = oldList->next->next;
            oldList = oldList->next;

            newList->next = newList->next->next;
            newList = newList->next;
        }
        oldList->next = oldList->next->next;

        return newHead;
    }
};