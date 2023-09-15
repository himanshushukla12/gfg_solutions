//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<int> v(N,INT_MAX);
        vector<vector<int>> M(N,v);
        for(int i=0;i<N;i++) M[i][i]=0;
        for(int i=N-1;i>=1;--i){
            for(int j=i+1;j<N;++j){
                for(int k=i;k<j;++k){
                    int temp=arr[i-1]*arr[k]*arr[j]+M[i][k]+M[k+1][j];
                    M[i][j]=min(M[i][j],temp);
                }
            }
        }
        return M[1][N-1];
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