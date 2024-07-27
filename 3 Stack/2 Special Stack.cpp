#include <bits/stdc++.h>  // Includes all standard libraries
using namespace std;

stack<int> m;  // Stack to keep track of minimum values

// Function to push an element onto the stack
void push(int x, stack<int> &s)
{
    s.push(x);  // Push the element onto the stack s

    // If the minimum stack is empty or the new element is smaller or equal to the top of the minimum stack
    if (m.empty() || x <= m.top())
        m.push(x);  // Push the element onto the minimum stack
}

// Function to pop an element from the stack
void pop(stack<int> &s)
{
    // If the top of stack s is the same as the top of the minimum stack
    if (s.top() == m.top())
        m.pop();  // Pop the top of the minimum stack
    
    s.pop();  // Pop the top of the stack s
}

// Function to get the minimum element from the stack
void getmin()
{
    cout << m.top() << endl;  // Print the top of the minimum stack
}

int main()
{
    stack<int> s;  // Create a stack s

    push(5, s);  // Push 5 onto the stack s
    getmin();  // Print the minimum element (5)

    push(3, s);  // Push 3 onto the stack s
    getmin();  // Print the minimum element (3)

    push(1, s);  // Push 1 onto the stack s
    getmin();  // Print the minimum element (1)

    pop(s);  // Pop the top element (1) from the stack s
    getmin();  // Print the minimum element (3)

    push(2, s);  // Push 2 onto the stack s
    getmin();  // Print the minimum element (2)

    return 0;  // Return 0 to indicate successful execution
}
