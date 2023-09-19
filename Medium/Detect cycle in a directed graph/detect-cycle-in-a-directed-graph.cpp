//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    bool DFS(int node, vector<int> adj[], int viz[],int pathViz[]){
        viz[node]=1;
        pathViz[node]=1;
        for(auto it:adj[node]){
            if(!viz[it]){
                // when node is not vizited
                if(DFS(it,adj,viz,pathViz)){
                    return true;
                }//node prev has been visited but it has to be visited on same path
            }else if(pathViz[it]){
                return true;
            }
        }
        pathViz[node]=0;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int viz[V]={0};
        int pathViz[V]={0};
        for(int i=0;i<V;i++){
            if(not viz[i]){
                if(DFS(i,adj,viz,pathViz)) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends