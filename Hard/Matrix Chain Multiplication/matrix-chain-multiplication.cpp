//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int matrixChainMultiplication(int *arr,int n) {

    // Create a DP table to store minimum multiplication counts
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    // Fill the DP table using bottom-up approach
    for (int chainLen = 2; chainLen < n; chainLen++) {
        for (int i = 1; i < n - chainLen + 1; i++) {
            int j = i + chainLen - 1;
            dp[i][j] = INT_MAX;
            
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    
    // The result is stored in dp[1][n-1], which represents the minimum cost of multiplication
    return dp[1][n - 1];
}
    int matrixMultiplication(int n, int arr[])
    {
       return  matrixChainMultiplication(arr,n);
    }

};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends