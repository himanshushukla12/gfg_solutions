//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void DFS(int i,int j,int n,int m, vector<vector<bool>> &viz, vector<vector<int>> &mat) {
        if(i<0||i>=n||j<0||j>=m||viz[i][j]||mat[i][j]==0) return;
    
        viz[i][j]=true;
        DFS(i+1,j,n,m,viz,mat);
        DFS(i-1,j,n,m,viz,mat);
        DFS(i,j+1,n,m,viz,mat);
        DFS(i,j-1,n,m,viz,mat);
    }
    
    int numberOfEnclaves(vector<vector<int>> &mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<bool>> viz(n,vector<bool>(m,false));
    
        for(int i=0;i<n;i++){
            if(!viz[i][0] && mat[i][0]==1) DFS(i,0,n,m,viz,mat);
            if(!viz[i][m-1] && mat[i][m-1]==1) DFS(i,m-1,n,m,viz,mat);
        }
        for(int i=0;i<m;i++){
            if(mat[0][i]==1 && !viz[0][i]) DFS(0,i,n,m,viz,mat);
            if(mat[n-1][i]==1 && !viz[n-1][i]) DFS(n-1,i,n,m,viz,mat);
        }
    
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){  // Fix here
                if(!viz[i][j] and mat[i][j]==1) count++;
            }
        }
        return count;
    }

};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends