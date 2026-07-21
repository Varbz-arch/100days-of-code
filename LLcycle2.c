// Given the head of a linked list, return the node where the cycle begins. 
// If there is no cycle, return null. 
// There is a cycle in a linked list if there is some node in the list 
// that can be reached again by continuously following the next pointer. 
// Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). 
// It is -1 if there is no cycle. Note that pos is not passed as a parameter. Do not modify the linked list. 
// Example 1: Input: head = [3,2,0,-4], pos = 1 
// Output: tail connects to node index 1 
// Explanation: There is a cycle in the linked list, where tail connects to the second node..

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode *node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Function to detect the starting node of the cycle
struct ListNode* detectCycle(struct ListNode *head) {
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    // Step 1: Detect if a cycle exists
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Step 2: Find the starting node
            struct ListNode *ptr = head;

            while (ptr != slow) {
                ptr = ptr->next;
                slow = slow->next;
            }

            return ptr;
        }
    }

    // No cycle
    return NULL;
}

int main() {
    // Create nodes
    struct ListNode *head = createNode(3);
    struct ListNode *second = createNode(2);
    struct ListNode *third = createNode(0);
    struct ListNode *fourth = createNode(-4);

    // Connect nodes
    head->next = second;
    second->next = third;
    third->next = fourth;

    // Create cycle (tail points to second node)
    fourth->next = second;

    // Detect cycle
    struct ListNode *start = detectCycle(head);

    if (start != NULL)
        printf("Cycle starts at node with value: %d\n", start->val);
    else
        printf("No Cycle\n");

    return 0;
}


// If the answer is a number → int
// If the answer is true/false → bool
// If the answer is a node/location in linked list → struct Node*