//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    long long pairAndSum(int n, long long arr[]) {
        long long totalSum = 0;
        // Iterate through each bit position, considering up to 63 bits for long long
        for (int bit = 0; bit < 63; ++bit) {
            int count = 0;
            // Count how many numbers have the current bit set
            for (int i = 0; i < n; i++) {
                if (arr[i] & (1LL << bit)) {  // Ensure shift is applied to a long long
                    count++;
                }
            }
            // Each pair's contribution from this bit (if set) to the total sum
            long long pairCount = (long long)count * (count - 1) / 2;
            long long contribution = pairCount * (1LL << bit); // Ensure bit shift is on a long long
            totalSum += contribution;
        }
        return totalSum;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        long long Arr[N];
        for (int i = 0; i < N; i++) {
            cin >> Arr[i];
        }
        Solution ob;
        cout << ob.pairAndSum(N, Arr) << endl;
    }
    return 0;
}
// } Driver Code Ends