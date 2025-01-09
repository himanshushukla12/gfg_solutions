//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        vector<int> v;
        int start=0,end=0;
        long long sum=0;
        bool flag=false;
        int n=arr.size();
        int s=target;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            if(sum>=s)
            {
                end=i;
                while(sum>s && start<end)
                {
                    sum-=arr[start++];
                }
            }
            if(sum==s)
            {
                flag=true;
                v.push_back(start+1);
                v.push_back(end+1);
                break;
            }
        }
        if(flag) return v;
        else
        {
            v.push_back(-1);
            return v;
        }
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int d;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore();

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result) {
            cout << i << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends