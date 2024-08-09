#include <bits/stdc++.h>  // Includes all standard libraries
using namespace std;

// Class representing a stack with a method to get the minimum element
class Stack
{
    int maxsize;  // Maximum size of the stack
    int minl;  // Variable to keep track of the minimum element
    int top;  // Index of the top element in the stack
    vector<pair<int, int>> arr;  // Vector to store stack elements and their corresponding minimums
    
public:
    // Constructor to initialize the stack with a given maximum size
    Stack(int maxsize)
    {
        this->maxsize = maxsize;  // Set the maximum size
        top = -1;  // Initialize top index to -1 (empty stack)
        minl = std::numeric_limits<int>::max();  // Initialize minl to the maximum possible integer value
    }
    
    // Function to push an element onto the stack
    void push(int x)
    {
        cout << "Push : ";
        
        if (top + 1 == maxsize)  // Check if the stack is full
        {
            cout << "Stack overflow" << endl;
            return;
        }
        
        cout << x << endl;
        top++;  // Increment the top index
        minl = ((minl < x) ? minl : x);  // Update the minimum element
        arr.push_back({x, minl});  // Push the element and the current minimum onto the stack
    }
    
    // Function to pop an element from the stack
    void pop()
    {
        cout << "Pop : ";
        
        if (top == -1)  // Check if the stack is empty
        {
            cout << "Stack underflow" << endl;
            return;
        }
        
        cout << arr[top].first << endl;  // Print the popped element
        top--;  // Decrement the top index
        
        if (top != -1)
            minl = arr[top].second;  // Update the minimum element
        else
            minl = std::numeric_limits<int>::max();  // Reset minl if the stack is empty
    }
    
    // Function to get the minimum element in the stack
    void min()
    {
        cout << "Minimum element : ";
        
        if (top != -1)
            cout << arr[top].second << endl;  // Print the current minimum element
        else
            cout << "Stack Empty" << endl;  // Print a message if the stack is empty
    }
    
    // Function to check if the stack is empty
    bool isempty()
    {
        return (top == -1);  // Return true if the top index is -1 (stack is empty)
    }
};

int main()
{
    Stack *s = new Stack(3);  // Create an instance of Stack with a maximum size of 3

    s->push(4);  s->min();  // Push elements onto the stack and print the minimum element
    s->push(3);  s->min();
    s->push(2);  s->min();
    s->push(1);  s->min();  // This push will result in stack overflow

    while (!s->isempty())  // Pop elements until the stack is empty
    {
        s->pop();
        s->min();
    }
    
    s->pop();  // Attempt to pop from an empty stack
    
    return 0;  // Return 0 to indicate successful execution
}
