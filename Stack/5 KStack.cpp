#include <bits/stdc++.h>  // Includes all standard libraries
using namespace std;

// Class representing multiple stacks using a single array
class kstack
{
    int n;  // Total size of the array
    int k;  // Number of stacks
    int *arr;  // Array to store elements of all stacks
    int *top;  // Array to store indices of the top elements of all stacks
    int *next;  // Array to store next entry in all stacks and free list
    int nextavailable;  // Index of the next available free spot

public:
    // Constructor to initialize k stacks in an array of size n
    kstack(int n, int k)
    {
        this->k = k;  // Set the number of stacks
        this->n = n;  // Set the size of the array

        arr = new int[n];  // Allocate memory for the array
        top = new int[k];  // Allocate memory for the top array
        next = new int[n];  // Allocate memory for the next array

        nextavailable = 0;  // Initialize next available free spot

        for (int i = 0; i < n; i++)
            arr[i] = 0;  // Initialize the array with zeros

        for (int i = 0; i < k; i++)
            top[i] = -1;  // Initialize all stacks as empty

        for (int i = 0; i < n-1; i++)
            next[i] = i+1;  // Initialize all entries in the next array

        next[n-1] = -1;  // Last entry in the next array is -1
    }
    
    // Function to push an element onto stack k
    void push(int x, int k)
    {
        if (nextavailable == -1)  // Check for stack overflow
        {
            cout << "Stack " << k << " Overflow" << endl;
            return;
        }
        
        cout << x << " was Pushed in Stack " << k << endl;
        
        int i = nextavailable;  // Get index of the next available spot
        
        arr[i] = x;  // Store the element at index i
        nextavailable = next[i];  // Update the next available spot
        next[i] = top[k];  // Update next to point to the old top
        top[k] = i;  // Update top to the new element's index
    }
    
    // Function to pop an element from stack k
    void pop(int k)
    {
        if (top[k] == -1)  // Check for stack underflow
        {
            cout << "Stack " << k << " Underflow" << endl;
            return;
        }
        
        cout << arr[top[k]] << " was Popped from Stack " << k << endl;
        
        int t = top[k];  // Get the index of the top element
        top[k] = next[t];  // Update top to the next element
        next[t] = nextavailable;  // Add the popped index to the free list
        nextavailable = t;  // Update the next available spot
    }
    
    // Function to print all elements in the array
    void print()
    {
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    
    // Function to print elements of stack k
    void stack(int k)
    {
        cout << "Stack " << k << ": ";
        
        int i = top[k];  // Start from the top of the stack
        
        if (i == -1)  // Check if the stack is empty
        {
            cout << "Empty Stack " << k << endl;
            return;
        }
        
        while (i != -1)  // Iterate through the stack
        {
            cout << arr[i] << " ";  // Print the element
            i = next[i];  // Move to the next element
        }
        
        cout << endl;
    }
};

int main()
{
    kstack stk(6, 3);  // Create an instance of kstack with size 6 and 3 stacks
    
    stk.push(55, 0);  stk.print();
    stk.pop(0);  stk.print();
    stk.pop(0);  stk.print();
    stk.push(51, 0);  stk.print();
    stk.push(52, 0);  stk.print();
    stk.push(56, 1);  stk.print();
    stk.pop(0);  stk.print();
    stk.push(57, 2);  stk.print();
    stk.push(58, 2);  stk.print();
    stk.push(66, 0);  stk.print();
    stk.push(90, 1);  stk.print();
    stk.push(55, 0);  stk.print();
    stk.push(45, 1);  stk.print();
    stk.push(35, 1);  stk.print();
    
    stk.stack(0);  // Print elements of stack 0
    stk.stack(1);  // Print elements of stack 1
    stk.stack(2);  // Print elements of stack 2
    
    return 0;  // Return 0 to indicate successful execution
}
