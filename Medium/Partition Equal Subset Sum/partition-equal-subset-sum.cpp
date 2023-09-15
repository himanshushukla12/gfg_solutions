//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool canPartition(int *arr, int N) {
        int totalSum = 0;
        for (int i = 0; i < N; i++) {
            totalSum += arr[i];
        }
    
        // If the total sum is odd, it's impossible to partition the array
        if (totalSum % 2 != 0) {
            return false;
        }
    
        int targetSum = totalSum / 2;
    
        // Create a 2D DP table with dimensions (N+1) x (targetSum+1)
        vector<vector<bool>> dp(N + 1, vector<bool>(targetSum + 1, false));
    
        // Base case: When the target sum is 0, it's always possible to achieve it by not picking any elements
        for (int i = 0; i <= N; i++) {
            dp[i][0] = true;
        }
    
        // Fill in the DP table
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= targetSum; j++) {
                // If the current element is greater than the target sum, we can't pick it
                if (arr[i - 1] > j) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    // Include the current element in the subset or exclude it
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                }
            }
        }
    
        // The answer will be in dp[N][targetSum]
        return dp[N][targetSum];
    }

    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=accumulate(arr,arr+N,0);
        if(sum&1) return 0; //if odd then partition not possible
        return canPartition(arr,N);
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
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends