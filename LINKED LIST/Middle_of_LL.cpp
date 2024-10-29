/* Find the middle of Linked List */
/*

roblem Statement: Given the head of a linked list of integers, determine the middle node of the linked list. However, if the linked list has an even number of nodes, return the second middle node.

Examples
Example 1:
Input: LL: 1  2  3  4  5

Output: 3
Explanation: Node with value 3 is the middle node of this linked list.
Example 2:
Input: LL: 1  2  3  4  5  6


Output: 4
Explanation:  In this example, the linked list has an even number of nodes hence we return the second middle node which is 4

*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Node class represents a node in a linked list
class Node
{
public:
    // Data stored in the node
    int data;

    // Pointer to the next node in the list
    Node *next;

    // Constructor with both data
    // and next node as parameters
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    // Constructor with only data as
    // a parameter, sets next to nullptr
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

// Function to find the middle
// node of a linked list
Node *findMiddle(Node *head)
{

    // Initialize the slow pointer to the head.
    Node *slow = head;

    // Initialize the fast pointer to the head.
    Node *fast = head;

    // Traverse the linked list using the
    // Tortoise and Hare algorithm.
    while (fast != NULL && fast->next != NULL)
    {
        // Move slow one step.
        slow = slow->next;
        // Move fast two steps.
        fast = fast->next->next;
    }

    // Return the slow pointer,
    // which is now at the middle node.
    return slow;
}

int main()
{
    // Creating a sample linked list:
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Find the middle node
    Node *middleNode = findMiddle(head);

    // Display the value of the middle node
    cout << "The middle node value is: " << middleNode->data << endl;

    return 0;
}
