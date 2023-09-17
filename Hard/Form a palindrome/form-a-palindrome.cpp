//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestPalinSubseq(string A) {
        //code here
        int n=A.size();
        vector<vector<int>> dp(n,vector<int>(n,false));
        for(int g=0;g<n;g++){
            for(int i=0,j=g;j<n;i++,j++)
            {
                if(g==0) dp[i][j]=1;
                else if(g==1&&A[i]==A[j]) dp[i][j]=2;
                else if(g==1&&A[i]!=A[j]) dp[i][j]=1;
                else {
                    if(A[i]==A[j]) dp[i][j]=2+dp[i+1][j-1];
                    else dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
                }
            }
        }
       return dp[0][n-1];
    }
    int countMin(string str){
    //complete the function here
    return str.size()-longestPalinSubseq(str);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends