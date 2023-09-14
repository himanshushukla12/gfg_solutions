//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Initialize a helper matrix to store the cumulative count of 1s in each column.
        int dp[n][m];
        for (int i = 0; i < m; i++) {
            dp[0][i] = M[0][i];
            for (int j = 1; j < n; j++) {
                dp[j][i] = (M[j][i] == 1) ? dp[j - 1][i] + 1 : 0;
            }
        }
    
        int maxRectangle = 0;
    
        // For each row, calculate the maximum rectangle area using the largestRectangleArea function.
        for (int i = 0; i < n; i++) {
            vector<int> heights(m);
            for (int j = 0; j < m; j++) {
                heights[j] = dp[i][j];
            }
            maxRectangle = max(maxRectangle, largestRectangleArea(heights));
        }
    
        return maxRectangle;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int n = heights.size();
        int maxArea = 0;
    
        for (int i = 0; i < n; i++) {
            while (!s.empty() && heights[i] < heights[s.top()]) {
                int height = heights[s.top()];
                s.pop();
                int width = s.empty() ? i : i - s.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            s.push(i);
        }
    
        while (!s.empty()) {
            int height = heights[s.top()];
            s.pop();
            int width = s.empty() ? n : n - s.top() - 1;
            maxArea = max(maxArea, height * width);
        }
    
        return maxArea;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends