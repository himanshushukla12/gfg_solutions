//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    int dfs(vector<vector<char>>& grid, int i, int j){
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]=='0') return 0;
        grid[i][j]='0';
        dfs(grid, i, j+1);
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j-1);
        dfs(grid, i-1, j-1);
        dfs(grid, i+1, j+1);
        dfs(grid, i-1, j+1);
        dfs(grid, i+1, j-1);
        return 1;
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int ans=0;
        if(grid.size()==0) return 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                ans+=dfs(grid,i,j);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends