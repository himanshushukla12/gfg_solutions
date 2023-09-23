//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
        // code here
        unordered_map<int,int> m;
        int freq=INT_MAX,num=arr[0];
        for(int i=0;i<n;i++){
            m[arr[i]]++;
        }
      
        int minfreq=INT_MAX,lar=INT_MIN;
        for(int i=0;i<n;i++)
        if(m[arr[i]]<minfreq)
        minfreq=m[arr[i]];
        for(int i=0;i<n;i++)
        if(m[arr[i]]==minfreq)
            if(arr[i]>lar)
                lar=arr[i];
      
      return lar;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}
// } Driver Code Ends