//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int isCircle(vector<string> &arr)
    {
        int n = arr.size(); // Number of strings in the array
        int start = 0; // Variable to store the starting node for DFS traversal

        // Graph representation with adjacency matrix
        vector<vector<bool>> graph(26, vector<bool>(26, false)); 

        // Degree vector to keep track of in-degree and out-degree differences
        vector<int> degree(26, 0); 

        // Constructing the graph
        for (auto &str : arr) {
            int u = str.front() - 'a'; // Starting character of the string
            int v = str.back() - 'a';  // Ending character of the string
            
            degree[u]++;   // Increase out-degree for node 'u'
            degree[v]--;   // Decrease in-degree for node 'v'
            graph[u][v] = true; // Mark the edge from 'u' to 'v'
            
            start = u; // Update start to the first character of the current string
        }

        // Check if any node has non-zero degree, meaning unequal in-degree and out-degree
        if (any_of(degree.begin(), degree.end(), [&](int x) { return x != 0; })) 
            return false;

        // Lambda function to perform DFS traversal
        auto dfs = [&](auto self, int u) -> void {
            for (int v = 0; v < 26; v++) {
                if (graph[u][v]) {
                    graph[u][v] = false; // Mark the edge as visited
                    self(self, v); // Recur for the next node
                }
            }
        };

        // Start DFS from the initial node
        dfs(dfs, start);

        // Check if all edges have been visited
        return !any_of(graph.begin(), graph.end(), [&](const auto &v) { return count(v.begin(), v.end(), true) > 0; });
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> A;
        string s;

        for (int i = 0; i < N; i++) {
            cin >> s;
            A.push_back(s);
        }

        Solution ob;
        cout << ob.isCircle(A) << endl;
    }
    return 0;
}
// } Driver Code Ends