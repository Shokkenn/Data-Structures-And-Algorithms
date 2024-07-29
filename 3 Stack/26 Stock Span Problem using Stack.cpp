#include <bits/stdc++.h> // Includes all standard libraries
using namespace std;     // Using the standard namespace

// Function to calculate the stock span
void Stock_Span(vector<int> &a, int n) {
    stack<int> s; // Initialize an empty stack to store indices of stock prices

    // Iterate through each element in the stock prices array
    for (int i = 0; i < n; i++) {
        // Pop elements from the stack while the stack is not empty and the current
        // element is greater than or equal to the element at the index stored at the top of the stack
        while (!s.empty() && a[s.top()] <= a[i])
            s.pop();

        // If the stack is empty, it means all previous elements are smaller than the current element
        // Therefore, the span is the current index + 1
        // If the stack is not empty, the span is the difference between the current index and the index of the top element in the stack
        (s.empty()) ? cout << (i + 1) : cout << (i - s.top());

        cout << " "; // Print a space to separate the spans

        s.push(i); // Push the current index onto the stack
    }
}

int main() {
    vector<int> a = {100, 80, 60, 70, 60, 75, 85}; // Initialize the stock prices
    int n = a.size(); // Get the number of stock prices

    Stock_Span(a, n); // Call the Stock_Span function

    return 0; // Return 0 to indicate successful execution
}
