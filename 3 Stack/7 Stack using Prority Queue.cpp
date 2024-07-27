#include <bits/stdc++.h>  // Includes all standard libraries
using namespace std;

// Class representing a stack using a priority queue
class Stack
{
    priority_queue<pair<int, int>> pq;  // Priority queue to store elements with their order of insertion
    int cnt;  // Counter to keep track of the order of insertion
    
public:
    // Constructor to initialize an empty stack
    Stack()
    {
        cnt = 0;  // Initialize counter to 0
    }
    
    // Function to push an element onto the stack
    void push(int x)
    {
        cnt++;  // Increment the counter
        pq.push({cnt, x});  // Push the element along with its order of insertion into the priority queue
        cout << x << " was pushed" << endl;  // Print the pushed element
    }
    
    // Function to pop an element from the stack
    void pop()
    {
        if (pq.empty())  // Check if the stack is empty
            return;
        
        cnt--;  // Decrement the counter
        cout << pq.top().second << " was removed" << endl;  // Print the removed element
        pq.pop();  // Remove the top element from the priority queue
    }
    
    // Function to check if the stack is empty
    bool isempty()
    {
        return pq.empty();  // Return true if the priority queue is empty, otherwise false
    }
};

int main()
{
    Stack *s = new Stack();  // Create an instance of Stack

    s->push(1);  // Push elements onto the stack
    s->push(2);
    s->push(3);
    s->push(4);

    while (!s->isempty())  // Pop elements until the stack is empty
    {
        s->pop();
    }
    
    return 0;  // Return 0 to indicate successful execution
}
