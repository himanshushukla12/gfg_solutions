//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    pair<long,long> indexes(vector<long long> arr, long long x)
    {
        // code here
        int n=arr.size();
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
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}

// } Driver Code Ends