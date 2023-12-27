//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> matrix) 
    {
        // Code here
        std::vector<int> result;
        int n = matrix.size();
        // Traverse the upper half of the matrix including the diagonal
        for (int i = 0; i < n; ++i) {
            int x = 0, y = i;
            while (x < n && y >= 0) {
                result.push_back(matrix[x][y]);
                x++;
                y--;
            }
        }
        // Traverse the lower half of the matrix excluding the diagonal
        for (int i = 1; i < n; ++i) {
            int x = i, y = n - 1;
            while (x < n && y >= 0) {
                result.push_back(matrix[x][y]);
                x++;
                y--;
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
        int n;
        cin >> n;
        vector<vector<int>> matrix;
        matrix.resize(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> ans = ob.antiDiagonalPattern(matrix);
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends