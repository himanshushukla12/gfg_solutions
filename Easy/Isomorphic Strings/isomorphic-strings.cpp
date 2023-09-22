//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        
        // Your code here
        int n=str1.size();
        int k=str2.size();
        if(n!=k) return false;
        unordered_map<char,char> m;
        for(int i=0;i<n;i++){
            if(m.find(str1[i])!=m.end()){
                if(m[str1[i]]!=str2[i])
                return false;
            }
            else{
                vector<char> values;
                for (auto it : m) {
                    values.push_back(it.second);
                }
                if (find(values.begin(), values.end(), str2[i])
                    != values.end()) {
                    return false;
                }
                else {
                    m[str1[i]] = str2[i];
                }
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends