//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        // finding the lower index
        int low=0,high=n-1,mid;
        int lowerIdx=-1;
        while(low<=high){
            mid=(low+high)/2;
            if(arr[mid]==x){
                if(mid-1>=0 and arr[mid-1]==x)
                lowerIdx=mid-1;
                else 
                lowerIdx=mid;
                high=mid-1;
            }
            else if(x>arr[mid]) low=mid+1;
            else high=mid-1;
        }
        
        //finding upper index
        low=lowerIdx,high=n-1;
        int upperIdx=-1;
        while(low<=high){
            mid=(low+high)/2;
            if(arr[mid]==x){
                if(mid+1<n and arr[mid+1]==x)
                upperIdx=mid+1;
                else 
                upperIdx=mid;
                low=mid+1;
            }
            else if(x>arr[mid]) low=mid+1;
            else high=mid-1;
        }
        return {lowerIdx,upperIdx};
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends