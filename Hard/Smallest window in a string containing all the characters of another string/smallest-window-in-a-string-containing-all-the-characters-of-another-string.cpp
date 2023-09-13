//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    const int no_of_chars=256;
    string smallestWindow (string str, string pat)
    {
        // Your code here
        int len1=str.length();
        int len2=pat.length();
        if(len1<len2) return "-1";
        int hash_pat[no_of_chars]={0};
        int hash_str[no_of_chars]={0};
        //storing the occurrence of char patterns
        for(int i=0;i<len2;i++)
        hash_pat[pat[i]]++;
        int start=0,start_index=-1,min_len=INT_MAX;
        int count=0;
        for(int j=0;j<len1;j++){
            hash_str[str[j]]++;
            if(hash_str[str[j]]<=hash_pat[str[j]])
            count++;
            if(count==len2){
                while(hash_str[str[start]]>hash_pat[str[start]]
                ||hash_pat[str[start]]==0){
                    if(hash_str[str[start]]>hash_pat[str[start]]){
                        hash_str[str[start]]--;
                        start++;
                    }
                }
                int len_window=j-start+1;
                if(min_len>len_window){
                    min_len=len_window;
                    start_index=start;
                }
            }
        }
        if(start_index==-1) return "-1";
        return str.substr(start_index,min_len);
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends