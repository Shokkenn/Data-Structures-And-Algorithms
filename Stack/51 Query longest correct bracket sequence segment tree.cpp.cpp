#include<bits/stdc++.h>
using namespace std;

// Structure to represent each node in the segment tree
struct node {
    int pair, open, close;

    node() {
        pair = open = close = 0;  // Initialize all values to 0
    }
};

// Function to merge two nodes into a parent node
node merge(node left, node right) {
    node parent;

    // Minimum of open brackets in the left node and close brackets in the right node
    int minmatched = min(left.open, right.close);

    // Total pairs is the sum of pairs in both nodes plus the newly matched pairs
    parent.pair = left.pair + right.pair + minmatched;

    // Update the open and close brackets for the parent node
    parent.open = left.open + right.open - minmatched;
    parent.close = left.close + right.close - minmatched;

    return parent;
}

// Function to handle the query on the segment tree
node query(node* st, int l, int r, int ql, int qr, int sti) {
    // If the current segment is completely within the query range
    if (l >= ql && r <= qr)
        return st[sti];

    // If the current segment is completely outside the query range
    if (l > qr || r < ql) {
        node nullnode;
        return nullnode;
    }

    // If the current segment overlaps with the query range
    int m = (l + r) >> 1;

    // Merge results from the left and right children
    return merge(query(st, l, m, ql, qr, sti * 2 + 1), query(st, m + 1, r, ql, qr, sti * 2 + 2));
}

// Function to construct the segment tree recursively
void constructuntill(string &s, int l, int r, node* st, int sti) {
    // If it's a leaf node
    if (l == r) {
        st[sti].pair = 0;  // No pairs at a single character
        st[sti].open = (s[l] == '(') ? 1 : 0;  // If the character is '(', increment open count
        st[sti].close = (s[l] == ')') ? 1 : 0;  // If the character is ')', increment close count
        cout << st[sti].pair << " " << st[sti].open << " " << st[sti].close << "  " << l << " " << r << endl;
        return;
    }

    int m = (l + r) >> 1;

    // Recursively construct the left and right children
    constructuntill(s, l, m, st, sti * 2 + 1);
    constructuntill(s, m + 1, r, st, sti * 2 + 2);

    // Merge the results from the left and right children
    st[sti] = merge(st[sti * 2 + 1], st[sti * 2 + 2]);
    cout << st[sti].pair << " " << st[sti].open << " " << st[sti].close << "  " << l << " " << r << endl;
}

// Function to initialize and construct the segment tree
node* constructst(string &s, int n) {
    int p = (int)(ceil(log2(n)));  // Height of the segment tree
    int size = 2 * (int)pow(2, p) - 1;  // Maximum size of the segment tree
    node* st = new node[size];  // Create the segment tree array

    constructuntill(s, 0, n - 1, st, 0);  // Construct the segment tree

    return st;
}

// Function to handle multiple queries
int Queries(node* st, int l, int r, int n) {
    return 2 * query(st, 0, n - 1, l, r, 0).pair;  // Each pair contributes 2 to the result
}

signed main() {
    cout << "( ) ) ( ( ) ) ( ( ) )  (" << endl;
    cout << "0 1 2 3 4 5 6 7 8 9 10 11" << endl;
    cout << "P O C  L R" << endl;

    string s = "())(())(())(";  // Input string representing brackets
    int n = s.length();  // Length of the string

    vector<pair<int, int>> Q = {{4, 11}, {4, 5}, {1, 2}};  // Queries: pairs of (l, r) indices
    int q = Q.size();  // Number of queries

    node* st = constructst(s, n);  // Construct the segment tree

    for (int i = 0; i < q; i++)
        cout << Queries(st, Q[i].first, Q[i].second, n) << endl;  // Process each query and output the result

    return 0;
}
