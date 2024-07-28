#include <bits/stdc++.h>
using namespace std;

// Function to calculate the prefix sum up to the given index using BIT
int Pref_Sum(int *BIT, int ind) {
    int sum = 0, i = ind + 1;  // BIT indices are 1-based, so increment index by 1
    
    // Traverse the BIT to get the prefix sum
    while (i != 0) {
        sum += BIT[i];  // Add the value at BIT[i] to sum
        i &= (i - 1);   // Move to the parent node in BIT
    }
    
    return sum;  // Return the calculated prefix sum
}

// Function to update the BIT for a given index
void Update(int *BIT, int n, int ind, int x, int ai) {
    int diff = x - ai;  // Calculate the difference to be updated
    int i = ind + 1;    // BIT indices are 1-based, so increment index by 1
    
    // Traverse the BIT to update the value
    while (i <= n) {
        BIT[i] += diff;  // Update the value at BIT[i] by diff
        i += (i & -i);   // Move to the next relevant node in BIT
    }
}

// Function to construct the BIT from the given array
int* Construct(vector<int> &a, int n) {
    int *BIT = new int[n + 1];  // Allocate memory for BIT
    memset(BIT, 0, sizeof(int) * (n + 1));  // Initialize BIT with zeros
    
    // Update the BIT with values from the array
    for (int i = 0; i < n; i++)
        Update(BIT, n, i, a[i], 0);  // Initial values are considered as 0 in BIT
    
    return BIT;  // Return the constructed BIT
}

signed main() {
    vector<int> a = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};  // Input array
    int n = a.size();  // Size of the input array
    
    int *BIT = Construct(a, n);  // Construct the BIT from the input array
    
    // Print the prefix sum up to index 5
    cout << Pref_Sum(BIT, 5) << endl;  // Output: 12
    
    // Update the value at index 3 to 6
    Update(BIT, n, 3, 6, a[3]);
    
    // Print the updated prefix sum up to index 5
    cout << Pref_Sum(BIT, 5) << endl;  // Output: 15
    
    return 0;
}
