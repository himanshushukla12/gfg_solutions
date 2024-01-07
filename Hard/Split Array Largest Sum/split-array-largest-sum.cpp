//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int no_of_subarrays_that_can_be_split (int arr[], int ans, int N)
    {
        int sum=0;
        int count = 1;
        
        for(int i=0; i<N; i++)
        {
            sum = sum + arr[i];
            if(sum>ans)
            {
                sum = arr[i];
                count++;
            }
        }
        return count;
    }
  
    int splitArray(int arr[] ,int N, int K) {
        // code here
        int ans = INT_MAX;
     
        // answer will line in rage of (max(arr), sum(array))
        int low=INT_MIN, high=0;
        for(int i=0; i<N; i++)
        {
            high =  high + arr[i];
            low = max(low, arr[i]);
        }
        
        while(low<=high)
        {
            int mid = (low+high)/2;
            int n = no_of_subarrays_that_can_be_split(arr, mid, N);
            
            
            if(n>K) // in this case mid can not be answer
            {
                low = mid+1;
            }
            else
            {
                ans = mid;
                high = mid - 1;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends