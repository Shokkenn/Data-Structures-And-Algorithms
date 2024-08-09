#include <bits/stdc++.h>  // Includes all standard libraries
using namespace std;      

// Function to calculate the stock span
void Stock_Span(vector<int> &a, int n) {
    vector<int> b(n + 1); // Create a vector b with size n+1

    b[0] = std::numeric_limits<int>::max(); // Set the first element of b to the maximum integer value

    for (int i = 1; i <= n; i++)
        b[i] = a[i - 1]; // Copy elements from a to b, with a shift in indexing

    vector<int> p(n + 1); // Create a vector p with size n+1

    for (int i = 0; i <= n; i++)
        p[i] = i - 1; // Initialize p with indices offset by -1

    for (int i = 1; i <= n; i++) {
        int x = i; // Set x to the current index

        // Find the previous index where the value in a is greater than the current value
        while (a[p[x]] <= a[i])
            x = p[x]; // Move to the previous index
        p[i] = p[x]; // Update the p value to point to the index found
    }

    for (int i = 1; i <= n; i++)
        cout << i - p[i] << " "; // Print the stock span for each day
    cout << endl; // Print a newline at the end
}

int main() {
    vector<int> a = {100, 80, 60, 70, 60, 75, 85}; // Initialize the stock prices
    int n = a.size(); // Get the number of stock prices

    Stock_Span(a, n); // Call the Stock_Span function

    return 0; // Return 0 to indicate successful execution
}
