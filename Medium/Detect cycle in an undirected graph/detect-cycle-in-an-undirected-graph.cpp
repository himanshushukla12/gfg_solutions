//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool DFS(vector<int> adj[],vector<bool> &viz,int i,int parent){
        viz[i]=true;
        for(auto u:adj[i]){
            if(not viz[u]){
                if(DFS(adj,viz,u,i)){
                    return true;
                }
            }
            else if(u!=parent) return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> viz(V,false);
        // for loop for disjoint sets
        for(int i=0;i<V;++i){
            if(not viz[i]){
                if(DFS(adj,viz,i,-1)){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends