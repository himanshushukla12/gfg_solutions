//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        // Your code here
        if(str1.length()!=str2.length())
            return false;
        int n = str1.length();
        int i, j, k;
        
        for(i=2, j=str1.length()-2, k=0; i<n+1 && j<n+(n-2); i++, j++, k++) {
            if(str1[i%n]!=str2[k] && str1[j%n]!=str2[k])
                return false;
        }
        
        return true;
    }

};


//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}

// } Driver Code Ends