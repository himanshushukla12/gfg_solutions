//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        // code here
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        
        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({A[A.size()-1]+B[B.size()-1],{A.size()-1,B.size()-1}});
        
        set<pair<int,int>> st;
        vector<int> result;
        
        st.insert({A.size()-1,B.size()-1});
        
        while(K--){
            auto top = pq.top();
            pq.pop();
            
            int sum = top.first;
            
            int x = top.second.first;
            int y = top.second.second;
            
            result.push_back(sum);
            
            if(st.find({x-1,y}) == st.end() && x-1 >= 0){
                pq.push({A[x-1]+B[y],{x-1,y}});
                st.insert({x-1,y});
            }
            if(st.find({x,y-1}) == st.end() && y-1 >= 0){
                pq.push({A[x]+B[y-1],{x,y-1}});
                st.insert({x,y-1});
            }
        }
        
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends