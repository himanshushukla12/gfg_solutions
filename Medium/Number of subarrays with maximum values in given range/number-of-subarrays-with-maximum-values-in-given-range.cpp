//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    long countSubarrays(int a[], int n, int L, int R){
        vector<int> left(n,-1);
        vector<int> right(n,n);
        
        stack<int> s;
        for(int i=0;i<n;i++){
            while(!s.empty() && a[s.top()]<=a[i]){
                s.pop();
            }
            if(!s.empty()){
                left[i]=s.top();
            }
            s.push(i);
        }
        
        s=stack<int>();
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && a[s.top()]<a[i]){
                s.pop();
            }
            if(!s.empty()){
                right[i]=s.top();
            }
            s.push(i);
        }
        
        long res=0;
        for(int i=0;i<n;i++){
            if(a[i]>=L && a[i]<=R){
                int ways=(i-left[i])*(right[i]-i);
                res+=ways;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
// driver program
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        
        int n ,l,r;
        cin >> n>>l>>r;
        int a[n];
        for(int i=0;i<n;i++)
        cin >> a[i];
        Solution ob;
    	cout << ob.countSubarrays(a, n, l, r)<<endl;
    }
	return 0;
}

// } Driver Code Ends