//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		int nthPoint(int n){
		    const int mod=1e9+7;
		    // Code here
		    int a=1,b=2;
		    int c=a+b;
		    if(n<=3)
		    return n;
		    for(int i=3;i<n;i++){
		        a=b;
		        b=c;
		        c=(a%mod+b%mod)%mod;
		    }
		    return c%mod;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends