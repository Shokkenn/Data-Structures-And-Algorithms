#include <bits/stdc++.h> 
using namespace std;

// Comparator function to sort queries by their end index
bool comp(pair<pair<int, int>, int> Q1, pair<pair<int, int>, int> Q2) {
    return Q1.first.second < Q2.first.second;
}

// Function to get the sum of elements up to a certain index in the BIT
int Get_Distinct(int BIT[], int ind) {
    int sum = 0;
    
    // Traverse the BIT backwards to get the prefix sum
    for (; ind > 0; ind -= (ind & -ind))
        sum += BIT[ind];
    
    return sum;
}

// Function to update the BIT with a value at a certain index
void Update(int BIT[], int n, int ind, int val) {
    // Traverse the BIT and update the value at each relevant position
    for (; ind <= n; ind += (ind & -ind))
        BIT[ind] += val;
}

// Function to answer the queries about distinct elements in subarrays
void Ans_Queries(vector<int> &a, int n, vector<pair<pair<int, int>, int>> &Q, int q) {
    // Sort the queries by their end index
    sort(Q.begin(), Q.end(), comp);

    int ans[q];  // Array to store the answers to the queries
    
    int BIT[n+1];  // Binary Indexed Tree (BIT) for prefix sums
    memset(BIT, 0, sizeof(BIT));  // Initialize BIT with zeros
    
    map<int, int> last_vis;  // Map to store the last visited index of each element
    
    int j = 0;  // Index for the queries
    
    // Process each element in the array
    for (int i = 0; i < n; i++) {
        // If the element has been seen before, update the BIT to remove its previous occurrence
        if (last_vis[a[i]])
            Update(BIT, n, last_vis[a[i]], -1);
        
        // Update the last visited index of the element
        last_vis[a[i]] = i + 1;
        
        // Update the BIT to include the current occurrence of the element
        Update(BIT, n, i + 1, 1);
        
        // Process all queries that end at the current index
        while (j < q && Q[j].first.second == i) {
            // Get the number of distinct elements in the range specified by the query
            ans[Q[j].second] = Get_Distinct(BIT, i + 1) - Get_Distinct(BIT, Q[j].first.first);
            j++;
        }
    }
    
    // Print the answers to all queries
    for (int i = 0; i < q; i++)
        cout << ans[i] << " ";
    cout << endl;
}

int main() {
    vector<int> a = {1, 1, 2, 1, 3};  // Input array
    int n = a.size();  // Size of the input array
    
    // Queries in the form of pairs of (start, end) indices with their original index
    vector<pair<pair<int, int>, int>> Q = {{{0, 4}, 0}, {{1, 3}, 1}, {{2, 4}, 2}};
    int q = Q.size();  // Number of queries
    
    // Answer the queries
    Ans_Queries(a, n, Q, q);
    
    return 0; 
}


// 1 1 2 1 3
// 0 1 2 3 4  
// 0->4 = 3
//1->3 = 2
//2->4 = 3