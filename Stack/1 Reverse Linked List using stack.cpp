#include <bits/stdc++.h>
using namespace std;

// Definition of the node structure
struct node {
    int data;       // Data stored in the node
    node* next;     // Pointer to the next node in the list
};

// Function to insert a node at the end of the list
node* insert(node** head, int x) {
    node* temp = new node(); // Create a new node
    temp->data = x;          // Assign data to the new node
    temp->next = NULL;       // Set the next pointer of the new node to NULL
    
    node** cur = head;       // Create a pointer to traverse the list
    
    // Traverse to the end of the list
    while (*cur) {
        cur = &((*cur)->next);
    }
    
    *cur = temp;             // Insert the new node at the end of the list
}

// Function to print the linked list
void print(node* head) {
    while (head) {           // Traverse the list
        cout << head->data << " ";  // Print the data of the current node
        head = head->next;   // Move to the next node
    }
    cout << endl;            // Print a new line at the end
}

// Function to reverse the linked list using a stack
void reverse(node** head) {
    stack<node*> s;          // Create a stack to hold the nodes
    
    node* temp = *head;      // Temporary pointer to traverse the list
    
    // Push all nodes onto the stack
    while (temp) {
        s.push(temp);
        temp = temp->next;
    }
    
    *head = s.top();         // Set the head to the last node (top of the stack)
    s.pop();                 // Pop the last node
    
    temp = *head;            // Set temp to the new head
    
    // Pop all nodes from the stack and rearrange pointers
    while (!s.empty()) {
        temp->next = s.top(); // Set the next pointer of the current node
        s.pop();              // Pop the top node
        temp = temp->next;    // Move to the next node
    }
    
    temp->next = NULL;       // Set the next pointer of the last node to NULL
}

int main() {
    node* head = NULL;       // Initialize the head of the list to NULL

    // Insert nodes with data 1, 2, 3, 4, 5
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);
    
    print(head);             // Print the list: 1 2 3 4 5
    
    reverse(&head);          // Reverse the list
    
    print(head);             // Print the reversed list: 5 4 3 2 1
    
    return 0; 
}
