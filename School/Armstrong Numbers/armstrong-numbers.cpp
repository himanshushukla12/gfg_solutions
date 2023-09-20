//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string armstrongNumber(int n){
        // code here
        int size=0;
        int N=n;
        while(N>0){
            N/=10;
            size++;
        }
        int sum=0;
        N=n;
        while(N>0){
            sum+=pow(N%10,size);
            N/=10;
        }
        if(n==sum) return "Yes";
        return "No";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends