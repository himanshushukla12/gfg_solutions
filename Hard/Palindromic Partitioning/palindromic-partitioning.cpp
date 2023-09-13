//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int palindromicPartition(string str)
    {
        // code here
        int n=str.size();
        int dp[n][n]={0};
        for(int gap=1;gap<n;gap++){
            for(int i=0,j=gap;i<n-gap;i++,j++){
                if(str[i] == str[j] && (gap == 1 || dp[i + 1][j - 1] == 0)) dp[i][j]=0;
                else{
                    dp[i][j]=INT_MAX;
                    for(int k=i;k<j;k++){
                        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+1);
                    }
                }
            }
        }
        return dp[0][str.size()-1];
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends