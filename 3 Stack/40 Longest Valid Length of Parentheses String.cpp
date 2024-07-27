#include <bits/stdc++.h>  // Includes all standard libraries
using namespace std;

// Function to find the length of the longest valid (well-formed) parentheses substring
int Valid_Length(string &s)
{
    stack<int> st;  // Stack to store indices of the characters in the string
    st.push(-1);  // Initialize the stack with -1 to handle the base case
    int mx = 0;  // Variable to keep track of the maximum length of valid parentheses
    
    // Iterate through each character in the string
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')  // If the character is '(', push its index onto the stack
        {
            st.push(i);
        }
        else  // If the character is ')'
        {
            st.pop();  // Pop the top index from the stack
            if (!st.empty())  // If the stack is not empty
            {
                // Calculate the length of the current valid substring
                mx = max(mx, i - st.top());
            }
            else  // If the stack is empty, push the current index onto the stack
            {
                st.push(i);
            }
        }
    }
    return mx;  // Return the maximum length of valid parentheses
}

int main()
{
    string s = "((())()";  // Input string containing parentheses

    cout << Valid_Length(s) << endl;  // Output the length of the longest valid parentheses substring

    return 0;  // Return 0 to indicate successful execution
}
