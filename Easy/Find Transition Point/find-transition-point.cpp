//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int transitionPoint(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], i;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << transitionPoint(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends


int transitionPoint(int arr[], int n) {
    // code here
    int left=0,right=n-1;
    int mid;
    int ans=-1;
    while(left<=right){
        mid=(left+right)/2;
        if(arr[mid]==1){
            if(mid-1>0 and arr[mid-1]==1){
                ans=mid-1;
            }
            else ans=mid;
            right=mid-1;
        }
        else if(arr[mid]==0) left=mid+1;
        else right=mid-1;
    }
    return ans;
}