#include <bits/stdc++.h>  // Includes all standard libraries
using namespace std;

// Class representing two stacks using a single array
class two_stack
{
    int *arr;  // Array to store elements of both stacks
    int top1;  // Top index for the first stack
    int top2;  // Top index for the second stack
    int size;  // Size of the array

public:
    // Constructor to initialize the two stacks
    two_stack(int n)
    {
        size = n;  // Set the size of the array
        arr = new int[size];  // Allocate memory for the array
        top1 = -1;  // Initialize top index of the first stack
        top2 = size;  // Initialize top index of the second stack
    }

    // Function to push an element into the first stack
    void push1(int x)
    {
        // Check for stack overflow
        if (top1 + 1 == top2)
        {
            cout << "Stack 1 Overflow" << endl;
            return;
        }

        arr[++top1] = x;  // Increment top1 and push the element
        cout << x << " was pushed in Stack 1" << endl;
    }

    // Function to push an element into the second stack
    void push2(int x)
    {
        // Check for stack overflow
        if (top2 - 1 == top1)
        {
            cout << "Stack 2 Overflow" << endl;
            return;
        }

        arr[--top2] = x;  // Decrement top2 and push the element
        cout << x << " was pushed in Stack 2" << endl;
    }

    // Function to pop an element from the first stack
    int pop1()
    {
        // Check if the first stack is empty
        if (top1 == -1)
        {
            cout << "Stack 1 empty: ";
            return -1;  // Return -1 if the stack is empty
        }

        int x = arr[top1--];  // Pop the element from the first stack
        cout << "Top 1: ";
        return x;
    }

    // Function to pop an element from the second stack
    int pop2()
    {
        // Check if the second stack is empty
        if (top2 == size)
        {
            cout << "Stack 2 empty: ";
            return -1;  // Return -1 if the stack is empty
        }

        int x = arr[top2++];  // Pop the element from the second stack
        cout << "Top 2: ";
        return x;
    }
};

int main()
{
    two_stack tstk(5);  // Create an instance of two_stack with an array size of 5

    tstk.push1(1);  // Push 1 into the first stack
    tstk.push1(2);  // Push 2 into the first stack
    tstk.push2(5);  // Push 5 into the second stack
    tstk.push2(4);  // Push 4 into the second stack
    tstk.push2(3);  // Push 3 into the second stack
    tstk.push1(6);  // Attempt to push 6 into the first stack (will cause overflow)
    tstk.push2(7);  // Attempt to push 7 into the second stack (will cause overflow)

    cout << tstk.pop1() << endl;  // Pop and print the top element of the first stack
    cout << tstk.pop1() << endl;  // Pop and print the next top element of the first stack
    cout << tstk.pop1() << endl;  // Pop and print the next top element of the first stack
    cout << tstk.pop2() << endl;  // Pop and print the top element of the second stack
    cout << tstk.pop2() << endl;  // Pop and print the next top element of the second stack
    cout << tstk.pop2() << endl;  // Pop and print the next top element of the second stack
    cout << tstk.pop2() << endl;  // Attempt to pop from an empty second stack

    return 0;  // Return 0 to indicate successful execution
}
