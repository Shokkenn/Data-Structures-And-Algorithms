#include <bits/stdc++.h>  // Includes all standard libraries
using namespace std;

// Class representing a stack using a linked list
class Stack
{
    // Structure representing a node in the linked list
    struct node
    {
        int data;  // Data stored in the node
        node* next;  // Pointer to the next node
    };
    
    node* head;  // Pointer to the head (top) of the stack
    node* tail;  // Pointer to the tail (end) of the stack
    
public:
    // Constructor to initialize an empty stack
    Stack()
    {
        head = NULL;  // Initialize head as NULL
        tail = NULL;  // Initialize tail as NULL
    }
    
    // Function to push an element onto the stack
    void push(int x)
    {
        node* temp = new node();  // Create a new node
        temp->data = x;  // Set the data of the new node
        temp->next = head;  // Set the next pointer of the new node to the current head
        head = temp;  // Update the head pointer to the new node
        
        if (!tail)
            tail = head;  // If the stack was empty, set tail to the new head
    }
    
    // Function to pop an element from the stack
    void pop()
    {
        if (!head) return;  // Check if the stack is empty
        
        node* temp = head;  // Store the head node in temp
        head = head->next;  // Update the head pointer to the next node
        
        delete temp;  // Delete the old head node
        
        if (!head)
            tail = NULL;  // If the stack is now empty, set tail to NULL
    }
    
    // Function to merge another stack into the current stack
    void merge(Stack s)
    {
        if (tail)
            tail->next = s.head;  // If current stack is not empty, link the tail to the head of the other stack
        else
            head = s.head;  // If current stack is empty, set head to the head of the other stack
    }
    
    // Function to print the stack
    void print()
    {
        node* temp = head;  // Start from the head node
        
        while (temp)
        {
            cout << temp->data << " ";  // Print the data of the current node
            temp = temp->next;  // Move to the next node
        }
        
        cout << endl;
    }
};

int main()
{
    Stack s1, s2;  // Create two instances of Stack
    
    s1.push(1);  // Push elements onto stack s1
    s1.push(2);
    s1.push(3);
    s2.push(4);  // Push elements onto stack s2
    s2.push(5);
    s2.push(6);
    
    s1.print();  // Print stack s1
    s2.print();  // Print stack s2
    
    s1.merge(s2);  // Merge stack s2 into stack s1
    
    s1.print();  // Print the merged stack s1
    
    return 0;  // Return 0 to indicate successful execution
}
