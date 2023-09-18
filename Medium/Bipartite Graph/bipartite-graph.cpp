//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
//linear graphs, neans no cycle will always be a bipartite graph
// graph with odd lenght cycle is not a BIPARTITE GRAPH
	bool check(int start, int V, vector<int> adj[], vector<int> &color){
	    queue<int> q;
	    q.push(start); // starting node 0 with color code 0
	    color[start]=0;
	    while(!q.empty()){
	        int node;
	        node=q.front();
	        q.pop();
	        for(auto u:adj[node]){
	            if(color[u]==-1){
	                color[u]=1-color[node];
	                q.push(u);
	            }else if(color[node]==color[u]) return false;
	        }
	    }
	    return true;
	}
	bool isBipartite(int V, vector<int>adj[]){
	    // using BFS, taking only two color 0 and 1, -1 is considered as no color
	    vector<int> color(V,-1);
	    for(int i=0;i<V;i++){
	        if(color[i]==-1){
	            if(!check(i,V,adj,color)){
	                return false;
	            }
	        }
	    }
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends