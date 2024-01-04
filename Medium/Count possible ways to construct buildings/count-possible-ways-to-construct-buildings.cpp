//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int TotalWays(int N)
	{
	    // Code here
	    const int mod=1e9+7;
	    long long dp[N+1]={0};
	    dp[1]=2;
	    dp[2]=3;
	    for(int i=3;i<=N;++i){
	        dp[i]=(dp[i-1]+dp[i-2])%mod;
	        dp[i]%=mod;
	    }
	    return ((dp[N]*dp[N])%mod);
	}
	// N: 1  2  3    4    5
	// B: 4  9  25  64   169
	//    2  3  5   8     
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends