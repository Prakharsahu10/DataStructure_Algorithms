/*

Problem Statement: Given a doubly linked list, and a value ‘k’, insert a node having value ‘k’ at the end of the doubly linked list.

*/

// Function to insert a new node with value 'k' at the end of the doubly linked list
Node *insertAtTail(Node *head, int k)
{
    // Create a new node with data 'k'
    Node *newNode = new Node(k);

    // If the doubly linked list is empty, set 'head' to the new node
    if (head == nullptr)
    {
        return newNode;
    }

    // Traverse to the end of the doubly linked list
    Node *tail = head;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }

    // Connect the new node to the last node in the list
    tail->next = newNode;
    newNode->back = tail;

    return head;
}

int main()
{
    vector<int> arr = {12, 5, 8, 7, 4};
    Node *head = convertArr2DLL(arr);

    cout << "Doubly Linked List Initially: " << endl;
    print(head);

    cout << endl
         << "Doubly Linked List After Inserting at the tail with value 10: " << endl;
    // Insert a node with value 10 at the end
    head = insertAtTail(head, 10);
    print(head);

    return 0;
}

//Time Complexity: O(n), where n is the number of nodes in the doubly linked list. This is because we traverse the list to find the last node.
// Space Complexity: O(1), as we are only using a constant amount of extra space for the new node.