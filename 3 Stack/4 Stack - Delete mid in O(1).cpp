#include <bits/stdc++.h>  // Includes all standard libraries
using namespace std;

// Class representing a stack with additional functionalities
class Stack
{
    // Structure representing a node in the doubly linked list
    struct node
    {
        int data;  // Data stored in the node
        node* next;  // Pointer to the next node
        node* prev;  // Pointer to the previous node
    };

    node* top;  // Pointer to the top node of the stack
    node* mid;  // Pointer to the middle node of the stack
    int count;  // Count of the number of elements in the stack

public:
    // Constructor to initialize the stack
    Stack()
    {
        top = NULL;  // Initialize top as NULL
        mid = NULL;  // Initialize mid as NULL
        count = 0;  // Initialize count as 0
    }
    
    // Function to push an element onto the stack
    void push(int x)
    {
        cout << "Pushed element: " << x << endl;
        
        node* temp = new node();  // Create a new node
        temp->data = x;  // Set the data of the new node
        temp->prev = NULL;  // Set the previous pointer of the new node to NULL
        temp->next = top;  // Set the next pointer of the new node to the current top
        
        if (top)
            top->prev = temp;  // Update the previous pointer of the current top if it exists
        
        top = temp;  // Update the top pointer to the new node
        
        if (count == 0)
            mid = top;  // If the stack was empty, set mid to the new top
        else if (count % 2 == 0)
            mid = mid->prev;  // Update mid pointer if the count was even
        
        count++;  // Increment the count
    }
    
    // Function to pop an element from the stack
    void pop()
    {
        cout << "Popped Element: ";
        
        if (!top)
        {
            cout << "Empty Stack" << endl;  // Print message if stack is empty
            return;
        }
        
        cout << top->data << endl;  // Print the data of the top element
        
        node* temp = top;  // Store the top node in temp
        top = top->next;  // Update the top pointer to the next node
        
        if (top)
            top->prev = NULL;  // Update the previous pointer of the new top if it exists
        
        delete temp;  // Delete the old top node
        
        if (count % 2 != 0)
            mid = mid->next;  // Update mid pointer if the count was odd
        
        count--;  // Decrement the count
    }
    
    // Function to get the top element of the stack
    void Top()
    {
        cout << "Top: ";
        
        if (!top)
        {
            cout << "Empty Stack" << endl;  // Print message if stack is empty
            return;
        }
        
        cout << top->data << endl;  // Print the data of the top element
    }
    
    // Function to get the middle element of the stack
    void Mid()
    {
        cout << "Mid: ";
        
        if (!mid)
        {
            cout << "Empty Stack" << endl;  // Print message if stack is empty
            return;
        }
        
        cout << mid->data << endl;  // Print the data of the middle element
    }
    
    // Function to delete the middle element of the stack
    void deletemid()
    {
        cout << "Mid deleted: ";
        
        if (mid == NULL)
        {
            cout << "Empty Stack" << endl;  // Print message if stack is empty
            return;
        }
        
        cout << mid->data << endl;  // Print the data of the middle element
        
        node* prev = mid->prev;  // Store the previous node of mid
        node* next = mid->next;  // Store the next node of mid
        
        if (mid->prev)
            mid->prev->next = mid->next;  // Update the next pointer of the previous node if it exists
        
        if (mid->next)
            mid->next->prev = mid->prev;  // Update the previous pointer of the next node if it exists
        
        if (count % 2 == 0)
            mid = prev;  // Update mid pointer if the count was even
        else
            mid = next;  // Update mid pointer if the count was odd
        
        if (count == 1 || count == 2)
            top = mid;  // Update top pointer if there was only one or two elements
        
        count--;  // Decrement the count
    }
    
    // Function to print the stack
    void print()
    {
        cout << endl;
        cout << "Stack: " << endl;
        
        node* temp = top;  // Start from the top node
        node* last;
        
        // Print elements from top to bottom
        while (temp)
        {
            cout << temp->data << " ";
            last = temp;
            temp = temp->next;
        }
        
        cout << endl;
        
        // Print elements from bottom to top
        while (last)
        {
            cout << last->data << " ";
            last = last->prev;
        }
        
        cout << endl << endl;
    }
};

int main()
{
    Stack s;  // Create an instance of Stack
    
    s.push(9);  s.Mid();  s.Top();  s.print();  s.deletemid();  cout << endl;
    
    s.push(10);  s.push(12);  s.Mid();  s.Top();  s.print();  s.deletemid();  s.pop();  cout << endl;
    
    s.push(8);  s.push(7);  s.push(6);  s.push(5);  s.push(4);  s.push(3);  s.push(2);  s.push(1);  s.Mid();
    
    s.Top();  s.print();  s.deletemid();  s.print();  s.Mid();  s.pop();  s.print();  s.Mid();
    
    return 0;  // Return 0 to indicate successful execution
}
