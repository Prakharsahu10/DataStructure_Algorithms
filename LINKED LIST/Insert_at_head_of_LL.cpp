/*

Problem Statement:  Given a linked list and an integer value val, insert a new node with that value at the beginning (before the head) of the list and return the updated linked list.

*/

class Node
{
public:
    int data;
    Node *next;

    // Constructor with both data and next node
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    // Constructor with only data (assuming next is initially null)
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

// Function to print the linked list
void printLL(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

// Function to insert a new node at the head of the linked list
Node *insertHead(Node *head, int val)
{
    Node *temp = new Node(val, head);
    return temp;
}

int main()
{
    // Sample array and value for insertion
    vector<int> arr = {12, 8, 5, 7};
    int val = 100;

    // Creating a linked list with initial elements from the array
    Node *head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);

    // Inserting a new node at the head of the linked list
    head = insertHead(head, val);

    // Printing the linked list
    printLL(head);

    return 0;
}

// Time Complexity: O(1) for insertion at the head, O(n) for printing the list.
// Space Complexity: O(1) for insertion, O(n) for the linked list storage.