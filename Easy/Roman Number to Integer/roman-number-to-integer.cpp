//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &s) {
        // code here
        unordered_map<char, int> ump;
        ump['I'] =1;
        ump['V'] =5;
        ump['X'] =10;
        ump['L'] =50;
        ump['C'] =100;
        ump['D'] =500;
        ump['M'] =1000;
        int max =ump[s[s.length()-1]];
        int ans = 0;
        for(int i =s.length()-1;i>=0; i--){
            int num =ump[s[i]];
            if(num>=max){
                ans = num+ans;
                max = num;
            }
            else 
                ans -= num;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends